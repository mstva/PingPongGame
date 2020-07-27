#include "Paddle.h"
#include "Game.h"

Paddle::Paddle() :
    mPaddlePosRight(),
    mPaddlePosLeft(),
    mPaddleDirRight(0),
    mPaddleDirLeft(0)
{
}

void Paddle::initPaddle()
{
    mPaddlePosRight.x = 0;
    mPaddlePosRight.y = HIEGHT / 2;

    mPaddlePosLeft.x = WIDTH - thickness;
    mPaddlePosLeft.y = HIEGHT / 2;
}

void Paddle::showPaddle(SDL_Renderer* mRenderer, std::string dir)
{
}

void Paddle::movePaddle()
{
}

void Paddle::updatePaddle(float deltaTime, std::string dir)
{
}
