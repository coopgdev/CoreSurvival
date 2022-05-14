#include "raylib.h"

int EndingScreen(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "CoreSurvival | GamePlay");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    while (!WindowShouldClose()) {
        BeginDrawing();
        DrawRectangle(0, 0, screenWidth, screenHeight, RED);
        DrawText("you died", 20, 20, 40, WHITE);
        DrawText("you died", 120, 220, 20, WHITE);
        DrawText("you died L", 120, 230, 20, DARKBLUE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}