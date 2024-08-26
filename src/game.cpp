#include "raylib.h"

int main(void)
{
    int screenWidth = 900;
    int screenHeight = 600;
    int backgroundX = backgroundX - 770;
    int backgroundY = backgroundY - 970;
    int playerSpeed = 8;
    int playerHeartsMax = 20;
    int playerHearts = 20;

    // ウィンドウの初期化
    InitWindow(screenWidth, screenHeight, "raylib - Background Image Example");

    // 背景画像のロード
    Texture2D background = LoadTexture("resources/Textures/OverWorld/maptile_grasslands_one.png");  // 背景画像のパス

    Image playerTextureTexture = LoadImage("resources/Textures/playerImage.png");
    Image playerHeartsImageImage = LoadImage("resources/Textures/playerHeart.png");
    Image playerFullStomachImageImage = LoadImage("resources/Textures/Beef.png");
    Image playerWaterFullImageImage = LoadImage("resources/Textures/Water-full.png");

    int playerWidth = 150;
    int playerHeight = 200;
    // 画像サイズを変更
    ImageResize(&playerTextureTexture, playerWidth, playerHeight);
    ImageResize(&playerHeartsImageImage, 30, 30);
    ImageResize(&playerFullStomachImageImage, 30, 30);
    ImageResize(&playerWaterFullImageImage, 30, 30);

    // テクスチャに変換
    Texture2D playerTexture = LoadTextureFromImage(playerTextureTexture);
    Texture2D playerHeartsImage = LoadTextureFromImage(playerHeartsImageImage);
    Texture2D playerFullStomachImage = LoadTextureFromImage(playerFullStomachImageImage);
    Texture2D playerWaterFullImage = LoadTextureFromImage(playerWaterFullImageImage);


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

        // プレイヤーを描画
        DrawTexture(playerTexture, playerPosition.x -100, playerPosition.y - 100, WHITE);

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

        int playerFullStomachPositionXOne = playerPosition.x + 75;
        int playerFullStomachPositionXTwo = playerPosition.x + 113;
        int playerFullStomachPositionXThree = playerPosition.x + 146;
        int playerFullStomachPositionXFour = playerPosition.x + 179;
        int playerFullStomachPositionXFive = playerPosition.x + 217;
        int playerFullStomachPositionXSix = playerPosition.x + 255;
        int playerFullStomachPositionXSeven = playerPosition.x + 293;
        int playerFullStomachPositionXEight = playerPosition.x + 331;
        int playerFullStomachPositionXNine = playerPosition.x + 369;
        int playerFullStomachPositionXTen = playerPosition.x + 407;



        int playerHeartsPositionYOne = playerPosition.y + 260;
        int playerHeartsPositionYTwo = playerPosition.y + 210;
        int playerFullStomachPositionY = playerPosition.y + 260;
        int playerWaterFullPositionY = playerPosition.y + 480;

        // ハート
        DrawTexture(playerHeartsImage, playerHeartsPositionXOne, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXTwo, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXThree, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXFour, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXFive, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXSix,playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXSeven, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXEight, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXNine, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXTen, playerHeartsPositionYOne, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXOne, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXTwo, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXThree, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXFour, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXFive, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXSix, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXSeven, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXEight, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXNine, playerHeartsPositionYTwo, WHITE);
        DrawTexture(playerHeartsImage, playerHeartsPositionXTen, playerHeartsPositionYTwo, WHITE);

        // 飯ゲージ
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXOne, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXTwo, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXThree, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXFour, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXFive, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXSix, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXSeven, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXEight, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXNine, playerFullStomachPositionY, WHITE);
        DrawTexture(playerFullStomachImage, playerFullStomachPositionXTen, playerFullStomachPositionY, WHITE);

        // 水ゲージ(満タン)
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXOne, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXTwo, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXThree, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXFour, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXFive, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXSix, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXSeven, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXEight, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXNine, playerWaterFullPositionY, WHITE);
        DrawTexture(playerWaterFullImage, playerFullStomachPositionXTen, playerWaterFullPositionY, WHITE);



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
