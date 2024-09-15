#include <sstream>
#include <string>
#include <iostream>
#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "rainbowPuiPui");
    SetTargetFPS(60);

    // オーディオデバイスを初期化
    InitAudioDevice();

    bool debugMode = false;

    bool shieldOF = true;
    double shield = 300;

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

    double MPDefault = 1000.0;
    double MPDefaultMax = 1145148101919.0;
    double playerMPMax = 1000.0;
    double playerMP = 1000.0;

    double startTime = GetTime(); // 開始時刻を取得

    double bossHP = 1000.0;
    double bossHPDefault = 1000.0;
    double bossMPDefault = 1000.0;
    double bossMP = 114514.0;
    bool bossHPWatch = false;

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
    double playerHPDefault = 99.0;
    double playerHP = 99.0;
    double playerPositionX = 405.0;
    double playerPositionY = 305.0;
    double playerLevel = 20;
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

    Rectangle turnOneAttackRect = { 205, 305, 50, 50 };

    Rectangle turnOneAttackRectTwo = { 400, 500, 50, 50 };

    Rectangle turnOneAttackRectThree = { 605, 300, 50, 50 };

    Rectangle turnOneAttackRectFour = { 400, 70, 50, 50 };
    while (!WindowShouldClose())
    {
        if (playerHP == 0)
        {
            if (debugMode)
            {}
            else if (!debugMode)
            {
                BeginDrawing();

                ClearBackground(RAYWHITE);

                UpdateMusicStream(deathBGM);
                DrawText("Game Over", 190, 200, 20, BLACK);

                EndDrawing();
            }
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
            if (turn == 0.5)
            {
                if (IsKeyDown(KEY_UP)) playerPositionY -= 5;
                if (IsKeyDown(KEY_DOWN)) playerPositionY += 5;
                if (IsKeyDown(KEY_RIGHT)) playerPositionX += 5;
                if (IsKeyDown(KEY_LEFT)) playerPositionX -= 5;
            }
            else if (turn == 1)
            {
                // playerPositionX = 50;
                // playerPositionX = 290;
                // playerPositionX = 510;
                // playerPositionX = 715;
                playerPositionY = 545;
                if (playerPositionX == 50)
                {
                    if (IsKeyPressed(KEY_RIGHT)) playerPositionX = 290;
                    if (IsKeyDown(KEY_Z))
                    {
                        attack = true;
                    }
                }
                else if (playerPositionX == 290)
                {
                    if (IsKeyPressed(KEY_LEFT)) playerPositionX = 50;
                    if (IsKeyPressed(KEY_RIGHT)) playerPositionX = 510;
                    if (IsKeyPressed(KEY_Z))
                    {
                        if (playerMP > 100)
                        {
                            playerMP -= 100;
                            if (playerHP + 20 > playerHPDefault)
                            {
                                playerHP = playerHPDefault;
                            }
                            else
                            {
                                playerHP += 20;
                            }
                        }

                    }
                }
                else if (playerPositionX == 510)
                { 
                    if (IsKeyPressed(KEY_LEFT)) playerPositionX = 290;
                    if (IsKeyPressed(KEY_RIGHT)) playerPositionX = 715;
                }
                else if (playerPositionX == 715)
                {
                    if (IsKeyPressed(KEY_LEFT)) playerPositionX = 510;
                }
            }

            if (attack)
            {
                playerPositionX = 70;
                playerPositionY = 240;
            }

            // UpdateMusicStream(damageBGM);
            // 当たり判定
            if (IsKeyDown(KEY_SPACE))
            {
                if (shield > 0)
                {}
                if (!shieldOF)
                {
                    if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                    {
                        playerHP -= 1.0;
                    }
                    // 当たり判定
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                    {
                        playerHP -= 1.0;
                    }
                    // 当たり判定
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                    {
                        playerHP -= 1.0;
                    }
                    // 当たり判定
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                    {
                        playerHP -= 1.0;
                    }
                }
                else if (shield < 0)
                {
                    if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                    {
                        playerHP -= 1.0;
                    }
                    // 当たり判定
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                    {
                        playerHP -= 1.0;
                    }
                    // 当たり判定
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                    {
                        playerHP -= 1.0;
                    }
                    // 当たり判定
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                    {
                        playerHP -= 1.0;
                    }
                }
            }
            else
            {
                if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                {
                    playerHP -= 1.0;
                }
                // 当たり判定
                if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                {
                    playerHP -= 1.0;
                }
                // 当たり判定
                if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                {
                    playerHP -= 1.0;
                }
                // 当たり判定
                if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                {
                    playerHP -= 1.0;
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
                        shield -= 2.6;
                    }
                }
                if (IsKeyUp(KEY_SPACE))
                {
                    if (shield == 300)
                    {}
                    else if (shield < 300)
                    {
                        shield += 3;
                    }
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

            if (turn == 0.5)
            {
                // プレイヤーが枠の外に出ないように制限
                if (playerPositionX < outerFrameX) playerPositionX = outerFrameX;
                if (playerPositionX + playerRect.width > outerFrameX + outerFrameWidth)
                    playerPositionX = outerFrameX + outerFrameHeight - playerRect.width;

                if (playerPositionY < outerFrameY) playerPositionY = outerFrameY;
                if (playerPositionY + playerRect.height > outerFrameY + outerFrameWidth)
                    playerPositionY = outerFrameY + outerFrameHeight - playerRect.height;
            }
            else if (turn == 1)
            {}

            BeginDrawing();
            ClearBackground(BLACK);

            if (turn == 0.5)
            {
                outerFrameX = 300;
                outerFrameWidth = 250;
                outerFrameHeight = 250;
                innerFrameX = 305;
                innerFrameWidth = 240;
                innerFrameHeight = 240;
            }
            else if (turn == 1)
            {
                outerFrameX = 55;
                outerFrameWidth = 790;
                outerFrameHeight = 250;
                innerFrameX = 60;
                innerFrameWidth = 780;
                innerFrameHeight = 240;
            }
            // 外側の矩形 (枠線)
            DrawRectangle(outerFrameX, outerFrameY, outerFrameWidth, outerFrameHeight, WHITE);
            if (flameColor == 1)
            {
                // 内側の矩形 (背景色)
                DrawRectangle(innerFrameX, innerFrameY, innerFrameWidth, innerFrameHeight, Black);
            }
            else if (flameColor == 2)
            {
                // 内側の矩形 (背景色)
                DrawRectangle(innerFrameX, innerFrameY, innerFrameWidth, innerFrameHeight, Purple);
            }
            else if (flameColor == 3)
            {
                // 内側の矩形 (背景色)
                DrawRectangle(innerFrameX, innerFrameY, innerFrameWidth, innerFrameHeight, darkRed);
            }
            if (attack)
            {
                DrawRectangle(innerFrameX, innerFrameY, innerFrameWidth, innerFrameHeight, Black);
                if (playerPositionX == 70 && playerPositionY == 240)
                {
                    DrawText("boss", 100, 230, 38, darkRed);
                }
                else
                {
                    DrawText("boss", 100, 230, 38, WHITE);
                }
            }
            
            DrawRectangle(30, 520, 180, 65, WHITE);
            DrawRectangle(35, 525, 170, 57, BLACK);
            DrawText("Attack", 80, 540, 36, WHITE);

            DrawRectangle(270, 520, 180, 65, WHITE);
            DrawRectangle(275, 525, 170, 57, BLACK);
            DrawText("MP", 320, 540, 36, WHITE);

            DrawRectangle(490, 520, 180, 65, WHITE);
            DrawRectangle(495, 525, 170, 57, BLACK);
            DrawText("ITEM", 540, 540, 36, WHITE);

            DrawRectangle(700, 520, 180, 65, WHITE);
            DrawRectangle(705, 525, 170, 57, BLACK);
            DrawText("RUN", 750, 540, 36, WHITE);

            if (playerPositionX == 50 && playerPositionY == 545)
            {
                DrawRectangle(30, 520, 180, 65, darkRed);
                DrawRectangle(35, 525, 170, 57, BLACK);
                DrawText("Attack", 80, 540, 36, darkRed);
            }
            else if (playerPositionX == 290 && playerPositionY == 545)
            {
                DrawRectangle(270, 520, 180, 65, darkRed);
                DrawRectangle(275, 525, 170, 57, BLACK);
                DrawText("MP", 320, 540, 36, darkRed);
            }
            else if (playerPositionX == 510 && playerPositionY == 545)
            {
                DrawRectangle(490, 520, 180, 65, darkRed);
                DrawRectangle(495, 525, 170, 57, BLACK);
                DrawText("ITEM", 540, 540, 36, darkRed);
            }
            else if (playerPositionX == 715 && playerPositionY == 545)
            {
                DrawRectangle(700, 520, 180, 65, darkRed);
                DrawRectangle(705, 525, 170, 57, BLACK);
                DrawText("RUN", 750, 540, 36, darkRed);
            }

            if (bossHPWatch)
            {
                DrawRectangle(360, 100, bossHPDefault / 8, 15, GRAY);
                DrawRectangle(360, 100, bossHP / 8, 15, GREEN);
            }

        // 変数を表示するための文字列を生成
            std::ostringstream playerHPOutput;
            playerHPOutput << "LV" << playerLevel << "      " << playerHP << " / " << playerHPDefault;
            std::string playerHPText = playerHPOutput.str();

            DrawText(playerHPText.c_str(), 30, 485, 28, WHITE);  // 変数の内容を表示
            DrawRectangle(280, 485, playerHPDefault * 3, 28, darkRed);
            DrawRectangle(280, 485, playerHP * 3, 28, DARKPURPLE);

            if (shieldOF)
            {
                DrawRectangle(700, 485, shield / 2, 28, GREEN);
            }

            DrawTexture(bossTexture, 300, -60, WHITE);

            if (turn == 0.5)
            {
                int fuckTime = GetTime(); // 現在の時刻を取得
                // 2秒経過したかをチェック
                if (currentTime - startTime >= 0.3)
                {
                    turnOneAttackRect.x += 5;
                    turnOneAttackRectTwo.y -= 5;
                    turnOneAttackRectThree.x -= 5;
                    turnOneAttackRectFour.y += 5;
                }
                if (fuckTime == 3) 
                {
                    playerPositionX = 50;
                    turn += 0.5;
                }
            }
            else if (turn == 1)
            {}
            
            
            DrawTexture(attackTexture, turnOneAttackRect.x, turnOneAttackRect.y, WHITE);
            DrawTexture(attackTexture, turnOneAttackRectTwo.x, turnOneAttackRectTwo.y, WHITE);
            DrawTexture(attackTexture, turnOneAttackRectThree.x, turnOneAttackRectThree.y, WHITE);
            DrawTexture(attackTexture, turnOneAttackRectFour.x, turnOneAttackRectFour.y, WHITE);

            DrawTexture(playerTexture, playerPositionX, playerPositionY, WHITE);
            // プレイヤーと攻撃の矩形を更新
            playerRect.x = playerPositionX;
            playerRect.y = playerPositionY;

            EndDrawing();
        }
    }

    // オーディオデバイスを閉じる
    CloseAudioDevice();

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
