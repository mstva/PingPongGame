#pragma once
#include "SDL.h"
#include "Constants.h"

class Ball
{
public:
	// constractor
	Ball();

	// public functions
	void initBall();
	void showBall(SDL_Renderer* mRenderer);
	void updateBall(float deltaTime);
};

