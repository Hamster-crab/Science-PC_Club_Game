#include "raylib.h"

int main(void)
{
    int playerX, playerY = 0;
    int screenWidth = 900;
    int screenHeight = 600;

    // ウィンドウの初期化
    InitWindow(screenWidth, screenHeight, "raylib - Background Image Example");

    // 背景画像のロード
    Texture2D background = LoadTexture("resources/Textures/OverWorld/maptile_grasslands_one.png");  // 背景画像のパス

    Texture2D playerTexture = LoadTexture("resources/Textures/Beef.png");  // プレイヤー画像のパス

    // プレイヤーの初期設定
    Vector2 playerPosition = { screenWidth / 2.0f - playerTexture.width / 2.0f, screenHeight / 2.0f - playerTexture.height / 2.0f };

    // カメラの初期設定
    Camera2D camera = { 0 };
    camera.target = playerPosition;
    camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);


    // メインループ
    while (!WindowShouldClose())
    {

        // プレイヤーの位置を更新
        if (IsKeyDown(KEY_D)) playerPosition.x += 3.0f;
        if (IsKeyDown(KEY_A)) playerPosition.x -= 3.0f;
        if (IsKeyDown(KEY_W)) playerPosition.y -= 3.0f;
        if (IsKeyDown(KEY_S)) playerPosition.y += 3.0f;

        // カメラのターゲットをプレイヤーの位置に設定
        camera.target = playerPosition;

        // プレイヤーが壁にあたったかどうかをチェック
        if (playerPosition.x < 0 || playerPosition.x + playerTexture.width > screenWidth ||
            playerPosition.y < 0 || playerPosition.y + playerTexture.height > screenHeight)
        {
            // 画像を描画（画面全体に表示するため、画像のサイズをウィンドウサイズに合わせる）
            DrawTexture(background, 500, 0, WHITE);
            DrawTexture(background, 0, 500, WHITE);
        }
        // プレイヤーが壁にあたったかどうかをチェック
        else if (playerPosition.y < 0 || playerPosition.y + playerTexture.height > screenHeight ||
            playerPosition.x < 0 || playerPosition.x + playerTexture.width > screenWidth)
        {
            // 画像を描画（画面全体に表示するため、画像のサイズをウィンドウサイズに合わせる）
            DrawTexture(background, 0, playerPosition.y + 500, WHITE);
            DrawTexture(background,  playerPosition.x + 500, 0, WHITE);
        }

            // 描画の開始
            BeginDrawing();

        // 背景色の設定（画像が描画される前に）
        ClearBackground(RAYWHITE);

        // カメラの描画開始
        BeginMode2D(camera);

        // 画像を描画（画面全体に表示するため、画像のサイズをウィンドウサイズに合わせる）
        DrawTexture(background, 0, 0, WHITE);

        // プレイヤーを描画
        DrawTexture(playerTexture, playerPosition.x, playerPosition.y, WHITE);

        // カメラの描画終了
        EndMode2D();

        // 描画の終了
        EndDrawing();
    }

    // 画像のアンロード
    UnloadTexture(background);
    UnloadTexture(background);

    // ウィンドウを閉じる
    CloseWindow();

    return 0;
}
// Test
