#ifndef EMPTYBLOCK_H
#define EMPTYBLOCK_H

#include "Block.h"
#include <sstream>

class EmptyBlock : public Block{
public:
	EmptyBlock(float x, float y, Board::cellType type, Board* board);

	int numTouching;
	sf::Text text;
	std::string Result;
	std::ostringstream convert;

	void update();
	void render(sf::RenderWindow* window);
	void loadSprite();
	void clearBlocks();
};

#endif