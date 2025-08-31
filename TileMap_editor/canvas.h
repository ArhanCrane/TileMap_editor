#pragma once
#include <SFML/Graphics.hpp>
#include "user_prefs.h"
#include <vector>

class button {
public:
	sf::RectangleShape shape;
	bool isBusy;

	button(sf::Vector2f position, sf::Vector2f size) {
		isBusy = false;
		shape.setPosition({ position.x, position.y });
		shape.setSize({ size.x, size.y });
		shape.setFillColor(sf::Color(213, 0, 100));
	}

};
//The mechanics of basic buttons


class Canvas {
public:
	//canvas(sf::Vector2f position, sf::Vector2f size);
	/*sf::Vector2f position;
	sf::Vector2f size;*/

	//void moving(const sf::Keyboard::Key&, Canvas*);
};

class pallete : public Canvas {

public:
	pallete(sf::Vector2f position, sf::Vector2f size);
	sf::RectangleShape shape;

	std::vector<button> buttonTank;

	void render(sf::RenderWindow*);
	void switchTexture(float, float, UserPrefs&);	

private:
	int indexTexTankX{};
	int indexTexTankY{};

};

class camera {

public:
	camera(float, float);
	void moving(camera*, pallete*, sf::RenderWindow*);

	sf::RectangleShape shape;
	sf::View view;

};




