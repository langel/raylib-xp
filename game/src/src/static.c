

uint32_t * static_pixels = NULL;


void static_image_init() {
	static_pixels = malloc(canvas_width * canvas_height * sizeof(uint32_t));
}


void static_image_update() {
	int i = 1337;
	for (int y = 0; y < canvas_height; y++) {
		for (int x = 0; static_pixels != NULL && x < canvas_width; x++)	{
			uint32_t ppos = y * canvas_width + x;
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
	UpdateTexture(screen_target.texture, static_pixels);
}



