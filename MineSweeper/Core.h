#ifndef CORE_H
#define CORE_H

#include "SFML\Graphics.hpp"

class Board;

class Core{
public:
	int WIDTH, HEIGHT;
	Board* board;
	sf::RenderWindow* window;
	sf::Event* event;
	int rightClickPresses, rightClickAbsorbs;
	bool rightClicked;

	Core();
	~Core();

	void start();
	void update();
	void render(sf::RenderWindow* window);
};

#endif