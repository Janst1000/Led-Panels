void rainbow_animation(CRGB* leds, int phase_shift, uint8_t panel_shift){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            Panels[y][x].setFullPanel(leds, CHSV((phase_shift - (x * panel_shift * 0.2) - (y * panel_shift)), 255, 255));
        }
    }
}