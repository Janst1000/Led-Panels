# 1 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\main.ino"
#define FASTLED_INTERNAL 
# 3 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\main.ino" 2
# 4 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\main.ino" 2
# 5 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\main.ino" 2
# 6 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\main.ino" 2
# 7 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\main.ino" 2


const bool DEBUG = false;

#define NUM_LEDS 75
#define DATA_PIN 5
#define LED_PER_PANEL 3
#define BRIGHTNESS 255
const uint8_t width = 15;
const uint8_t height = 5;
const uint8_t pwidth = 5;
const uint8_t pheigth = 5;

CRGB leds[75];

CRGB rain_array[pwidth][pheigth];
int cnt = 0;





int XY(uint8_t x, uint8_t y){
    const uint8_t XY_TABLE[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15,
    30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45,
    60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74
    };

    uint8_t i = (y * width) + x;
    uint8_t j = XY_TABLE[i];
    return j;

}

const uint8_t PanelsTable[pwidth][pheigth][3] = {
    {{ 0, 1, 2}, { 3, 4, 5}, { 6, 7, 8}, { 9, 10, 11}, {12, 13, 14}},
    {{28, 29, 27}, {25, 26, 24}, {22, 23, 21}, {19, 20, 18}, {15, 17, 16}},
    {{30, 31, 32}, {33, 34, 35}, {36, 37, 38}, {39, 40, 41}, {42, 44, 43}},
    {{58, 59, 57}, {55, 56, 54}, {52, 53, 51}, {49, 50, 48}, {45, 47, 46}},
    {{60, 61, 62}, {63, 64, 65}, {66, 67, 68}, {69, 70, 71}, {72, 74, 73}}
};


Panel Panels[pwidth][pheigth];

int phase_shift=0;
int pattern=5;
CRGB temp_color = CHSV(random(256), 255, 255);
bool frame_array[pwidth][pheigth];


CRGB prideflag[5] = { CHSV(206, 255, 200),CHSV(155, 255, 200),CHSV(104, 255, 200),CHSV(53, 255, 200),CHSV(2, 255, 255)};
CRGB gay[5] = { CRGB(0x2600FF),CRGB(0x5049CC),CRGB(0xFFFFFF),CRGB(0x27CEAA),CRGB(0x078D70)};
CRGB lesbian[5] { CRGB(0xA80068),CRGB(0xE04C99),CRGB(0xFFFFFF),CRGB(0xFF9B56),CRGB(0xD32E00)};
CRGB bi[5] { CRGB(0x0038A8),CRGB(0x0038A8),CRGB(0xBC2FB2),CRGB(0xD60270),CRGB(0xD60270)};
CRGB trans[5] { CRGB(0x14BDFF),CRGB(0xF76381),CRGB(0xFFFFFF),CRGB(0xF763F5),CRGB(0x0037FF)};

CRGB *colors;

void setup(){

  // LED Strip initializing
  FastLED.addLeds<WS2812B, 5, GRB>(leds, 75); // GRB ordering is typical
  FastLED.setBrightness(200);
  for(int y = 0; y < pheigth; y++){
      for(int x = 0; x < pwidth; x++){
        Panels[x][y].setLedPanel(PanelsTable[x][y][0], PanelsTable[x][y][1], PanelsTable[x][y][2]);
        }
    }
    //Panels[1][1].setFullPanel(leds, 255, 0, 0);
    rain_init();
    randomSeed(millis());
    Serial.begin(115200);
    FastLED.setCorrection(TypicalSMD5050);
    FastLED.setTemperature(Tungsten100W);

    colors = flag_select(cnt, colors);
}

