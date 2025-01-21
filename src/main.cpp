#include "raylib.h"
#include "incCirc.h"
#include <iostream>
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //-------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    incCirc C1({400, 225}, 100, 1, 10);
    incCirc C2({400, 225}, 100, 1, 10);
    SetTargetFPS(60); // Set our game to run at 6 frames-per-second
    //---------------------------------k-------------------------------------------------
    float frame = 0;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        C.setRotation(frame/60);
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        C.Draw();
        DrawFPS(0,0);
        

        EndDrawing();
        frame++;
        //--------------------------------------------------------------------------------
    }

    // De-Initialization
    //-----------------------------------------------------------------l--------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
