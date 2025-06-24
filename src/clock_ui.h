#ifndef CLOCK_UI_H
#define CLOCK_UI_H

#include <lvgl.h>
#include "lvgl_v8_port.h"
#include "clock_messages.h"
#include "clock_server.h"

LV_FONT_DECLARE(xanh_mono_108);
LV_FONT_DECLARE(brygada_1918_24);
LV_IMG_DECLARE(gear);

struct UILabels {
    lv_obj_t* time_l;
    lv_obj_t* date_l;
    lv_obj_t* message_l;
};
static UILabels labels;
static lv_obj_t* line;

static lv_obj_t* settingsImg;
static lv_obj_t* settingsBtn;
static bool settingsBtnVisible;

static lv_obj_t* tint;
static lv_obj_t* settingsContainer;
static bool settingsMenuOpen;

inline char pendingSsid[33] = {0};
inline char pendingPswd[64] = {0};
inline bool connectRequest;
static lv_obj_t* ssid_ta;
static lv_obj_t* ssid_label;
static lv_obj_t* pswd_ta;
static lv_obj_t* pswd_label;
static lv_obj_t* connect_btn;
static lv_obj_t* connect_status;
static lv_obj_t* keyboard;
static bool keyboardOpen;

static String currentMessage;
static String currentTime;
static String currentDate;

static lv_style_t screen_style;
static lv_style_t text_style;
static lv_style_t time_style;
static lv_style_t line_style;
static lv_style_t settings_style;
static lv_style_t tint_style;
static lv_style_t ta_style;

void InitUI();
void UpdateTime();
void UpdateMessage();
void OnScreenTap(lv_event_t *e);
void OnSettingsTap(lv_event_t *e);
void ConfigureSettingsMenu();
void ActivateKeyboard(lv_event_t *e);
void DeactivateKeyboard();
void OnConnectToWifi(lv_event_t *e);
void SetWifiStatusIcon(bool status);

#endif