#pragma once
#include "SDL.h"
#include "Constants.h"

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
	void processInput();
	void updateGame();
	void renderGame();

	// private varible
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	// game logic
	bool isRunning;
	Uint32 mTicksCount;
};

