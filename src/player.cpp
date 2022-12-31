#include "player.hpp"

Player::Player(Vector2 location, Texture2D sprite) {
   this->location = location;
   this->sprite = sprite;
}

void Player::draw() {
    DrawTextureV(this->sprite, this->location, RAYWHITE);
}

void Player::move() {
    return;
}
