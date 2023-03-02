#include "Room.h"
#include <iostream>

Room::Room(sf::RenderWindow& window) : _window(window)
{
}

Room::~Room()
{
}

void Room::Init()
{
}

void Room::HandleInput()
{
	while (this->_window.pollEvent(this->_event))
	{
		switch (this->_event.type)
		{
		case sf::Event::Closed:
			this->_window.close();
			break;
		default:
			break;
		}
	}
}

void Room::Update(float dt)
{
}

void Room::Draw()
{
}

void Room::Pause()
{

}

void Room::Resume()
{

}