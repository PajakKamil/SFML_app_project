#include "cBall.h"


Ball::Ball()
{
	shape.setPosition(shape_radius, shape_radius);
	shape.setRadius(shape_radius);
	shape.setFillColor(sf::Color::White);
	shape.setOrigin(shape_radius, shape_radius); // Ustawienie dla "origin" poczêtek wiesz tego... punktu, który to jest uwa¿any za punkt :)
	ball_speed.x = ball_speed.y = 4;
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
	ball_speed.x= rand() % 7 - 3;
	ball_speed.y = rand() % 7 - 3;
	if (ball_speed.x == 0)
	{
		ball_speed.x--;
	}
	if (ball_speed.y == 0)
	{
		ball_speed.y++;
	}
	return;
}

void Ball::Update(sf::RenderWindow& window)
{
	shape.move(ball_speed);
	if (Left() < 0)
	{
		ball_speed.x = abs(ball_speed.x);
	}
	else if (Right() > window.getSize().x)
	{
		ball_speed.x = -abs(ball_speed.x);
	}

	if (Top() < 0)
	{
		ball_speed.y = abs(ball_speed.y);
	}
	else if (Bottom() > window.getSize().y)
	{
		ball_speed.y = -abs(ball_speed.y);
		buffer.loadFromFile("Audio/Woof_woof.flac");
		sound.setBuffer(buffer);
		sound.play();
	}
	return;
}


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

void Ball::Collision(Ball _which, Ball& _what)
{
	float distance_x = (_which.shape.getPosition().x + (_what.shape_bounds.width / 2)) - (_what.shape.getPosition().x + (_what.shape_bounds.width / 2));
	float distance_y = (_which.shape.getPosition().y + (_what.shape_bounds.height /2 )) - (_what.shape.getPosition().y + (_what.shape_bounds.width / 2));
	float distance = std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
	if (distance <= (_what.shape_bounds.width / 2) + (_what.shape_bounds.width / 2))
	{
		std::cout << "Uda³o sie :)\n";
	}
		return;
}

void Ball::Take_control(Ball& _target)
{
	if (_target.shape.getFillColor() != sf::Color::Green)
	{
		_target.shape.setFillColor(sf::Color::Green);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		_target.ball_speed.y -= 0.12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		_target.ball_speed.y += 0.12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		_target.ball_speed.x += 0.12;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		_target.ball_speed.x -= 0.12;
	}

	if (_target.ball_speed.x > 7)
	{
		_target.ball_speed.x = 7;
	}
	else if (_target.ball_speed.x < -7)
	{
		_target.ball_speed.x = -7;
	}

	if (_target.ball_speed.y > 7)
	{
		_target.ball_speed.y = 7;
	}
	else if (_target.ball_speed.y < -7)
	{
		_target.ball_speed.y = -7;
	}
	return;
}