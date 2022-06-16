#include "riverman.hpp"
#include"frog.hpp"
#include<SFML/Graphics.hpp>
#include"Values.hpp"

riverman::riverman()
{
	in_water = 0;
}

void riverman::update(frog& frogs)
{
	if (in_water == 0 && frogs.y_not() < CELL_SIZE * floor(0.5f * MAP_HEIGHT))
	{
		frogs.set_dead();
	}
}