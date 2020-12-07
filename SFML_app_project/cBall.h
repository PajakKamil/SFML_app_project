#pragma once

#ifndef _ball_h_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include <list>

#define _ball_h_

class Ball : public sf::Drawable, public sf::Transformable
{
public:
	Ball(const float rad);
	Ball(float _x, float _y, const float rad);
	~Ball() = default;
	void Update(sf::RenderWindow& window);
	static void Collision(Ball& _master, Ball& _food);
	static void Take_control(Ball& _target);

private:
	sf::CircleShape shape;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	sf::FloatRect shape_bounds;
	sf::Vector2f ball_speed{};
	float Top();
	float Bottom();
	float Right();
	float Left();
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

#endif // !_ball_h_