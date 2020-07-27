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
}

void Ball::showBall(SDL_Renderer* mRenderer)
{
}

void Ball::updateBall(float deltaTime)
{
}
