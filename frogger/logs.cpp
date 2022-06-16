#include "logs.hpp"
#include "cars.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Values.hpp"
#include <iostream>

logs::logs(unsigned char fx, unsigned char fy) :
	direction(fy % 2),
	x(CELL_SIZE* fx),
	size(CELL_SIZE* (1 + (2 > fy))),
	type(fy),
	y(static_cast<unsigned short>(CELL_SIZE* floor(1 + fy + 0.5f * MAP_HEIGHT)))
{
	if (direction == 0)
	{
		if (x >= CELL_SIZE * MAP_WIDTH)
		{
			x -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
	else
	{
		if (x <= -CELL_SIZE * MAP_WIDTH)
		{
			x = static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}

}

void logs::draw(sf::RenderWindow& win)
{
	texture.loadFromFile("car1.png");
	sprite.setPosition(x, y);
	sprite.setTexture(texture);

	sprite.setTextureRect(sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE));



	win.draw(sprite);
}


void logs::update()
{
	if (direction == 0)
	{
		x += speed;

		if (x >= CELL_SIZE * MAP_WIDTH)
		{

			x -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
	else
	{
		x -= speed;

		if (x <= -CELL_SIZE * floor(0.5f * MAP_WIDTH))
		{

			x += static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
}

sf::IntRect logs::get_rect() const
{
	return sf::IntRect(x, y, CELL_SIZE, CELL_SIZE);
}