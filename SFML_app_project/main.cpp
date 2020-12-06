#include "header.h"


int main()
{
	system("chcp 1250");
	sf::RenderWindow window(sf::VideoMode(800, 600), "Moje okno");
	window.setFramerateLimit(60);
	Ball main_shape;
	Ball shape(300, 300);
	//Vector:
	//std::vector<Ball> balls;
	//balls.push_back(shape);				//Dzia³a
	//balls[0].setPosition(100, 200)
	
	//Lista:
	/*std::list<Ball> balls;
	balls.push_back(shape);
	balls.resize(10);
	//auto balls_it = balls.begin();
	//			//lub
	std::list<Ball>::iterator balls_it = balls.begin();*/

	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		main_shape.Update(window);
		shape.Update(window);
		//balls[0].Update(window);
		Ball::Collision(main_shape, shape);			// Kazd¹ kolizjê trzeba sprawdzaæ osobno (niestety / stety)
		Ball::Take_control(shape);					// Nad jakim obiektem chcesz przej¹æ kontrolê?
		window.clear(sf::Color::Black);
		window.draw(main_shape);
		window.draw(shape);
		//Draw dla vectora:
		//window.draw(balls[0]);

		//Draw dla listy:
		/*for (balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
		{
			Ball& rect = (*balls_it);
			window.draw(rect);
		}*/
		window.display();
	}
	return 0;
}

// Sektor nie udanych eksperymentów i wstydliwej przesz³oœci <NIE WCHODZIÆ>

