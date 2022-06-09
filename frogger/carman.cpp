#include"cars.hpp"
#include "carman.hpp"
#include<array>
#include<SFML/Graphics.hpp>

carman::carman()
{
	caar.clear();
	
	caar.push_back(cars(0, 0));
	caar.push_back(cars(1, 1));
	caar.push_back(cars(0, 2));
	caar.push_back(cars(1, 3));
	caar.push_back(cars(0, 4));
	caar.push_back(cars(1, 5));
}				   

void carman::draw(sf::RenderWindow& win)
{
	for (cars& car : caar)
	{
		car.draw(win);
	}
}



void carman::update()
{
	for (cars& car : caar)
	{
		car.update();
	}
}