#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "tile.h"

class grid
{
public:
	std::vector <std::vector<tile>> grid_map;

	grid();

	void render(sf::RenderWindow*);
	void thecolor(float, float, sf::Texture* texture);

private:
	unsigned int height{};
	unsigned int width{};

	float cursorPosX{}; //regarding the grid position
	float cursorPosY{}; //regarding the grid position



};

