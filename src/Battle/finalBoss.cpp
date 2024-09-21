#include <sstream>
#include <string>
#include <iostream>
#include "raylib.h"

void reset(Rectangle a, Rectangle b)
{
    a = b;
}

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "林 凌久");
    SetTargetFPS(60);

    // オーディオデバイスを初期化
    InitAudioDevice();

    bool debugMode = false;

    bool turnOneAttack = true;

    bool shieldOF = true;
    double shieldDefault = 300;
    double shield = shieldDefault;

    double turn = 0.5;

    int flameColor = 1; // 1 = black  2 = purple  3 = red
    Color Purple = CLITERAL(Color){ 112, 31, 126, 255 };
    Color Black = CLITERAL(Color){ 0, 0, 0, 255 };
    Color darkRed = CLITERAL(Color){ 139, 0, 0, 255 };

    bool attack = false;
    int Onetime = 0;

    int outerFrameX = 300;
    int outerFrameY = 200;
    int innerFrameX = 305;
    int innerFrameY = 205;

    int outerFrameWidth = 250;
    int outerFrameHeight = 250;
    
    int innerFrameWidth = 240;
    int innerFrameHeight = 240;

    double playerMPDefault = 800.0;
    double playerMP = 800.0;

    double startTime = GetTime(); // 開始時刻を取得

    double bossHP = 1000.0;
    double bossHPDefault = 1000.0;
    double bossMPDefault = 1000.0;
    double bossMP = 114514.0;
    bool bossHPWatch = false;
    int nomalAttackDamage = 5;
    int nomalAttackShield = 3;

    double playerHPMax = 100.0;
    double playerHPDefault = 20.0;
    double playerHP = playerHPDefault;
    double playerPositionX = 405.0;
    double playerPositionY = 305.0;
    double playerLevel = 1;
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
    Image bossTextureTexture = LoadImage("resources/finalBossTexture/nomal.png");
    Image attackTextureTexture = LoadImage("resources/Textures/boiled_egg.png");
    Image playerTextureTexture = LoadImage("resources/Textures/player/playerImage.png");
    Image playerTextureGreenTexture = LoadImage("resources/Textures/Beef.png");

    ImageResize(&summonSatoOneTextureTexture, 100, 100);
    ImageResize(&summonSatoTwoTextureTexture, 100, 100);
    ImageResize(&bossTextureTexture, 900, 600);
    ImageResize(&attackTextureTexture, 20, 20);
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

    Rectangle turnOneAttackRect = { 205, 305, 20, 20 };

    double damageCooldown = 0;  // プレイヤーのダメージクールダウンタイマー
    double invincibilityTime = 0.5;  // ダメージを受けた後の無敵時間（0.4秒）

    double shieldCooldown = 0;  // プレイヤーshieldのダメージクールダウンタイマー
    double shieldInvincibilityTime = 0.4;  // shield後の無敵時間（0.4秒）

    while (!WindowShouldClose())
    {
        playerRect.x = playerPositionX;
        playerRect.y = playerPositionY;
        double damageTime = GetTime(); // 現在の時刻を取得
        // クールダウンタイマーを時間経過で減少させる
        if (damageCooldown > 0)
        {
            damageCooldown -= GetFrameTime();  // フレーム時間に応じてクールダウンを減少
        }

        if (playerHP > playerHPDefault)
        {
            playerHP = playerHPDefault;
        }
        if (playerHP < 1)
        {
            if (debugMode)
            {
                playerHP = playerHPDefault;
            }
            else if (!debugMode)
            {
                BeginDrawing();

                ClearBackground(BLACK);

                UpdateMusicStream(deathBGM);
                DrawText("Game Over", 180, 80, 100, WHITE);

                EndDrawing();
            }
        }
        else if (bossHP < 0)
        {
            BeginDrawing();

            ClearBackground(BLACK);

            UpdateMusicStream(deathBGM);
            DrawText("You win!", 180, 80, 100, WHITE);
            DrawText("Fuck you!!!!!!!!!!!!!!!!!!!!!!!!!!!!!", 180, 200, 30, WHITE);

            EndDrawing();
        }
        else
        {
            UpdateMusicStream(sampleBGM);
            double currentTime = GetTime(); // 現在の時刻を取得
            // プレイヤーの位置を更新
            if (IsKeyDown(KEY_UP)) playerPositionY -= 5;
            if (IsKeyDown(KEY_DOWN)) playerPositionY += 5;
            if (IsKeyDown(KEY_RIGHT)) playerPositionX += 5;
            if (IsKeyDown(KEY_LEFT)) playerPositionX -= 5;

            // UpdateMusicStream(damageBGM);
            // 当たり判定
            if (shieldOF)
            {
                if (IsKeyDown(KEY_SPACE))
                {
                    if (shield > 0)
                    {
                        // if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                        // {
                        //     shield -= nomalAttackShield;
                        //     shieldCooldown = shieldInvincibilityTime;  // クールダウンをリセット
                        // }
                    }
                    if (!shieldOF)
                    {
                        if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                        {
                            // if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                            // {
                            //     playerHP -= nomalAttackDamage;
                            //     damageCooldown = invincibilityTime;  // クールダウンをリセット
                            // }
                        }
                    }
                    else if (shield < 0)
                    {
                        if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                        {
                            // if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                            // {
                            //     playerHP -= nomalAttackDamage;
                            //     damageCooldown = invincibilityTime;  // クールダウンをリセット
                            // }
                        }
                    }
                }
                else
                {
                    if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                    {
                        // if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                        // {
                        //     playerHP -= nomalAttackDamage;
                        //     damageCooldown = invincibilityTime;  // クールダウンをリセット
                        // }
                    }
                }
            }
            else
            {
                if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                {
                    // if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                    // {
                    //     playerHP -= nomalAttackDamage;
                    //     damageCooldown = invincibilityTime;  // クールダウンをリセット
                    // }
                }
            }

            if (shieldOF)
            {
                if (IsKeyDown(KEY_SPACE))
                {
                    if (shield < 0)
                    {}
                    else
                    {
                        shield -= 2.8;
                    }
                }
            }
            if (IsKeyUp(KEY_SPACE))
            {
                if (shield == 300)
                {}
                else if (shield < 300)
                {
                    shield += 2.5;
                }
            }
            
            BeginDrawing();
            ClearBackground(BLACK);

            DrawTexture(bossTexture, 0, 0, WHITE);

            DrawRectangle(playerPositionX, playerPositionY, 18, 18, RED);
            DrawRectangle(screenWidth - 875, screenHeight - 60, playerHPDefault * 5, 28, darkRed);
            DrawRectangle(screenWidth - 875, screenHeight - 60, playerHP * 5, 28, DARKPURPLE);

            DrawRectangle(screenWidth - 200, screenHeight - 60, shieldDefault / 2, 28, darkRed);
            if (shieldOF)
            {
                DrawRectangle(screenWidth - 200, screenHeight - 60, shield / 2, 28, GREEN);
            }
            else if (!shieldOF)
            {
                DrawRectangle(screenWidth - 200, screenHeight - 60, shield / 2, 28, WHITE);
            }

            // プレイヤーと攻撃の矩形を更新
            playerRect.x = playerPositionX;
            playerRect.y = playerPositionY;

            if (IsKeyPressed(KEY_D))
            {
                if (debugMode == true) debugMode = false;
                else if (debugMode == false) debugMode = true;
            }
            if (debugMode == true) DrawText("DEBUG", 10, 10, 40, WHITE);
            else if (debugMode == false) DrawText("", 10, 10, 40, WHITE);
            EndDrawing();
        }
    }

    // オーディオデバイスを閉じる
    CloseAudioDevice();

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
