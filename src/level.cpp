#include "level.hpp"


void Level::level(int data[100]) {
    this->data = data;
}

void Level::render(std::map<int, Texture2D> textures) {
    for(int y=0; y < 10; y++) {
        for(int x=0; x < 10; x++) {
            DrawTexture(LoadTexture("assets/images/ground.png"), 64*x, 64*y, WHITE);
            if(this->data[y*10+x]) DrawTexture(textures[this->data[y*10+x], 64*x, 64*y, WHITE);
        }
    }
}
