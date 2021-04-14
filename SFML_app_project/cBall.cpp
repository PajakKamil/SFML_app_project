#include "cBall.h"


Ball::Ball()
{
	shape.setPosition(shape_radius + 500, shape_radius + 500);
	shape.setRadius(shape_radius);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(shape_radius, shape_radius); // Ustawienie dla "origin" poczêtek wiesz tego... punktu, który to jest uwa¿any za punkt :)
	this->shape_bounds = shape.getGlobalBounds();
	return;
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
	return;
}


Ball::Ball(float _x, float _y)
{
	srand(time(NULL));
	shape.setPosition(_x, _y);
	shape.setRadius(this->shape_radius);
	shape.setOrigin(shape_radius, shape_radius);
	shape.setFillColor(sf::Color::Red);
	this->shape_bounds = shape.getGlobalBounds();
	do
	{
		ball_speed.x = rand() % 7 - 3;
		ball_speed.y = rand() % 7 - 3;
		if (ball_speed.x != 0 && ball_speed.y != 0)
		{
			break;
		}

	} while (true);

	return;
}

void Ball::Update(sf::RenderWindow& window)
{
	shape.move(ball_speed);
	if (Left() < 0)
	{
		ball_speed.x = abs(ball_speed.x);
		buffer.loadFromFile("Audio/Nice.flac");
		sound.setBuffer(buffer);
		sound.play();
	}
	else if (Right() > window.getSize().x)
	{
		ball_speed.x = -abs(ball_speed.x);
		buffer.loadFromFile("Audio/Nice.flac");
		sound.setBuffer(buffer);
		sound.play();
	}

	if (Top() < 0)
	{
		ball_speed.y = abs(ball_speed.y);
		buffer.loadFromFile("Audio/Nice.flac");
		sound.setBuffer(buffer);
		sound.play();
	}
	else if (Bottom() == window.getSize().y)
	{
		ball_speed.x = 0;
		ball_speed.y = 0;
		shape.setPosition(window.getSize().x / static_cast<float>(2), 9999);
		//ball_speed.y = -abs(ball_speed.y);
		/*buffer.loadFromFile("Audio/Woof_woof.flac");
		sound.setBuffer(buffer);
		sound.play();*/
	}
	return;
}


//void Ball::Update(sf::RenderWindow& window, Ball*& _target)
//{
//	shape.move(ball_speed);
//	if (Left() < 0)
//	{
//		ball_speed.x = abs(ball_speed.x);
//		buffer.loadFromFile("Audio/Nice.flac");
//		sound.setBuffer(buffer);
//		sound.play();
//	}
//	else if (Right() > window.getSize().x)
//	{
//		ball_speed.x = -abs(ball_speed.x);
//		buffer.loadFromFile("Audio/Nice.flac");
//		sound.setBuffer(buffer);
//		sound.play();
//	}
//
//	if (Top() < 0)
//	{
//		ball_speed.y = abs(ball_speed.y);
//		buffer.loadFromFile("Audio/Nice.flac");
//		sound.setBuffer(buffer);
//		sound.play();
//	}
//	else if (Bottom() > window.getSize().y)
//	{
//		ball_speed.y = -abs(ball_speed.y);
//		buffer.loadFromFile("Audio/Woof_woof.flac");
//		sound.setBuffer(buffer);
//		sound.play();
//		_target = NULL;
//		delete _target;
//		_target = NULL;
//	}
//	return;
//}


float Ball::Top()
{
	return shape.getPosition().y - shape.getRadius();
}

float Ball::Bottom()
{
	return shape.getPosition().y + shape.getRadius();
}

float Ball::Left()
{

	return shape.getPosition().x - shape.getRadius();
}

float Ball::Right()
{
	return shape.getPosition().x + shape.getRadius();
}

void Ball::Collision(Ball& _circle_shape, Ball& _circle_shape_1)
{
	float distance_x = (_circle_shape.shape.getPosition().x + (_circle_shape_1.shape_bounds.width / 2)) - (_circle_shape_1.shape.getPosition().x + (_circle_shape_1.shape_bounds.width / 2));
	float distance_y = (_circle_shape.shape.getPosition().y + (_circle_shape_1.shape_bounds.height /2 )) - (_circle_shape_1.shape.getPosition().y + (_circle_shape_1.shape_bounds.width / 2));
	float distance = std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
	if (distance <= (_circle_shape_1.shape_bounds.width / 2) + (_circle_shape_1.shape_bounds.width / 2))
	{
		//std::cout << "Uda³o sie :)\n";
		_circle_shape.ball_speed.x = -_circle_shape.ball_speed.x;
		_circle_shape.ball_speed.y = -_circle_shape.ball_speed.y;
		_circle_shape_1.ball_speed.x = -_circle_shape_1.ball_speed.x;		//Narazie beznadziejna kolizja ALEEEE!!! DZIA£A!
		_circle_shape_1.ball_speed.y = -_circle_shape_1.ball_speed.y;
	}
		return;
}

void Ball::Take_control()
{
	if (shape.getFillColor() != sf::Color::Green)
	{
		shape.setFillColor(sf::Color::Green);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		ball_speed.y -= 0.12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		ball_speed.y += 0.12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		ball_speed.x += 0.12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		ball_speed.x -= 0.12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		ball_speed.x = ball_speed.y = 0;
	}

	if (ball_speed.x > 7)
	{
		ball_speed.x = 7;
	}
	else if (ball_speed.x < -7)
	{
		ball_speed.x = -7;
	}

	if (ball_speed.y > 7)
	{
		ball_speed.y = 7;
	}
	else if (ball_speed.y < -7)
	{
		ball_speed.y = -7;
	}
	return;
}