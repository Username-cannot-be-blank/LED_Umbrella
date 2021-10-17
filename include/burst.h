#include <FastLED.h>
#include <vector>

void burst(CRGB LEDs[], std::vector<CRGB> palette, uint32_t speed, int num_LEDs)
{
  int midPixel = num_LEDs/2;
  CRGB color = palette.at(rand() % palette.size());
  LEDs[midPixel] = color;
  FastLED.show();
  for (int x = 0; x <= midPixel; x++)
  {
    LEDs[midPixel + x] = LEDs[midPixel + x] + color;
    LEDs[midPixel - x] = LEDs[midPixel - x] + color;
    FastLED.show();
    fadeToBlackBy(LEDs, num_LEDs, 16);
    delay(speed);
  }

  for (int x = 0; x < 15; x++) 
  {
    fadeToBlackBy(LEDs, num_LEDs, 16);
    FastLED.show();
    delay(speed);
  }
}