
#pragma once

#include<SFML/Graphics.hpp>
#include <array>
class frog
{
	short x;
	unsigned short y;
	sf::Texture texture;
	
	sf::Sprite sprite;
	std::array<bool, 4> control_keys;
public:
	void draw(sf::RenderWindow& w);
	frog();
	void update();
};

