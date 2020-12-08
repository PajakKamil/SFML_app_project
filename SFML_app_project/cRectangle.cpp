#include "cRectangle.h"

Rectangle::Rectangle(sf::RenderWindow& window)
{
	shape.setFillColor(sf::Color::White);
	shape.setSize(shape_size_default);
	shape.setOrigin(shape_size_default.x / 2, shape_size_default.y / 2);
	shape.setPosition(window.getSize().x / 2, window.getSize().y - shape_size_default.y);
	this->shape_bounds = shape.getGlobalBounds();
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
	return;
}

void Rectangle::Controll(sf::RenderWindow& window, Rectangle& _target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _target.shape.getPosition().x - (_target.shape_bounds.width / 2) > 0)
	{
		_target.shape.move(_target.move_left);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _target.shape.getPosition().x - (_target.shape_bounds.width / 2) > 0)
	{
		_target.shape.move(_target.move_left);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _target.shape.getPosition().x + (_target.shape_bounds.width / 2) < window.getSize().x)
	{
		_target.shape.move(_target.move_right);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _target.shape.getPosition().x + (_target.shape_bounds.width / 2) < window.getSize().x)
	{
		_target.shape.move(_target.move_right);
	}

	return;
}