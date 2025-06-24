#include "clock_server.h"
#include "clock_messages.h"

WebServer server(80);
const char* timezone = "EST5EDT,M3.2.0,M11.1.0";
const char* ntpServer = "pool.ntp.org";
const char* months[]  = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

bool ConnectToWifi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    
    int retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < 20) {
        delay(500);
        Serial.print(".");
        retries++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi connected: " + WiFi.localIP().toString());
        return true;
    } else {
        Serial.println("\nWiFi connection failed");
        return false;
    }
}

bool IsWifiConnected() {
    return WiFi.status() == WL_CONNECTED;
}

void SyncTime() {
    configTzTime(timezone, ntpServer);
}

String GetCurrentTime() {
  struct tm timeinfo;
  char time_str[32];

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return String(time_str);
  }

  strftime(time_str, sizeof(time_str), "%I:%M %p", &timeinfo);
  return String(time_str);
}

String GetCurrentDate() {
  struct tm timeinfo;
  char time_str[32];

  if (!getLocalTime(&timeinfo)) {
    Serial.println("Failed to obtain time");
    return String(time_str);
  }

  String date = String(months[timeinfo.tm_mon]) + " " + String(timeinfo.tm_mday) + ", " + String(timeinfo.tm_year + 1900);
  return date;
}

void StartHttpServer() {
    server.on("/post", HTTP_POST, HandlePost);
    server.begin();
    Serial.println("HTTP server started."); 
}

void HandlePost() {
    if (server.method() == HTTP_POST) {
        String body = server.arg("plain");
        Serial.println("Received POST: " + body);
        
        AddNewMessage(body);

        server.send(200, "text/plain", "Message received");
    } else {
        server.send(405, "text/plain", "Method Not Allowed");
    }
}