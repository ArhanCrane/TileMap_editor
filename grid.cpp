#include "grid.h"

grid::grid() {

	std::ifstream file("adjustment.txt");
	if (file.is_open()) {
		std::string text;
		std::string text1;

		std::getline(file, text);
		std::getline(file, text1);
		text.erase(text.find("//"));
		text1.erase(text1.find("//"));

		std::stringstream ss(text);
		std::stringstream ss1(text1);

		ss >> height;
		ss1 >> width;
	}

	file.close();

	

	for (size_t i{}; i < width; i++) {
		grid_map.push_back(std::vector<tile>(height, tile(50.f, 50.f, sf::Color::Black)));
	}
	
	for (size_t i{}; i < grid_map.size(); i++) {
		for (size_t j{}; j < grid_map[i].size(); j++) {
			grid_map[i][j].shape.setPosition({100.f + (50.f * i), 50.f + (50.f * j)});
		}
	}

	
}

void grid::render(sf::RenderWindow* window) {

	for (size_t i{}; i < grid_map.size(); i++) {
		for (size_t j{}; j < grid_map[i].size(); j++) {
			window->draw(grid_map[i][j].shape);
		}
	}

}

void grid::thecolor(float x, float y, sf::Color color) {

	cursorPosX = (x - (int)grid_map[0][0].shape.getPosition().x) / 50;
	cursorPosY = (y - (int)grid_map[0][0].shape.getPosition().y) / 50;

	if ((cursorPosX <= width - 1 && cursorPosX >= 0) && (cursorPosY <= height - 1 && cursorPosY >= 0)) {
		grid_map[cursorPosX][cursorPosY].shape.setFillColor(color);
	}
	else {
		return;
	}
}
