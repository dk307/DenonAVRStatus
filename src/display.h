#pragma once

#include <Wire.h>
#include <MD_MAX72xx.h>
#include <MD_Parola.h>
#include <string>

#define CLK_PIN 18  // or SCK
#define DATA_PIN 21 // or MOSI
#define CS_PIN 19   // or SS

class display
{
public:
    void begin();
    void loop();
    void displayLine(std::string_view line, uint16_t pause = 5000);
    void clear();

    static display instance;
private:
    MD_Parola matrix{MD_MAX72XX::FC16_HW, DATA_PIN, CLK_PIN, CS_PIN, 4};

    uint8_t currentIntensity = 8;
    std::string currentDisplayText;

    bool refreshDisplay{false};
    bool currentScroll{false};
};