void loop(){
    if(DEBUG == true){ //check if debug flag up top is set

    } else {
        if(pattern == 5){ //pride
            flag_animation(colors, frame_array);
            FastLED.show();
            FastLED.delay(1000/60);
            static CEveryNSeconds PER0(4); if( PER0 ){
                frame_init(frame_array);
                colors = flag_select(cnt, colors);
                cnt++;
            }
        }
        if(pattern == 4){ //plop
            Serial.println(cnt);
            plop(temp_color, cnt, frame_array);
            FastLED.show();
            FastLED.delay(1000/60);
            static CEveryNMillis PER1(100); if( PER1 ){ cnt++;}
            static CEveryNSeconds PER2(1); if( PER2 ){
                temp_color = CHSV(random(256), 255, 255);
                cnt = 0;
                }
        }
        if(pattern == 3){ //flush
            flush_animation(temp_color, cnt);
            FastLED.show();
            //FastLED.delay(1000/60);
            static CEveryNMillis PER3(75); if( PER3 ){ cnt++; }
            static CEveryNSeconds PER4(1); if( PER4 ) {
                temp_color = CHSV(random(0, 256), 255, 255);
                cnt = 0;
            }
        }
        if(pattern == 2){ //xydemo
            uint32_t ms = millis();
            int32_t yHueDelta32 = ((int32_t)cos16( ms * (27/1) ) * (350 / pwidth));
            int32_t xHueDelta32 = ((int32_t)cos16( ms * (39/1) ) * (310 / pheigth));
            xydemo( ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);
            if( ms < 5000 ) {
            FastLED.setBrightness( scale8( 255, (ms * 256) / 5000));
            } else {
            FastLED.setBrightness(255);
            }
            FastLED.show();
            FastLED.delay(1000/60);
        }
        if(pattern == 1){ //rain
            static CEveryNMillis PER5(100); if( PER5 ){
                rain();
                if((cnt % 3) == 0){
                    new_droplet(CHSV(random(0, 256), 255, 255));
                }
                cnt++;
            }
            FastLED.delay(1000/60);
        }
        if(pattern == 0){ //rainbow
            FastLED.delay(1000/60);
            rainbow_animation(leds, phase_shift, 40);
            static CEveryNMillis PER6(10); if( PER6 ){phase_shift++;}
        }

        static CEveryNSeconds PER7(20); if( PER7 ){
            if(pattern == 5){
                pattern = 0;
            } else {
                //pattern++;
            }
            for(uint8_t y = 0; y < pheigth; y++){
                for (uint8_t x = 0; x < pwidth; x++){
                    Panels[y][x].off(leds);
                }

            }
            cnt = 0; //reset cnt variable to prevent overflow
            Serial.println("reset");
        }
    }


}
# 1 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\flag.ino"
void flag(CRGB colors[]){
 for(int y = 0; y < pheigth; y++){
  for(int x = 0; x < pwidth; x++){
   CRGB temp = colors[y];
   Panels[y][x].setFullPanel(leds, temp);
  }
 }
}

void flag_animation(CRGB *colors, bool frame_array[pheigth][pwidth]){
 uint8_t y = random(pheigth);
 uint8_t x = random(pwidth);
 unsigned long start = millis();
 unsigned long now = millis();
 do
 {
  y = random(pheigth);
  x = random(pwidth);
  now = millis();
  if((now - start) > 100){
   break;
  }
 } while (frame_array[y][x] == 1);
 CRGB temp = colors[y];
 Panels[y][x].setFullPanel(leds, temp);
 frame_array[y][x] = 1;
 Serial.println(cnt);
}

CRGB* flag_select(uint8_t num, CRGB *colors){
 switch (num)
 {
 case 0:
  return prideflag;
  break;
 case 1:
  return gay;
  break;
 case 2:
  return lesbian;
  break;
 case 3:
  return bi;
  break;
 case 4:
  return trans;
  break;
 default:
  break;
 }
}
# 1 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\flush.ino"
void flush_animation(CRGB color, int cnt){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            if(x + y <= cnt){
                Panels[y][x].setFullPanel(leds, color);
            }
        }
    }
}
# 1 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\plop.ino"
void plop(CRGB color, int cnt, bool frame_array[pheigth][pwidth]){
    plop_frame(cnt, frame_array);
    for(int y = 0; y < pheigth; y++){
        for(int x = 0; x < pwidth; x++){
            if(frame_array[y][x] == 1){
                Panels[y][x].setFullPanel(leds, color);
            }
        }
    }
}

