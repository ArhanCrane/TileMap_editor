#include "tile.h"


tile::tile(float x, float y, sf::Color color) {

	shape.setSize({x, y});
	shape.setFillColor(color);
	shape.setOutlineThickness(-1.f);
}
