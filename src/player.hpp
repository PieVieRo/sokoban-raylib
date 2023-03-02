#pragma once

#include<raylib.h>
#include<raymath.h>

#include "level.hpp"

class Player {
    Texture2D sprite;
    Vector2 location;

public:
    Player(Texture2D sprite, Vector2 location);
    void draw();
    void move(Level* level);

};
