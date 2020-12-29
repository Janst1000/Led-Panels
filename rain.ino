void rain(int delay_time, CRGB color){
    randomSeed(millis());
    Droplet d(0, color);
    Panels[d.getX()][d.getY()].setFullPanel(leds, color);
    FastLED.show();
    delay(delay_time);
    for(int i = 0; i < 4; i++){
        delay(delay_time);
        d.update();
        Panels[d.getX()][d.getY()].setFullPanel(leds, d.getColor());
        FastLED.show();
    }
}