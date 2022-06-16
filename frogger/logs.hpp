#pragma once
#pragma once

#include <SFML/Graphics.hpp>
#include<array>

class logs
{
	sf::Texture texture;
	bool direction;

	short x;

	unsigned char size;
	unsigned char speed = 2;
	unsigned char type;
	unsigned short y;
	sf::Sprite sprite;
public:
	void draw(sf::RenderWindow& win);
	void update();
	logs(unsigned char fx, unsigned char fy);
	sf::IntRect get_rect() const;
};

