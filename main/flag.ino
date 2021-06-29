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