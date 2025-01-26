#pragma once

#include <SFML/Graphics.hpp>

class tile
{
public:
	tile(float, float, sf::Color);
	sf::RectangleShape shape;

private:
	
	
	sf::Color color;
};

