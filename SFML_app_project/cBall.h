#pragma once

#ifndef _ball_h_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <random>
#include <ctime>
#include <cmath>

#define _ball_h_

class cCollision;

class Ball : public sf::Drawable
{
public:
	Ball();
	Ball(float _x, float _y);
	~Ball() = default;
	void Update(sf::RenderWindow& window);
	void Update(sf::RenderWindow& window, Ball*& _target);
	static void Collision(Ball& _circle_shape, Ball& _circle_shape_1);
	static void Take_control(Ball& _target);

protected:
	sf::Vector2f ball_speed{4, 4};
	sf::CircleShape shape;

private:
	const float shape_radius{ 10.f };
	virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
	float Top();
	float Bottom();
	float Right();
	float Left();
	sf::SoundBuffer buffer;
	sf::Sound sound;
	friend class cCollision;
	sf::FloatRect shape_bounds;
};

#endif // !_ball_h_