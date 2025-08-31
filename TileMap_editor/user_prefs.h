#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class UserPrefs {

public:
	UserPrefs();

	sf::Texture* current_texture;

	void change_texture(int index);

	bool canvasSleshTilemap;

	std::vector<sf::Texture> textureTank;

};
