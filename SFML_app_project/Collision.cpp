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
	for(Rectangle& rect : _bricks)
	if (rect.shape.getGlobalBounds().intersects(_ball.shape.getGlobalBounds()))
	{
		_ball.ball_speed.y = abs(_ball.ball_speed.y);
		rect.brick_life--;
		if (!rect.brick_life)
		{
			std::cout << "Destruction!\n";
			rect.shape.setPosition(9999, 9999);
		}
		std::cout << "Life: " << rect.brick_life << std::endl;
	}
	return;
}
