#include <SFML/Graphics.hpp>
#include "TileMap.h"

using namespace sf;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 1024), "Tilemap!");

    TileMap map;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Escape) {
                    window.close();
                }
            }
        }

        window.clear();

        map.render(window); //This is explained)

        window.display();
    }

    return 0;
}