#include "Game.h"

Game::Game() :
    mWindow(nullptr),
    mRenderer(nullptr),
    isRunning(true),
    mTicksCount(0)
{
}

bool Game::initGame()
{
    // check SDL initialzation
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    // create the window
    mWindow = SDL_CreateWindow(
        "Ping Pong",                       // title
        SDL_WINDOWPOS_UNDEFINED,           // x position
        SDL_WINDOWPOS_UNDEFINED,           // y position
        WIDTH,                             // width
        HIEGHT,                            // height
        SDL_WINDOW_OPENGL                  // flag
    );

    // check window creating
    if (mWindow == NULL)
    {
        SDL_Log("Unable to create SDL window: %s", SDL_GetError());
        return false;
    }

    return true;
}

void Game::closeGame()
{
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

void Game::runGame()
{
}

void Game::processInput()
{
}

void Game::updateGame()
{
}

void Game::renderGame()
{
}
