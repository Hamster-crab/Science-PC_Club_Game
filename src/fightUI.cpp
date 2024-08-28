#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib [Core] Example - Draw Square");
    SetTargetFPS(60);

    double MPDefault = 1000.0;
    double MPDefaultMax = 1145148101919.0;
    double playerMPMax = 1000.0;
    double playerMP = 1000.0;

    double bossHPDefault = 114514.0;
    double bossHP = 114514.0;
    double bossMPDefault = 114514.0;
    double bossMP = 114514.0;

    double satoOneHP = 100.0;
    double satoOneHPDefault = 100.0;
    double satoOneMPDefault = 30.0;
    double satoOneMP = 810.0;
    double satoOneMPMax = 810.0;

    double satoTwoHP = 50.0;
    double satoTwoHPDefault = 50.0;
    double satoTwoMPDefault = 30.0;
    double satoTwoMP = 40.0;
    double satoTwoMPMax = 40.0;

    double playerHeartsMax = 20.0;
    double playerHeart = 20.0;

    Image summonSatoOneTextureTexture = LoadImage("resources/Partner-Sato/GanGimariSato.png");
    Image summonSatoTwoTextureTexture = LoadImage("resources/Partner-Sato/SatoSeenFromAbove.png");
    Image bossTextureTexture = LoadImage("resources/Bosses/faceOfBroccoli/material/hand.png");

    ImageResize(&summonSatoOneTextureTexture, 100, 100);
    ImageResize(&summonSatoTwoTextureTexture, 100, 100);
    ImageResize(&bossTextureTexture, 300, 300);

    Texture2D summonSatoOneTexture = LoadTextureFromImage(summonSatoOneTextureTexture);
    Texture2D summonSatoTwoTexture = LoadTextureFromImage(summonSatoTwoTextureTexture);
    Texture2D bossTexture = LoadTextureFromImage(bossTextureTexture);


    // 不要なイメージデータを解放
    UnloadImage(summonSatoOneTextureTexture);
    UnloadImage(summonSatoTwoTextureTexture);
    UnloadImage(bossTextureTexture);


    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(690, 7, 200, 110, BLUE);
        DrawRectangle(700, 10, satoOneHPDefault, 10, RED);
        DrawRectangle(700, 10, satoOneHP, 10, YELLOW);
//        DrawText("20/20", 820, 10, 10, BLACK);
        DrawRectangle(700, 20, satoOneMP / 80, 10, DARKPURPLE);
        DrawText("Attack", 750, 38, 20, BLACK);
        DrawText("MP recovery", 750, 58, 20, BLACK);
        DrawText("Item", 750, 78, 20, BLACK);
        DrawText("Shield", 750, 98, 20, BLACK);
        DrawTexture(summonSatoOneTexture, 585, 13, WHITE);

        DrawRectangle(690, 150, 200, 110, BLUE);
        DrawRectangle(700, 154, satoTwoHPDefault, 10, RED);
        DrawRectangle(700, 154, satoTwoHP, 10, YELLOW);
//        DrawText("20/20", 820, 10, 10, BLACK);
        DrawRectangle(700, 164, satoTwoMP, 10, DARKPURPLE);
        DrawText("Attack", 750, 180, 20, BLACK);
        DrawText("MP recovery", 750, 200, 20, BLACK);
        DrawText("Item", 750, 220, 20, BLACK);
        DrawText("Shield", 750, 240, 20, BLACK);
        DrawTexture(summonSatoTwoTexture, 585, 158, WHITE);


        DrawRectangle(10, 10, 50, 580, BLUE);
        DrawRectangle(13, 15, 20, 570, YELLOW);
        DrawRectangle(35, 15, 20, 570, DARKPURPLE);
        DrawTexture(bossTexture, 30, 100, WHITE);




//        DrawRectangle(555, 425, 335, 120, BLUE);
//        DrawRectangle(600, 435, playerHeart * 3, 20, YELLOW);
//        DrawText("20/20", 670, 435, 20, BLACK);
//        DrawRectangle(750, 435, playerMP / 80, 20, RED);
//        DrawRectangle(750, 435, playerMP / 80, 20, DARKPURPLE);
//        DrawText("Attack", 600, 460, 20, BLACK);
//        DrawText("MP recovery", 600, 480, 20, BLACK);
//        DrawText("Item", 600, 500, 20, BLACK);
//        DrawText("Shouldering another's debt", 600, 520, 20, BLACK);


        // 外側の矩形 (枠線)
        DrawRectangle(300, 200, 250, 250, BLACK);

        // 内側の矩形 (背景色)
        DrawRectangle(305, 205, 240, 240, DARKPURPLE);  // 枠線の太さは5ピクセル

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}