#include "raylib.h"
#include "../include/player.h"

using namespace Player;

int main(void)
{
    // ウィンドウの初期化
    InitWindow(800, 600, "raylib - Background Image Example");

    // 背景画像のロード
    Texture2D background = LoadTexture("resources/Textures/OverWorld/maptile_grasslands_one.png");  // 背景画像のパス

    // メインループ
    while (!WindowShouldClose())
    {
        // 描画の開始
        BeginDrawing();

        // 背景色の設定（画像が描画される前に）
        ClearBackground(RAYWHITE);

        // 画像を描画（画面全体に表示するため、画像のサイズをウィンドウサイズに合わせる）
        DrawTexture(background, 0, 0, WHITE);

        DrawTexture(Player::player, 0, 0, WHITE);

        // 描画の終了
        EndDrawing();
    }

    // 画像のアンロード
    UnloadTexture(background);

    // ウィンドウを閉じる
    CloseWindow();

    return 0;
}
