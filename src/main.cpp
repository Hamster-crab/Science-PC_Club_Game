#include "raylib.h"
#include <iostream>

int main()
{
    const int Width = 200;
    const int Height = 200;
    // Load the image
    Image titleImage = LoadImage("resources/Satos/Title/TitleSato.jpg");


    ImageResize(&titleImage, Width, Height);

    // Initialize the window
    InitWindow(900, 600, "TNTN");

    Font fonts = LoadFont("/fonts/setback.png");

    // Convert the image to a texture
    Texture2D titleTexture = LoadTextureFromImage(titleImage);

    // Unload the image as it's no longer needed
//    UnloadImage(titleImage);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        // 文字の描画
        DrawText("TNTN", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    // Unload the texture before closing the window
    UnloadTexture(titleTexture);
    CloseWindow();

    return 0;
}