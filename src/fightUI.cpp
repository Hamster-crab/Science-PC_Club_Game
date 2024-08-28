#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;
    int MPDefault = 1000;
    int MPDefaultMax = 1145148101919;
    int playerMPMax = 1000;
    int playerMP = 1000;

    int bossHPDefault = 114514;
    int bossHP = 114514;
    int bossMPDefault = 114514;
    int bossMP = 114514;


    int playerHeartsMax = 20;
    int playerHeart = 20;

    InitWindow(screenWidth, screenHeight, "Raylib [Core] Example - Draw Square");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(690, 7, 200, 110, BLUE);
        DrawText("Attack", 750, 38, 20, BLACK);
        DrawText("MP recovery", 750, 58, 20, BLACK);
        DrawText("Item", 750, 78, 20, BLACK);
        DrawText("Shield", 750, 98, 20, BLACK);

        DrawRectangle(690, 150, 200, 110, BLUE);
        DrawText("Attack", 750, 180, 20, BLACK);
        DrawText("MP recovery", 750, 200, 20, BLACK);
        DrawText("Item", 750, 220, 20, BLACK);
        DrawText("Shield", 750, 240, 20, BLACK);


        DrawRectangle(10, 10, 50, 580, BLUE);
        DrawRectangle(13, 15, 20, 500, YELLOW);
        DrawRectangle(35, 15, 20, 500, DARKPURPLE);
//        DrawText("");




//        DrawRectangle(555, 425, 335, 120, BLUE);
//        DrawRectangle(600, 435, playerHeart * 3, 20, YELLOW);
//        DrawText("20/20", 670, 435, 20, BLACK);
//        if (playerMPMax > 300)
//        {
//        DrawRectangle(750, 435, playerMP / 10, 20, RED);
//        DrawRectangle(750, 435, playerMP / 10, 20, DARKPURPLE);
//        }
//        else
//        {
//            DrawRectangle(750, 435, playerMP / 100, 20, RED);
//            DrawRectangle(750, 435, playerMP / 100, 20, DARKPURPLE);
//        }
//        DrawText("Attack", 600, 460, 20, BLACK);
//        DrawText("MP recovery", 600, 480, 20, BLACK);
//        DrawText("Item", 600, 500, 20, BLACK);
//        DrawText("Shouldering another's debt", 600, 520, 20, BLACK);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}