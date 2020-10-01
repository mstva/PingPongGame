#include "Game.h"

Game::Game() :
    mWindow(nullptr),
    mRenderer(nullptr),
    isRunning(true),
    mTicksCount(0),
    paddle(),
    ball()
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

    mRenderer = SDL_CreateRenderer(
        mWindow,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    if (mRenderer == NULL)
    {
        SDL_Log("Unable to create SDL renderer: %s", SDL_GetError());
        return false;
    }

    // initialize paddle
    paddle.initPaddle();

    // initialize ball
    ball.initBall();

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
    while (isRunning)
    {
        processInput();
        updateGame();
        renderGame();
    }
}

void Game::checkCollision(Paddle* paddle, Ball* ball)
{

    static int scoreRight = 0;
    static int scoreLeft = 0;

    bool collideRight = checkCollideRight(*paddle, *ball);
    bool collideLeft = checkCollideLeft(*paddle, *ball);

    //if (collideRight) { cout << "scoreRight = " << scoreRight++ << endl; }

    //else if (collideLeft) { cout << "scoreLeft = " << scoreLeft++ << endl; }

}

bool Game::checkCollideRight(Paddle& paddle, Ball& ball)
{
    Vector2 paddlePosRight = paddle.getPaddlePosRight();
    Vector2 ballPos = ball.getBallPos();

    // collision x-axis?
    bool collisionX = 
        paddlePosRight.x + thickness 
        >= ballPos.x && ballPos.x + thickness 
        >= paddlePosRight.x;

    cout << "collisionX = " << collisionX << endl;

    // collision y-axis?
    bool collisionY = 
        paddlePosRight.y + paddleH 
        >= ballPos.y && ballPos.y + thickness 
        >= paddlePosRight.y;

    cout << "collisionY = " << collisionX << endl;

    // collision only if on both axes
    return collisionX && collisionY;
}

bool Game::checkCollideLeft(Paddle& paddle, Ball& ball)
{
    Vector2 paddlePosLeft = paddle.getPaddlePosLeft();
    Vector2 ballPos = ball.getBallPos();

    // collision x-axis?
    bool collisionX =
        paddlePosLeft.x + thickness
        >= ballPos.x && ballPos.x + thickness
        >= paddlePosLeft.x;

    // collision y-axis?
    bool collisionY =
        paddlePosLeft.y + paddleH
        >= ballPos.y && ballPos.y + thickness
        >= paddlePosLeft.y;

    // collision only if on both axes
    return collisionX && collisionY;
}

void Game::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        }
    }

    paddle.movePaddle();
}

void Game::updateGame()
{
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount));

    float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;

    if (deltaTime > 0.05f) { deltaTime = 0.05f; }

    mTicksCount = SDL_GetTicks();

    // update paddle position
    paddle.updatePaddle(deltaTime, "right");
    paddle.updatePaddle(deltaTime, "left");

    // update ball position
    ball.updateBall(deltaTime);

    // check collision
    checkCollision(&paddle, &ball);
}

void Game::renderGame()
{
    // set background color
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);

    // draw the paddle
    paddle.showPaddle(mRenderer, "right");
    paddle.showPaddle(mRenderer, "left");

    // draw the ball
    ball.showBall(mRenderer);

    // present the render on the screen
    SDL_RenderPresent(mRenderer);
}
