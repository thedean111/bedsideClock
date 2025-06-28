#include "clock_ui.h"

void InitUI() {
    setTimeBtnVisible = false;
    settingTime = false;
    timeSet = false;
    hour = 12;
    minute = 00;
    month = 0;
    day = 1;
    year = 2000;
    changeMessage = false;

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

    lv_style_init(&incrTimeBtnBg);
    
    lv_style_init(&incrTimeBtn);
    lv_style_set_bg_color(&incrTimeBtn, lv_color_hex(0xacb1bc));
    lv_style_set_align(&incrTimeBtn, LV_ALIGN_CENTER);
    //-----
    // UI OBJECTS
    //-----
    setTimeBtns = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(setTimeBtns);
    lv_obj_align(setTimeBtns, LV_ALIGN_TOP_MID, 0, 75);
    lv_obj_set_size(setTimeBtns, 600, 228);
    lv_obj_set_layout(setTimeBtns, LV_USE_GRID);
    lv_obj_set_grid_dsc_array(setTimeBtns, column, row);
    lv_obj_set_grid_align(setTimeBtns, LV_GRID_ALIGN_SPACE_EVENLY, LV_GRID_ALIGN_SPACE_BETWEEN);

    uint32_t i, j;
    static TimeComponent tc[2][3];
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            tc[i][j].setting = static_cast<TimeComp>(j);
            tc[i][j].value = int8_t(((2*i) - 1) * -1);

            lv_obj_t *btnContainer = lv_btn_create(setTimeBtns);
            lv_obj_t *btnImg = lv_img_create(btnContainer);
            lv_obj_remove_style_all(btnContainer);
            lv_obj_remove_style_all(btnImg);
            lv_obj_add_style(btnContainer, &incrTimeBtnBg, 0);
            lv_obj_add_style(btnImg, &incrTimeBtn, 0);
            lv_img_set_src(btnImg, &arrow_1);
            lv_img_set_angle(btnImg, 1800 * i);
            lv_obj_set_grid_cell(btnContainer, LV_GRID_ALIGN_STRETCH, j, 1, 
                                               LV_GRID_ALIGN_STRETCH, i, 1);
            lv_obj_add_event_cb(btnContainer, IncrementTimeComponent, LV_EVENT_CLICKED, &tc[i][j]);
        }
    }

    // Create Time Label
    UpdateTimeString();
    labels.time_l = lv_label_create(lv_scr_act());
    lv_label_set_text(labels.time_l, currentTime);
    lv_obj_add_style(labels.time_l, &time_style, 0);
    lv_obj_align(labels.time_l, LV_ALIGN_TOP_MID, 0, 145);

    // Create Date Label
    UpdateDateString();
    labels.date_l = lv_label_create(lv_scr_act());
    lv_label_set_text(labels.date_l, currentDate);
    lv_obj_add_style(labels.date_l, &text_style, 0);
    lv_obj_align_to(labels.date_l, labels.time_l, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    // Create a line to separate the messages from date and time
    line = lv_line_create(lv_scr_act());
    static lv_point_t points[] = {{50, 370}, {750, 370}};
    lv_line_set_points(line, points, 2);
    lv_obj_add_style(line, &line_style, 0);

    // Create Message Label
    labels.message_l = lv_label_create(lv_scr_act());
    lv_label_set_text(labels.message_l, "-");
    lv_obj_add_style(labels.message_l, &text_style, 0);
    lv_obj_align(labels.message_l, LV_ALIGN_TOP_MID, 0, 400);
    lv_obj_set_width(labels.message_l, 650);

    // Create Gear Button
    setTimeBtn = lv_btn_create(lv_scr_act());
    lv_obj_remove_style_all(setTimeBtn);
    lv_obj_clear_flag(setTimeBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_size(setTimeBtn, 65, 65);
    lv_obj_align(setTimeBtn, LV_ALIGN_TOP_RIGHT, -20, 20);

    // Set time icon
    settingsImg = lv_img_create(setTimeBtn);
    lv_img_set_src(settingsImg, &set_time);
    lv_obj_center(settingsImg);
    lv_obj_set_style_img_recolor_opa(settingsImg, LV_OPA_COVER, 0);
    lv_obj_set_style_img_recolor(settingsImg, lv_color_hex(0x272e2f), 0);

    // Confirm button
    // Used for confirming the set time or date
    confirmBtn = lv_btn_create(lv_scr_act());
    lv_obj_remove_style_all(confirmBtn);
    lv_obj_clear_flag(confirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_size(confirmBtn, 65, 65);
    lv_obj_align(confirmBtn, LV_ALIGN_TOP_RIGHT, -20, 20);

    checkmarkImg = lv_img_create(confirmBtn);
    lv_img_set_src(checkmarkImg, &checkmark);
    lv_obj_center(checkmarkImg);
    lv_obj_set_style_img_recolor_opa(checkmarkImg, LV_OPA_COVER, 0);
    lv_obj_set_style_img_recolor(checkmarkImg, lv_color_hex(0x272e2f), 0);



    //---
    // EVENTS
    //---
    lvgl_port_unlock();

    lv_obj_add_event_cb(lv_scr_act(), OnScreenTap, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(setTimeBtn, OnSetTime, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(confirmBtn, ConfirmSetting, LV_EVENT_PRESSED, NULL);

    //---
    // DEFAULT STATE
    //---
    ToggleElement(confirmBtn, false, 0, 0);
    ToggleElement(setTimeBtns, false, 0, 0);
    ToggleElement(setTimeBtn, false, 0, 0);
}

void UpdateTimeString() {
    int hr = ((hour + 11) % 12) + 1;
    snprintf(currentTime, sizeof(currentTime), "%02d:%02d %s", 
    hr, 
    minute, 
    isPm ? "PM" : "AM");
}

void UpdateDateString() {
    snprintf(currentDate, sizeof(currentDate), "%s %d, %d", 
    months[month], 
    day, 
    year);
}

void IncrementTime() {
    ESP_UTILS_LOGI("Time increment update");
    minute += 1;
    // If 60 minutes passed increment the hour
    if (minute >= 60) {
        changeMessage = true;
        minute = 0;
        hour = (hour + 1) % 24;

        // If its the 0 hour increment the day
        if (hour == 0) {
            // increment day:
            day++;
            // if it’s past the end of month:
            if (day > daysPerMonth[month]) {
                day = 1;
                month = (month + 1) % 12;
                if (month == 0) {
                    year++;

                    // then update February’s length once per year:
                    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
                    daysPerMonth[1] = leap ? 29 : 28;
                }
            }
            UpdateDateString();
        }
    }

    UpdateTimeString();
    ESP_UTILS_LOGI("Settings strings!");
    // Lock LVGL while modifying UI
    lvgl_port_lock(-1);
    lv_label_set_text(labels.time_l, currentTime);
    lv_label_set_text(labels.date_l, currentDate);
    lvgl_port_unlock();
}

void UpdateMessage(const char *msg) {
    // Lock LVGL while modifying UI
    lvgl_port_lock(-1);
    lv_label_set_text(labels.message_l, msg);
    lvgl_port_unlock();
}

void OnScreenTap(lv_event_t *e) {
    // Don't change anything if currently setting the time
    if (settingTime)
        return;

    if (setTimeBtnVisible) {
        ToggleElement(setTimeBtn, false, 200, 0);
        setTimeBtnVisible = false;

    } else {
        ToggleElement(setTimeBtn, true, 200, 0);
        setTimeBtnVisible = true;
    }

    ESP_UTILS_LOGI("Screen tap detected!");
}

void OnSetTime(lv_event_t *e) {
    settingTime = true;
    timeSet = false;
    ToggleElement(labels.date_l, false, 200, 0);
    ToggleElement(setTimeBtn, false, 200, 0);
    ToggleElement(confirmBtn, true, 200, 200);
    ToggleElement(setTimeBtns, true, 200, 0);
    ESP_UTILS_LOGI("Settings button tapped!");
}

void ConfirmSetting(lv_event_t *e) {
    if (settingTime) {
        lastTimeUpdate = millis();
        settingTime = false;
        timeSet = true;
        if (isPm && hour < 12) {
            hour += 12;
        } else if (!isPm && hour >= 12) {
            hour -= 12;
        }
        ToggleElement(labels.date_l, true, 200, 0);
        ToggleElement(confirmBtn, false, 200, 0);
        ToggleElement(setTimeBtns, false, 200, 0);
    }
}

void ToggleElement(lv_obj_t *obj, bool status, int time, int delay) {
    uint32_t i = 0;
    if (status) {
        lv_obj_fade_in(obj, time, delay);
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_t * child = lv_obj_get_child(obj, i);
        while(child) {
            lv_obj_add_flag(child, LV_OBJ_FLAG_CLICKABLE);
            i++;
            child = lv_obj_get_child(obj, i);
        }
    } else {
        lv_obj_fade_out(obj, time, delay);
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_t * child = lv_obj_get_child(obj, i);
        while(child) {
            lv_obj_clear_flag(child, LV_OBJ_FLAG_CLICKABLE);
            i++;
            child = lv_obj_get_child(obj, i);
        }
    }
}

void IncrementTimeComponent(lv_event_t *e) {
    TimeComponent* tc = (TimeComponent *)lv_event_get_user_data(e);
    switch(tc->setting) {
        case TimeComp::HOUR:
            hour = (hour + tc->value) % 24;
            break;
        
        case TimeComp::MINUTE:
            minute = (minute + tc->value) % 60;
            break;
        
        case TimeComp::AMPM:
            isPm = !isPm;
            break;
            
        default:
            break;
    }

    UpdateTimeString();
    lvgl_port_lock(-1);
    lv_label_set_text(labels.time_l, currentTime);
    lvgl_port_unlock();
    ESP_UTILS_LOGI("%d, %d", (int)tc->setting, tc->value);
}