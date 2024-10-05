#include "Tile.h"

Tile::Tile() {
	/*
	    | The default constructor is necessary.		 |
	    | Otherwise it's gonna complain because	     |
	    | you need a default constructor when		 |
	    | you're making a vector of class's elements |
	*/ 
}

Tile::Tile(float x, float y, float gridSizeF) {

	/*
		| "x" and "y" variables are the coordinates |
		| of the new Tile.							|
		| "gridSizeF" is the amount of Tile's size  |
	*/

	this->shape.setSize(sf::Vector2f(gridSizeF, gridSizeF));
	//Setting the size of the new Tile

	this->shape.setFillColor(sf::Color::Green);
	//Color

	this->shape.setPosition(x, y);
	//Position. You got it!)
}

Tile::~Tile() {

}

//Functions
void Tile::update() {

}

/*
	| Tile::render fuction is used to	|
	| draw a Tile on the window.		|
*/
void Tile::render(sf::RenderTarget& target) {
	target.draw(this->shape);
}
