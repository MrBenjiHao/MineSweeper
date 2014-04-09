#include "Core.h"
#include <iostream>
#include "Board.h"

Core::Core(){
	WIDTH = 768;
	HEIGHT = 768;

	board = new Board(this);
	rightClickPresses = 0;
	rightClickAbsorbs = 0;
	rightClicked = false;
	start();
}

Core::~Core(){}

void Core::start(){
	sf::RenderWindow mainWindow(sf::VideoMode(WIDTH, HEIGHT), "MineSweeper");
	mainWindow.setVisible(true);
	window = &mainWindow;
	mainWindow.setKeyRepeatEnabled(false);

	event = new sf::Event;
	sf::Clock clock;
	double prevTime = (double) clock.getElapsedTime().asSeconds();
	double currTime;
	double maxTimeDiff = 0.5;
	double delta = 1.0 / 30.0;
	double FPS_TIME = (double) clock.getElapsedTime().asMilliseconds();
	int ticks = 0, fps = 0;

	// Game Loop
    while (mainWindow.isOpen()){
		currTime = (double) clock.getElapsedTime().asSeconds();

		while (mainWindow.pollEvent(*event)){
			if (event->type == sf::Event::Closed) mainWindow.close();
			if(event->type == sf::Event::MouseButtonPressed && event->key.code == sf::Mouse::Right) rightClickPresses++;
		}

		if(currTime - prevTime > maxTimeDiff) prevTime = currTime;
		if(currTime >= prevTime){
			update();
			ticks++;
			prevTime += delta;
			if(currTime < prevTime){
				render(&mainWindow);
				fps++;
			}
		}
		else sf::sleep(sf::milliseconds(1000 * (prevTime - currTime)));
		
		if(rightClickAbsorbs < rightClickPresses){
			rightClickAbsorbs++;
			rightClicked = true;
		}
		else rightClicked = false;

		if(clock.getElapsedTime().asMilliseconds() - FPS_TIME > 1000){
			FPS_TIME += 1000;
			std::cout << ticks << " " << fps << std::endl;
			ticks = 0;
			fps = 0;
		}
    }
}

void Core::update(){
	board->update();
}

void Core::render(sf::RenderWindow* window){
	window->clear(sf::Color(100, 100, 100, 255));
	board->render(window);
	window->display();
}

int main(){
	Core minesweeper;

	return 0;
}