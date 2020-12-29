#include <FastLED.h>
#include "rain_animation.h"
#include "panel.h"
#include <time.h>

uint8_t Droplet::getX(){
    return x;
}

uint8_t Droplet::getY(){
    return y;
}

/*parametric constructors*/
Droplet::Droplet(uint8_t nx, uint8_t ny, CRGB nc){
    x = nx;
    y = ny;
    color = nc;
}

/*defaults y to panel height*/
Droplet::Droplet(uint8_t nx, CRGB nc){
    x = nx;
    y = 5;
    color = nc;
}

/*emtpy constructor*/
Droplet::Droplet(){

}

void Droplet::update(){
    //for(int i = y, i < pheigth, i++){
        color.fadeToBlackBy(128);
        Panels[x][y].setFullPanel(leds, color);
    //}
    
}

void rain(int delay_time, CRGB color){
    randomSeed(millis());
    Droplet d(0, color);
    Panels[d.getX()][d.getY()].setFullPanel(leds, color);
    FastLED.show();
    delay(delay_time);
    for(int i = 0; i < 4; i++){
        delay(delay_time);
        d.update();
        FastLED.show();
    }
}