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
    // draw the paddle
    SDL_SetRenderDrawColor(mRenderer, 0, 255, 0, 255);
    SDL_Rect paddle;

    if (dir == "right")
    {
        paddle = { mPaddlePosRight.x, mPaddlePosRight.y, thickness, paddleH };
    }
    if (dir == "left")
    {
        paddle = { mPaddlePosLeft.x, mPaddlePosLeft.y, thickness, paddleH };
    }

    SDL_RenderFillRect(mRenderer, &paddle);
}

void Paddle::movePaddle()
{
    const Uint8* state = SDL_GetKeyboardState(NULL);

    mPaddleDirRight = 0;
    if (state[SDL_SCANCODE_W]) { mPaddleDirRight -= 1; }
    if (state[SDL_SCANCODE_S]) { mPaddleDirRight += 1; }

    mPaddleDirLeft = 0;
    if (state[SDL_SCANCODE_UP]) { mPaddleDirLeft -= 1; }
    if (state[SDL_SCANCODE_DOWN]) { mPaddleDirLeft += 1; }
}

void Paddle::updatePaddle(float deltaTime, std::string dir)
{
    if (dir == "right")
    {
        // update paddle position
        if (mPaddleDirRight != 0)
        {
            mPaddlePosRight.y += mPaddleDirRight * speed * deltaTime;

            if (mPaddlePosRight.y < thickness)
            {
                mPaddlePosRight.y = thickness;
            }

            else if (mPaddlePosRight.y > (HIEGHT - paddleH - thickness))
            {
                mPaddlePosRight.y = HIEGHT - paddleH - thickness;
            }
        }
    }

    if (dir == "left")
    {
        // update paddle position
        if (mPaddleDirLeft != 0)
        {
            mPaddlePosLeft.y += mPaddleDirLeft * speed * deltaTime;

            if (mPaddlePosLeft.y < thickness)
            {
                mPaddlePosLeft.y = thickness;
            }

            else if (mPaddlePosLeft.y > (HIEGHT - paddleH - thickness))
            {
                mPaddlePosLeft.y = HIEGHT - paddleH - thickness;
            }
        }
    }
}
