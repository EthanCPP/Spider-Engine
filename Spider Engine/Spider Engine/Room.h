#pragma once

#include <SFML/Graphics.hpp>

class Room
{
public:
	Room(sf::RenderWindow& window);
	~Room();

	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw();

	void Pause();
	void Resume();

private:

	sf::RenderWindow& _window;
	sf::Event _event;

};

