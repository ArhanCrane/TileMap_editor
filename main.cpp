#include <SFML/Graphics.hpp>

#include "grid.h"

int main()
{
    

    sf::RenderWindow window(sf::VideoMode(1500, 1000), "tilemap_editor");       
    grid grid_;
    sf::RectangleShape selected({50.f, 50.f});

    while (window.isOpen()) {


        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {

                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }

            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.key.code == sf::Mouse::Left) {
                    grid_.thecolor(selected.getPosition().x, selected.getPosition().y, sf::Color::White);
                }
                if (event.key.code == sf::Mouse::Right) {
                    grid_.thecolor(selected.getPosition().x, selected.getPosition().y, sf::Color(255, 0, 149));
                }
                if (event.key.code == sf::Mouse::Middle) {
                    grid_.thecolor(selected.getPosition().x, selected.getPosition().y, sf::Color::Black);
                }
            }
        }
        
        selected.setPosition({ std::floor((float)sf::Mouse::getPosition(window).x / 50.f) * 50.f, 
            std::floor((float)sf::Mouse::getPosition(window).y / 50.f) * 50.f });

        window.clear();

        grid_.render(&window);

        window.display();

    }
    
    return 0;
}
