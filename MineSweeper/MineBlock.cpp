#include "MineBlock.h"
#include "Core.h"
#include <iostream>

MineBlock::MineBlock(float x, float y, Board::cellType type, Board* board) : Block(x, y, type, board){
	loadSprite();
}

void MineBlock::update(){
	sf::Vector2i mousePos = sf::Mouse::getPosition(*board->core->window);
	highlightBlock(mousePos);
}

void MineBlock::render(sf::RenderWindow* window){
	window->draw(sprite);
}

void MineBlock::loadSprite(){
	Block::loadSprite();
	sprite.setTextureRect(sf::IntRect(0, 8 * 16, 16, 16));
}

void MineBlock::highlightBlock(sf::Vector2i mousePos){
	if(mousePos.x > sprite.getPosition().x && mousePos.x < sprite.getPosition().x + sprite.getGlobalBounds().width
	&& mousePos.y > sprite.getPosition().y && mousePos.y < sprite.getPosition().y + sprite.getGlobalBounds().height){
		sprite.setColor(sf::Color::Cyan);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !FLAGGED) board->gameOver = true;
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			if(board->core->rightClicked){
				FLAGGED = !FLAGGED;
				if(FLAGGED){
					board->numBombs--;
					board->minesFlagged--;
				}
				else{
					board->numBombs++;
					board->minesFlagged++;
				}
				std::cout << board->numBombs << std::endl;
			}
		}
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) sprite.setColor(sf::Color::Red);
	else sprite.setColor(sf::Color::White);
	

	if(FLAGGED) sprite.setTextureRect(sf::IntRect(8 * 16, 8 * 16, 16, 16));
	else sprite.setTextureRect(sf::IntRect(0 * 16, 8 * 16, 16, 16));
}