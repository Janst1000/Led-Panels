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