#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    int playerHeartsMax = 20;
    int playerHeart = 20;

    InitWindow(screenWidth, screenHeight, "Raylib [Core] Example - Draw Square");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(555, 7, 335, 120, BLUE);
        DrawText("Attack", 600, 38, 20, BLACK);
        DrawText("MP recovery", 600, 58, 20, BLACK);
        DrawText("Item", 600, 78, 20, BLACK);
        DrawText("Shield", 600, 98, 20, BLACK);

        DrawRectangle(555, 150, 335, 120, BLUE);
        DrawText("Attack", 600, 180, 20, BLACK);
        DrawText("MP recovery", 600, 200, 20, BLACK);
        DrawText("Item", 600, 220, 20, BLACK);
        DrawText("Shield", 600, 240, 20, BLACK);

        DrawRectangle(555, 425, 335, 120, BLUE);
        DrawRectangle(600, 435, playerHeart * 5, 20, YELLOW);
        DrawText("20/20", 720, 435, 20, BLACK);
        DrawText("Attack", 600, 460, 20, BLACK);
        DrawText("MP recovery", 600, 480, 20, BLACK);
        DrawText("Item", 600, 500, 20, BLACK);
        DrawText("Shouldering another's debt", 600, 520, 20, BLACK);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}