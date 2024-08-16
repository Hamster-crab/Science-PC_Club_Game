#include "raylib.h"

int main()
{
    // ウィンドウの初期化
    InitWindow(900, 600, "Sato who came to let us know of his love");

    // 背景画像のロード
    Texture background = LoadTexture("resources/Textures/Beef.png");  // 背景画像のパス

    // メインループ
    while (!WindowShouldClose())
    {
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


        // 描画の終了
        EndDrawing();
    }

    // 画像のアンロード
    UnloadTexture(background);

    // ウィンドウを閉じる
    CloseWindow();

    return 0;
}