void frame_init(bool frame_array[pheigth][pwidth]){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            frame_array[y][x] = 0;
        }
    }
}

void plop_frame(uint8_t cnt, bool frame_array[pheigth][pwidth]){
    switch(cnt){
        case 0: {
            for(uint8_t y = 0; y < pheigth; y++){
                for(uint8_t x = 0; x < pwidth; x++){
                    frame_array[y][x] = 0;
                }
            }
            break;
        }
        case 1: {
            frame_array[2][2] = 1;
            break;
        }
        case 2: {
            frame_array[1][2] = 1;
            frame_array[1][3] = 1;
            frame_array[2][1] = 1;
            frame_array[2][3] = 1;
            frame_array[3][1] = 1;
            frame_array[3][2] = 1;
            break;
        }
        case 3: {
            frame_array[0][2] = 1;
            frame_array[0][3] = 1;
            frame_array[0][4] = 1;
            frame_array[1][1] = 1;
            frame_array[1][4] = 1;
            frame_array[2][0] = 1;
            frame_array[2][4] = 1;
            frame_array[3][0] = 1;
            frame_array[3][3] = 1;
            frame_array[4][0] = 1;
            frame_array[4][1] = 1;
            frame_array[4][2] = 1;
            break;
        }
        case 4: {
            frame_array[0][1] = 1;
            frame_array[1][0] = 1;
            frame_array[3][4] = 1;
            frame_array[4][3] = 1;
            break;
        }
        case 5:{
            frame_array[0][0] = 1;
            frame_array[4][4] = 1;
            break;
        }
        default:{
            //do nothing
        }
    }
}
# 1 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\rain.ino"
void rain_init(){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            rain_array[y][x] = 0;
        }
    }
}

void rain(){
    fadeToBlackBy(leds, 75, 150);//150 good value
    /*go through all elements and shift the 1s down by one*/
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            if(rain_array[y][x] != CRGB(0)){
                CRGB temp = rain_array[y][x];
                rain_array[y][x] = 0;
                if(y != 0){
                    rain_array[y-1][x] = temp;
                    Panels[y-1][x].setFullPanel(leds, temp);
                }
            }
        }
    }


}

void new_droplet(CRGB color){
    uint8_t randx = random(5);
    rain_array[4][randx] = CRGB(color);
    Panels[4][randx].setFullPanel(leds, color);
}

void offAtBrigthness(){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            if(leds[Panels[y][x].getFirst()].getAverageLight() < 42){
                Panels[y][x].off(leds);
            }
        }
    }
}
# 1 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\rainbow.ino"
void rainbow_animation(CRGB* leds, int phase_shift, uint8_t panel_shift){
    for(uint8_t y = 0; y < pheigth; y++){
        for(uint8_t x = 0; x < pwidth; x++){
            Panels[y][x].setFullPanel(leds, CHSV((phase_shift - (x * panel_shift * 0.2) - (y * panel_shift)), 255, 255));
        }
    }
}
# 1 "c:\\Users\\janst\\Coding\\projects\\Arduino\\main\\xydemo.ino"
void xydemo(uint8_t startHue8, int8_t yHueDelta8, int8_t xHueDelta8){
    uint8_t lineStartHue = startHue8;
    for(uint8_t y = 0; y < pheigth; y++){
        lineStartHue += yHueDelta8;
        uint8_t pixelHue = lineStartHue;
        for(uint8_t x = 0; x < pwidth; x++){
            pixelHue += (xHueDelta8 / 3) + (yHueDelta8 / 2);
            Panels[y][x].setFullPanel(leds, CHSV(pixelHue, 255, 255));
        }
    }
}
