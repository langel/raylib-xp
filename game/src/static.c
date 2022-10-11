
#include "raylib.h"

int static_width = 320;
int static_height = 200;

RenderTexture2D static_target;

unsigned * static_pixels = NULL;


void static_image_init() {
	static_pixels = malloc(static_width * static_height * sizeof(unsigned));
	static_target = LoadRenderTexture(static_width, static_height);
}


void static_image_update() {
	for (int y = 0; y < static_height; y++) {
		for (int x = 0; static_pixels != NULL && x < static_width; x++)	{
			unsigned ppos = y * static_width + x;
			// 32bit ABGR syntax for why?!?!
			static_pixels[ppos] = 0xff000000 + (y << 16);
			/*
			// simple checkerboard pattern
			if (((x/32+y/32)/1)%2 == 0) static_pixels[ppos] = 0x112233ff;
			else static_pixels[ppos] = 0xeeddccff;
			*/
		}
	}
	UpdateTexture(static_target.texture, static_pixels);
}



void static_image_draw() {

	DrawTexture(static_target.texture, screenWidth/2 - static_target.texture.width/2, screenHeight/2 - static_target.texture.height/2 - 40, WHITE);

}
