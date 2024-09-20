#include "raylib.h"
#include <string>
#include <sstream>

int main(void)
{
    int screenWidth = 900;
    int screenHeight = 600;
    int backgroundX = 375;
    int backgroundY = -63;
    int playerSpeed = 8;
    int playerDryThroat = 20;
    double playerHeartsMax = 40.0;
    double playerHeartsDefault = 20.0;
    double playerHearts = 20.0;
    double playerMP = 200.0;
    double playerMPDefault = 200.0;
    double playerMPMax = 1000.0;

    // ウィンドウの初期化
    InitWindow(screenWidth, screenHeight, "raylib - Background Image Example");
    SetTargetFPS(60);

    // オーディオデバイスを初期化
    InitAudioDevice();

    // 背景画像のロード
    Image backgroundImage = LoadImage("resources/Nomal-World/GameMap.png");  // 背景画像のパス
    Image playerTextureTexture = LoadImage("resources/Textures/player/playerImage.png");
    Image playerFullStomachImageImage = LoadImage("resources/Textures/Beef.png");
    Image playerWaterFullImageImage = LoadImage("resources/Textures/Water-Full.png");
    Image playerWaterHalfImageImage = LoadImage("resources/Textures/Water-Half.png");
    Image playerWaterEmptyImageImage = LoadImage("resources/Textures/Water-Empty.png");

    int playerWidth = 150;
    int playerHeight = 200;
    // 画像サイズを変更
    ImageResize(&playerTextureTexture, playerWidth, playerHeight);
    ImageResize(&playerFullStomachImageImage, 30, 30);
    ImageResize(&playerWaterFullImageImage, 30, 30);
    ImageResize(&playerWaterHalfImageImage, 30, 30);
    ImageResize(&playerWaterEmptyImageImage, 30, 30);
    ImageResize(&backgroundImage, 9000, 9000);

    // テクスチャに変換
    Texture2D playerTexture = LoadTextureFromImage(playerTextureTexture);
    Texture2D playerFullStomachImage = LoadTextureFromImage(playerFullStomachImageImage);
    Texture2D playerWaterFullImage = LoadTextureFromImage(playerWaterFullImageImage);
    Texture2D playerWaterHalfImage = LoadTextureFromImage(playerWaterHalfImageImage);
    Texture2D playerWaterEmptyImage = LoadTextureFromImage(playerWaterEmptyImageImage);
    Texture2D background = LoadTextureFromImage(backgroundImage);

    Music mainBGM = LoadMusicStream("music/mainBGM.mp3");
    // 音楽の再生を開始
    PlayMusicStream(mainBGM);

    // プレイヤーの初期設定
    Vector2 playerPosition = { screenWidth / 2.0f - playerTexture.width / 2.0f, screenHeight / 2.0f - playerTexture.height / 2.0f };

    // カメラの初期設定
    Camera2D camera = { 0 };
    camera.target = playerPosition;
    camera.offset = (Vector2){ screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;


    // メインループ
    while (!WindowShouldClose())
    {
        // 音楽ストリームを更新
        UpdateMusicStream(mainBGM);
        if (IsKeyDown(KEY_Y))
        {
            if (playerMP > 50.0)
            {
                if (playerHearts < playerHeartsDefault)
                {
                    playerMP -= 50.0;
                    if (playerHeartsDefault > 1)
                    {
                        playerHearts += 0.5;
                    }

                }
            }
        }
        else if (IsKeyUp(KEY_Y))
        {
            if (playerMPDefault > playerMP)
            {
                playerMP += 1.0;
            }
        }

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
        DrawTexture(background, -5000, -5000, WHITE); // 中央

        // プレイヤーを描画
        DrawTexture(playerTexture, playerPosition.x -100, playerPosition.y - 100, WHITE);

        int playerHeartsPositionXOne = playerPosition.x - 440;
        int playerHeartsPositionXFour = playerPosition.x - 338;

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
        int playerWaterFullPositionY = playerPosition.y + 220;

        // ハート

        // 変数を表示するための文字列を生成
        std::ostringstream playerHeartsOutput;
        playerHeartsOutput << playerHearts << " / " << playerHeartsDefault;
        std::string playerHeartsText = playerHeartsOutput.str();

        // 変数を表示するための文字列を生成
        std::ostringstream playerMPOutput;
        playerMPOutput << playerMP << "/" << playerMPDefault;
        std::string playerMPText = playerMPOutput.str();

        // playerのxy表示
        std::ostringstream playerXY;
        playerXY << "X : " << playerPosition.x << "\n\n" << "Y : " << playerPosition.y;
        std::string playerXYText = playerXY.str();

        DrawText(playerHeartsText.c_str(), playerHeartsPositionXOne, playerHeartsPositionYOne, 20, BLACK);  // 変数の内容を表示
        DrawText(playerXYText.c_str(), playerHeartsPositionXOne, playerHeartsPositionYOne - 550, 20, BLACK);  // playerのxy表示

        DrawRectangle(playerHeartsPositionXFour, playerHeartsPositionYOne, playerHeartsDefault * 12, 20, RED);
        DrawRectangle(playerHeartsPositionXFour, playerHeartsPositionYOne, playerHearts * 12, 20, YELLOW);

        DrawText(playerMPText.c_str(), playerHeartsPositionXOne, playerHeartsPositionYOne - 30, 20, BLACK);  // 変数の内容を表示
        DrawRectangle(playerHeartsPositionXFour, playerHeartsPositionYOne - 30, playerMPDefault / 3, 20, RED);
        DrawRectangle(playerHeartsPositionXFour, playerHeartsPositionYOne - 30, playerMP / 3, 20, DARKPURPLE);

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

        // 水ゲージ
        if (playerDryThroat == 20)
        {
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
        }

        if (IsKeyPressed(KEY_E))
        {
            DrawRectangle(playerPosition.x, playerPosition.y, 500, 300, GRAY);
        }

        // カメラの描画終了
        EndMode2D();

        // 描画の終了
        EndDrawing();
    }

    // 画像のアンロード
    UnloadTexture(background);
    // ウィンドウを閉じる
    CloseWindow();

    return 0;
}
// Test
