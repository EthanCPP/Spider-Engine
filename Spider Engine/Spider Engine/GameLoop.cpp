#include "GameLoop.h"

GameLoop::GameLoop(int windowWidth, int windowHeight, sf::String windowTitle)
{
	// Create the window
	this->_window.create(sf::VideoMode(windowWidth, windowHeight), windowTitle);
	this->_window.setFramerateLimit(60);

	// Create the room manager
	this->_roomManager = new RoomManager(this->_window);
}

GameLoop::~GameLoop()
{
}

void GameLoop::Run()
{
	while (this->_window.isOpen())
	{
		sf::Time dt = this->dtClock.restart();

		this->_roomManager->HandleInput();
		this->_roomManager->Update(dt.asSeconds());
		this->_roomManager->Render();
	}
}