//void Eat_them_all(sf::RenderWindow& window, std::list<sf::CircleShape>& balls, sf::CircleShape& shape, float& speed_x, float& speed_y);
//
//void Balls_collision(sf::RenderWindow& window, std::vector<sf::CircleShape>& balls, sf::CircleShape& shape);
//
//int main()
//{
//	srand(time(NULL));
//	sf::RenderWindow window(sf::VideoMode(1280, 720), "Kamil i jego OKNO!");
//	window.setFramerateLimit(60);
//	float shape_render_size = 10;
//	sf::CircleShape shape{ shape_render_size };
//	std::list<sf::CircleShape> balls(10);
//	//std::vector<sf::CircleShape> balls;
//	balls.resize(10, sf::CircleShape{ shape_render_size });
//
//	//std::list<sf::CircleShape>::iterator balls_it = balls.begin();		// Czy ten iterator bêdzie potrzebny?
//
//	std::cout << "Czerwone pilki: " << balls.size() << std::endl;
//	std::cout << "Rozmiar pilki: " << shape.getRadius() << std::endl;
//	/*sf::FloatRect test = shape.getGlobalBounds();
//	std::cout << "\nWidth: " << test.width / 2;*/
//
//	for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//	{
//		balls_it->setFillColor(sf::Color::Red);
//		balls_it->setPosition(rand() % window.getSize().x - (shape_render_size * 2), rand() % window.getSize().y - (shape_render_size * 2));
//		if (balls_it->getPosition().x <= shape_render_size)
//		{
//			balls_it->setPosition(balls_it->getPosition().x + (shape_render_size * 2) + 3 , balls_it->getPosition().y);
//		}
//		else if (balls_it->getPosition().y <= shape_render_size)
//		{
//			balls_it->setPosition(balls_it->getPosition().x, balls_it->getPosition().y + (shape_render_size * 2) + 3);
//		}
//	}
//	shape.setFillColor(sf::Color::White);
//	float speed_x{ 1 }, speed_y{ 1 };
//	float speed_limit{ 12 };
//	shape.setPosition(0, 0);
//	std::vector<float> random_move_x(balls.size());
//	std::vector<float> random_move_y(balls.size());
//	for (int i = 0; i < balls.size(); i++)
//	{
//		random_move_x[i] = (rand() % 7 - 3);
//		random_move_y[i] = (rand() % 7 - 3);
//		if (random_move_x[i] == 0)
//		{
//			while (random_move_x[i] == 0)
//			{
//				random_move_x[i] = (rand() % 7 - 3);
//			}
//		}
//		else if (random_move_y[i] == 0)
//		{
//			random_move_y[i] = (rand() % 7 - 3);
//		}
//	}
//	//std::cout << typeid(window.getSize().y).name();
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		Eat_them_all(window, balls, shape, speed_x, speed_y);
//		shape.move(speed_x, speed_y);
//		int i = 0;
//		for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//		{
//			balls_it->move(random_move_x[i], random_move_y[i]);
//			i++;
//		}
//		i = 0;
//		for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//		{
//			if (balls_it->getPosition().y + (balls_it->getRadius() * 2) > window.getSize().y || balls_it->getPosition().y + (balls_it->getRadius() * 2) <= (balls_it->getRadius() * 2))
//			{
//				random_move_y[i] *= -1;
//			}
//			else if (balls_it->getPosition().x + (balls_it->getRadius() * 2) > window.getSize().x)
//			{
//				random_move_x[i] *= -1;
//			}
//			else if (balls_it->getPosition().x + (balls_it->getRadius() * 2) <= (balls_it->getRadius() * 2))
//			{
//				random_move_x[i] *= -1;
//			}
//			i++;
//		}
//
//		if (shape.getPosition().y + (shape.getRadius() * 2) > window.getSize().y)
//		{
//			speed_y *= -1;
//		}
//		if (shape.getPosition().y + (shape.getRadius() * 2) <= (shape.getRadius() * 2))
//		{
//			speed_y *= -1;
//		}
//		if (shape.getPosition().x + (shape.getRadius() * 2) > window.getSize().x)
//		{
//			speed_x *= -1;
//		}
//		if (shape.getPosition().x + (shape.getRadius() * 2) <= (shape.getRadius() * 2))
//		{
//			speed_x *= -1;
//			//shape.setPosition(shape.getPosition().x + shape.getRadius(), shape.getPosition().y);
//		}
//
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
//		{
//			speed_y -= 0.12;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
//		{
//			speed_y += 0.12;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
//		{
//			speed_x += 0.12;
//		}
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
//		{
//			speed_x -= 0.12;
//		}
//
//
//		if (speed_x > speed_limit)
//		{
//			speed_x = speed_limit;
//		}
//		else if (speed_x < -speed_limit)
//		{
//			speed_x = -speed_limit;
//		}
//		else if (speed_y > speed_limit)
//		{
//			speed_y = speed_limit;
//		}
//		else if (speed_y < -speed_limit)
//		{
//			speed_y = -speed_limit;
//		}
//
//		window.clear(sf::Color::Black);
//		window.draw(shape);
//		std::list<sf::CircleShape>::iterator it;
//		for (it = balls.begin(); it != balls.end(); it++)
//		{
//			sf::CircleShape& rect = (*it);
//			window.draw(rect);
//		}
//		/*for (auto balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//			window.draw(*balls_it);*/	//Ten sprób to nie sposób bo nie dzi³a :(
//		window.display();
//	}
//	return 0;
//}
//
//void Eat_them_all(sf::RenderWindow& window, std::list<sf::CircleShape>& balls, sf::CircleShape& shape, float &speed_x, float &speed_y)
//{
//	sf::FloatRect shape_1 = shape.getGlobalBounds();
//	std::vector<sf::FloatRect> balls_1(balls.size());
//	static unsigned int balls_counter = balls.size() - 1;
//	static float shape_radius = shape.getRadius();
//	int i = 0;
//	for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//	{
//		balls_1[i] = balls_it->getGlobalBounds();
//		i++;
//	}
//	i = 0;
//	for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//	{
//		float distance_x(shape.getPosition().x + (balls_1[i].width / 2) - balls_it->getPosition().x + (balls_1[i].width / 2));
//		float distance_y(shape.getPosition().y + (balls_1[i].width /2 ) - balls_it->getPosition().y + (balls_1[i].width / 2));
//		float distance = std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
//		if (distance <= (balls_1[i].width / 2) + (balls_1[i].width / 2))
//		{
//			std::cout << "Pozostalo: " << --balls_counter << " czerwonych pilek\n";
//			//balls[i].setPosition(9999, 9999);
//			//balls[i].move(0, 0);
//			std::list<sf::CircleShape>::iterator iterator_delete = balls_it;
//			balls.erase(iterator_delete);
//			balls_it = balls.begin();
//			shape.setRadius(shape.getRadius() + 2);
//			if (speed_x > 0 && speed_y > 0)
//			{
//				speed_x++;
//				speed_y++;
//			}
//			else if (speed_x < 0 && speed_y < 0)
//			{
//				speed_x--;
//				speed_y--;
//			}
//			else if (speed_x > 0 && speed_y < 0)
//			{
//				speed_x++;
//				speed_y--;
//			}
//			else if (speed_x < 0 && speed_y > 0)
//			{
//				speed_x--;
//				speed_y++;
//			}
//			std::cout << "Rozmiar pilki: " << ++shape_radius << std::endl << std::endl;
//		}
//		i++;
//	}
//	return;
//}
//
//void Balls_collision(sf::RenderWindow& window, std::vector<sf::CircleShape>& balls, sf::CircleShape& shape)
//{
//	sf::FloatRect shape_1 = shape.getGlobalBounds();
//	std::vector<sf::FloatRect> balls_1(balls.size());
//	for (int i = 0; i < balls.size(); i++)
//	{
//		balls_1[i] = balls[i].getGlobalBounds();
//	}
//	for (int i = 0; i < balls.size(); i++)
//	{
//		float distance_x(shape.getPosition().x + (shape_1.width / 2) - balls[i].getPosition().x + (balls_1[i].width / 2));
//		float distance_y(shape.getPosition().y + (shape_1.width / 2) - balls[i].getPosition().y + (balls_1[i].width / 2));
//		float distance = std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
//		if (distance <= (shape_1.width / 2) + (balls_1[i].width / 2))
//		{
//			std::cout << "Tuaj siê coœ napiszê";
//			//Bla bla kod...
//		}
//	}
//	return;
//}


