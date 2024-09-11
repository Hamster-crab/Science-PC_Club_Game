#include <sstream>
#include <string>
#include "raylib.h"

namespace attack
{
    Rectangle attackRect = { 205, 305, 50, 50 };

    Rectangle attackRectTwo = { 400, 500, 50, 50 };

    Rectangle attackRectThree = { 605, 300, 50, 50 };

    Rectangle attackRectFour = { 400, 70, 50, 50 };

    void damage(Music damageBGM, double hpOne, double hpTwo, Rectangle playerRect)
    {
        UpdateMusicStream(damageBGM);
        // 当たり判定
        if (CheckCollisionRecs(playerRect, attackRect))
        {
            hpOne -= 1.0;
        }
        // 当たり判定
        if (CheckCollisionRecs(playerRect, attackRectTwo))
        {
            hpOne -= 1.0;
        }
        // 当たり判定
        if (CheckCollisionRecs(playerRect, attackRectThree))
        {
            hpOne -= 1.0;
        }
        // 当たり判定
        if (CheckCollisionRecs(playerRect, attackRectFour))
        {
            hpOne -= 1.0;
        }
    }
    void testAttack(Texture2D texture)
    {
        double currentTime = GetTime(); // 現在の時刻を取得
            double startTime = GetTime(); // 開始時刻を取得
        // 2秒経過したかをチェック
        if (currentTime - startTime >= 0.3)
        {
            attackRect.x += 5;
            attackRectTwo.y -= 5;
            attackRectThree.x -= 5;
            attackRectFour.y += 5;
        }
        DrawTexture(texture, attackRect.x, attackRect.y, WHITE);
        DrawTexture(texture, attackRectTwo.x, attackRectTwo.y, WHITE);
        DrawTexture(texture, attackRectThree.x, attackRectThree.y, WHITE);
        DrawTexture(texture, attackRectFour.x, attackRectFour.y, WHITE);
    }
}

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "rainbowPuiPui");
    SetTargetFPS(60);

    // オーディオデバイスを初期化
    InitAudioDevice();

    int nextAttack = 0;

    bool shieldOF = true;
    double shield = 300;
    double shieldX = 700;

    int turn = 1;

    int outerFrameX = 300;
    int outerFrameY = 200;
    int innerFrameX = 305;
    int innerFrameY = 205;

    int outerFrameWidth = 250;
    int outerFrameHeight = 250;
    
    int innerFrameWidth = 240;
    int innerFrameHeight = 240;

    double MPDefault = 1000.0;
    double MPDefaultMax = 1145148101919.0;
    double playerMPMax = 1000.0;
    double playerMP = 1000.0;

    double startTime = GetTime(); // 開始時刻を取得

    double bossHPDefault = 114514.0;

    double bossHP = 114514.0;
    double bossMPDefault = 114514.0;
    double bossMP = 114514.0;

    double satoOneHP = 100.0;
    double satoOneHPDefault = 100.0;
    double satoOneMPDefault = 1000.0;
    double satoOneMP = 1000.0;
    double satoOneMPMax = 10000.0;
    int satoOneShield = 0;

    double satoTwoHP = 50.0;
    double satoTwoHPDefault = 50.0;
    double satoTwoMPDefault = 10000.0;
    double satoTwoMP = 10000.0;
    double satoTwoMPMax = 1000000.0;
    int satoTwoShield = 0;

    double playerHPMax = 100.0;
    double playerHPDefault = 20.0;
    double playerHP = 20.0;
    double playerPositionX = 405.0;
    double playerPositionY = 305.0;
