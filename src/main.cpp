#include "raylib.h"
#include "incCirc.h"
#include <iostream>
#include "ball.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include "imgui.h"
#define NO_FONT_AWESOME
#include "rlImGui.h"
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{

    // Initialization
    //-------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    bool pause = false;
    InitWindow(screenWidth, screenHeight, "Ball Thingy");
    incCirc C1({400, 225}, 100, 1, 10,5000);
    incCirc C2({400, 225}, 175, 1, 10, 10000);
    int rad = 10;
    float rps1 = 2;
    float rps2 = 3;
    Ball ball({screenWidth/2,screenHeight/2 - 30}, &rad);
    ball.addRing(C1);
    ball.addRing(C2);
    C1.setRotation(PI);
    SetTargetFPS(60); // Set our game to run at 6 frames-per-second
    //---------------------------------k-------------------------------------------------
    float frame = 0;
    // Main game loop
    rlImGuiSetup(true);

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        if(!pause){
            C1.setRotation(frame/(60/rps1));
            C2.setRotation(-frame/(60/rps2));
            ball.Update();
            frame++;
        }
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------


        // Draw
        //---------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GRAY);
        C1.Draw();
        C2.Draw();
        ball.Draw();
        DrawFPS(0,0);
        
        rlImGuiBegin();
        
        ImGui::Begin("God Menu");
        if(ImGui::Button("Pause")){
            pause = !pause;
        }
        if(ImGui::Button("Reset Ball")){
            ball.Reset();
        }
        ImGui::Text("Ball Rad");
        ImGui::SliderInt("##1", &rad, 0, 100);
        ImGui::Text("Ring 1 RPS");
        ImGui::SliderFloat("##2", &rps1, -10,10);
        ImGui::Text("Ring 2 RPS");
        ImGui::SliderFloat("##3", &rps2, -10, 10);
        ImGui::End();

        rlImGuiEnd();
        EndDrawing();
      
        //--------------------------------------------------------------------------------
    }
    // De-Initialization
    //-----------------------------------------------------------------l--------------
    rlImGuiShutdown();
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
