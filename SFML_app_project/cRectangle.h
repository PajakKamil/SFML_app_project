#pragma once
#ifndef _rectangle_h_

#include <SFML/Graphics.hpp>

#define _rectangle_h_
class Rectangle : public sf::Drawable, public sf::Transformable
{
public:
	Rectangle(sf::RenderWindow& window);
	virtual ~Rectangle() = default;
	static void Controll(sf::RenderWindow& window, Rectangle& _target);

private:
	sf::RectangleShape shape;
	const sf::Vector2f shape_size_default{100, 10};
	sf::FloatRect shape_bounds;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	const sf::Vector2f move_right{ 5.f, 0.f };
	const sf::Vector2f move_left{ -5.f, 0.f };
};

#endif //_rectangle_h