#include "canvas.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>


pallete::pallete(sf::Vector2f position, sf::Vector2f size) {
	shape.setPosition({position.x, position.y});
	shape.setSize(size);	
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineThickness(1.f);

	
	for (int j{}; j < 5; j++) {
		buttonTank.push_back(button({10.f, 10.f + (60.f * j)}, {50.f, 50.f}));
		buttonTank.push_back(button({70.f, 10.f + (60.f * j)}, {50.f, 50.f}));
		buttonTank.push_back(button({130.f, 10.f + (60.f * j)}, {50.f, 50.f}));
	}		
}

void pallete::render(sf::RenderWindow* window) {
	window->draw(shape);
	for (auto& elem : buttonTank) {
		window->draw(elem.shape);
	}
}

void pallete::switchTexture(float x, float y, UserPrefs& user_prefs) {	
	/*indexTexTankX = std::floor(x / 60);
	indexTexTankY = std::floor(y / 60) + (1 * std::floor(y / 60));*/

	indexTexTankX = std::floor(x / 60);
	indexTexTankY = std::floor(y / 60);

	
	

	if ((buttonTank.size() >= (((indexTexTankY * 3) + indexTexTankX) + 1) && (indexTexTankX <= 2))) {
		
		if ((indexTexTankY * 3) + indexTexTankX < user_prefs.textureTank.size() + 1) {
			if (buttonTank[(indexTexTankY * 3) + indexTexTankX].isBusy && user_prefs.textureTank.size() >= (((indexTexTankY * 3) + indexTexTankX) + 1)) {
				
				
				user_prefs.current_texture = &user_prefs.textureTank[(indexTexTankY * 3) + indexTexTankX];
				std::cout << "new texture is set" << std::endl;
			}
			else {				
				
				OPENFILENAMEA f = { sizeof(OPENFILENAMEA) };

				f.lpstrFilter = "png files\0*.png\0";
				f.lpstrTitle = "Dialog box lmao";

				char buff[MAX_PATH] = {};
				f.nMaxFile = sizeof(buff);
				f.lpstrFile = buff;
				GetOpenFileNameA(&f);
				if (buff[0] != NULL) {
					user_prefs.textureTank.push_back(sf::Texture(buff));
					user_prefs.current_texture = &user_prefs.textureTank[(indexTexTankY * 3) + indexTexTankX];
					buttonTank[(indexTexTankY * 3) + indexTexTankX].isBusy = true;

					buttonTank[(indexTexTankY * 3) + indexTexTankX].shape.setFillColor(sf::Color::White);
					buttonTank[(indexTexTankY * 3) + indexTexTankX].shape.setTexture(&user_prefs.textureTank[(indexTexTankY * 3) + indexTexTankX]);

					std::cout << "new texture is set to the button" << std::endl;
				}				
			}
		}
	}
}

camera::camera(float x, float y) {
	//shape.setOrigin({ shape.getSize().x / 2, shape.getSize().y / 2});
	shape.setSize({50.f, 50.f});
	shape.setPosition({x, y});
}

void camera::moving(camera* camera_, pallete* palette, sf::RenderWindow* window) {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		palette->shape.move({ 0.f, -20.f });
		for (size_t i{}; i < palette->buttonTank.size(); i++) {
			palette->buttonTank[i].shape.move({ 0.f, -20.f });
		}
		(camera_)->shape.move({ 0.f, -20.f });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		palette->shape.move({ 0.f, 20.f });
		for (size_t i{}; i < palette->buttonTank.size(); i++) {
			palette->buttonTank[i].shape.move({ 0.f, 20.f });
		}
		(camera_)->shape.move({ 0.f, 20.f });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		palette->shape.move({ 20.f, 0.f });
		for (size_t i{}; i < palette->buttonTank.size(); i++) {
			palette->buttonTank[i].shape.move({ 20.f, 0.f });
		}
		(camera_)->shape.move({ 20.f, 0.f });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		palette->shape.move({ -20.f, 0.f });
		for (size_t i{}; i < palette->buttonTank.size(); i++) {
			palette->buttonTank[i].shape.move({ -20.f, 0.f });
		}
		(camera_)->shape.move({ -20.f, 0.f });
	}

	view.setCenter({ shape.getPosition().x, shape.getPosition().y });
	window->setView(view);
}