

void antlife_init() {
	ant_count = 9;
	for (int i = 0; i < ant_count; i++) {
		ants[i].x = (i % 3) * (canvas_width / 4) + canvas_width / 4;
		ants[i].y = (int)(i / 3) * (canvas_height / 4) + canvas_height / 4;
		ants[i].d = 0;
	}
	antlife_pixels = malloc(screen_size);
	antlife_off = clr_cream;
	antlife_on = clr_brown;
	for (int i = 0; i < canvas_size; i++) {
		antlife_pixels[i] = antlife_off;
	}
	antlife_conways = malloc(screen_size);
}



void antlife_update() {
	conway_cycle();
	// multiple ant steps per frame
	for (int f = 0; f < 1700; f++) {
		for (int i = 0; i < ant_count; i++) {
			langton_cycle(i);
		}
	}
	UpdateTexture(screen_target.texture, antlife_pixels);
}
