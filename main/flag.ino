void flag(CRGB colors[]){
	for(int y = 0; y < pheigth; y++){
		for(int x = 0; x < pwidth; x++){
			CRGB temp = colors[y];
			Panels[y][x].setFullPanel(leds, temp);
		}
	}
}