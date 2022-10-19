
#include "./sandbox.c"

#include "./ant_life.c"

#include "./conway.c"
#include "./langton.c"
#include "./static.c"

#include "./ant_life_post.c"


void src_init() {
	sandbox_pixels = malloc(screen_size);
	conway_buffer = malloc(screen_size);
	static_image_init();
	antlife_init();
}
