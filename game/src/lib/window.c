
int window_width;
int window_height;


void window_init(int width, int height, char * title) {
	window_width = width;
	window_height = height;
	InitWindow(width, height, title);
}


void window_update() {
	window_width = GetScreenWidth();
	window_height = GetScreenHeight();
}
	
