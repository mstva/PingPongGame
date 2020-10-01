#pragma once
#include "SDL.h"
#include "Constants.h"
#include <cstdio>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
using namespace std;

class Game
{
public:
	// constructor
	Game();

	// public functions
	bool initGame();
	void closeGame();
	void runGame();

private:
	// private functions
	void checkCollision(Paddle* paddle, Ball* ball);
	bool checkCollideRight(Paddle &paddle, Ball &ball);
	bool checkCollideLeft(Paddle &paddle, Ball &ball);
	void processInput();
	void updateGame();
	void renderGame();

	// private varible
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	Paddle paddle;
	Ball ball;

	// game logic
	bool isRunning;
	Uint32 mTicksCount;
};

