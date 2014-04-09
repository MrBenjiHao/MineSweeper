#include "Block.h"

Block::Block(float x, float y, Board::cellType type, Board* board) : x(x), y(y), width(32), height(32), board(board), type(type), replace(false), FLAGGED(false){
}

void Block::update(){
}

void Block::render(sf::RenderWindow* window){
}

void Block::loadSprite(){
	sprite.setTexture(board->spriteSheet);
	sprite.setScale(2.0, 2.0);
	sprite.setPosition(x * width, y * height);
}