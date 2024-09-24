#include "raylib.h"
#include <cstdlib>

int main()
{
    int screenWidth = 900;
    int screenHeight = 600;
    // ウィンドウの初期化
    InitWindow(screenWidth, screenHeight, "Sato who came to let us know of his love");

    // 背景画像のロード
    Texture background = LoadTexture("resources/Textures/Beef.png");  // 背景画像のパス

    int titleButtonWidth = screenWidth / 2 - 50;

    // start
    Rectangle startButton = { static_cast<float>(titleButtonWidth), static_cast<float>(screenHeight - 390), 100, 40 };
    Color startButtonColor = DARKGRAY;
    bool startButtonPressed = false;

    // settings
    Rectangle settingsButton = { static_cast<float>(titleButtonWidth), static_cast<float>(screenHeight - 290), 100, 40 };
    Color settingsButtonColor = DARKGRAY;
    bool settingsButtonPressed = false;

    // end
    Rectangle endButton = { static_cast<float>(titleButtonWidth), static_cast<float>(screenHeight - 180), 100, 40 };
    Color endButtonColor = DARKGRAY;
    bool endButtonPressed = false;

    // メインループ
    while (!WindowShouldClose())
    {

        // buttonのいろ
        // start
        Vector2 mousePoint = GetMousePosition();
        if (CheckCollisionPointRec(mousePoint, startButton))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                startButtonColor = LIGHTGRAY;
            }
            else
            {
                startButtonColor = GRAY;
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                startButtonPressed = true;
            }
        }
        else
        {
            startButtonColor = DARKGRAY;
        }

        // settings
        if (CheckCollisionPointRec(mousePoint, settingsButton))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                settingsButtonColor = LIGHTGRAY;
            }
            else
            {
                settingsButtonColor = GRAY;
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                settingsButtonPressed = true;
            }
        }
        else
        {
            settingsButtonColor = DARKGRAY;
        }

        // end
        if (CheckCollisionPointRec(mousePoint, endButton))
        {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            {
                endButtonColor = LIGHTGRAY;
            }
            else
            {
                endButtonColor = GRAY;
            }

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
            {
                endButtonPressed = true;
            }
        }
        else
        {
            endButtonColor = DARKGRAY;
        }


        // 描画の開始
        BeginDrawing();

        // 背景色の設定（画像が描画される前に）
        ClearBackground(RAYWHITE);

        // 画像のサイズを 900x600 にしてウィンドウの中央に表示
        Vector2 center = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
        DrawTexturePro(background, (Rectangle){ 0, 0, (float)background.width, (float)background.height },
                       (Rectangle){ center.x - 450, center.y - 300, 900, 600 }, (Vector2){ 0, 0 }, 0.0f, WHITE);

        // テキストのレンダリング（フォントサイズを調整）
        DrawText("Sato who came to let us know of his love", 33, 69, 40, PINK);  // fontSize を 30 に設定

        // startButtonDraw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(startButton, startButtonColor);
        DrawText("Start", startButton.x + 20, startButton.y + 10, 23, BLACK);

        // ゲームウィンドウ
        if (startButtonPressed)
        {
            #ifdef _WIN32
                system("inm.exe"); // Windows の場合
            #else
                system("./battle"); // Linux または macOS の場合
            #endif
        }

        // settingsButtonDraw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(settingsButton, settingsButtonColor);
        DrawText("Settings", settingsButton.x + 20, settingsButton.y + 10, 23, BLACK);
        if (settingsButtonPressed)
        {
            UnloadTexture(background);

            // Create a new window
            InitWindow(screenWidth, screenHeight, "Settings");

            // Draw something in the new window
            while (!WindowShouldClose())
            {
                BeginDrawing();
                ClearBackground(LIGHTGRAY);
                EndDrawing();
            }

            // Close the new window
            CloseWindow();
        }

        // endButtonDraw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawRectangleRec(endButton, endButtonColor);
        DrawText("End", endButton.x + 20, endButton.y + 10, 23, BLACK);

        if (endButtonPressed)
        {
            break;
        }

        // 描画の終了
        EndDrawing();
    }

    // 画像のアンロード
    UnloadTexture(background);

    // ウィンドウを閉じる
    CloseWindow();

    return 0;
}
