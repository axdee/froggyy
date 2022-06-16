#include"cars.hpp"
#include "carman.hpp"
#include<array>
#include<SFML/Graphics.hpp>
#include"frog.hpp"
#include "Values.hpp"
#include<chrono>

#include<iostream>


carman::carman()
{
	caar.clear();



	caar.push_back(cars(1, 0));
	caar.push_back(cars(9, 0));

	caar.push_back(cars(7, 1));
	caar.push_back(cars(11, 1));

	caar.push_back(cars(8, 3));
	caar.push_back(cars(10, 2));

	caar.push_back(cars(2, 3));

	caar.push_back(cars(0, 4));
	caar.push_back(cars(6, 4));
	caar.push_back(cars(13, 4));

	caar.push_back(cars(0, 5));
	caar.push_back(cars(7, 5));
	caar.push_back(cars(14, 5));

}
void carman::draw(sf::RenderWindow& win)
{
	for (cars& car : caar)
	{
		car.draw(win);
	}
}



void carman::update(frog& frogs)
{
	for (cars& car : caar)
	{
		car.update();
	}
	
	if (0 == frogs.get_dead())
	{
		for (cars& car : caar)
		{
			if (1 == car.get_rect().intersects(frogs.get_rect()))
			{
				frogs.set_dead();
				
			}
			
		}
		
	}
	
}