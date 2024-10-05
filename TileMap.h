#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

class TileMap
{
private:
	float gridSizeF;
	unsigned gridSizeU;

	sf::Vector2u mapSize;

	unsigned layers;

	//-------------------------------------------------------
	std::vector< std::vector< std::vector< Tile > > > map;
	/*
		|  the map vector contains:									|
		|															|
		|     1     2     3     4 - std::vector<std::vector<Tile>>	|
		| 1 |TILE||TILE||TILE||TILE|								|
		| 2 |TILE||TILE||TILE||TILE| - std::vector<Tile>			|
		| 3 |TILE||TILE||TILE||TILE|								|
		| 4 |TILE||TILE||TILE||TILE|								|
		|	  |														|
		|  One TILE is a vector which contains						|
		|  this->layers amount of layers of one cell map[1][4]		|	
	*/




public:
	TileMap();
	~TileMap();

	void update();
	void render(sf::RenderTarget&);

};

#endif TILEMAP_H