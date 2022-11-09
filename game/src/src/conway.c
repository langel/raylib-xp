
uint32_t * conway_buffer = NULL;

void conway_cycle() {
	uint32_t pixel;
	int xx;
	int yy;
	int living_neighbors;
	int living_cell;
	for (int x = 0; x < canvas_width; x++) {
		for (int y = 0; y < canvas_height; y++) {
			living_neighbors = 0;
			// XXX broken conway was x + y * canvas_height   xD
			pixel = sandbox_pixels[screen_pos(x, y)];
			living_cell = (pixel == antlife_on) ? 1 : 0;
			// pos 0
			xx = screen_dex(x);
			yy = screen_dey(y);
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 1
			xx = x;
			yy = screen_dey(y);
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 2
			xx = screen_inx(x);
			yy = screen_dey(y);
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 3
			xx = screen_dex(x);
			yy = y;
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos == current cell
			// pos 5
			xx = screen_inx(x);
			yy = y;
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 6
			xx = screen_dex(x);
			yy = screen_iny(y);
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 7
			xx = x;
			yy = screen_iny(y);
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// pos 8
			xx = screen_inx(x);
			yy = screen_iny(y);
			pixel = sandbox_pixels[screen_pos(xx, yy)];
			if (pixel == antlife_on) living_neighbors++;
			// conway rules
			if (living_cell) {
				if (living_neighbors != 2 && living_neighbors != 3) {
					living_cell = 0;
				}
			}
			else if (living_neighbors == 3) {
				living_cell = 1;
			}
			else living_cell = 0;
			pixel = (living_cell) ? antlife_on : antlife_off;
			conway_buffer[screen_pos(x, y)] = pixel;
/*
Any live cell with two or three live neighbours survives.

Any dead cell with three live neighbours becomes a live cell.

All other live cells die in the next generation. Similarly, all other dead cells stay dead.
*/
		}
	}
	memcpy(sandbox_pixels, conway_buffer, screen_size);
}
