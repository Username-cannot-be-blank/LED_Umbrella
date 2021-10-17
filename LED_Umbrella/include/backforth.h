#include <vector>
#include <FastLED.h>

void back_forth(CRGB LEDs[], std::vector<CRGB> currentPalette, uint32_t speed, int num_LEDs)
{
    
    CRGB color = currentPalette.at(rand() % currentPalette.size());
    CRGB color2 = currentPalette.at(rand() % currentPalette.size());

  while (color == color2)
    {
      color2 = currentPalette.at(rand() % currentPalette.size());
    }
  for (int x = 0; x < num_LEDs; x++)
    {
      LEDs[x] = LEDs[x] + color;
      LEDs[num_LEDs - x] = LEDs[num_LEDs - x] + color2;
      FastLED.show();
      delay(speed);
      fadeToBlackBy(LEDs, num_LEDs, 32);
    }
      for (int x = num_LEDs - 1; x >= 0; x--)
    {
      LEDs[x] = LEDs[x] + color;
      LEDs[num_LEDs - x] = LEDs[num_LEDs - x] + color2;
      FastLED.show();
      delay(speed);
      fadeToBlackBy(LEDs, num_LEDs, 32);
    }
}