#include "raylib.h"

int main(void)
{
    int screenWidth = 900;
    int screenHeight = 600;
    int backgroundX, backgroundY = 0;
    int playerSpeed = 8;
    int playerHeartsMax = 20;
    int playerHearts = 20;

    // ウィンドウの初期化
    InitWindow(screenWidth, screenHeight, "raylib - Background Image Example");

    // 背景画像のロード
    Texture2D background = LoadTexture("resources/Textures/OverWorld/maptile_grasslands_one.png");  // 背景画像のパス

    Image playerTextureTexture = LoadImage("resources/Textures/Beef.png");

    int playerWidth = 45;
    int playerHeight = 30;
    // 画像サイズを変更
    ImageResize(&playerTextureTexture, playerWidth, playerHeight);

    // テクスチャに変換
    Texture2D playerTexture = LoadTextureFromImage(playerTextureTexture);

    Image playerHeartsImageImage = LoadImage("resources/Textures/playerHeart.png");

    // 画像サイズを変更
    ImageResize(&playerHeartsImageImage, 30, 30);


    // テクスチャに変換
    Texture2D playerHeartsImage = LoadTextureFromImage(playerHeartsImageImage);

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
        if (IsKeyDown(KEY_D)) playerPosition.x += playerSpeed;
        if (IsKeyDown(KEY_A)) playerPosition.x -= playerSpeed;
        if (IsKeyDown(KEY_W)) playerPosition.y -= playerSpeed;
        if (IsKeyDown(KEY_S)) playerPosition.y += playerSpeed;
        // プレイヤーの位置を更新
        if (IsKeyDown(KEY_RIGHT)) playerPosition.x += playerSpeed;
        if (IsKeyDown(KEY_LEFT)) playerPosition.x -= playerSpeed;
        if (IsKeyDown(KEY_UP)) playerPosition.y -= playerSpeed;
        if (IsKeyDown(KEY_DOWN)) playerPosition.y += playerSpeed;

        if (IsKeyDown(KEY_ESCAPE)) break;

        playerWidth = playerWidth - 200;
        // カメラのターゲットをプレイヤーの位置に設定
        camera.target = playerPosition;

            // 描画の開始
            BeginDrawing();

        // 背景色の設定（画像が描画される前に）
        ClearBackground(RAYWHITE);

        // カメラの描画開始
        BeginMode2D(camera);

        // 画像を描画（画面全体に表示するため、画像のサイズをウィンドウサイズに合わせる）
        DrawTexture(background, backgroundX, backgroundY, WHITE);

////        横
//
////      左
//        DrawTexture(background, backgroundX + 500, backgroundY, WHITE);
//        DrawTexture(background, backgroundX + ( 500 / 2 ), backgroundY, WHITE);
//
////      下
//        DrawTexture(background, backgroundX, backgroundY + ( 500 / 2 ), WHITE);
//
////      右
//        DrawTexture(background, backgroundX - ( 500 * 2 ), backgroundY, WHITE);
//
////        上
//        DrawTexture(background, backgroundX, backgroundY - ( 500 * 2 ), WHITE);



        // プレイヤーを描画
        DrawTexture(playerTexture, playerPosition.x, playerPosition.y, WHITE);

        int playerHeartsPositionXOne = playerPosition.x - 440;
        int playerHeartsPositionXTwo = playerPosition.x - 406;
        int playerHeartsPositionXThree = playerPosition.x - 372;
        int playerHeartsPositionXFour = playerPosition.x - 338;
        int playerHeartsPositionXFive = playerPosition.x - 304;
        int playerHeartsPositionXSix = playerPosition.x - 270;
        int playerHeartsPositionXSeven = playerPosition.x - 236;
        int playerHeartsPositionXEight = playerPosition.x - 202;
        int playerHeartsPositionXNine = playerPosition.x - 168;
        int playerHeartsPositionXTen = playerPosition.x - 134;
//        int playerHeartsPositionXEleven = playerPosition.x - 100;
//        int playerHeartsPositionXTwelve = playerPosition.x - 66;
//        int playerHeartsPositionXThirteen = playerPosition.x - 32;
//        int playerHeartsPositionXFourteen = playerPosition.x + 2;
//        int playerHeartsPositionXFifteen = playerPosition.x + 36;
//        int playerHeartsPositionXSixteen = playerPosition.x + 70;
//        int playerHeartsPositionXSeventeen = playerPosition.x + 104;
//        int playerHeartsPositionXEighteen = playerPosition.x + 138;
//        int playerHeartsPositionXNineteen = playerPosition.x + 172;
//        int playerHeartsPositionXTwenty = playerPosition.x + 206;
        int playerHeartsPositionY = playerPosition.y + 250;

        // ハート
        DrawTexture(playerHeartsImage, playerHeartsPositionXOne, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXTwo, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXThree, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXFour, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXFive, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXSix,playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXSeven, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXEight, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXNine, playerHeartsPositionY, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXTen, playerHeartsPositionY, WHITE);

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
