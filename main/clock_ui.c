#include "clock_ui.h"

// Define your arrays
const char *months[12] = {
    "January","February","March","April","May","June",
    "July","August","September","October","November","December"
};
int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

static lv_obj_t *time_l;
static lv_obj_t *date_l;
static lv_obj_t *message_l;
static lv_obj_t *line;
static lv_obj_t *setTimeBtns;
static lv_obj_t *calendarSelect;
static lv_obj_t *settingsImg;
static lv_obj_t *setTimeBtn;
static lv_obj_t *setDateBtn;
static bool setTimeBtnVisible;
static lv_coord_t column[] = {50,50,50,LV_GRID_TEMPLATE_LAST};
static lv_coord_t row[]    = {50,50,LV_GRID_TEMPLATE_LAST};
static lv_obj_t *header;
static lv_obj_t *confirmBtn;
static bool settingTime;
static bool settingDate;
static bool changeMessage;
static bool timeSet = false;
static char currentTime[16];
static char currentDate[32];
static int hour;
static int minute;
static uint8_t month;
static uint8_t day;
static uint16_t year;
static bool isPm;
static lv_style_t screen_style, text_style, time_style, line_style;
static lv_style_t incrTimeBtnBg, incrTimeBtn;

void InitUI() {
    setTimeBtnVisible = false;
    settingTime = false;
    settingDate = false;
    timeSet = false;
    hour = 12;
    minute = 00;
    month = 1;
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
    // Header container
    header = lv_obj_create(lv_scr_act());
    lv_obj_remove_style_all(header);
    lv_obj_clear_flag(header, LV_EVENT_ALL);
    lv_obj_set_width(header, lv_pct(100));
    lv_obj_set_height(header, 120);
    lv_obj_set_layout(header, LV_LAYOUT_FLEX);
    lv_obj_set_flex_align(header, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_all(header, 25, 0);
    
    // Time Set arrow buttons
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
            tc[i][j].setting = j;
            tc[i][j].value = ((2*i) - 1) * -1;

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
    time_l = lv_label_create(lv_scr_act());
    lv_label_set_text(time_l, currentTime);
    lv_obj_add_style(time_l, &time_style, 0);
    lv_obj_align(time_l, LV_ALIGN_TOP_MID, 0, 145);

    // Create Date Label
    UpdateDateString();
    date_l = lv_label_create(lv_scr_act());
    lv_label_set_text(date_l, currentDate);
    lv_obj_add_style(date_l, &text_style, 0);
    lv_obj_align_to(date_l, time_l, LV_ALIGN_OUT_BOTTOM_MID, 0, 20);

    // Create a line to separate the messages from date and time
    line = lv_line_create(lv_scr_act());
    static lv_point_t points[] = {{50, 370}, {750, 370}};
    lv_line_set_points(line, points, 2);
    lv_obj_add_style(line, &line_style, 0);

    // Create Message Label
    message_l = lv_label_create(lv_scr_act());
    lv_label_set_text(message_l, "-");
    lv_obj_add_style(message_l, &text_style, 0);
    lv_obj_align(message_l, LV_ALIGN_TOP_MID, 0, 400);
    lv_obj_set_width(message_l, 650);


    // Create Gear Button
    setTimeBtn = lv_btn_create(header);
    lv_obj_remove_style_all(setTimeBtn);
    lv_obj_clear_flag(setTimeBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_height(setTimeBtn, lv_pct(100));
    lv_obj_set_style_border_color(setTimeBtn, lv_color_hex(0x272e2f), 0);
    lv_obj_set_style_border_opa(setTimeBtn, LV_OPA_100, 0);

    settingsImg = lv_img_create(setTimeBtn);
    lv_img_set_src(settingsImg, &set_time);
    lv_obj_center(settingsImg);
    lv_obj_set_style_img_recolor_opa(settingsImg, LV_OPA_COVER, 0);
    lv_obj_set_style_img_recolor(settingsImg, lv_color_hex(0x272e2f), 0);

    // Set Date Button
    setDateBtn = lv_btn_create(header);
    lv_obj_remove_style_all(setDateBtn);
    lv_obj_clear_flag(setDateBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_height(setDateBtn, lv_pct(100));
    lv_obj_set_style_border_color(setDateBtn, lv_color_hex(0x272e2f), 0);
    lv_obj_set_style_border_opa(setDateBtn, LV_OPA_100, 0);

    lv_obj_t *calImg = lv_img_create(setDateBtn);
    lv_img_set_src(calImg, &calendar);
    lv_obj_center(calImg);
    lv_obj_set_style_img_recolor_opa(calImg, LV_OPA_COVER, 0);
    lv_obj_set_style_img_recolor(calImg, lv_color_hex(0x272e2f), 0);

    // Confirm button
    // Used for confirming the set time or date
    confirmBtn = lv_btn_create(lv_scr_act());
    lv_obj_remove_style_all(confirmBtn);
    lv_obj_clear_flag(confirmBtn, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
    lv_obj_set_size(confirmBtn, 65, 65);
    lv_obj_align_to(confirmBtn, setTimeBtn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_t *checkmarkImg = lv_img_create(confirmBtn);
    lv_img_set_src(checkmarkImg, &checkmark);
    lv_obj_center(checkmarkImg);
    lv_obj_set_style_img_recolor_opa(checkmarkImg, LV_OPA_COVER, 0);
    lv_obj_set_style_img_recolor(checkmarkImg, lv_color_hex(0x272e2f), 0);
    lv_obj_set_style_img_recolor(calImg, lv_color_hex(0x272e2f), 0);

    calendarSelect = lv_calendar_create(lv_scr_act());
    lv_calendar_header_dropdown_create(calendarSelect);
    static const char * year_list =
    "2099\n2098\n2097\n2096\n2095\n2094\n2093\n2092\n2091\n2090\n"
    "2089\n2088\n2087\n2086\n2085\n2084\n2083\n2082\n2081\n2080\n"
    "2079\n2078\n2077\n2076\n2075\n2074\n2073\n2072\n2071\n2070\n"
    "2069\n2068\n2067\n2066\n2065\n2064\n2063\n2062\n2061\n2060\n"
    "2059\n2058\n2057\n2056\n2055\n2054\n2053\n2052\n2051\n2050\n"
    "2049\n2048\n2047\n2046\n2045\n2044\n2043\n2042\n2041\n2040\n"
    "2039\n2038\n2037\n2036\n2035\n2034\n2033\n2032\n2031\n2030\n"
    "2029\n2028\n2027\n2026\n2025\n2024\n2023\n2022\n2021\n2020\n"
    "2019\n2018\n2017\n2016\n2015\n2014\n2013\n2012\n2011\n2010\n"
    "2009\n2008\n2007\n2006\n2005\n2004\n2003\n2002\n2001\n2000";
    lv_calendar_header_dropdown_set_year_list(calendarSelect, year_list);
    lv_obj_align(calendarSelect, LV_ALIGN_CENTER, 0, -40);
    lv_obj_set_size(calendarSelect, 320, 320);
    lv_calendar_set_today_date(calendarSelect, year, month, day);
    lv_calendar_set_showed_date(calendarSelect, year, month);

    //---
    // EVENTS
    //---
    lv_obj_add_event_cb(lv_scr_act(), OnScreenTap, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(setTimeBtn, OnSetTime, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(setDateBtn, OnSetDate, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(confirmBtn, ConfirmSettings, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(calendarSelect, OnSelectDay, LV_EVENT_ALL , NULL);
    lvgl_port_unlock();

    //---
    // DEFAULT STATE
    //---
    ToggleElement(confirmBtn, false, 0, 0, false);
    ToggleElement(setTimeBtns, false, 0, 0, true);
    ToggleElement(setTimeBtn, false, 0, 0, false);
    ToggleElement(setDateBtn, false, 0, 0, false);
    ToggleElement(calendarSelect, false, 0, 0, true);
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
    months[month-1], 
    day, 
    year);
}

void IncrementTime() {
    // Only increment if the time has been set
    if (!timeSet) {
        return;
    }

    ESP_LOGI(TAG, "Time increment update");
    minute += 1;
    // If 60 minutes passed increment the hour
    if (minute >= MINUTE_IN_HOUR) {
        UpdateMessage(GetMessage());

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
    ESP_LOGI(TAG, "Settings strings!");
    // Lock LVGL while modifying UI
    lvgl_port_lock(-1);
    lv_label_set_text(time_l, currentTime);
    lv_label_set_text(date_l, currentDate);
    lvgl_port_unlock();
}

void UpdateMessage(const char *msg) {
    // Lock LVGL while modifying UI
    lvgl_port_lock(-1);
    lv_label_set_text(message_l, msg);
    lvgl_port_unlock();
}

void OnScreenTap(lv_event_t *e) {
    // Don't change anything if currently setting the time
    if (settingTime)
        return;

    if (settingDate) {
        ConfirmSettings(NULL);
    }

    if (setTimeBtnVisible) {
        ToggleElement(setTimeBtn, false, 200, 0, false);
        ToggleElement(setDateBtn, false, 200, 0, false);
        setTimeBtnVisible = false;

    } else {
        ToggleElement(setTimeBtn, true, 200, 0, false);
        ToggleElement(setDateBtn, true, 200, 0, false);
        setTimeBtnVisible = true;
    }

    ESP_LOGI(TAG, "Screen tap detected!");
}

void OnSetTime(lv_event_t *e) {
    settingTime = true;
    timeSet = false;
    ToggleElement(date_l, false, 200, 0, false);
    ToggleElement(setTimeBtn, false, 200, 0, false);
    ToggleElement(setDateBtn, false, 200, 0, false);
    ToggleElement(confirmBtn, true, 200, 200, false);
    ToggleElement(setTimeBtns, true, 200, 0, true);
    ESP_LOGI(TAG, "Settings button tapped!");
}

void OnSetDate(lv_event_t *e) {
    if (settingDate)
        return;

    settingDate = true;
    lv_calendar_set_showed_date(calendarSelect, year, month);
    ToggleElement(calendarSelect, true, 200, 0, true);
    ToggleElement(setTimeBtn, false, 200, 0, false);
    ToggleElement(setDateBtn, false, 200, 0, false);
}

void ConfirmSettings(lv_event_t *e) {
    if (settingTime) {
        // lastTimeUpdate = esp_timer_get_time();
        settingTime = false;
        timeSet = true;
        if (isPm && hour < 12) {
            hour += 12;
        } else if (!isPm && hour >= 12) {
            hour -= 12;
        }
        ToggleElement(date_l, true, 200, 0, false);
        ToggleElement(confirmBtn, false, 200, 0, false);
        ToggleElement(setTimeBtns, false, 200, 0, true);
    } else if (settingDate) {
        settingDate = false;
        ToggleElement(calendarSelect, false, 200, 0, true);
        ToggleElement(setDateBtn, false, 200, 0, false);
        UpdateDateString();
        lvgl_port_lock(-1);
        lv_label_set_text(date_l, currentDate);
        lvgl_port_unlock();
    }
}

void hide_cb(lv_timer_t *timer) {
    lv_obj_t *obj = timer->user_data;
    lv_obj_add_flag(obj, LV_OBJ_FLAG_HIDDEN);
    lv_timer_del(timer);
}

void ToggleElement(lv_obj_t *obj, bool status, int time, int delay, bool toggleChildren) {

    if (status) {
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_fade_in(obj, time, delay);

    } else {
        lv_obj_fade_out(obj, time, delay);
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        lv_timer_create(hide_cb, delay, obj);
    }

    if (toggleChildren) {
        uint32_t i = 0;
        lv_obj_t *child = lv_obj_get_child(obj, i);
        if (status) {
            while(child) {
                lv_obj_add_flag(child, LV_OBJ_FLAG_CLICKABLE);
                i++;
                child = lv_obj_get_child(obj, i);
            }
        } else {
            while(child) {
                lv_obj_clear_flag(child, LV_OBJ_FLAG_CLICKABLE);
                i++;
                child = lv_obj_get_child(obj, i);
            }
        }
    }
}

void IncrementTimeComponent(lv_event_t *e) {
    TimeComponent* tc = (TimeComponent *)lv_event_get_user_data(e);
    switch(tc->setting) {
        case HOUR:
            hour = (hour + tc->value) % 24;
            break;
        
        case MINUTE:
            minute = (minute + tc->value + 60) % 60;
            break;
        
        case AMPM:
            isPm = !isPm;
            break;
            
        default:
            break;
    }
    ESP_LOGI(TAG, "%d", minute);
    UpdateTimeString();
    lvgl_port_lock(-1);
    lv_label_set_text(time_l, currentTime);
    lvgl_port_unlock();
    ESP_LOGI(TAG, "%d, %d", tc->setting, tc->value);
}

void OnSelectDay(lv_event_t *e)  {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t date;
        if(lv_calendar_get_pressed_date(obj, &date)) {
            year = date.year;
            month = date.month;
            day = date.day;
            lv_calendar_set_highlighted_dates(obj, &date, 1);
            lv_calendar_set_today_date(obj, year, month, day);
        }
    }
}