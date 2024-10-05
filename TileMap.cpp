#include "TileMap.h"


TileMap::TileMap() {
	this->gridSizeF = 20.f; /* "gridSizeF" isn't able to change the amount of tiles
	it's still 10x10 Tiles	*/
	this->gridSizeU = static_cast<unsigned>(this->gridSizeF);

	//----------------------
	this->mapSize.x = 10;
	this->mapSize.y = 10;
	this->layers = 1;
	/*
		This three variables are an essential part
		of filling a vector "map" with tiles.
		
		In this case we're making a map of 10x10 Tiles
		with only one layer.

	*/
	
	//---------------------------------------------------------------------------------------------------
	this->map.resize(this->mapSize.x);
	//(1) We're resizing the "map" vector to the amount of 10

	for (size_t x{}; x < this->mapSize.x; x++) {
		this->map.push_back(std::vector<std::vector<Tile>>());
		/*(2) Here it's giving to the "map" all 10 columns which
		will contain all 10 rows*/

		for (size_t y{}; y < this->mapSize.y; y++) {
			this->map[x].push_back(std::vector<Tile>());
			/*(3) Next it's giving to the "map" all 10 rows which
			will contain the vector<Tile>*/

			for (size_t z{}; z < this->layers; z++) {
				this->map[x][y].push_back(Tile(x * this->gridSizeF, y * this->gridSizeF, this->gridSizeF));
				/*(4) Eventually the "map" is going to get filled with
				10 columns and 10 rows which have the vector<Tile> with 1 layer(element)*/
			}
		}
	}
	//---------------------------------------------------------------------------------------------------
}

TileMap::~TileMap() {

}

//Functions
void TileMap::update() {

}

void TileMap::render(sf::RenderTarget& target) {

	/*
		| Here we're going to execute the Tile::render  |
		| function of every Tile inside "map" vector	|
	*/

	for (auto& x : this->map) {
		for (auto& y : x) {
			for (auto& z : y) {
				z.render(target);
			}
		}
	}	
}