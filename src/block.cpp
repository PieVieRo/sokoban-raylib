#include "block.hpp"

Block::Block(Texture2D sprite, bool is_passable) {
    this->sprite = sprite;
    this->is_passable = is_passable;
}

void Block::draw(int x, int y) {
    DrawTexture(this->sprite, 64*x, 64*y, WHITE);
}
