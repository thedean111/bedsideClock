// clock_ui.h
#ifndef CLOCK_UI_H
#define CLOCK_UI_H

#include "lvgl_port.h"
#include "waveshare_rgb_lcd_port.h"
#include <esp_timer.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "clock_messages.h"

LV_FONT_DECLARE(xanh_mono_108);
LV_FONT_DECLARE(brygada_1918_24);
LV_IMG_DECLARE(gear);
LV_IMG_DECLARE(set_time);
LV_IMG_DECLARE(checkmark);
LV_IMG_DECLARE(arrow_1);
LV_IMG_DECLARE(calendar);

#define MINUTE_IN_HOUR 5

typedef enum {
    HOUR,
    MINUTE,
    AMPM
} TimeComp;

typedef struct {
    TimeComp setting;
    int value;
} TimeComponent;

void InitUI(void);
void IncrementTime(void);
void UpdateMessage(const char *msg);
void ConfirmSettings(lv_event_t *e);
void ToggleElement(lv_obj_t *obj, bool status, int time, int delay, bool toggleChildren);
void OnScreenTap(lv_event_t *e);
void OnSetTime(lv_event_t *e);
void OnSetDate(lv_event_t *e);
void OnSelectDay(lv_event_t *e);
void IncrementTimeComponent(lv_event_t *e);
void UpdateTimeString();
void UpdateDateString();

#endif // CLOCK_UI_H