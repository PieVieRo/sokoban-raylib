#pragma once

#include <raylib.h>
#include <map>

#include "player.hpp"

class Level {
public:
    int data[100];

    Level(int data[100]);
    void render(std::map<int, Texture2D> textures);
};
