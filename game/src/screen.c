
#define OVERSCALE 3
int canvas_width = 420;
int canvas_height = 200;
Rectangle canvas_rect;

RenderTexture2D overscan_render;
Rectangle overscan_rect;

RenderTexture2D screen_target;
unsigned * screen_pixels = NULL;


void screen_init() {
	canvas_rect = (Rectangle) { 0, 0, canvas_width, canvas_height };
	overscan_rect = (Rectangle) { 0, 0, canvas_width * OVERSCALE, canvas_height * OVERSCALE };
	overscan_render = LoadRenderTexture(overscan_rect.width, overscan_rect.height);
	SetTextureFilter(overscan_render.texture, TEXTURE_FILTER_BILINEAR);
	screen_target = LoadRenderTexture(canvas_width, canvas_height);
	screen_pixels = malloc(canvas_width * canvas_height * sizeof(unsigned));
}


void screen_update() {
	BeginTextureMode(overscan_render);
	DrawTexturePro(screen_target.texture, canvas_rect, overscan_rect, (Vector2) { 0, 0 }, 0.f, WHITE);  
	EndTextureMode();
}


void screen_draw() {
	DrawTexturePro(overscan_render.texture, overscan_rect, (Rectangle) { 0, 0, screenWidth, screenHeight}, (Vector2) { 0, 0 }, 0.f, WHITE);  
}
