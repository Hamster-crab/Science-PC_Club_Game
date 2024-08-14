#include "raylib.h"

int main(void)
{
    // ウィンドウの初期化
    InitWindow(800, 600, "");

    // ボタンの位置とサイズ
    Rectangle buttonRec = { 350, 250, 100, 50 };
    Color buttonColor = LIGHTGRAY;
    Color buttonHoverColor = GRAY;
    Color buttonPressedColor = DARKGRAY;

    // メインループ
    while (!WindowShouldClose())
    {
        // マウスの状態を取得
        Vector2 mousePoint = GetMousePosition();
        bool mouseOnButton = CheckCollisionPointRec(mousePoint, buttonRec);

        // 描画の開始
        BeginDrawing();

        // 背景色の設定
        ClearBackground(RAYWHITE);

        // ボタンの色を設定
        if (mouseOnButton)
        {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                buttonColor = buttonPressedColor;
            else
                buttonColor = buttonHoverColor;
        }
        else
        {
            buttonColor = LIGHTGRAY;
        }

        // ボタンを描画
        DrawRectangleRec(buttonRec, buttonColor);

        // ボタンのテキストを描画
        DrawText("Click Me!", 365, 265, 20, BLACK);

        // 描画の終了
        EndDrawing();
    }

    // ウィンドウを閉じる
    CloseWindow();

    return 0;
}
