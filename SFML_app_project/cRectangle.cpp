#include "cRectangle.h"

sf::Vector2f Rectangle::position{ 70.f, 20.f };

Rectangle::Rectangle(sf::RenderWindow& window)
{
	shape.setFillColor(sf::Color::White);
	shape.setSize(shape_size_default);
	shape.setOrigin(shape_size_default.x / 2, shape_size_default.y / 2);
	shape.setPosition(window.getSize().x / static_cast<float>(2), window.getSize().y - shape_size_default.y);
	this->shape_bounds = shape.getGlobalBounds();
}

void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
	return;
}


void Rectangle::Controll(sf::RenderWindow& window, Rectangle& _target)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && _target.shape.getPosition().x - (_target.shape_bounds.width / 2) > 0)
	{
		_target.shape.move(_target.move_left);
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && _target.shape.getPosition().x - (_target.shape_bounds.width / 2) > 0)
	{
		_target.shape.move(_target.move_left);
	}

	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && _target.shape.getPosition().x + (_target.shape_bounds.width / 2) < window.getSize().x)
	{
		_target.shape.move(_target.move_right);
	}*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && _target.shape.getPosition().x + (_target.shape_bounds.width / 2) < window.getSize().x)
	{
		_target.shape.move(_target.move_right);
	}

	return;
}

void Rectangle::Bricks(sf::RenderWindow& window)
{
	//if (_bricks.size() > 1)
	//	_bricks[0].setPosition(shape_size_default);
	//else
	//	return;
	//float position = shape_size_default.y;
	//if (_bricks.size() > 2)
	//{
	//	for (int i = 1; i < _bricks.size(); i++)
	//	{
	//		if (_bricks[i].getPosition().x + shape_size_default.x < window.getSize().x)
	//		{
	//			_bricks[i].setPosition(_bricks[static_cast<std::vector<Rectangle, std::allocator<Rectangle>>::size_type>(i) - 1].getPosition().x + shape_size_default.x, _bricks[i].getPosition().y);
	//			//To samo co:	_bricks[i].setPosition(_bricks[i - 1].getPosition() + shape_size_default);
	//		}
	//		else if (_bricks[i].getPosition().x + shape_size_default.x > window.getSize().x)
	//		{
	//			position += shape_size_default.y;
	//			_bricks[i].setPosition(shape_size_default.x, position);
	//		}
	//	}
	//}
	//shape.setOrigin()
	shape.setOrigin(bricks_size.x / 2, bricks_size.y / 2);
	shape.setSize(bricks_size);
	if (position.x < window.getSize().x)
	{
		this->shape.setPosition(position.x / 2, position.y / 2);
		position.x += position.x;
	}
	else if (position.x > window.getSize().x)
	{
		position.y += position.y;
		position.x = bricks_size.x;
		shape.setPosition(position.x + 2, position.y / 2);
	}
	std::cout << "X: " << shape.getPosition().x << std::endl << "Y: " << shape.getPosition().y << std::endl;
	return;
}