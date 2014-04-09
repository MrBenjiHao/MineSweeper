#include "Board.h"
#include <iostream>
#include "Core.h"
#include "NormalBlock.h"
#include "MineBlock.h"
#include "EmptyBlock.h"

Board::Board(Core* core) : numBombs(30), core(core), gameOver(false), pause(false), minesFlagged(numBombs){
	initBoard();
	//Loading sprite sheet texture
	spriteSheet.loadFromFile("Resources/SpriteSheet.png");
	font.loadFromFile("Resources/sansation.ttf");
}


void Board::update(){
	// Updating each block
	if(!gameOver && !pause){
		Block* block;
		for(int y = 0; y < height; y++){
			for(int x = 0; x < width; x++){
				block = cells[x + y * width];
				block->update();
				if(block->replace){
				delete block;
				board[x][y] = emptyCell;
				EmptyBlock* eblock = new EmptyBlock(x, y, emptyCell, this);
				cells[x + y * width] = eblock;
				}
			}
		}
	}
	else if(gameOver){
		for(int i = 0; i < cells.size(); i++){
			if(cells[i]->type == mineCell) cells[i]->sprite.setColor(sf::Color::Red);
		}
	}
	if(minesFlagged <= 0){
		pause = true;
		std::cout << "GOOD JOB AMBER, YOU'VE WON!!!\n";
	}
}

void Board::render(sf::RenderWindow* window){
	// Drawing each block onto the window
	for(int i = 0; i < cells.size(); i++){
		cells[i]->render(window);
	}
}

void Board::initBoard(){
	// Initializing all cells to normalCells
	for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			board[x][y] = normalCell;
		}
	}

	srand(time(NULL));
	int i = numBombs;
	// Placing mineCells on the board;
	while(i > 0){
		int randX = rand() % (width);
		int randY = rand() % (height);
		if(board[randX][randY] != mineCell){
			board[randX][randY] = mineCell;
			i--;
		}
	}

	// Printing board for test purposes
	/*for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			std::cout << board[x][y];
		}
		std::cout << std::endl;
	}*/

	// Creating sprites at board locations
	for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			if(board[x][y] == normalCell) cells.push_back(new NormalBlock(x, y, normalCell, this));
			else if(board[x][y] == mineCell) cells.push_back(new MineBlock(x, y, mineCell, this));
		}
	}
}

// Replace a normal block with an empty block after it's been clicked
void Board::replaceCells(){
	Block* block;
	for(int y = 0; y < height; y++){
		for(int x = 0; x < width; x++){
			block = cells[x + y * width];
			if(block->replace){
				delete block;
				board[x][y] = emptyCell;
				EmptyBlock* eblock = new EmptyBlock(x, y, emptyCell, this);
				cells[x + y * width] = eblock;
			}
		}
	}
}