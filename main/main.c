/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include "waveshare_rgb_lcd_port.h"
#include <esp_timer.h>
#include "esp_err.h"
#include "clock_ui.h"
#include "clock_messages.h"

#define CLOCK_UPDATE_FACTOR .1


static esp_timer_handle_t esp_timer;
static void setup_clock_timer(void) {
    const esp_timer_create_args_t args = {
        .callback = (esp_timer_cb_t)IncrementTime,
        .name     = "clock_tick"
    };

    esp_timer_create(&args, &esp_timer);
    // 60 000 000 μs = 1 min
    esp_timer_start_periodic(esp_timer,  CLOCK_UPDATE_FACTOR * 60000000);
}

void app_main()
{
    // Configure LittleFS
    SetupFS();
    esp_err_t ret = InitMessages();

    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failure to load a message!");
    } else {
        ESP_LOGI(TAG, "Messages loaded!");
    }

    // Initialize the LCD
    waveshare_esp32_s3_rgb_lcd_init(); // Initialize the Waveshare ESP32-S3 RGB LCD 
    // wavesahre_rgb_lcd_bl_on();  //Turn on the screen backlight 
    // wavesahre_rgb_lcd_bl_off(); //Turn off the screen backlight 
    
    // Display the UI
    if (lvgl_port_lock(-1)) {
        InitUI();

        lvgl_port_unlock();
    }

    // Setup the timer to update the clock
    setup_clock_timer();
}
