#pragma once
#ifndef _rectangle_h_

#include <SFML/Graphics.hpp>
#include <iostream>

#define _rectangle_h_

class cCollision;

class Rectangle : public sf::Drawable, public sf::Transformable
{
public:
	Rectangle(sf::RenderWindow& window);
	void Bricks(sf::RenderWindow& window);
	virtual ~Rectangle() = default;
	static void Controll(sf::RenderWindow& window, Rectangle& _target);

protected:
	sf::RectangleShape shape;

private:
	const sf::Vector2f shape_size_default{100, 10};
	const sf::Vector2f bricks_size{ 70,20 };
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	const sf::Vector2f move_right{ 5.f, 0.f };
	const sf::Vector2f move_left{ -5.f, 0.f };
	friend class cCollision;
	sf::FloatRect shape_bounds;
	static sf::Vector2f position;
};

#endif //_rectangle_h