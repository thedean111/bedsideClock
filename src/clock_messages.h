#include <Arduino.h>
#include <LittleFS.h>
#include "FS.h"

#include <vector>
#include <set>

#ifndef CLOCK_MESSAGES_H
#define CLOCK_MESSAGES_H

#define FORMAT_LITTLEFS_IF_FAILED true

static std::vector<String> messages;
static std::vector<int> available;
static std::set<int> used;

void SetupLittleFS();
void LoadAllMessages();
void LoadAllUsed();
String GetRandomMessage();
void UsedToDisk();
void SaveUsedIndex(int idx);
void AddNewMessage(String newMessage);
void BuildAvailableList();

#endif