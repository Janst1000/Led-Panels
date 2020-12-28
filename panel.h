#ifndef _PANEL_H_
#define _PANEL_H_

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
};

#endif