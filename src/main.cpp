#include <Arduino.h>
#include <vector>
#include <string.h>
#define FASTLED_INTERNAL
#include <FastLED.h>
#include <time.h>
#include <display.h>
#include <backforth.h>
#include <fire.h>
#include "palettes.h"
#include "twinkle.h"


// Switches
#define INTERRUPT_PIN_1 21 
#define INTERRUPT_PIN_2 39
#define INTERRUPT_PIN_3 35
#define INTERRUPT_PIN_4 34


// LED Strip
#define LED_STRIP_PIN 17
#define NUM_LEDS 75
uint8_t Brightness = 255;
uint32_t LED_Speed = 10;



uint16_t dispWidth = 320;
uint16_t dispHeight = 240;
//CRGB currentPalette[]= {CRGB::Red, CRGB::Blue, CRGB::White};
std::vector<CRGB> currentPalette = palettes::christmas;

int cycleCount = 0;
String cycleString = "";


// Setup LED Strip Array
CRGB bow[NUM_LEDS] = {0};

// Instantiate smoothFireEffects Class
std::vector<int> coolingOptions = {1, 2, 3, 5, 10, 30};
int currentCoolingOption = 1;
int cooling = coolingOptions[currentCoolingOption];
int sparking = 50;
int sparks = 3;
int sparkheight = 0;
bool breversed = true;
bool bmirrored = false;
//float sparkProbability = 1.0;
//float fcooling = 1.0;
//float spreadRate = 1.0;

ClassicFireEffect fire(NUM_LEDS, cooling, sparking, sparks, sparkheight, breversed, bmirrored); 

// FireEffectSmooth fire(NUM_LEDS, bmirrored, breversed, sparkheight, sparkProbability, fcooling, spreadRate);
// This doesn't seem to work

// Switch debouncing
long debouncing_time = 500; //Debouncing Time in Milliseconds
volatile unsigned long last_micros = 0;


void updateDisplay()
{
    tft.fillRect(0,100,dispWidth, dispHeight - 120, ILI9341_BLACK);
    tft.setCursor(0,120);
    tft.setTextSize(1);
    tft.printf("Cooling setting: %d", coolingOptions.at(currentCoolingOption));
    tft.println();
    tft.printf("Mirroring: ");
    tft.printf(bmirrored ? "true" : "false");
}

void adjustCooling()
{
  if((long)(micros() - last_micros) >= debouncing_time * 1000) 
  {
    last_micros = micros();
  if (currentCoolingOption == coolingOptions.size()-1)
    currentCoolingOption = 0;
  else
    currentCoolingOption++;
  fire.adjustCooling(coolingOptions.at(currentCoolingOption));
  updateDisplay();
  }
}

void setup()
{
  tft.begin();

  pinMode(LED_STRIP_PIN, OUTPUT);     // LED strip setup
  FastLED.addLeds<WS2812, LED_STRIP_PIN, GRB>(bow, NUM_LEDS);
  FastLED.setBrightness(Brightness);
  drawMainMenu();
  updateDisplay();
  
  pinMode(INTERRUPT_PIN_1, INPUT_PULLUP);
  attachInterrupt(INTERRUPT_PIN_1, adjustCooling, FALLING);

  pinMode(INTERRUPT_PIN_2, HIGH);
  //attachInterrupt(INTERRUPT_PIN_2, adjustMirroring, FALLING);
}



void loop() 
{
  FastLED.clear();
  fire.DrawFire();
  FastLED.show(100);
  delay(LED_Speed);

  EVERY_N_MILLISECONDS(250)
  {

  }

/*   currentPalette = palettes::RWB;
  back_forth(bow, currentPalette, LED_Speed, NUM_LEDS);
  currentPalette = palettes::christmas;
  burst(bow, currentPalette, LED_Speed, NUM_LEDS); */

}

