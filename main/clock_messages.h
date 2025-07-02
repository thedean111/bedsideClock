#ifndef CLOCK_MESSAGES_H
#define CLOCK_MESSAGES_H

#include "waveshare_rgb_lcd_port.h"
#include "esp_err.h"
#include "esp_littlefs.h"
#include <string.h>
#include "esp_random.h"
#include <stdio.h>
#include <stdlib.h>


#define MSG_PATH "/littlefs/messages.txt"
#define LINE_BUF_SIZE 128

void SetupFS();
esp_err_t InitMessages();
const char * GetMessage();
void hide_cb(lv_timer_t *timer);

#endif