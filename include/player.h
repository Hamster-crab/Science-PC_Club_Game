#ifndef SCIENCE_PC_CLUB_GAME_PLAYER_H
#define SCIENCE_PC_CLUB_GAME_PLAYER_H
#include <raylib.h>

namespace Player {
    class cPlayer {
        int playerX, playerY = 0;
        Image player = LoadImage("resources/Textures/player_arm_dot.png");
    };
}

#endif //SCIENCE_PC_CLUB_GAME_PLAYER_H
