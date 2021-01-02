void xydemo(uint8_t startHue8, int8_t yHueDelta8, int8_t xHueDelta8){
    uint8_t lineStartHue = startHue8;
    for(uint8_t y = 0; y < pheigth; y++){
        lineStartHue += yHueDelta8;
        uint8_t pixelHue = lineStartHue;
        for(uint8_t x = 0; x < pwidth; x++){
            pixelHue += xHueDelta8;
            Panels[y][x].setFullPanel(leds, CHSV(pixelHue, 255, 255));
        }
    }
}