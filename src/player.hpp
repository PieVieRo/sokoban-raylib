#pragma once
#include<raylib.h>

class Player {

    Vector2   location;
    Texture2D sprite;

public:
    Player(Vector2 location, Texture2D sprite);
    void draw();
    void move();

};
