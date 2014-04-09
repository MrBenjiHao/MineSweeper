#include "NormalBlock.h"
#include "Core.h"
#include <iostream>

NormalBlock::NormalBlock(float x, float y, Board::cellType type, Board* board) : Block(x, y, type, board), rightClick(false){
	loadSprite();
	absorbs = 0;
}

void NormalBlock::update(){
	sf::Vector2i mousePos = sf::Mouse::getPosition(*board->core->window);
	highlightBlock(mousePos);
}

void NormalBlock::render(sf::RenderWindow* window){
	window->draw(sprite);
}

void NormalBlock::loadSprite(){
	Block::loadSprite();
	sprite.setTextureRect(sf::IntRect(0, 8 * 16, 16, 16));
}

void NormalBlock::highlightBlock(sf::Vector2i mousePos){
	if(mousePos.x > sprite.getPosition().x && mousePos.x < sprite.getPosition().x + sprite.getGlobalBounds().width
	&& mousePos.y > sprite.getPosition().y && mousePos.y < sprite.getPosition().y + sprite.getGlobalBounds().height){
		sprite.setColor(sf::Color::Cyan);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){
			if(board->core->rightClicked){
				FLAGGED = !FLAGGED;
				if(FLAGGED) board->numBombs--;
				else board->numBombs++;
				std::cout << board->numBombs << std::endl;
			}
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !FLAGGED) replace = true;
	}
	else sprite.setColor(sf::Color::White);
	

	if(FLAGGED) sprite.setTextureRect(sf::IntRect(8 * 16, 8 * 16, 16, 16));
	else sprite.setTextureRect(sf::IntRect(0 * 16, 8 * 16, 16, 16));
}