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
	for (Rectangle& rect : _bricks)
	{
		if (rect.shape.getGlobalBounds().intersects(_ball.shape.getGlobalBounds()))
		{
			float brick_shape_right_x = (rect.shape.getPosition().x + (rect.bricks_size.x / 2.0));				//Prawo
			//float brick_shape_right_y = (rect.shape.getPosition().y + (rect.bricks_size.y / 2.0));
			////Po co mi to??
			//float brick_shape_bottom_x = (rect.shape.getPosition().x + (rect.bricks_size.x / 2.0));				//Dó³
			float brick_shape_bottom_y = (rect.shape.getPosition().y + (rect.bricks_size.y / 2.0));
			if (_ball.shape.getPosition().y < rect.shape.getGlobalBounds().top) // Odbicie od górnej krawêdzi
			{
				_ball.ball_speed.y = -abs(_ball.ball_speed.y);
			}
			if (_ball.shape.getPosition().x < rect.shape.getGlobalBounds().left) // Odbicie prawej krawêdzi
			{
				_ball.ball_speed.x = -abs(_ball.ball_speed.x);
			}
			if (_ball.shape.getPosition().x > brick_shape_right_x)	//Odbicie od lewej krawêdzi
			{
				_ball.ball_speed.x = abs(_ball.ball_speed.x);
			}
			if (_ball.shape.getPosition().y > brick_shape_bottom_y)		// Odbicie od dolnej krawêdzi
			{
				_ball.ball_speed.y = abs(_ball.ball_speed.y);
			}
			rect.brick_life--;
			if (!rect.brick_life)
			{
				//std::cout << "\n--------------------\nProstok¹t:\n--------------------\n";
				//std::cout << "X: " << rect.shape.getPosition().x << ", Y: " << rect.shape.getPosition().y << std::endl << std::endl;
				//std::cout << "Left: " << rect.shape.getGlobalBounds().left << "\nTop: " << rect.shape.getGlobalBounds().top << std::endl;
				//std::cout << "Bottom: " << rect.shape.getPosition().y + rect.bricks_size.y / 2.0 << std::endl;
				//std::cout << "Right: " << rect.shape.getPosition().x + rect.bricks_size.x / 2.0 << std::endl;
				//std::cout << "\nheight: " << rect.shape.getGlobalBounds().height << ", width: " << rect.shape.getGlobalBounds().width << std::endl;
				////std::cout << "Left_top: " << left_top << ", Left_bottom: " << left_bottom << std::endl << std::endl;

				//std::cout << "\n---------------------\nBall\n---------------------" << std::endl;
				//std::cout << "X: " << _ball.shape.getPosition().x << ", Y: " << _ball.shape.getPosition().y << std::endl << std::endl;
				//std::cout << "Left: " << _ball.shape.getGlobalBounds().left << "\nTop: " << _ball.shape.getGlobalBounds().top << std::endl;
				//std::cout << "Bottom: " << _ball.shape.getPosition().y + _ball.shape_bounds.height / 2.0 << std::endl;
				//std::cout << "Right: " << _ball.shape.getPosition().x + _ball.shape_bounds.width / 2.0 << std::endl;
				//std::cout << "\nheight: " << _ball.shape.getGlobalBounds().height << ", width: " << _ball.shape.getGlobalBounds().width << std::endl << std::endl;
				rect.shape.setPosition(9999, 9999);
			}
			//std::cout << "Life: " << rect.brick_life << std::endl;
		}
	}
	return;
}

//Top				   - Góra
//Left				   - Lewo
//(Pozycja.x + width)  - Prawo
//(Pozycja.y + height) - Lewo