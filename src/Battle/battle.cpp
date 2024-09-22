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

    bool shieldOF = false;
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

    Rectangle turnOneAttackRect = { 205, 305, 20, 20 };

    Rectangle turnOneAttackRectTwo = { 400, 500, 20, 20 };

    Rectangle turnOneAttackRectThree = { 605, 300, 20, 20 };

    Rectangle turnOneAttackRectFour = { 400, 70, 20, 20 };

    double damageCooldown = 0;  // プレイヤーのダメージクールダウンタイマー
    double invincibilityTime = 0.5;  // ダメージを受けた後の無敵時間（0.4秒）

    double shieldCooldown = 0;  // プレイヤーshieldのダメージクールダウンタイマー
    double shieldInvincibilityTime = 0.4;  // shield後の無敵時間（0.4秒）

    while (!WindowShouldClose())
    {
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
                    if (IsKeyPressed(KEY_Z))
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

            // UpdateMusicStream(damageBGM);
            // 当たり判定
            if (shieldOF)
            {
                if (IsKeyDown(KEY_SPACE))
                {
                    if (shield > 0)
                    {
                        if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                        {
                            shield -= nomalAttackShield;
                            shieldCooldown = shieldInvincibilityTime;  // クールダウンをリセット
                        }
                        if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                        {
                            shield -= nomalAttackShield;
                            shieldCooldown = shieldInvincibilityTime;  // クールダウンをリセット
                        }
                        if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                        {
                            shield -= nomalAttackShield;
                            shieldCooldown = shieldInvincibilityTime;  // クールダウンをリセット
                        }
                        if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                        {
                            shield -= nomalAttackShield;
                            shieldCooldown = shieldInvincibilityTime;  // クールダウンをリセット
                        }
                    }
                    if (!shieldOF)
                    {
                        if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                        {
                            if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                            if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                            if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                            if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                        }
                    }
                    else if (shield < 0)
                    {
                        if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                        {
                            if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                            if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                            if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                            if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                            {
                                playerHP -= nomalAttackDamage;
                                damageCooldown = invincibilityTime;  // クールダウンをリセット
                            }
                        }
                    }
                }
                else
                {
                    if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                    {
                        if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                        {
                            playerHP -= nomalAttackDamage;
                            damageCooldown = invincibilityTime;  // クールダウンをリセット
                        }
                        if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                        {
                            playerHP -= nomalAttackDamage;
                            damageCooldown = invincibilityTime;  // クールダウンをリセット
                        }
                        if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                        {
                            playerHP -= nomalAttackDamage;
                            damageCooldown = invincibilityTime;  // クールダウンをリセット
                        }
                        if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                        {
                            playerHP -= nomalAttackDamage;
                            damageCooldown = invincibilityTime;  // クールダウンをリセット
                        }
                    }
                }
            }
            else
            {
                if (damageCooldown <= 0)  // クールダウンが0以下の場合のみダメージを適用
                {
                    if (CheckCollisionRecs(playerRect, turnOneAttackRect))
                    {
                        playerHP -= nomalAttackDamage;
                        damageCooldown = invincibilityTime;  // クールダウンをリセット
                    }
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectTwo))
                    {
                        playerHP -= nomalAttackDamage;
                        damageCooldown = invincibilityTime;  // クールダウンをリセット
                    }
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectThree))
                    {
                        playerHP -= nomalAttackDamage;
                        damageCooldown = invincibilityTime;  // クールダウンをリセット
                    }
                    if (CheckCollisionRecs(playerRect, turnOneAttackRectFour))
                    {
                        playerHP -= nomalAttackDamage;
                        damageCooldown = invincibilityTime;  // クールダウンをリセット
                    }
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
            else
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
                playerPositionX = 70;
                playerPositionY = 240;
                if (playerPositionX == 70, playerPositionY == 240)
                {
                    if (IsKeyPressed(KEY_Z))
                    {
                        bossHPWatch = true;
                        bossHP -= 20;
                        turn -= 0.5;
                        attack = false;
                    }
                // }
                // DrawRectangle(200, 230, bossHPDefault / 8, 37, darkRed);
                // DrawRectangle(200, 230, bossHP / 8, 37, Purple);
                // if (playerPositionX == 70 && playerPositionY == 240)
                // {
                //     DrawText("boss", 100, 230, 38, darkRed);
                // }
                // else
                // {
                //     DrawText("boss", 100, 230, 38, WHITE);
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
                DrawText("20", 410, 100, 28, WHITE);
            }

            // 変数を表示するための文字列を生成
            std::ostringstream playerHPOutput;
            playerHPOutput << "LV" << playerLevel << "      " << playerHP << " / " << playerHPDefault;
            std::string playerHPText = playerHPOutput.str();

            std::ostringstream playerMPOutput;
            playerMPOutput << playerMP << " / " << playerMPDefault;
            std::string playerMPText = playerMPOutput.str();

            DrawText(playerHPText.c_str(), 30, 475, 23, WHITE);  // 変数の内容を表示
            DrawRectangle(280, 475, playerHPDefault * 3, 23, darkRed);
            DrawRectangle(280, 475, playerHP * 3, 23, DARKPURPLE);
            DrawText(playerMPText.c_str(), 140, 500, 14, WHITE);
            DrawRectangle(280, 498, playerMPDefault / 5, 10, darkRed);
            DrawRectangle(280, 498, playerMP / 5, 10, YELLOW);

            if (shieldOF)
            {
                DrawRectangle(700, 475, shieldDefault / 2, 28, darkRed);
                DrawRectangle(700, 475, shield / 2, 28, GREEN);
            }

            DrawTexture(bossTexture, 300, -60, WHITE);

            if (turn == 0.5)
            {
                int fuckTime = GetTime(); // 現在の時刻を取得
                // 2秒経過したかをチェック
                if (currentTime - startTime >= 0.3)
                {
                    turnOneAttackRect.x += 3;
                    turnOneAttackRectTwo.y -= 5;
                    turnOneAttackRectThree.x -= 7;
                    turnOneAttackRectFour.y += 8;
                }
                if (fuckTime == 3) 
                {
                    playerPositionX = 50;
                    turn += 0.5;
                }
            }
            else if (turn == 1)
            {
                turnOneAttackRect.x += 8;
            }

            if (turn == 0.5)
            {
                DrawTexture(attackTexture, turnOneAttackRect.x, turnOneAttackRect.y, WHITE);
                DrawTexture(attackTexture, turnOneAttackRectTwo.x, turnOneAttackRectTwo.y, WHITE);
                DrawTexture(attackTexture, turnOneAttackRectThree.x, turnOneAttackRectThree.y, WHITE);
                DrawTexture(attackTexture, turnOneAttackRectFour.x, turnOneAttackRectFour.y, WHITE);
            }

            if (attack) DrawRectangle(innerFrameX, innerFrameY, innerFrameWidth, innerFrameHeight, Black);
            if (shieldOF) if (IsKeyUp(KEY_SPACE)) DrawRectangle(playerPositionX - 3, playerPositionY - 3, 25, 25, GREEN);
            else if (!shieldOF)
            {}
            DrawTexture(playerTexture, playerPositionX, playerPositionY, WHITE);
            if (shieldOF) if (IsKeyDown(KEY_SPACE)) DrawRectangle(playerPositionX + 5, playerPositionY + 5, 8, 8, GREEN);
            else if (!shieldOF)
            {}
            // std::cout << attack << "    " << turn << std::endl;
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
