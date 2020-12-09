#pragma once
#ifndef _collision_h_

#include "Collision.h"
#include "cRectangle.h"
#include "cBall.h"
#include <SFML/Graphics.hpp>

#define _collision_h_

class cCollision : public Rectangle, public Ball, public sf::Transformable
{
public:
	static void Collision(Rectangle& _racket, Ball& _ball);
private:
};

#endif // !_collision_h_
