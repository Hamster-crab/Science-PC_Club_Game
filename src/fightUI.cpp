#include "raylib.h"

int main()
{
    const int screenWidth = 900;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib [Core] Example - Draw Square");
    SetTargetFPS(60);

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
    double satoOneMPMax = 810.0;

    double satoTwoHP = 50.0;
    double satoTwoHPDefault = 50.0;
    double satoTwoMPDefault = 81019.0;
    double satoTwoMP = 81019.0;
    double satoTwoMPMax = 40.0;

    double playerHeartsMax = 20.0;
    double playerHeart = 20.0;
    double playerPositionX = 405.0;
    double playerPositionY = 305.0;

//    XMax 305.0
//    YMax 415.0

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

    while (!WindowShouldClose())
    {
        double currentTime = GetTime(); // 現在の時刻を取得
        // プレイヤーの位置を更新
        if (IsKeyDown(KEY_D)) playerPositionX += 5;
        if (IsKeyDown(KEY_A)) playerPositionX -= 5;
        if (IsKeyDown(KEY_W)) playerPositionY -= 5;
        if (IsKeyDown(KEY_S)) playerPositionY += 5;
        if (IsKeyDown(KEY_RIGHT)) playerPositionX += 5;
        if (IsKeyDown(KEY_LEFT)) playerPositionX -= 5;
        if (IsKeyDown(KEY_UP)) playerPositionY -= 5;
        if (IsKeyDown(KEY_DOWN)) playerPositionY += 5;
        if (IsKeyDown(KEY_C))
        {
            if (satoOneMP > 0)
            {
                satoOneMP -= 10;
            }
            else if (satoTwoMP > 0)
            {
                satoTwoMP -= 10;
            }
        }
        else
        {
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

        // プレイヤーと攻撃の矩形を更新
        playerRect.x = playerPositionX;
        playerRect.y = playerPositionY;
        // 2秒経過したかをチェック
        if (currentTime - startTime >= 2.0)
        {
            attackRect.x += 1;
        }



        if (satoOneHP > 0)
        {
            // 当たり判定
            if (CheckCollisionRecs(playerRect, attackRect))
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
        DrawRectangle(playerPositionX, playerPositionY, 30, 30, ORANGE);
        DrawTexture(attackTexture, attackRect.x, attackRect.y, WHITE);

        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context

    return 0;
}
