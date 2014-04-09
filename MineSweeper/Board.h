#ifndef BOARD_H
#define BOARD_H

#include "SFML\Graphics.hpp"
#include <vector>

class Block;
class Core;

class Board{
public:
	enum cellType{
		emptyCell = 0, oneBomb, twoBomb, threeBomb, fourBomb,
		fiveBomb, sixBomb, sevenBomb, eightBomb,
		normalCell = 10, mineCell = 99
	};

	static const int width = 24;
	static const int height = 21;

	int numBombs, minesFlagged;
	int board[width][height];
	sf::Texture spriteSheet;
	std::vector<Block*> cells;
	Core* core;
	sf::Font font;
	bool gameOver, pause;

	Board(Core* core);

	void update();
	void render(sf::RenderWindow* window);
	void initBoard();
	void replaceCells();
};

#endif