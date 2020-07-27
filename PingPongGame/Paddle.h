#pragma once
#include "SDL.h"
#include "Constants.h"
#include <iostream>
#include <sstream>

class Paddle
{
public:
	// constractor
	Paddle();

	// public functions
	void initPaddle();
	void showPaddle(SDL_Renderer* mRenderer, std::string dir);
	void movePaddle();
	void updatePaddle(float deltaTime, std::string dir);


};

