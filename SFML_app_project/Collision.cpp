#include "Collision.h"

void cCollision::Collision(Rectangle& _racket, Ball& _ball)
{
	if (_racket.shape.getGlobalBounds().intersects(_ball.shape.getGlobalBounds()))
	{
		_ball.ball_speed.y = -abs(_ball.ball_speed.y);
	}
	return;
}