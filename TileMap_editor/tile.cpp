#include "tile.h"


tile::tile(sf::Vector2f vector2f) {

	shape.setSize({ vector2f.x, vector2f.y });
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineThickness(-1.f);
}