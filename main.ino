#define FASTLED_INTERNAL
#include <FastLED.h>
#include "Panel.h"
#include <time.h>

#define NUM_LEDS 75
#define DATA_PIN 5
#define LED_PER_PANEL 3
const uint8_t width = 15;
const uint8_t height = 5;
const uint8_t pwidth = 5;
const uint8_t pheigth = 5;

CRGB leds[NUM_LEDS];

CRGB rain_array[pwidth][pheigth];
int cnt = 0;



int XY(uint8_t x, uint8_t y){
    const uint8_t XY_TABLE[] = {
    0,   1,   2,   3,   4,   5,   6,   7,   8,   9,  10,  11,  12,  13,  14,
    29,  28,  27,  26,  25,  24,  23,  22,  21,  20,  19,  18,  17,  16,  15,
    30,  31,  32,  33,  34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,
    59,  58,  57,  56,  55,  54,  53,  52,  51,  50,  49,  48,  47,  46,  45,
    60,  61,  62,  63,  64,  65,  66,  67,  68,  69,  70,  71,  72,  73,  74
    };

    uint8_t i = (y * width) + x;
    uint8_t j = XY_TABLE[i];
    return j;

}

const uint8_t PanelsTable[pwidth][pheigth][LED_PER_PANEL] = {
    {{ 0,  1,  2}, { 3,  4,  5}, { 6,  7,  8}, { 9, 10, 11}, {12, 13, 14}},
    {{28, 29, 27}, {25, 26, 24}, {22, 23, 21}, {19, 20, 18}, {15, 17, 16}},
    {{30, 31, 32}, {33, 34, 35}, {36, 37, 38}, {39, 40, 41}, {42, 44, 43}},
    {{58, 59, 57}, {55, 56, 54}, {52, 53, 51}, {49, 50, 48}, {45, 47, 46}},
    {{60, 61, 62}, {63, 64, 65}, {66, 67, 68}, {69, 70, 71}, {72, 74, 73}}   
};


Panel Panels[pwidth][pheigth];

int phase_shift=0;

void setup(){

  // LED Strip initializing
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical
  FastLED.setBrightness(255);
  for(int y = 0; y < pheigth; y++){
      for(int x = 0; x < pwidth; x++){
        Panels[x][y].setLedPanel(PanelsTable[x][y][0], PanelsTable[x][y][1], PanelsTable[x][y][2]);
        }
    }
    //Panels[1][1].setFullPanel(leds, 255, 0, 0);
    rain_init();
    randomSeed(millis());
    Serial.begin(115200);
}

void loop(){
    
/*
    for(int i = 45; i < NUM_LEDS; i++){
        leds[i] = CRGB(255, 000, 000);
        FastLED.show();
        delay(500);
    }
<<<<<<< HEAD
*/
/*
    for(int x = 0; x < pwidth; x++){
        for (int y = 0; y < pheigth; y++){
            Panels[x][y].setFullPanel(leds, 0, 255, 0);
=======
*//*
    for(int y = 0; y < pwidth; y++){
        for (int x = 0; x < pheigth; x++){
            Panels[y][x].setFullPanel(leds, 0, 255, 0);
>>>>>>> rain
            
            //Panels[x-1][y].setFullPanel(leds, 0,0,0);
            FastLED.show();
            delay(100);
            /*
            for(int i = 0; i < NUM_LEDS; i++){
                leds[i] = 0;
            }
            FastLED.show();
            fadeToBlackBy(leds, NUM_LEDS, 170);
        }
        
    }*/
    rain();
    if((cnt % 3) == 0){
        new_droplet(CHSV(random(0, 256), 255, 255));
    }
<<<<<<< HEAD
    */
    FastLED.delay(1000/60);
    rainbow_animation(leds, phase_shift, 20);
    EVERY_N_MILLISECONDS( 20 ){phase_shift++;}
=======
    FastLED.show();
    delay(150);
    cnt++;
    
    
>>>>>>> rain
}
