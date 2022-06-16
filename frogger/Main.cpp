#include <SFML/Graphics.hpp>
#include "Values.hpp"
#include <array>
#include "frog.hpp"
#include "map.hpp"
#include "cars.hpp"
#include "carman.hpp"
#include"riverman.hpp"
int main()
{
	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * MAP_WIDTH * SCREEN_RESIZE, SCREEN_RESIZE * (FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)), "Frogo", sf::Style::Close);
	window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * MAP_WIDTH, FONT_HEIGHT + CELL_SIZE * MAP_HEIGHT)));
	frog frogg;
	carman carman;
	riverman riverman;
	sf::Clock clock;
	sf::Time accumulator = sf::Time::Zero;
	sf::Time ups = sf::seconds(1.f / 60.f);
	
	
	
	
	/*while (window.isOpen())
	{
		sf::Event evnt;
		
		if (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				break;
			}
			
		}
		
		window.clear();
		
		map(swamp, window);
		
		
		frogg.update();
		carman.update();
		frogg.draw(window);
		
		
		carman.draw(window);
		
		
		window.display();
		
	}*/
	

	while (window.isOpen())
	{
		sf::Event evnt;

		if (window.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
			{
				break;
			}

		}
		
		
		while (accumulator > ups)
		{
			accumulator -= ups;
			frogg.update();
			carman.update(frogg);
			riverman.update(frogg);
			
		}
		
		if (frogg.get_dead() == 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				frogg.reset();
			}
		}

		window.clear();
		map(window);
		frogg.draw(window);


		carman.draw(window);
		window.display();
		accumulator += clock.restart();
		
	}
	
	return 0;
}