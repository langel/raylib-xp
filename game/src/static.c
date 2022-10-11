
#include "raylib.h"

RenderTexture2D static_target;

unsigned * static_pixels = NULL;


void static_image_init() {
	static_pixels = malloc(canvas_width * canvas_height * sizeof(unsigned));
	static_target = LoadRenderTexture(canvas_width, canvas_height);
}


void static_image_update() {
	int i = 1337;
	for (int y = 0; y < canvas_height; y++) {
		for (int x = 0; static_pixels != NULL && x < canvas_width; x++)	{
			unsigned ppos = y * canvas_width + x;
			// 32bit ABGR syntax for why?!?!
			//static_pixels[ppos] = 0xff000000 + (y << 16);
			static_pixels[ppos] = squirrel3(frame_counter + i, 1337);
			/*
			// simple checkerboard pattern
			if (((x/32+y/32)/1)%2 == 0) static_pixels[ppos] = 0x112233ff;
			else static_pixels[ppos] = 0xeeddccff;
			*/
			i++;
		}
	}
	UpdateTexture(static_target.texture, static_pixels);
	BeginTextureMode(overscan_render);
	DrawTexturePro(static_target.texture, canvas_rect, overscan_rect, (Vector2) { 0, 0 }, 0.f, WHITE);  
	EndTextureMode();
}



void static_image_draw() {

//	DrawTexture(static_target.texture, screenWidth/2 - static_target.texture.width/2, screenHeight/2 - static_target.texture.height/2 - 40, WHITE);
//	DrawTexturePro(static_target.texture, (Rectangle) { 0, 0, canvas_width, canvas_height }, (Rectangle) { 0, 0, screenWidth, screenHeight}, (Vector2) { 0, 0 }, 0.f, WHITE);  

}
