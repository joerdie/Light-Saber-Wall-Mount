//Include the Neo Pixel Librabry
#include <Adafruit_NeoPixel.h>

// BEGIN LED Setup

  // Which pin on the Arduino is connected to the NeoPixels?
  #define LED_PIN 13
  
  // How many NeoPixels are attached to the Arduino?
  #define LED_COUNT 42
  
  //How Bright you want these strips? Set BRIGHTNESS to about 1/5 (max = 255)
  #define LED_BRIGHT 150
  
  // Colors
  const auto RED = Adafruit_NeoPixel::Color(255,0,0);
  const auto BLUE = Adafruit_NeoPixel::Color(0,0,255);
  const auto PURPLE = Adafruit_NeoPixel::Color(128,0,128);
  const auto BLACK = Adafruit_NeoPixel::Color(0,0,0);
  const auto WHITE = Adafruit_NeoPixel::Color(255,255,255);
  const auto GREEN = Adafruit_NeoPixel::Color(0,128,0);
  const auto YELLOW = Adafruit_NeoPixel::Color(255,255,0);
  
  // Declare our NeoPixel strip objects:
  Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
  
  // Declare arrays for sections of the strip
  const int jediCrysSize = 5;
  int jediCrystals[jediCrysSize] = {0, 1, 2, 3, 4};
  const int sithCrysSize = 5;
  int sithCrystals[sithCrysSize] = {5, 6, 7, 8, 9};
  const int sithHoloSize = 3;
  int sithHolo[sithHoloSize] = {10, 11, 12};
  const int jediHoloSize = 4;
  int jediHolo[jediHoloSize] = {13, 14, 15, 16};
  const int rearLedsSize = 25;
  int rearLeds[rearLedsSize] = {17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};

// END LED Setup

void setup() {
  strip.begin();           // INITIALIZE NeoPixel object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(LED_BRIGHT);
}

void loop() {
    setColor(WHITE, jediCrystals, jediCrysSize);
    setColor(WHITE, sithCrystals, sithCrysSize);
    setColor(BLUE, jediHolo, jediHoloSize);
    setColor(RED, sithHolo, sithHoloSize);
    // Spin colors for now. 
    setColor(WHITE, rearLeds, rearLedsSize);
    delay(1000);
    setColor(RED, rearLeds, rearLedsSize);
    delay(1000);
    setColor(BLUE, rearLeds, rearLedsSize);
    delay(1000);
    setColor(PURPLE, rearLeds, rearLedsSize);
    delay(1000);
}

void setColor(uint32_t color, int a[], int len) {
  for(int i = 0; i < len; i++) {      // For each pixel in the passed array
    strip.setPixelColor(a[i], color); //  Set pixel's color (in RAM)
    strip.show();                     //  Update strip to match
  }
}
