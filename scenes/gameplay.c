#include "raylib.h"
#include "endingscreen.c"
#include "gameplay.h"

int loadGameplay(void) {
    
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "CoreSurvival | GamePlay");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Texture2D bb = LoadTexture("./resources/cubic.png");
    Texture2D evil = LoadTexture("./resources/enemy.png");


    float x = 32.0f, y = 32.0f;
    float ex = 32.0f, ey = 32.0f;

    float EnemySpeed = 3;

    x = 300;
    y = 190;

    while (!WindowShouldClose()) {


        BeginDrawing();

        //Rectangle rect1 = {100, 100, 50, 50};
        Rectangle playerArea = {x, y, bb.width, bb.height};
        Rectangle eeeeArea = {ex, ey, evil.width, evil.height};


        //Starting Point

        ClearBackground(RAYWHITE);

        //Player Movement
        if (IsKeyDown(KEY_UP)) {
            y -= GetFrameTime() * 500.0f;
        }
        if (IsKeyDown(KEY_DOWN)) {
            y += GetFrameTime() * 500.0f;
        }
        if (IsKeyDown(KEY_LEFT)) {
            x -= GetFrameTime() * 500.0f;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            x += GetFrameTime() * 500.0f;
        }

        if (IsKeyUp(KEY_UP)) {
        }
        

        //Enemy AI
        if (x > ex) {
            ex += EnemySpeed;
        }

        if (x < ex) {
            ex -= EnemySpeed;
        }

        if (y > ey) {
            ey += EnemySpeed;
        }

        if (y < ey) {
            ey -= EnemySpeed;
        }

        if (CheckCollisionRecs(playerArea, eeeeArea)) {
            DrawText("Collided", 5, 5, 25, BLACK);
            x = 0;
            y = 0;
            UnloadTexture(bb);
            x = 0;
            y = 0;
            CloseWindow();
            x = 0;
            y = 0;
            EndingScreen();
            x = 0;
            y = 0;
            loadGameplay();
            x = 300;
            y = 190;
            return 0;
        }
        
        //Texture Library
        
        DrawRectangleRec(playerArea, RAYWHITE); 
        DrawTexture(bb, x, y, RAYWHITE);
        DrawRectangleRec(eeeeArea, RAYWHITE);
        DrawTexture(evil, ex, ey, RAYWHITE);
        //DrawRectangleRec(rect1, RED);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}