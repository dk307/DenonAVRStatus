#include "display.h"
#include <math.h>

display display::instance;

void display::begin()
{
    if (!matrix.begin())
    {
        Serial.println("Failed to initialize matrix");
    }
    matrix.setIntensity(currentIntensity);
    matrix.displayClear();
    matrix.setCharSpacing(2);
    displayLine("Starting", 5000);
}

void display::loop()
{
    matrix.displayAnimate();
}

void display::displayLine(std::string_view line, uint16_t pause)
{
    currentDisplayText = line;
    matrix.displayText(currentDisplayText.c_str(), PA_CENTER, 50, pause, PA_PRINT, PA_FADE);
    Serial.println(line.data());
}

void display::clear()
{
    matrix.displayClear();
    currentDisplayText.clear();
}
