#pragma once

#include "State.h"

class MainState : public State
{
	void Init();

	void HandleInput();
	void Update();
	void Draw(float dt);
};

