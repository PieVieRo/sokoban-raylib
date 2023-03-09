#include <iostream>

#include "player.hpp"

Player::Player(Texture2D sprite, Vector2 location) {
   this->sprite = sprite;
   this->location = location;
}

void Player::draw() {
    DrawTexture(this->sprite, 64*this->location.x, 64*this->location.y, WHITE);
}

void Player::move(Level* level) {

    if(IsKeyPressed(KEY_UP))  {
        if(level->data[(int)((this->location.y-1)*10 + this->location.x)]) return;
        this->location.y -= 1;
    }
    if(IsKeyPressed(KEY_DOWN))    {
        if(level->data[(int)((this->location.y+1)*10 + this->location.x)]) return;
        this->location.y += 1;
    }
    if(IsKeyPressed(KEY_RIGHT)) {
        if(level->data[(int)(this->location.y*10 + this->location.x+1)]) return;
        this->location.x += 1;
    }
    if(IsKeyPressed(KEY_LEFT))  {
        if(level->data[(int)(this->location.y*10 + this->location.x-1)]) return;
        this->location.x -= 1;
    }

}