// X 405 Y 305

    Music sampleBGM = LoadMusicStream("music/sampleBGM.mp3");
    Music damageBGM = LoadMusicStream("music/damageBGM.mp3");
    Music deathBGM = LoadMusicStream("music/deathBGM.mp3");
    float mainVolume = 0.2f;
    float damageVolume = 10.0f;

    SetMusicVolume(sampleBGM, mainVolume);
    SetMusicVolume(damageBGM, damageVolume);

    // 音楽の再生を開始
    PlayMusicStream(sampleBGM);
    PlayMusicStream(damageBGM);
    PlayMusicStream(deathBGM);

    Image summonSatoOneTextureTexture = LoadImage("resources/hamster/dededon.png");
    Image summonSatoTwoTextureTexture = LoadImage("resources/hamster/waterBug.png");
    Image bossTextureTexture = LoadImage("resources/Bosses/faceOfBroccoli/material/hand.png");
    Image attackTextureTexture = LoadImage("resources/Textures/boiled_egg.png");
    Image playerTextureTexture = LoadImage("resources/Textures/player/playerImage.png");
    Image playerTextureGreenTexture = LoadImage("resources/Textures/Beef.png");

    ImageResize(&summonSatoOneTextureTexture, 100, 100);
    ImageResize(&summonSatoTwoTextureTexture, 100, 100);
    ImageResize(&bossTextureTexture, 300, 300);
    ImageResize(&attackTextureTexture, 50, 50);
    ImageResize(&playerTextureTexture, 18, 18);
    ImageResize(&playerTextureGreenTexture, 18, 18);

    Texture2D summonSatoOneTexture = LoadTextureFromImage(summonSatoOneTextureTexture);
    Texture2D summonSatoTwoTexture = LoadTextureFromImage(summonSatoTwoTextureTexture);
    Texture2D bossTexture = LoadTextureFromImage(bossTextureTexture);
    Texture2D attackTexture = LoadTextureFromImage(attackTextureTexture);
    Texture2D playerTexture = LoadTextureFromImage(playerTextureTexture);
    Texture2D playerTextureGreen = LoadTextureFromImage(playerTextureGreenTexture);

    // 不要なイメージデータを解放
    UnloadImage(summonSatoOneTextureTexture);
    UnloadImage(summonSatoTwoTextureTexture);
    UnloadImage(bossTextureTexture);
    UnloadImage(attackTextureTexture);
    UnloadImage(playerTextureTexture);
    UnloadImage(playerTextureGreenTexture);

    Rectangle playerRect = { static_cast<float>(playerPositionX), static_cast<float>(playerPositionY), 30, 30 };

    while (!WindowShouldClose())
    {
        if (satoOneHP == 0 && satoTwoHP == 0)
        {
            BeginDrawing();

            ClearBackground(RAYWHITE);

            UpdateMusicStream(deathBGM);
            DrawText("Game Over", 190, 200, 20, BLACK);

            EndDrawing();
        }
        else if (bossHP < 0)
        {
            BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("You Win   Fuckyou", 190, 200, 20, BLACK);

            EndDrawing();
        }
        else
        {
            UpdateMusicStream(sampleBGM);
            double currentTime = GetTime(); // 現在の時刻を取得
            // プレイヤーの位置を更新
            if (playerPositionY == 40)
            {
                if (IsKeyDown(KEY_DOWN)) playerPositionY += 0.0000001;
                if (IsKeyDown(KEY_S))
                {}
            }
            else if (playerPositionY == 98)
            {
                if (IsKeyDown(KEY_UP))
                {}
                if (IsKeyDown(KEY_W))
                {}
            }

            else
            {
                if (IsKeyDown(KEY_W)) playerPositionY -= 5;
                if (IsKeyDown(KEY_A)) playerPositionX -= 5;
                if (IsKeyDown(KEY_S)) playerPositionY += 5;
                if (IsKeyDown(KEY_D)) playerPositionX += 5;
                if (IsKeyDown(KEY_UP)) playerPositionY -= 5;
                if (IsKeyDown(KEY_DOWN)) playerPositionY += 5;
                if (IsKeyDown(KEY_RIGHT)) playerPositionX += 5;
                if (IsKeyDown(KEY_LEFT)) playerPositionX -= 5;
            }

            if (shieldOF)
            {
                if (IsKeyDown(KEY_SPACE))
                {
                    if (shield == 0 && shieldX == 0)
                    {}
                    else
                    {
                        shieldX += 1.7;
                        shield -= 6;
                    }
                }
            }
            if (shield == 300 && shieldX == 700)
            {}
            else
            {
                if (IsKeyUp(KEY_SPACE))
                {
                    shieldX -= 1.7;
                    shield += 6;
                }
            }
                       

            if (currentTime - startTime >= 0.0000001)
            {
                double currentTime = GetTime(); // 現在の時刻を取得
                if (currentTime - startTime >= 2.0)
                {
                    if (satoOneMP < satoOneMPDefault)
                    {
                        satoOneMP += 10;
                    } else if (satoOneMP == satoOneMPDefault && satoTwoMP == satoTwoMPDefault)
                    {}
                    else if (satoTwoMP < satoTwoMPDefault)
                    {
                        satoTwoMP += 10;
                    }
                }
            }
            // プレイヤーが枠の外に出ないように制限
            if (nextAttack > 0)
            {
            }
            else {
                if (playerPositionX < outerFrameX) playerPositionX = outerFrameX;
                if (playerPositionX + playerRect.width > outerFrameX + outerFrameWidth)
                    playerPositionX = outerFrameX + outerFrameHeight - playerRect.width;

                if (playerPositionY < outerFrameY) playerPositionY = outerFrameY;
                if (playerPositionY + playerRect.height > outerFrameY + outerFrameWidth)
                    playerPositionY = outerFrameY + outerFrameHeight - playerRect.height;
            }

            attack::damage(damageBGM, satoOneHP, satoTwoHP, playerRect);
            BeginDrawing();
            ClearBackground(RAYWHITE);
            // 外側の矩形 (枠線)
            DrawRectangle(outerFrameX, outerFrameY, outerFrameWidth, outerFrameHeight, BLACK);
            // 内側の矩形 (背景色)
            DrawRectangle(innerFrameX, innerFrameY, innerFrameWidth, innerFrameHeight, DARKPURPLE);

            DrawTexture(playerTexture, playerPositionX, playerPositionY, WHITE);

            attack::testAttack(attackTexture);

            // プレイヤーと攻撃の矩形を更新
            playerRect.x = playerPositionX;
            playerRect.y = playerPositionY;

            if (shieldOF)
            {
                DrawRectangle(shieldX, 485, shield / 2, 20, GREEN);
            }

            EndDrawing();
        }
    }

    // オーディオデバイスを閉じる
    CloseAudioDevice();

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
