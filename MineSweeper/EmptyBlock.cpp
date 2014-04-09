#include "EmptyBlock.h"
#include "Core.h"
#include <iostream>
#include <string>

EmptyBlock::EmptyBlock(float x, float y, Board::cellType type, Board* board) : Block(x, y, type, board), numTouching(0){
	loadSprite();
	clearBlocks();

	if(this->type != Board::emptyCell){
		text.setFont(board->font);
		convert << this->type;      
		Result = convert.str();
		text.setString(Result);
		text.setPosition((x * width) + 7, (y * width) - 2);
	}
}

void EmptyBlock::update(){
	sf::Vector2i mousePos = sf::Mouse::getPosition(*board->core->window);
}

void EmptyBlock::render(sf::RenderWindow* window){
	window->draw(sprite);
	if(this->type != Board::emptyCell) window->draw(text);
}

void EmptyBlock::loadSprite(){
	Block::loadSprite();
	sprite.setTextureRect(sf::IntRect(1 * 16, 8 * 16, 16, 16));
}

void EmptyBlock::clearBlocks(){
	// Check all surrounding blocks
	for(int x = this->x - 1; x <= this->x + 1; x++){
		for(int y = this->y - 1; y <= this->y + 1; y++){
			if(x >= 0 && x < board->width){
				if(y >= 0 && y < board->height){
					if(board->board[x][y] == Board::mineCell) numTouching++;
				}
			}
		}
	}

	type = (Board::cellType) numTouching;
	board->board[(int) x][(int) y] = type;

	if(type == Board::emptyCell){
		for(int x = this->x - 1; x <= this->x + 1; x++){
			for(int y = this->y - 1; y <= this->y + 1; y++){
				if(x >= 0 && x < board->width){
					if(y >= 0 && y < board->height){
						if(board->board[x][y] == Board::normalCell && !board->cells[x + y * board->width]->FLAGGED) board->cells[x + y * board->width]->replace = true;
					}
				}
			}
		}
	}
}