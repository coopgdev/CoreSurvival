/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/
#include "raylib.h"
#include "scenes/titles.c"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Splash");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    int framesCounter = 0;
    
    Texture2D logo = LoadTexture("./resources/polyscripts.png");
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here

        
        
        HideCursor();
        framesCounter++;    // Count frames


                // Wait for 2 seconds (120 frames) before jumping to TITLE screen
                if (framesCounter > 120)
                {
                    CloseWindow();
                    loadTitles();
                    return 0;
                }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);
            //DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
            //DrawText("PolyScripts!", 325, 199, 20, DARKBLUE);
            DrawTexture(logo, 0, 0, RAYWHITE);


        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //loadTitles();          // Loads the new TITLES.C scene. (please note this is still a wip and wont work)
    //--------------------------------------------------------------------------------------------------------

    return 0;
}
