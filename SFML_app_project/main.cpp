#include "header.h"


int main()
{
	system("chcp 1250");
	sf::RenderWindow window(sf::VideoMode(800, 600), "Moje okno");
	window.setFramerateLimit(60);
	Ball additional_ball(30);
	Ball controled_ball(400, 300, 30);
	//Vector:
	/*std::vector<Ball> balls;
	balls.push_back(controled_ball);				//Dzia³a
	balls[0].setPosition(100, 200)*/
	
	//Lista:
	/*std::list<Ball> balls;
	balls.push_back(controled_ball);
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
			if (event.type == sf::Event::Resized)
			{
				std::cout << "new width: " << event.size.width << "\n";
				std::cout << "new height: " << event.size.width << "\n";
			}
		}

		additional_ball.Update(window);
		controled_ball.Update(window);
		//balls[0].Update(window);
		Ball::Collision(additional_ball, controled_ball);			// Kazd¹ kolizjê trzeba sprawdzaæ osobno (niestety / stety)
		Ball::Take_control(controled_ball);					// Nad jakim obiektem chcesz przej¹æ kontrolê?
		window.clear(sf::Color::Black);
		window.draw(additional_ball);
		window.draw(controled_ball);
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

//void Eat_them_all(sf::RenderWindow& window, std::list<sf::CircleShape>& balls, sf::CircleShape& controled_ball, float& speed_x, float& speed_y);
//
//void Balls_collision(sf::RenderWindow& window, std::vector<sf::CircleShape>& balls, sf::CircleShape& controled_ball);
//
//int main()
//{
//	srand(time(NULL));
//	sf::RenderWindow window(sf::VideoMode(1280, 720), "Kamil i jego OKNO!");
//	window.setFramerateLimit(60);
//	float shape_render_size = 10;
//	sf::CircleShape controled_ball{ shape_render_size };
//	std::list<sf::CircleShape> balls(10);
//	//std::vector<sf::CircleShape> balls;
//	balls.resize(10, sf::CircleShape{ shape_render_size });
//
//	//std::list<sf::CircleShape>::iterator balls_it = balls.begin();		// Czy ten iterator bêdzie potrzebny?
//
//	std::cout << "Czerwone pilki: " << balls.size() << std::endl;
//	std::cout << "Rozmiar pilki: " << controled_ball.getRadius() << std::endl;
//	/*sf::FloatRect test = controled_ball.getGlobalBounds();
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
//	controled_ball.setFillColor(sf::Color::White);
//	float speed_x{ 1 }, speed_y{ 1 };
//	float speed_limit{ 12 };
//	controled_ball.setPosition(0, 0);
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
//		Eat_them_all(window, balls, controled_ball, speed_x, speed_y);
//		controled_ball.move(speed_x, speed_y);
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
//		if (controled_ball.getPosition().y + (controled_ball.getRadius() * 2) > window.getSize().y)
//		{
//			speed_y *= -1;
//		}
//		if (controled_ball.getPosition().y + (controled_ball.getRadius() * 2) <= (controled_ball.getRadius() * 2))
//		{
//			speed_y *= -1;
//		}
//		if (controled_ball.getPosition().x + (controled_ball.getRadius() * 2) > window.getSize().x)
//		{
//			speed_x *= -1;
//		}
//		if (controled_ball.getPosition().x + (controled_ball.getRadius() * 2) <= (controled_ball.getRadius() * 2))
//		{
//			speed_x *= -1;
//			//controled_ball.setPosition(controled_ball.getPosition().x + controled_ball.getRadius(), controled_ball.getPosition().y);
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
//		window.draw(controled_ball);
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
//void Eat_them_all(sf::RenderWindow& window, std::list<sf::CircleShape>& balls, sf::CircleShape& controled_ball, float &speed_x, float &speed_y)
//{
//	sf::FloatRect shape_1 = controled_ball.getGlobalBounds();
//	std::vector<sf::FloatRect> balls_1(balls.size());
//	static unsigned int balls_counter = balls.size() - 1;
//	static float shape_radius = controled_ball.getRadius();
//	int i = 0;
//	for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//	{
//		balls_1[i] = balls_it->getGlobalBounds();
//		i++;
//	}
//	i = 0;
//	for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//	{
//		float distance_x(controled_ball.getPosition().x + (balls_1[i].width / 2) - balls_it->getPosition().x + (balls_1[i].width / 2));
//		float distance_y(controled_ball.getPosition().y + (balls_1[i].width /2 ) - balls_it->getPosition().y + (balls_1[i].width / 2));
//		float distance = std::sqrt(std::pow(distance_x, 2) + std::pow(distance_y, 2));
//		if (distance <= (balls_1[i].width / 2) + (balls_1[i].width / 2))
//		{
//			std::cout << "Pozostalo: " << --balls_counter << " czerwonych pilek\n";
//			//balls[i].setPosition(9999, 9999);
//			//balls[i].move(0, 0);
//			std::list<sf::CircleShape>::iterator iterator_delete = balls_it;
//			balls.erase(iterator_delete);
//			balls_it = balls.begin();
//			controled_ball.setRadius(controled_ball.getRadius() + 2);
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
//void Balls_collision(sf::RenderWindow& window, std::vector<sf::CircleShape>& balls, sf::CircleShape& controled_ball)
//{
//	sf::FloatRect shape_1 = controled_ball.getGlobalBounds();
//	std::vector<sf::FloatRect> balls_1(balls.size());
//	for (int i = 0; i < balls.size(); i++)
//	{
//		balls_1[i] = balls[i].getGlobalBounds();
//	}
//	for (int i = 0; i < balls.size(); i++)
//	{
//		float distance_x(controled_ball.getPosition().x + (shape_1.width / 2) - balls[i].getPosition().x + (balls_1[i].width / 2));
//		float distance_y(controled_ball.getPosition().y + (shape_1.width / 2) - balls[i].getPosition().y + (balls_1[i].width / 2));
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
//	sf::CircleShape controled_ball{ shape_render_size };
//	std::list<sf::CircleShape> balls;
//	balls.resize(5, sf::CircleShape{ shape_render_size });
//	std::cout << "Rozmiar listy: " << balls.size() << std::endl;
//	std::list<sf::CircleShape>::iterator balls_it_s = balls.begin();
//	controled_ball.setFillColor(sf::Color::White);
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
//	controled_ball.setPosition(0, 0);
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
//		Eat_them_all(window, balls, controled_ball, speed_x, speed_y);
//		controled_ball.move(speed_x, speed_y);
//
//		//for (std::list<sf::CircleShape>::iterator balls_it = balls.begin(); balls_it != balls.end(); balls_it++)
//		//{
//		//	balls_it->move(1, 1);
//		//}
//
//		if (controled_ball.getPosition().y + (controled_ball.getRadius() * 2) > window.getSize().y)
//		{
//			speed_y *= -1;
//		}
//		if (controled_ball.getPosition().y + (controled_ball.getRadius() * 2) <= (controled_ball.getRadius() * 2))
//		{
//			speed_y *= -1;
//		}
//		if (controled_ball.getPosition().x + (controled_ball.getRadius() * 2) > window.getSize().x)
//		{
//			speed_x *= -1;
//		}
//		if (controled_ball.getPosition().x + (controled_ball.getRadius() * 2) <= (controled_ball.getRadius() * 2))
//		{
//			speed_x *= -1;
//			//controled_ball.setPosition(controled_ball.getPosition().x + controled_ball.getRadius(), controled_ball.getPosition().y);
//		}
//
//		window.clear(sf::Color::Black);
//		window.draw(controled_ball);
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