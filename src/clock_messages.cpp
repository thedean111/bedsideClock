#include "clock_messages.h"


void SetupLittleFS() {
    if (!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)) {
        Serial.println("LittleFS Mount Failed");
        return;
    }
    Serial.println("LittleFS mount successful");
}

void LoadAllMessages() {
  File file = LittleFS.open("/messages.txt");
  if (!file || file.isDirectory()) {
    Serial.println("Failed to open messages.txt");
    return;
  }

  Serial.println("Reading messages.txt");

  while (file.available()) {
    String line = file.readStringUntil('\n');
    line.trim();
    line.replace("\r","");
    line.replace("\n","");
    if (line.length() > 0) {
        messages.push_back(line);
    }
  }
  file.close();

}

void BuildAvailableList() {
    for (int i = 0; i < messages.size(); i++) {
        if (used.find(i) == used.end()) {
            available.push_back(i);
        }
    }
}

void LoadAllUsed() {
  File file = LittleFS.open("/used.txt");
  if (!file || file.isDirectory()) {
    Serial.println("Failed to open used.txt");
    return;
  }

  Serial.println("Reading used.txt");

  while (file.available()) {
    String line = file.readStringUntil('\n');
    used.insert(line.toInt());
  }
  file.close();
  BuildAvailableList();
}

void UsedToDisk() {
    File file = LittleFS.open("/used.txt", "w"); // "w" mode truncates
    if (!file) {
        Serial.println("Failed to reset used.txt");
        return;
    }

    for (std::set<int>::iterator it = used.begin(); it != used.end(); ++it) {
        file.println(*it);
    }

    file.close(); // File is now empty
    Serial.println("used.txt has been reset.");
}

void AddNewMessage(String newMessage) {
  File file = LittleFS.open("/messages.txt", "a");  // append mode
  if (!file) {
    Serial.println("Failed to open used.txt to save index");
    return;
  }

  Serial.println("Adding message!");
  file.println(newMessage);
  file.close();
  messages.push_back(newMessage);
}

String GetRandomMessage() {
    if (available.empty()) {
        used.clear();
        BuildAvailableList();
    }

    int rIdx = random(available.size());
    int idx = available[rIdx];
    
    used.insert(idx);
    available[rIdx] = available.back();
    available.pop_back();

    return messages[idx];
}