// Tutaj jest poligon doœwiadczalny:

//int main()
//{
//	srand(time(NULL));
//	sf::RenderWindow window(sf::VideoMode(1280, 720), "Kamil i jego OKNO!");
//	window.setFramerateLimit(60);
//	float shape_render_size = 10;
//	sf::CircleShape shape{ shape_render_size };
//	std::list<sf::CircleShape> balls;
//	balls.resize(5, sf::CircleShape{ shape_render_size });
//	std::cout << "Rozmiar listy: " << balls.size() << std::endl;
//	std::list<sf::CircleShape>::iterator balls_it_s = balls.begin();
//	shape.setFillColor(sf::Color::White);
//	for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//	{
//		balls_it->setFillColor(sf::Color::Red);
//	}
//
//	for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//	{
//		int position_x = rand() % window.getSize().x + (shape_render_size * 2) + 2;
//		int position_y = rand() % window.getSize().y + (shape_render_size * 2) + 2;
//		if (position_x + (shape_render_size * 2) >= window.getSize().x)
//		{
//			position_x -= 100;
//		}
//		else if (position_y + (shape_render_size * 2) >= window.getSize().y)
//		{
//			position_y -= 100;
//		}
//		balls_it->setPosition(position_x, position_y);
//		//balls_it->setPosition(60, 60);
//		std::cout << balls_it->getRadius() << std::endl;
//	}
//	balls_it_s->setPosition(9999, 9999);
//	float speed_x = 1, speed_y = 1;
//	shape.setPosition(0, 0);
//	std::cout << "X3: " << std::next(balls.begin(), 3)->getPosition().x << std::endl;
//	std::cout << "X1: " << std::next(balls.begin(), 1)->getPosition().x << std::endl;
//
//	//std::cout << typeid(window.getSize().y).name();
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//				window.close();
//		}
//		Eat_them_all(window, balls, shape, speed_x, speed_y);
//		shape.move(speed_x, speed_y);
//
//		//for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//		//{
//		//	balls_it->move(1, 1);
//		//}
//
//		if (shape.getPosition().y + (shape.getRadius() * 2) > window.getSize().y)
//		{
//			speed_y *= -1;
//		}
//		if (shape.getPosition().y + (shape.getRadius() * 2) <= (shape.getRadius() * 2))
//		{
//			speed_y *= -1;
//		}
//		if (shape.getPosition().x + (shape.getRadius() * 2) > window.getSize().x)
//		{
//			speed_x *= -1;
//		}
//		if (shape.getPosition().x + (shape.getRadius() * 2) <= (shape.getRadius() * 2))
//		{
//			speed_x *= -1;
//			//shape.setPosition(shape.getPosition().x + shape.getRadius(), shape.getPosition().y);
//		}
//
//		window.clear(sf::Color::Black);
//		window.draw(shape);
//
//		if (balls.size() > 0)
//		{
//			std::list<sf::CircleShape>::iterator it;
//			for (it = balls.begin(); it != balls.end(); it++)
//			{
//				sf::CircleShape& rect = (*it);
//				window.draw(rect);
//
//			}
//		}
//		//for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++);
//		//{
//		//	window.draw(*balls_it);
//		//	std::cout << "X loop: " << balls_it->getPosition().x << std::endl;
//		//	std::cout << "X3: " << std::next(balls.begin(), 3)->getPosition().x << std::endl;
//		//	std::cout << "X1: " << std::next(balls.begin(), 1)->getPosition().x << std::endl;
//		//}
//		window.display();
//	}
//	return 0;
//}