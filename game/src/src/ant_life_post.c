

void antlife_init() {
	ant_count = 1;
	for (int i = 0; i < ant_count; i++) {
		ants[i].x = (i % 3) * (canvas_width / 4) + canvas_width / 4;
		ants[i].y = (int)(i / 3) * (canvas_height / 4) + canvas_height / 4;
		ants[i].d = 0;
	}
	antlife_off = clr_cream;
	antlife_on = clr_brown;
	sandbox_clear(antlife_off);
}


// fun history!
// broken conway + 1700 ant cycles and 9 ants


void antlife_update() {
	conway_cycle();
	// multiple ant steps per frame
	for (int f = 0; f < 7; f++) {
		for (int i = 0; i < ant_count; i++) {
			langton_cycle(i);
		}
	}
	UpdateTexture(screen_target.texture, sandbox_pixels);
}
