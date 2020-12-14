#include "Collision.h"

void cCollision::Collision(Rectangle& _racket, Ball& _ball)
{
	if (_racket.shape.getGlobalBounds().intersects(_ball.shape.getGlobalBounds()))
	{
		_ball.ball_speed.y = -abs(_ball.ball_speed.y);
	}
	return;
}

void cCollision::Collision(std::vector<Rectangle>& _bricks, Ball& _ball)
{
	for(int i = 0; i < _bricks.size(); i++)
	if (_bricks[i].shape.getGlobalBounds().intersects(_ball.shape.getGlobalBounds()))
	{
		_ball.ball_speed.y = -abs(_ball.ball_speed.y);
	}
	return;
}