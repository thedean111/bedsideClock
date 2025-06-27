#ifndef CLOCK_UI_H
#define CLOCK_UI_H

#include <lvgl.h>
#include "lvgl_v8_port.h"

LV_FONT_DECLARE(xanh_mono_108);
LV_FONT_DECLARE(brygada_1918_24);
LV_IMG_DECLARE(gear);
LV_IMG_DECLARE(set_time);
LV_IMG_DECLARE(checkmark);
LV_IMG_DECLARE(arrow_1);

static String months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
static int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

enum TimeComp {
    HOUR,
    MINUTE,
    AMPM
};

struct TimeComponent {
    TimeComp setting;
    int value;
};

struct UILabels {
    lv_obj_t* time_l;
    lv_obj_t* date_l;
    lv_obj_t* message_l;
};
static UILabels labels;
static lv_obj_t* line;

static lv_obj_t* setTimeBtns;

static lv_obj_t* settingsImg;
static lv_obj_t* setTimeBtn;
static bool setTimeBtnVisible;
static lv_coord_t column[] = {50, 50, 50, LV_GRID_TEMPLATE_LAST};
static lv_coord_t row[] = {50, 50, LV_GRID_TEMPLATE_LAST};

static lv_obj_t* confirmBtn;
static lv_obj_t* checkmarkImg;

static bool settingTime;

inline bool timeSet;
inline bool changeMessage;

static String currentMessage;
inline char currentTime[16];
inline char currentDate[32];

static lv_style_t screen_style;
static lv_style_t text_style;
static lv_style_t time_style;
static lv_style_t line_style;
static lv_style_t settings_style;
static lv_style_t incrTimeBtnBg;
static lv_style_t incrTimeBtn;

inline unsigned long lastTimeUpdate;
inline int hour;
inline int minute;
inline int month;
inline int day;
inline int year;
static bool isPm;

void InitUI();
void IncrementTime();
void UpdateMessage(const char *msg);
void OnScreenTap(lv_event_t *e);
void OnSetTime(lv_event_t *e);
void ConfirmSetting(lv_event_t *e);
void UpdateTimeString();
void UpdateDateString();
void ToggleElement(lv_obj_t *obj, bool status, int time, int delay);
void IncrementTimeComponent(lv_event_t *e);

#endif