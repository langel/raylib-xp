/*******************************************************************************************
*
*   raylib game template
*
*   <Game title>
*   <Game description>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include "lib/core.c"
#include "src/core.c"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
// NOTE: Those variables are shared between modules through screens.h
//----------------------------------------------------------------------------------
Music music = { 0 };
Sound fxCoin = { 0 };



//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void) {
    // Initialization
    //---------------------------------------------------------
	window_init(1600, 900, "raylib-xp");
	SetWindowState(FLAG_WINDOW_RESIZABLE);

	InitAudioDevice();      // Initialize audio device

	screen_init();
	antlife_init();
	static_image_init();

    // Load global data (assets that must be available in all screens, i.e. font)
    music = LoadMusicStream("resources/ambient.ogg");
    fxCoin = LoadSound("resources/coin.wav");

    SetMusicVolume(music, 1.0f);
    //PlayMusicStream(music);
	 SetSoundVolume(fxCoin, 0.25f);


#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
	 // Detect window close button or ESC key
	while (!WindowShouldClose())	{

		// NOTE: Music keeps playing between screens
		UpdateMusicStream(music);       
		// coin sfx important
		if (IsKeyPressed(KEY_ENTER) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsGestureDetected(GESTURE_TAP)) {
			PlaySound(fxCoin);
		}

		// update graphics
		window_update();
		//static_image_update();
		antlife_update();
		screen_update();

		// actually draw the screen
		BeginDrawing();
		screen_draw();
//		DrawFPS(10, 10);
		EndDrawing();

		frame_counter_inc;
	}
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // Unload global data loaded
    UnloadMusicStream(music);
    UnloadSound(fxCoin);

    CloseAudioDevice();     // Close audio context

    CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



