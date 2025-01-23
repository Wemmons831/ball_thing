#include "raylib.h"
#include "incCirc.h"
#include <iostream>
#include "ball.h"
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
    incCirc C1({400, 225}, 100, 1, 10,1000);
    incCirc C2({400, 225}, 200, 1, 10, 100000);

    Ball ball({screenWidth/2,screenHeight/2 - 30}, 10);
    ball.addRing(C1);
    ball.addRing(C2);
    C1.setRotation(PI);
    SetTargetFPS(60); // Set our game to run at 6 frames-per-second
    //---------------------------------k-------------------------------------------------
    float frame = 0;
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        C1.setRotation(frame/20);
        C2.setRotation(-frame/20);
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------


        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);
        C1.Draw();
        C2.Draw();
        ball.Draw();
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
