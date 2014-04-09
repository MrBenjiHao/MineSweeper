#ifndef MINEBLOCK_H
#define MINEBLOCK_H

#include "Block.h"

class MineBlock : public Block{
public:
	MineBlock(float x, float y, Board::cellType type, Board* board);

	void update();
	void render(sf::RenderWindow* window);
	void loadSprite();
	void highlightBlock(sf::Vector2i mousePos);
};

#endif