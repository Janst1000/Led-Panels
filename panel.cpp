#define FASTLED_INTERNAL
#include "Panel.h"
#include "FastLED.h"

/*empty constructor*/
Panel::Panel(){
    first = 0;
    second = 0;
    third = 0;
}

/*parametric consturctor*/
Panel::Panel(uint8_t f, uint8_t s, uint8_t t){
    first = f;
    second = s;
    third = t;
}

/*sets led info of Panel*/
void Panel::setLedPanel(uint8_t f, uint8_t s, uint8_t t){
    first = f;
    second = s;
    third = t;
}

/*sets Panel to supplied rgb value*/
void Panel::setFullPanel(CRGB* leds, uint8_t r, uint8_t g, uint8_t b){
    leds[first] = CRGB(r, g, b);
    leds[second] = CRGB(r, g, b);
    leds[third] = CRGB(r, g, b);
}

void Panel::setFullPanel(CRGB* leds, CRGB color){
    leds[first] = color;
    leds[second] = color;
    leds[third] = color;
}

/*turns off all leds*/
void Panel::off(CRGB* leds){
    leds[first] = 0;
    leds[second] = 0;
    leds[third] = 0;
}