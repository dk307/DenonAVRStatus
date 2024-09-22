#include <Arduino.h>
#include "display.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("Begin");
  display::instance.begin();
  display::instance.clear();
}

// int i = 40;
// auto c = millis();
void loop()
{
  display::instance.loop();

  // if ((millis() - c) > 200)
  // {
  //   display::instance.displayLine(std::to_string(i));
  //   i++;
  //   c = millis();
  // }

  delay(3);
}
