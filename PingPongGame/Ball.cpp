#include "Ball.h"
#include "Game.h"

Ball::Ball() :
	mBallPos(),
	mBallVel()
{
}

void Ball::initBall()
{
	// init ball position
	mBallPos.x = (WIDTH - thickness) / 2;
	mBallPos.y = (HIEGHT - thickness) / 2;

	// init ball velocity
	mBallVel.x = 200;
	mBallVel.y = -200;
}

void Ball::showBall(SDL_Renderer* mRenderer)
{
	// draw the ball
	SDL_SetRenderDrawColor(mRenderer, 0, 255, 0, 255);
	SDL_Rect ball{ mBallPos.x, mBallPos.y, thickness, thickness };
	SDL_RenderFillRect(mRenderer, &ball);
}

void Ball::updateBall(float deltaTime)
{
	//update ball position
	mBallPos.x += mBallVel.x * deltaTime;
	mBallPos.y += mBallVel.y * deltaTime;

	// collide with the top wall
	if (mBallPos.y <= thickness && mBallVel.y < 0)
	{
		mBallVel.y *= -1;
	}

	// collide with the left wall
	else if (mBallPos.x >= (WIDTH - thickness) && mBallVel.x > 0)
	{
		mBallVel.x *= -1;
	}

	// collide with the bottom wall
	else if (mBallPos.y >= (HIEGHT - thickness) && mBallVel.y > 0)
	{
		mBallVel.y *= -1;
	}

	// collide with the right wall
	else if (mBallPos.x <= 0 && mBallVel.x < 0)
	{
		mBallVel.x *= -1;
	}
}

Vector2 Ball::getBallPos()
{
	return mBallPos;
}
