#ifndef BLOCK_H
#define BLOCK_H

#include "Board.h"

class Block{
public:
	Block();
	Block(float x, float y, Board::cellType type, Board* board);

	Board::cellType type;
	Board* board;
	sf::Sprite sprite;
	float x, y, width, height;
	bool replace, FLAGGED;

	virtual void update() = 0;
	virtual void render(sf::RenderWindow* window) = 0;
	virtual void loadSprite();
};

#endif