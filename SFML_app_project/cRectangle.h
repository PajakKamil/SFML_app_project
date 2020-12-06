#pragma once
#ifndef _rectangle_h_

#include <SFML/Graphics.hpp>

#define _rectangle_h_
class Rectangle : public sf::Drawable, public sf::Transformable
{
public:
	Rectangle();
	virtual ~Rectangle() = default;

private:
	sf::RectangleShape shape;
	const sf::Vector2f shape_size_default{50, 20};
	sf::FloatRect shape_bounds = shape.getGlobalBounds();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

#endif //_rectangle_h