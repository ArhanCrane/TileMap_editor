#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include <SFML/Graphics.hpp>

class Tile
{
protected:
	sf::RectangleShape shape;
	//all tiles are in a rectangle shape

public:
	Tile();
	Tile(float, float, float);
	~Tile();

	//Functions
	void update();
	void render(sf::RenderTarget&);



};




#endif TILE_H

