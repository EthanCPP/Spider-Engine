#include "RoomManager.h"

#include <iostream>

RoomManager::RoomManager(sf::RenderWindow& window) : _window(window)
{
	// Add the splash room
	Room* splash = new Room(window);
	splash->Init();

	this->AddRoom(splash);
}

RoomManager::~RoomManager()
{
}

void RoomManager::AddRoom(Room* room)
{
	this->_rooms.push(room);
}

void RoomManager::HandleInput()
{
	if (!this->_rooms.empty())
	{
		this->_rooms.top()->HandleInput();
	}
}

void RoomManager::Update(float dt)
{
	if (!this->_rooms.empty())
	{
		this->_rooms.top()->Update(dt);
	}
}

void RoomManager::Render()
{
	this->_window.clear();

	if (!this->_rooms.empty())
	{
		this->_rooms.top()->Draw();
	}

	this->_window.display();
}
