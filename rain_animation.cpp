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

CRGB Droplet::getColor(){
    return color;
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
    //}
    
}

