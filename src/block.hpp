#pragma once

#include <raylib.h>

class Block {
    Texture2D sprite;
public:
    bool is_passable = false;
    Block(Texture2D sprite, bool is_passable = false);
    void draw(int x, int y);
};
