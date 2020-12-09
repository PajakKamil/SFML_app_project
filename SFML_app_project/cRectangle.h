#pragma once
#ifndef _rectangle_h_

#include <SFML/Graphics.hpp>

#define _rectangle_h_

class cCollision;

class Rectangle : public sf::Drawable, public sf::Transformable
{
public:
	Rectangle(sf::RenderWindow& window);
	virtual ~Rectangle() = default;
	static void Controll(sf::RenderWindow& window, Rectangle& _target);

protected:
	sf::RectangleShape shape;

private:
	const sf::Vector2f shape_size_default{100, 10};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	const sf::Vector2f move_right{ 5.f, 0.f };
	const sf::Vector2f move_left{ -5.f, 0.f };
	friend class cCollision;
	sf::FloatRect shape_bounds;
};

#endif //_rectangle_h