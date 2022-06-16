

#include <SFML/Graphics.hpp>
#include"cars.hpp"
#include "frog.hpp"

class carman
{
	std::vector<cars> caar;
public:
	carman();
	void draw(sf::RenderWindow& win);
	
	void update(frog& frogs);
};

