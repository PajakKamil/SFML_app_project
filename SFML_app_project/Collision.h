#pragma once
#ifndef _collision_h_

#include "Collision.h"
#include "cRectangle.h"
#include "cBall.h"
#include <SFML/Graphics.hpp>

#define _collision_h_

class cCollision
{
public:
	void Collision(Rectangle& _racket, Ball& _ball);
	void Collision(std::vector<Rectangle>& _bricks, Ball& _ball);
private:
};

#endif // !_collision_h_
