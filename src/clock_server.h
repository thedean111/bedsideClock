#ifndef CLOCK_SERVER_H
#define CLOCK_SERVER_H

#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>
#include "time.h"
#include <lvgl.h>
#include "lvgl_v8_port.h"

// THIS IS HOW TO COMMUNICATE TO THE ESP32 WITH A DEVICE ON THE SAME NETWORK
// 1. Be on the same network
// 2. [Windows] Open the command prompt
// 3. Use the following command
//   curl -X POST http://<esp32-ip>/post -H "Content-Type: test/plain" --data "<message-here>"

extern WebServer server;
extern const char* timezone;
extern const char* ntpServer;

bool ConnectToWifi(const char* ssid, const char* password);
bool IsWifiConnected();
void StartHttpServer();
void HandlePost();
void SyncTime();
String GetCurrentTime();
String GetCurrentDate();

#endif