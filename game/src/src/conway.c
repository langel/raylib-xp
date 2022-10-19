

void conway_cycle() {
	unsigned pixel;
	int xx;
	int yy;
	int living_neighbors;
	int living_cell;
	for (int x = 0; x < canvas_width; x++) {
		for (int y = 0; y < canvas_height; y++) {
			living_neighbors = 0;
			pixel = antlife_pixels[x + y * canvas_height];
			living_cell = (pixel == antlife_on) ? 1 : 0;
			// pos 0
			xx = screen_dex(x);
			yy = screen_dey(y);
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 1
			xx = x;
			yy = screen_dey(y);
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 2
			xx = screen_inx(x);
			yy = screen_dey(y);
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 3
			xx = screen_dex(x);
			yy = y;
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos == current cell
			// pos 5
			xx = screen_inx(x);
			yy = y;
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 6
			xx = screen_dex(x);
			yy = screen_iny(y);
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 7
			xx = x;
			yy = screen_iny(y);
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 8
			xx = screen_inx(x);
			yy = screen_iny(y);
			pixel = antlife_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// conway rules
			if (living_cell) {
				if (living_neighbors != 2 && living_neighbors != 3) {
					living_cell = 0;
				}
			}
			else if (!living_cell && living_neighbors == 3) {
				living_cell = 1;
			}
			else living_cell = 0;
			pixel = (living_cell) ? antlife_on : antlife_off;
			antlife_conways[screen_pos(x, y)] = pixel;
/*
Any live cell with two or three live neighbours survives.

Any dead cell with three live neighbours becomes a live cell.

All other live cells die in the next generation. Similarly, all other dead cells stay dead.
*/
		}
	}
	memcpy(antlife_pixels, antlife_conways, screen_size);
}
