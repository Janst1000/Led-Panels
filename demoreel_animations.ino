#include <FastLED.h>

void rainbow_animation(CRGB* leds, int phase_shift){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            Panels[y][x].setFullPanel(leds, CRGB(phase_shift, 255, 255));
        }
    }
}