
#include "raylib.h"

int static_width = 320;
int static_height = 200;

Image static_image;
RenderTexture2D static_target;
Texture2D static_texture;

unsigned long * static_pixels = NULL;



void static_image_init() {
	if (static_pixels == NULL) {
		static_pixels = malloc(static_width * static_height * 4);
	}
	printf("static size: %d\n", static_width * static_height * sizeof(unsigned));

	static_image = GenImageColor(static_width, static_height, BLACK);
	ImageFormat(&static_image, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
	static_texture = LoadTextureFromImage(static_image);
//	static_texture.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
	static_target = LoadRenderTexture(static_width, static_height);
}


void static_image_update() {
	for (int y = 0; y < static_height; y++) {
		for (int x = 0; static_pixels != NULL && x < static_width; x++)	{
			unsigned ppos = y * static_width + x;
			//printf("ppos: %d\n", ppos);
			static_pixels[ppos] = 0xfff00f0f;
			//printf("%d\n", ppos);
			/*
			if (((x/32+y/32)/1)%2 == 0) static_pixels[ppos] = ORANGE;
			else static_pixels[ppos] = GOLD;
			*/
			//if (((x/32+y/32)/1)%2 == 0) static_pixels[ppos] = 0x112233ff;
			//else static_pixels[ppos] = 0xeeddccff;
		}
	}
//	UpdateTexture(static_texture, static_pixels);

// Load pixels data into an image structure and create texture
/*
	Image checkedIm = {
		.data = static_pixels,             // We can assign pixels directly to data
		.width = static_width,
		.height = static_height,
		.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8,
		.mipmaps = 1
	};

	UpdateTexture(static_texture, static_image.data);
	UnloadImage(checkedIm);         // Unload CPU (RAM) image data (pixels)

	static_image = GenImageWhiteNoise(static_width, static_height, 0.5f);
	ImageFormat(&static_image, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
	UpdateTexture(static_texture, static_image.data);
	UnloadImage(static_image);
	*/

	UpdateTexture(static_texture, static_pixels);

	BeginTextureMode(static_target);
	DrawTexture(static_texture, 0, 0, WHITE);
	DrawText("hey wow i am impossible!", 10, 25, 20, GREEN);
	EndTextureMode();
}



void static_image_draw() {

	DrawTexture(static_target.texture, screenWidth/2 - static_texture.width/2, screenHeight/2 - static_texture.height/2 - 40, WHITE);

}
