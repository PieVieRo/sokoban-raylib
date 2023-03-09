#pragma once

#include <raylib.h>
#include <map>

class Level {
public:
    int data[100];

    Level(int data[100]);
    void draw(std::map<int, Texture2D> textures);
};
