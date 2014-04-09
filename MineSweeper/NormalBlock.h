#ifndef NORMALBLOCK_H
#define NORMALBLOCK_H

#include "Block.h"

class NormalBlock : public Block{
public:
	NormalBlock(float x, float y, Board::cellType type, Board* board);
	int absorbs;
	bool rightClick;

	void update();
	void render(sf::RenderWindow* window);
	void loadSprite();
	void highlightBlock(sf::Vector2i mousePos);
};

#endif