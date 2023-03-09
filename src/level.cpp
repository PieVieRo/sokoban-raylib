#include "level.hpp"

Level::Level(int data[100]) {
    for(int i=0; i<100; i++)
        this->data[i] = data[i];
}

void Level::draw(std::map<int, Texture2D> textures) {
    for(int y=0; y < 10; y++) {
        for(int x=0; x < 10; x++) {
            DrawTexture(LoadTexture("assets/sprites/ground.png"), 64*x, 64*y, WHITE);
            if(this->data[y*10+x]) DrawTexture(textures[this->data[y*10+x]], 64*x, 64*y, WHITE);
        }
    }
}
