#pragma once

#include <SFML/Graphics.hpp>

#include "RoomManager.h"

class GameLoop
{
public:
	GameLoop(int windowWidth, int windowHeight, sf::String windowTitle);
	~GameLoop();

	void Run();

private:
	sf::RenderWindow _window;
	sf::Clock dtClock;

	RoomManager* _roomManager;
};

