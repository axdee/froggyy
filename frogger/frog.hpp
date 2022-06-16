
#pragma once

#include<SFML/Graphics.hpp>
#include <array>
class frog
{
	short x;
	unsigned short y;
	sf::Texture texture;
	bool dead ;
	sf::Sprite sprite;
	std::array<bool, 4> control_keys;
public:
	void draw(sf::RenderWindow& w);
	frog();
	void update();
	bool get_dead() const;
	void set_dead();
	void reset();
	unsigned short y_not();
	sf::IntRect get_rect() const;
};

