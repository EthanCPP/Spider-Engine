#include "GameLoop.h"

#include <iostream>
int main()
{
	GameLoop* gameLoop = new GameLoop(1920, 1080, "Spider Engine");
	gameLoop->Run();

	return 0;
}