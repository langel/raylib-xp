uint32_t * sandbox_pixels = NULL;

void sandbox_clear(uint32_t fill) {
	for (int i = 0; i < canvas_size; i++) {
		sandbox_pixels[i] = fill;
	}
}

