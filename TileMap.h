#ifndef TILEMAP_H
#define TILEMAP_H

#include "Tile.h"

class TileMap
{
private:
	unsigned gridSizeU;
	sf::Vector2u mapSize;
	unsigned layers;
	std::vector< std::vector< std::vector< Tile > > > map;


public:
	TileMap();
	~TileMap();


};

#endif TILEMAP_H