


unsigned * antlife_pixels = NULL;

int antd = 1;
int antx;
int anty;
int antpos;

unsigned ant_black = 0xff111111;
unsigned ant_white = 0xffeeeeee;
unsigned ant_red   = 0xff1111cc; 

void antlife_init() {
	antx = canvas_width / 2;
	anty = canvas_height / 2;
	int mapsize = canvas_width * canvas_height;
	antlife_pixels = malloc(mapsize * sizeof(unsigned));
	for (int i = 0; i < mapsize; i++) {
		antlife_pixels[i] = ant_white;
	}
}


void antlife_update() {
	antpos = antx + canvas_width * anty;
	printf("%d %d\n", antx, anty);
	unsigned pixel = antlife_pixels[antpos];
	if (pixel == ant_black) {
		printf("black\n");
		antd++;
		if (antd > 3) antd = 0;
		antlife_pixels[antpos] = ant_white;
	}
	if (pixel == ant_white) {
		printf("white\n");
		antd--;
		if (antd < 0) antd = 3;
		antlife_pixels[antpos] = ant_black;
	}
	// right
	if (antd == 0) {
		antx++;
		if (antx >= canvas_width) antx = 0;
	}
	// up
	if (antd == 1) {
		anty--;
		if (anty < 0) anty = canvas_height - 1;
	}
	// left
	if (antd == 2) {
		antx--;
		if (antx < 0) antx = canvas_width - 1;
	}
	// down
	if (antd == 3) {
		anty++;
		if (anty >= canvas_height) anty = 0;
	}
	antpos = antx + canvas_width * anty;
//	antlife_pixels[antpos] = ant_red;
	UpdateTexture(screen_target.texture, antlife_pixels);
}
