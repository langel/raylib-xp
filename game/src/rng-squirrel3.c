
// discovered here : https://www.youtube.com/watch?v=LWFzPP8ZbdU

unsigned squirrel3(unsigned position, unsigned seed) {
	const unsigned BIT_NOISE1 = 0xB5297A4D;
	const unsigned BIT_NOISE2 = 0x68E31DA4;
	const unsigned BIT_NOISE3 = 0x1B56C4E9;

	unsigned mangled = position;
	mangled *= BIT_NOISE1;
	mangled += seed;
	mangled ^= (mangled >> 8);
	mangled += BIT_NOISE2;
	mangled ^= (mangled << 8);
	mangled *= BIT_NOISE3;
	mangled ^= (mangled >> 8);
	return mangled;
}

unsigned squirrel3_get_2d(int x, int y, unsigned seed) {
	const int prime = 198491317;
	return squirrel3((unsigned) (x + y * prime), seed);
}

unsigned squirrel3_get_3d(int x, int y, int z, unsigned seed) {
	const int prime1 = 198491317;
	const int prime2 = 6542989;
	return squirrel3((unsigned) (x + y * prime1 + z * prime2), seed);
}

// returns float between 0 and 1
float squirrel3_zero_float(unsigned position, unsigned seed) {
	return (float) squirrel3(position, seed) / (float) 0xffffffff;
}

// returns float between -1 and 1
float squirrel3_neg_float(unsigned position, unsigned seed) {
	return ((float) squirrel3(position, seed) / (float) 0x7fffffff) - 1.f;
}
