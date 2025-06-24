#include "clock_ui.h"

void InitUI() {
    settingsBtnVisible = true;
    connectRequest = false;

     // Lock LVGL while modifying UI
    lvgl_port_lock(-1);

    //-----
    // STYLES
    //-----
    // Configure style for screen background
    lv_style_init(&screen_style);
    lv_style_set_bg_color(&screen_style, lv_color_hex(0x343d3f));
    lv_obj_add_style(lv_scr_act(), &screen_style, 0);
    
    // Configure general text style
    lv_style_init(&text_style);
    lv_style_set_text_color(&text_style, lv_color_hex(0xb3b3b3));
    lv_style_set_text_font(&text_style, &brygada_1918_24);
    lv_style_set_width(&text_style, 800);
    lv_style_set_text_align(&text_style, LV_TEXT_ALIGN_CENTER);

    // Style for the time
    lv_style_init(&time_style);
    lv_style_set_text_color(&time_style, lv_color_hex(0xd2d2d2));
    lv_style_set_text_font(&time_style, &xanh_mono_108);

    // Style for the line
    lv_style_init(&line_style);
    lv_style_set_line_width(&line_style, 2);
    lv_style_set_line_color(&line_style, lv_color_hex(0x303030));

    //-----
    // UI OBJECTS
    //-----
    // Create Time Label
    labels.time_l = lv_label_create(lv_scr_act());
    lv_label_set_text(labels.time_l, "");
    lv_obj_add_style(labels.time_l, &time_style, 0);
    lv_obj_align(labels.time_l, LV_ALIGN_TOP_MID, 0, 145);

    // Create Date Label
    labels.date_l = lv_label_create(lv_scr_act());
    lv_label_set_text(labels.date_l, "Connect to wifi...");
    lv_obj_add_style(labels.date_l, &text_style, 0);
    lv_obj_align_to(labels.date_l, labels.time_l, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    // Create a line to separate the messages from date and time
    line = lv_line_create(lv_scr_act());
    static lv_point_t points[] = {{50, 370}, {750, 370}};
    lv_line_set_points(line, points, 2);
    lv_obj_add_style(line, &line_style, 0);

    // Create Message Label
    labels.message_l = lv_label_create(lv_scr_act());
    lv_label_set_text(labels.message_l, "");
    lv_obj_add_style(labels.message_l, &text_style, 0);
    lv_obj_align(labels.message_l, LV_ALIGN_TOP_MID, 0, 400);
    lv_obj_set_width(labels.message_l, 650);

    // Create Gear Button
    settingsBtn = lv_btn_create(lv_scr_act());
    lv_obj_remove_style_all(settingsBtn);
    lv_obj_clear_flag(settingsBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_size(settingsBtn, 45, 45);
    lv_obj_align(settingsBtn, LV_ALIGN_TOP_RIGHT, -20, 20);

    // Settings (gear) icon
    settingsImg = lv_img_create(settingsBtn);
    lv_img_set_src(settingsImg, &gear);
    lv_obj_center(settingsImg);

    // Settings menu
    ConfigureSettingsMenu();

    //---
    // EVENTS
    //---
    lvgl_port_unlock();

    lv_obj_add_event_cb(lv_scr_act(), OnScreenTap, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(settingsBtn, OnSettingsTap, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(connect_btn, OnConnectToWifi, LV_EVENT_PRESSED, NULL);
}

void ConfigureSettingsMenu() {
    // Background style
    lv_style_init(&tint_style);
    lv_style_set_bg_color(&tint_style, lv_color_hex(0x000000));
    lv_style_set_bg_opa(&tint_style, LV_OPA_30);
    lv_style_set_width(&tint_style, 800);
    lv_style_set_height(&tint_style, 480);
    lv_style_set_align(&tint_style, LV_ALIGN_CENTER);

    lv_style_init(&settings_style);
    lv_style_set_width(&settings_style, 300);
    lv_style_set_height(&settings_style, 350);
    lv_style_set_align(&settings_style, LV_ALIGN_CENTER);
    lv_style_set_bg_color(&settings_style, lv_color_hex(0xC6C8CD));
    lv_style_set_border_color(&settings_style, lv_color_hex(0x303030));
    lv_style_set_pad_top(&settings_style, 20);
    lv_style_set_pad_bottom(&settings_style, 20);
    lv_style_set_pad_left(&settings_style, 20);
    lv_style_set_pad_right(&settings_style, 20);

    // Container
    tint = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(tint);
    lv_obj_add_style(tint, &tint_style, 0);
    lv_obj_clear_flag(tint, LV_OBJ_FLAG_CLICKABLE);

    settingsContainer = lv_obj_create(tint);
    lv_obj_clear_flag(settingsContainer, LV_OBJ_FLAG_EVENT_BUBBLE);
    lv_obj_add_style(settingsContainer, &settings_style, 0);
    lv_obj_set_flex_flow(settingsContainer, LV_FLEX_FLOW_COLUMN);

    // Text area style
    lv_style_init(&ta_style);

    //----
    // SSID
    //----
    // Container
    lv_obj_t* ssid_cont = lv_obj_create(settingsContainer);
    lv_obj_remove_style_all(ssid_cont);
    lv_obj_set_size(ssid_cont, LV_PCT(100), 40);
    lv_obj_set_flex_align(ssid_cont, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_flex_flow(ssid_cont, LV_FLEX_FLOW_ROW);

    // Label
    ssid_label = lv_label_create(ssid_cont);
    lv_label_set_text(ssid_label, "SSID:");
    lv_obj_set_style_text_font(ssid_label, &brygada_1918_24, 0);
    lv_obj_set_width(ssid_label, LV_PCT(50));

    // Text Area
    ssid_ta = lv_textarea_create(ssid_cont);
    lv_obj_add_style(ssid_ta, &ta_style, 0);
    lv_textarea_set_one_line(ssid_ta, true);
    lv_obj_set_flex_grow(ssid_ta, 1);
    lv_obj_add_event_cb(ssid_ta, ActivateKeyboard, LV_EVENT_PRESSED, NULL);

    //----
    // Password
    //----
    // Container
    lv_obj_t* pswd_cont = lv_obj_create(settingsContainer);
    lv_obj_remove_style_all(pswd_cont);
    lv_obj_set_size(pswd_cont, LV_PCT(100), 40);
    lv_obj_set_flex_align(pswd_cont, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_flex_flow(pswd_cont, LV_FLEX_FLOW_ROW);

    // Label
    pswd_label = lv_label_create(pswd_cont);
    lv_label_set_text(pswd_label, "Password:");
    lv_obj_set_style_text_font(pswd_label, &brygada_1918_24, 0);
    lv_obj_set_width(pswd_label, LV_PCT(50));

    // Text Area
    pswd_ta = lv_textarea_create(pswd_cont);
    lv_obj_add_style(pswd_ta, &ta_style, 0);
    lv_textarea_set_one_line(pswd_ta, true);
    lv_obj_set_flex_grow(pswd_ta, 1);
    lv_obj_add_event_cb(pswd_ta, ActivateKeyboard, LV_EVENT_PRESSED, NULL);

    //----
    // Connect Button
    //----
    // Container
    lv_obj_t* cnt_container = lv_obj_create(settingsContainer);
    lv_obj_remove_style_all(cnt_container);
    lv_obj_set_size(cnt_container, LV_PCT(100), 60);
    lv_obj_set_flex_align(cnt_container, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_flex_flow(cnt_container, LV_FLEX_FLOW_ROW);

    // Button
    connect_btn = lv_btn_create(cnt_container);
    lv_obj_set_width(connect_btn, LV_SIZE_CONTENT);
    lv_obj_t* connect_label = lv_label_create(connect_btn);
    lv_label_set_text(connect_label, "CONNECT");
    lv_obj_set_style_text_font(connect_label, &brygada_1918_24, 0);
    lv_obj_align(connect_label, LV_ALIGN_CENTER, 0, 0);

    // Icon
    connect_status = lv_label_create(cnt_container);
    lv_label_set_text(connect_status, LV_SYMBOL_CLOSE);

    //----
    // Keyboard
    //----
    keyboardOpen = true;
    keyboard = lv_keyboard_create(lv_scr_act());
    lv_obj_set_size(keyboard, 800, 200);

    settingsMenuOpen = true;
}

void UpdateTime() {
    currentTime = GetCurrentTime();
    currentDate = GetCurrentDate();

    // Lock LVGL while modifying UI
    lvgl_port_lock(-1);
    lv_label_set_text(labels.time_l, currentTime.c_str());
    lv_label_set_text(labels.date_l, currentDate.c_str());
    lvgl_port_unlock();
}

void UpdateMessage() {
    currentMessage = GetRandomMessage();

    // Lock LVGL while modifying UI
    lvgl_port_lock(-1);
    lv_label_set_text(labels.message_l, currentMessage.c_str());
    lvgl_port_unlock();
}

void OnScreenTap(lv_event_t *e) {
    if (settingsMenuOpen) {
        lv_obj_fade_out(tint, 100, 0);
        settingsMenuOpen = false;

    } else if (settingsBtnVisible) {
        lv_obj_fade_out(settingsBtn, 200, 0);
        settingsBtnVisible = false;

    } else {
        lv_obj_fade_in(settingsBtn, 200, 0);
        settingsBtnVisible = true;
    }

    if (keyboardOpen) {
        DeactivateKeyboard();
    }

    ESP_UTILS_LOGI("Screen tap detected!");
}

void OnSettingsTap(lv_event_t *e) {
    if (!settingsBtnVisible) {
        lv_obj_fade_in(settingsBtn, 200, 0);
        settingsBtnVisible = true;
        return;
    }

    if (!settingsMenuOpen) {
        lv_obj_fade_in(tint, 50, 0);
        lv_obj_clear_flag(settingsContainer, LV_OBJ_FLAG_EVENT_BUBBLE);

    } else {
        lv_obj_fade_out(tint, 50, 0);
        lv_obj_add_flag(settingsContainer, LV_OBJ_FLAG_EVENT_BUBBLE);
    }

    if (keyboardOpen) {
        DeactivateKeyboard();
    }

    settingsMenuOpen = !settingsMenuOpen;
    ESP_UTILS_LOGI("Settings button tapped!");
}

void ActivateKeyboard(lv_event_t *e) {
    if (!keyboardOpen) {
        lv_obj_fade_in(keyboard, 50, 0);
        keyboardOpen = true;
    }

    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    if(keyboard != NULL) lv_keyboard_set_textarea(keyboard, ta);
}

void DeactivateKeyboard() {
    if (keyboardOpen) {
        lv_obj_fade_out(keyboard, 50, 0);
        keyboardOpen = false;
    }
}

void OnConnectToWifi(lv_event_t* e) {
    if (keyboardOpen) {
        DeactivateKeyboard();
    }

    ESP_UTILS_LOGI("Attempt to connect");
    connectRequest = true;
    strncpy(pendingSsid, lv_textarea_get_text(ssid_ta), sizeof(pendingSsid)-1);
    strncpy(pendingPswd, lv_textarea_get_text(pswd_ta), sizeof(pendingPswd)-1);
    pendingSsid[sizeof(pendingSsid)-1] = '\0';
    pendingPswd[sizeof(pendingPswd)-1] = '\0';

}

void SetWifiStatusIcon(bool status) {
    lvgl_port_lock(-1);
    if (status) {
        lv_label_set_text(connect_status, LV_SYMBOL_OK);
    } else {
        lv_label_set_text(connect_status, LV_SYMBOL_CLOSE);
    }
    lvgl_port_unlock();
}