#include <iostream>

#include "player.hpp"

Player::Player(Vector2 location, Texture2D sprite) {
   this->location = location;
   this->sprite = sprite;
}

void Player::draw() {
    DrawTextureV(this->sprite, this->location, RAYWHITE);
}

void Player::move() {
    if(IsKeyPressed(KEY_UP))  { this->location = Vector2Add(this->location, (Vector2){ 0, -64 }); };
    if(IsKeyPressed(KEY_DOWN)) { this->location = Vector2Add(this->location, (Vector2){ 0,  64 }); };
    if(IsKeyPressed(KEY_RIGHT))    { this->location = Vector2Add(this->location, (Vector2){ 64,  0 }); };
    if(IsKeyPressed(KEY_LEFT))  { this->location = Vector2Add(this->location, (Vector2){ -64, 0 }); };
    this->location = Vector2Clamp(this->location, Vector2Zero(), (Vector2){576,576});
}
