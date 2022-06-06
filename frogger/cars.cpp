#include "cars.hpp"
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Values.hpp"

cars::cars(unsigned char fx, unsigned char fy) :
	direction(fy%2),
	x(CELL_SIZE*fx),
	size(CELL_SIZE*(1+(2>fy))),
	type(fx),
	y(static_cast<unsigned short>(CELL_SIZE* floor(1 + fy + 0.5f * MAP_HEIGHT)))
{
	if (direction == 0)
	{
		if (x >=CELL_SIZE * MAP_WIDTH)
		{
			x -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
	else
	{
		if (x <= CELL_SIZE * MAP_WIDTH)
		{
			x = static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}

}

void cars::draw(sf::RenderWindow& win)
{	
	texture.loadFromFile("car.png");

	sprite.setPosition(x, y);
	sprite.setTexture(texture);

	if (direction == 0)
	{
		sprite.setTextureRect(sf::IntRect(0, CELL_SIZE * type, size, CELL_SIZE));
	}
	else
	{
		sprite.setTextureRect(sf::IntRect(0, CELL_SIZE * type, size, CELL_SIZE));
	}
	win.draw(sprite);
}


void cars::update()
{
	if (direction == 0)
	{
		x += SPEED -1;

		if (x >= CELL_SIZE * MAP_WIDTH)
		{
			x -= static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
	else
	{
		x -= SPEED;

		if (x <= CELL_SIZE * MAP_WIDTH)
		{
			x += static_cast<short>(CELL_SIZE * floor(1.5f * MAP_WIDTH));
		}
	}
}