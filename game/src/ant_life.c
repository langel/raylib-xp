
#define ANT_COUNT 3

unsigned * antlife_pixels = NULL;
unsigned antlife_off;
unsigned antlife_on;
unsigned * antlife_conways = NULL;

typedef struct {
	int d;
	int x;
	int y;
	int pos;
} ant_ent;

ant_ent ants[ANT_COUNT];

unsigned ant_black = 0xff111111;
unsigned ant_white = 0xffeeeeee;
unsigned ant_red   = 0xff1111cc; 
unsigned ant_brown = 0xff193865;
unsigned ant_cream = 0xffd0fdff;


void antlife_init() {
	for (int i = 0; i < ANT_COUNT; i++) {
		ants[i].x = (i % 3) * (canvas_width / 4) + canvas_width / 4;
		ants[i].y = (int)(i / 3) * (canvas_height / 4) + canvas_height / 4;
		ants[i].d = 0;
	}
	antlife_pixels = malloc(screen_size);
	antlife_off = ant_cream;
	antlife_on = ant_brown;
	for (int i = 0; i < canvas_size; i++) {
		antlife_pixels[i] = antlife_off;
	}
	antlife_conways = malloc(screen_size);
}


void ant_cycle(int ant_id) {
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


void antlife_update() {
	conway_cycle();
	// multiple ant steps per frame
	for (int f = 0; f < 1700; f++) {
		for (int i = 0; i < ANT_COUNT; i++) {
			ant_cycle(i);
		}
	}
	UpdateTexture(screen_target.texture, antlife_pixels);
}
