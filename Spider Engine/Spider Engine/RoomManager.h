#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

#include "Room.h"

class RoomManager
{
public:
	RoomManager(sf::RenderWindow& window);
	~RoomManager();

	void AddRoom(Room* room);

	void HandleInput();
	void Update(float dt);
	void Render();

private:

	sf::RenderWindow& _window;

	std::stack<Room*> _rooms;

};

