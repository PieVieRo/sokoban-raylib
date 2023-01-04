#pragma once

#include<raylib.h>
#include<raymath.h>

class Player {
    Texture2D sprite;

public:
    Player(Texture2D sprite);
    void draw(int pl[2]);
    void move(int pl[2], int test_level[10][10]);

};
