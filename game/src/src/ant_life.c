
unsigned * antlife_pixels = NULL;
unsigned antlife_off;
unsigned antlife_on;
unsigned * antlife_conways = NULL;

typedef struct {
	int d;
	int x;
	int y;
	int pos;
} ant_ent;

ant_ent ants[256];
int ant_count;

