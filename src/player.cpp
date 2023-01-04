#include <iostream>

#include "player.hpp"

Player::Player(Texture2D sprite) {
   this->sprite = sprite;
}

void Player::draw(int pl[2]) {
    DrawTexture(this->sprite, 64*pl[1], 64*pl[0], WHITE);
}

void Player::move(int pl[2], int test_level[10][10]) {
    if(IsKeyPressed(KEY_UP))  {
        if(test_level[pl[0]-1][pl[1]+0]) return;
        std::swap(test_level[pl[0]][pl[1]], test_level[pl[0]-1][pl[1]+0]);
        pl[0]--;
    }
    if(IsKeyPressed(KEY_DOWN))    {
        if(test_level[pl[0]+1][pl[1]+0]) return;
        std::swap(test_level[pl[0]][pl[1]], test_level[pl[0]+1][pl[1]+0]);
        pl[0]++;
    }
    if(IsKeyPressed(KEY_RIGHT)) {
        if(test_level[pl[0]+0][pl[1]+1]) return;
        std::swap(test_level[pl[0]][pl[1]], test_level[pl[0]+0][pl[1]+1]);
        pl[1]++;
    }
    if(IsKeyPressed(KEY_LEFT))  {
        if(test_level[pl[0]+0][pl[1]-1]) return;
        std::swap(test_level[pl[0]][pl[1]], test_level[pl[0]+0][pl[1]-1]);
        pl[1]--;
    }

}
