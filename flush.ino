void flush_animation(CRGB color, int cnt){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            if(x <= cnt && y <= cnt){
                Panels[y][x].setFullPanel(leds, color);
            }
        }
    }
}