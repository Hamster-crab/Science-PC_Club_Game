#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Raylib [Core] Example - Draw Square");
    SetTargetFPS(60);

    int nextAttack = 0;
    int nextnextAttack = 1;

    int outerFrameX = 300;
    int outerFrameY = 200;
    int innerFrameX = 305;
    int innerFrameY = 205;

    int outerFrameWidthHeight = 250;
    int innerFrameWidthHeight = 240;

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
    double satoOneMPDefault = 300.0;
    double satoOneMP = 300.0;
    double satoOneMPMax = 1000.0;

    double satoTwoHP = 50.0;
    double satoTwoHPDefault = 50.0;
    double satoTwoMPDefault = 10000.0;
    double satoTwoMP = 10000.0;
    double satoTwoMPMax = 1000000.0;

    double playerHeartsMax = 20.0;
    double playerHeart = 20.0;
    double playerPositionX = 405.0;
    double playerPositionY = 305.0;
// X 405 Y 305

    Image summonSatoOneTextureTexture = LoadImage("resources/Partner-Sato/GanGimariSato.png");
    Image summonSatoTwoTextureTexture = LoadImage("resources/Partner-Sato/SatoSeenFromAbove.png");
    Image bossTextureTexture = LoadImage("resources/Bosses/faceOfBroccoli/material/hand.png");
    Image attackTextureTexture = LoadImage("resources/Textures/boiled_egg.png");

    ImageResize(&summonSatoOneTextureTexture, 100, 100);
    ImageResize(&summonSatoTwoTextureTexture, 100, 100);
    ImageResize(&bossTextureTexture, 300, 300);
    ImageResize(&attackTextureTexture, 50, 50);

    Texture2D summonSatoOneTexture = LoadTextureFromImage(summonSatoOneTextureTexture);
    Texture2D summonSatoTwoTexture = LoadTextureFromImage(summonSatoTwoTextureTexture);
    Texture2D bossTexture = LoadTextureFromImage(bossTextureTexture);
    Texture2D attackTexture = LoadTextureFromImage(attackTextureTexture);

    // 不要なイメージデータを解放
    UnloadImage(summonSatoOneTextureTexture);
    UnloadImage(summonSatoTwoTextureTexture);
    UnloadImage(bossTextureTexture);
    UnloadImage(attackTextureTexture);

    Rectangle playerRect = { playerPositionX, playerPositionY, 30, 30 }; // ここのコード修正したら殺す
    Rectangle attackRect = { 205, 305, 50, 50 };

    Rectangle attackRectTwo = { 400, 500, 50, 50 };

    Rectangle attackRectThree = { 605, 300, 50, 50 };

    Rectangle attackRectFour = { 400, 70, 50, 50 };

    while (!WindowShouldClose())
    {
        double currentTime = GetTime(); // 現在の時刻を取得

        // プレイヤーの位置を更新
        if (nextAttack == 1)
        {
            if (IsKeyDown(KEY_S)) playerPositionY += 10;
            if (IsKeyDown(KEY_DOWN)) playerPositionY += 10;
            if (IsKeyDown(KEY_W)) playerPositionY -= 5;
            if (IsKeyDown(KEY_UP)) playerPositionY -= 5;
        }
        else {
            if (IsKeyDown(KEY_W)) playerPositionY -= 5;
            if (IsKeyDown(KEY_A)) playerPositionX -= 5;
            if (IsKeyDown(KEY_S)) playerPositionY += 5;
            if (IsKeyDown(KEY_D)) playerPositionX += 5;
            if (IsKeyDown(KEY_UP)) playerPositionY -= 5;
            if (IsKeyDown(KEY_DOWN)) playerPositionY += 5;
            if (IsKeyDown(KEY_RIGHT)) playerPositionX += 5;
            if (IsKeyDown(KEY_LEFT)) playerPositionX -= 5;
        }

        if (IsKeyDown(KEY_Y))
        {
            if (satoOneMP > 100.0)
            {
                if (satoOneHP < satoOneHPDefault)
                {
                    satoOneMP -= 20.0;
                    if (satoOneHPDefault > 1)
                    {
                        satoOneHP += 0.05;
                    }

                }
            }
        }

        if (IsKeyDown(KEY_U))
        {
            if (satoTwoMP > 20.0)
            {
                if (satoTwoHP < satoTwoHPDefault)
                {
                    satoTwoMP -= 20.0;
                    if (satoTwoHPDefault > 1)
                    {
                        satoTwoHP += 1.0;
                    }
                    else
                    {}
                }
            }
        }


        // プレイヤーが枠の外に出ないように制限
        if (nextAttack > 0)
        {}
        else {
            if (playerPositionX < outerFrameX) playerPositionX = outerFrameX;
            if (playerPositionX + playerRect.width > outerFrameX + outerFrameWidthHeight)
                playerPositionX = outerFrameX + outerFrameWidthHeight - playerRect.width;

            if (playerPositionY < outerFrameY) playerPositionY = outerFrameY;
            if (playerPositionY + playerRect.height > outerFrameY + outerFrameWidthHeight)
                playerPositionY = outerFrameY + outerFrameWidthHeight - playerRect.height;
        }

        // プレイヤーと攻撃の矩形を更新
        playerRect.x = playerPositionX;
        playerRect.y = playerPositionY;
//         2秒経過したかをチェック
        if (currentTime - startTime >= 1.5)
        {
            attackRect.x += 1;
        }
        // 4秒経過したかをチェック
        if (currentTime - startTime >= 1.5)
        {
            attackRectTwo.y -= 1;
        }
        // 2秒経過したかをチェック
        if (currentTime - startTime >= 1.5)
        {
            attackRectThree.x -= 1;
        }
        // 2秒経過したかをチェック
        if (currentTime - startTime >= 1.5)
        {
            attackRectFour.y += 1;
        }


        if(IsKeyDown(KEY_C))
        {
            if (satoOneMP > 0)
            {
                satoOneMP -= 10;
            }
            else if (satoOneMP == 0)
            {
                satoTwoMP -= 10;
            }
        }
        else {
            if (satoOneHP > 0)
            {
                // 当たり判定
                if (CheckCollisionRecs(playerRect, attackRect))
                {
                    satoOneHP -= 1.0;
                    if (satoOneHP < 0) satoOneHP = 0;
                }
                // 当たり判定
                if (CheckCollisionRecs(playerRect, attackRectTwo))
                {
                    satoOneHP -= 1.0;
                    if (satoOneHP < 0) satoOneHP = 0;
                }
                // 当たり判定
                if (CheckCollisionRecs(playerRect, attackRectThree))
                {
                    satoOneHP -= 1.0;
                    if (satoOneHP < 0) satoOneHP = 0;
                }
                // 当たり判定
                if (CheckCollisionRecs(playerRect, attackRectFour))
                {
                    satoOneHP -= 1.0;
                    if (satoOneHP < 0) satoOneHP = 0;
                }
            }
            else
            {
                // 当たり判定
                if (CheckCollisionRecs(playerRect, attackRect))
                {
                    satoTwoHP -= 1.0;
                    if (satoTwoHP < 0) satoTwoHP = 0;
                }
                if (CheckCollisionRecs(playerRect, attackRectTwo))
                {
                    satoTwoHP -= 1.0;
                    if (satoTwoHP < 0) satoTwoHP = 0;
                }
                if (CheckCollisionRecs(playerRect, attackRectThree))
                {
                    satoTwoHP -= 1.0;
                    if (satoTwoHP < 0) satoTwoHP = 0;
                }
                if (CheckCollisionRecs(playerRect, attackRectFour))
                {
                    satoTwoHP -= 1.0;
                    if (satoTwoHP < 0) satoTwoHP = 0;
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
        }


        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawRectangle(690, 7, 200, 110, BLUE);
        DrawRectangle(700, 10, satoOneHPDefault, 10, RED);
        DrawRectangle(700, 10, satoOneHP, 10, YELLOW);
        DrawRectangle(700, 20, satoOneMP / 10.0, 10, DARKPURPLE);
        DrawText("Attack", 750, 38, 20, BLACK);
        DrawText("MP recovery", 750, 58, 20, BLACK);
        DrawText("Item", 750, 78, 20, BLACK);
        DrawText("Shield", 750, 98, 20, BLACK);
        DrawTexture(summonSatoOneTexture, 585, 13, WHITE);

        DrawRectangle(690, 150, 200, 110, BLUE);
        DrawRectangle(700, 154, satoTwoHPDefault, 10, RED);
        DrawRectangle(700, 154, satoTwoHP, 10, YELLOW);
        DrawRectangle(700, 164, satoTwoMP / 10.0, 10, DARKPURPLE);
        DrawText("Attack", 750, 180, 20, BLACK);
        DrawText("MP recovery", 750, 200, 20, BLACK);
        DrawText("Item", 750, 220, 20, BLACK);
        DrawText("Shield", 750, 240, 20, BLACK);
        DrawTexture(summonSatoTwoTexture, 585, 158, WHITE);

        DrawRectangle(10, 10, 50, 580, BLUE);
        DrawRectangle(13, 15, 20, 570, YELLOW);
        DrawRectangle(35, 15, 20, 570, DARKPURPLE);
        DrawTexture(bossTexture, 30, 100, WHITE);

        // 外側の矩形 (枠線)
        DrawRectangle(outerFrameX, outerFrameY, outerFrameWidthHeight, outerFrameWidthHeight, BLACK);
        // 内側の矩形 (背景色)
        DrawRectangle(innerFrameX, innerFrameY, innerFrameWidthHeight, innerFrameWidthHeight, DARKPURPLE);
        DrawTexture(attackTexture, attackRect.x, attackRect.y, WHITE);
        DrawTexture(attackTexture, attackRectTwo.x, attackRectTwo.y, WHITE);
        DrawTexture(attackTexture, attackRectThree.x, attackRectThree.y, WHITE);
        DrawTexture(attackTexture, attackRectFour.x, attackRectFour.y, WHITE);

        DrawRectangle(playerPositionX, playerPositionY, 18, 18, ORANGE);

//        if (attackRect.x == 600)
//        {
//            nextAttack += 1;
//            playerPositionX = 710;
//            playerPositionY = 40;
//        }

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
