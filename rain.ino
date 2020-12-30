void rain_init(){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            rain_array[y][x] = 0;
        }
    }
}

void rain(){
    fadeToBlackBy(leds, NUM_LEDS, 220);
    /*go through all elements and shift the 1s down by one*/
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            if(rain_array[y][x] == 1){
                rain_array[y][x] = 0;
                if(y != 0){
                    rain_array[y-1][x] = 1;
                    Panels[y-1][x].setFullPanel(leds, 0, 255, 0);
                }
            }
        }
    }
    
    
}

void new_droplet(){
    uint8_t randx = random(5);
    rain_array[4][randx] = 1;
    Serial.println(randx);
    Panels[4][randx].setFullPanel(leds, 0, 255, 0);
}