
#define OVERSCALE 3
int canvas_width;
int canvas_height;
int canvas_size;
Rectangle canvas_rect;

RenderTexture2D overscan_render;
Rectangle overscan_rect;

RenderTexture2D screen_target;
unsigned * screen_pixels = NULL;
int screen_size;


// MAIN FUNCTIONS

void screen_init() {
	canvas_width = 420;
	canvas_height = 200;
	canvas_size = canvas_width * canvas_height;
	canvas_rect = (Rectangle) { 0, 0, canvas_width, canvas_height };
	overscan_rect = (Rectangle) { 0, 0, canvas_width * OVERSCALE, canvas_height * OVERSCALE };
	overscan_render = LoadRenderTexture(overscan_rect.width, overscan_rect.height);
	SetTextureFilter(overscan_render.texture, TEXTURE_FILTER_BILINEAR);
	screen_target = LoadRenderTexture(canvas_width, canvas_height);
	screen_size = canvas_size * sizeof(unsigned);
	screen_pixels = malloc(screen_size);
}


void screen_update() {
	BeginTextureMode(overscan_render);
	DrawTexturePro(screen_target.texture, canvas_rect, overscan_rect, (Vector2) { 0, 0 }, 0.f, WHITE);  
	EndTextureMode();
}


void screen_draw() {
	DrawTexturePro(overscan_render.texture, overscan_rect, (Rectangle) { 0, 0, window_width, window_height }, (Vector2) { 0, 0 }, 0.f, WHITE);  
}


// UTIL FUNCTIONS

// right
int screen_inx(int x) {
	x++;
	if (x >= canvas_width) x = 0;
	return x;
}
// down
int screen_iny(int y) {
	y++;
	if (y >= canvas_height) y = 0;
	return y;
}
// left
int screen_dex(int x) {
	x--;
	if (x < 0) x = canvas_width - 1;
	return x;
}
// up
int screen_dey(int y) {
	y--;
	if (y < 0) y = canvas_height - 1;
	return y;
}

// returns logical address for position
int screen_pos(int x, int y) {
	return x + y * canvas_width;
}
