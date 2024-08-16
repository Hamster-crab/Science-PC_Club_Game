#include "raylib.h"

int main(void)
{
    int playerX, playerY = 0;
    // ウィンドウの初期化
    InitWindow(800, 600, "raylib - Background Image Example");

    // 背景画像のロード
    Texture2D background = LoadTexture("resources/Textures/OverWorld/maptile_grasslands_one.png");  // 背景画像のパス

    Image playerImage = LoadImage("resources/Textures/OverWorld/player.png");  // プレイヤー画像のパス
    Texture2D playerTexture = LoadTextureFromImage(playerImage);

    // 画像のメモリ解放
    UnloadImage(playerImage);


    SetTargetFPS(60);


    // メインループ
    while (!WindowShouldClose())
    {
        // 描画の開始
        BeginDrawing();

        // 背景色の設定（画像が描画される前に）
        ClearBackground(RAYWHITE);

        // 画像を描画（画面全体に表示するため、画像のサイズをウィンドウサイズに合わせる）
        DrawTexture(background, 0, 0, WHITE);

        // プレイヤー画像の描画
        DrawTexture(playerTexture, 300, 230, WHITE);


        // 描画の終了
        EndDrawing();
    }

    // 画像のアンロード
    UnloadTexture(background);
    UnloadTexture(background);
    UnloadTexture(playerTexture);

    // ウィンドウを閉じる
    CloseWindow();

    return 0;
}
// Test
