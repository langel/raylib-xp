
void langton_cycle(int ant_id) {
	ant_ent ant = ants[ant_id];
	int antpos = screen_pos(ant.x, ant.y);
	unsigned pixel = antlife_pixels[antpos];
	if (pixel == antlife_off) {
		ant.d++;
		if (ant.d > 3) ant.d = 0;
		antlife_pixels[antpos] = antlife_on;
	}
	if (pixel == antlife_on) {
		ant.d--;
		if (ant.d < 0) ant.d = 3;
		antlife_pixels[antpos] = antlife_off;
	}
	// right
	if (ant.d == 0) ant.x = screen_inx(ant.x);
	// up
	if (ant.d == 1) ant.y = screen_dey(ant.y);
	// left
	if (ant.d == 2) ant.x = screen_dex(ant.x);
	// down
	if (ant.d == 3) ant.y = screen_iny(ant.y);
	ants[ant_id] = ant;
}
