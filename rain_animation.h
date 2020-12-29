#ifndef _RAIN_ANIMATION_
#define _RAIN_ANIMATION_

#include <FastLED.h>
#include "panel.h"



class Droplet{
    private:
        CRGB color;
        uint8_t x;
        uint8_t y;
    public:
        Droplet();
        Droplet(uint8_t nx, uint8_t ny, CRGB nc);
        Droplet(uint8_t nx, CRGB nc);
        void update();
        uint8_t getX();
        uint8_t getY();
};

void rain(int delay_time, CRGB color);

#endif