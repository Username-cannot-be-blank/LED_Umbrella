#include <SPI.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_GFX.h>
#include <Fonts/FreeSans18pt7b.h>
#include <Fonts/FreeMono12pt7b.h>

// Color TFT Display
#define TFT_RST 4  // IO 26 Reset
#define TFT_DC  26  // DC/RS Command/Data IO 25
#define TFT_CLK 18  // HSPI-SCK
#define TFT_SDO 19  // HSPI-MISO
#define TFT_SDI 23  // HSPI-MOSI
#define TFT_CS  5  // HSPI-SS0 CS - Chip Select / SS - Slave Select
#define TFT_LED 0 // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 50 // Initial brightness of TFT backlight

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void drawCursor(int x, int y)
{
  tft.drawCircle(x,y, 5, ILI9341_BLUE);
  tft.drawLine(x - 10, y - 10, x + 10, y + 10, ILI9341_BLUE);
}

void drawMainMenu()
{
  tft.fillScreen(ILI9341_BLACK);
  tft.setRotation(3);
  drawCursor(20,20);
  tft.setFont(&FreeMono12pt7b);
  tft.setTextColor(ILI9341_LIGHTGREY);
  tft.setCursor(20, 26);
  tft.print("Program: ");
  tft.setCursor(20, 52);
  tft.print("Color Palette: ");
  tft.setCursor(20, 78);
  tft.print("Speed: ");

  return;
}