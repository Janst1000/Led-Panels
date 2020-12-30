#ifndef _PANEL_H_
#define _PANEL_H_
#define FASTLED_INTERNAL
#include <FastLED.h>

class Panel{
    private:
        uint8_t first;
        uint8_t second;
        uint8_t third;
    public:
        Panel(uint8_t f,uint8_t s, uint8_t t);
        Panel();
        void setLedPanel(uint8_t f, uint8_t s, uint8_t t);
        void setFullPanel(CRGB* leds,uint8_t r,uint8_t g,uint8_t b);
        void setFullPanel(CRGB* leds, CRGB color);
        void off(CRGB* leds);
};

#endif