/*================================================================================
CONFIGURATION
================================================================================*/
// Include
#include <Arduino.h>
#include <esp_display_panel.hpp>
#include <lvgl.h>
#include "lvgl_v8_port.h"

#include "clock_messages.h"
#include "clock_ui.h"

#define PERIOD_UPDATE_MESSAGE_MIN .1
#define PERIOD_SAVE_USED_MIN .2
#define PERIOD_UPDATE_TIME_INCREMENT 2000 // 60000 is every a minute

// Namespaces
using namespace esp_panel::drivers;
using namespace esp_panel::board;

// Local Variables
unsigned long lastMsgUpdate;
unsigned long lastSave;

/*================================================================================
SETUP
================================================================================*/
void setup()
{
    Serial.begin(115200);
    delay(1000);

    ESP_UTILS_LOGI("Setting up!");

    SetupLittleFS();
    LoadAllMessages();
    LoadAllUsed();

    delay(2000);

    Serial.println("Initializing board");
    Board *board = new Board();
    board->init();

#if LVGL_PORT_AVOID_TEARING_MODE
    auto lcd = board->getLCD();
    
    // When avoid tearing function is enabled, the frame buffer number should be set in the board driver
    lcd->configFrameBufferNumber(LVGL_PORT_DISP_BUFFER_NUM);
#if ESP_PANEL_DRIVERS_BUS_ENABLE_RGB && CONFIG_IDF_TARGET_ESP32S3
    auto lcd_bus = lcd->getBus();
    /**
     * As the anti-tearing feature typically consumes more PSRAM bandwidth, for the ESP32-S3, we need to utilize the
     * "bounce buffer" functionality to enhance the RGB data bandwidth.
     * This feature will consume `bounce_buffer_size * bytes_per_pixel * 2` of SRAM memory.
     */
    if (lcd_bus->getBasicAttributes().type == ESP_PANEL_BUS_TYPE_RGB) {
        static_cast<BusRGB *>(lcd_bus)->configRGB_BounceBufferSize(lcd->getFrameWidth() * 10);
    }
#endif
#endif
    assert(board->begin());

    Serial.println("Initializing LVGL");
    lvgl_port_init(board->getLCD(), board->getTouch());

    ESP_UTILS_LOGI("Creating UI");

    InitUI();
    ESP_UTILS_LOGI("UI Created!");

    lastTimeUpdate = millis();
    lastMsgUpdate = millis();
    lastSave = millis();

    delay(1000);
}

/*================================================================================
LOOP
================================================================================*/
void loop()
{
  if (timeSet && millis() - lastTimeUpdate > PERIOD_UPDATE_TIME_INCREMENT) {
    IncrementTime();

    if (changeMessage) {
      changeMessage = false;
      UpdateMessage(GetRandomMessage().c_str());
    }

    lastTimeUpdate = millis();
  }

  // Save every minute for now
  // Update the UI right after
  if (millis() - lastSave >= (PERIOD_SAVE_USED_MIN * 60000)) {
    UsedToDisk();

    // Sets the text to what it was before the save
    lvgl_port_lock(-1);
    lv_label_set_text(labels.time_l, currentTime);
    lv_label_set_text(labels.date_l, currentDate);
    // lv_label_set_text(labels.message_l, currentMessage.c_str());
    lvgl_port_unlock();

    lastSave = millis();
  }
  
  delay(5);
}
