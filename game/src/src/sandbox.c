unsigned * sandbox_pixels = NULL;

void sandbox_clear(unsigned fill) {
	for (int i = 0; i < canvas_size; i++) {
		sandbox_pixels[i] = fill;
	}
}

