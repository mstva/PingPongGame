#include "Game.h"

int main(int argc, char** argv) {

	Game game;

	if (game.initGame()) { game.runGame(); }

	game.closeGame();

	return 0;
}