/*
    SFML 3.0.0
*/


#include <SFML/Graphics.hpp>
#include "grid.h"

//#include <windows.h>

/*OPENFILENAMEA f = { sizeof(OPENFILENAMEA) };

    f.lpstrFilter = "png files\0*.png\0jpg files\0*.jpg\0";
    f.lpstrTitle = "Dialog box lmao";

    char buff[MAX_PATH] = {};
    f.nMaxFile = sizeof(buff);
    f.lpstrFile = buff;
    GetOpenFileNameA(&f);*/


#include "user_prefs.h"
#include "canvas.h"

int main()
{

    sf::RenderWindow window(sf::VideoMode({ 1500, 1000 }), "tilemap_editor");    
    window.setFramerateLimit(60);
    grid grid_;
    UserPrefs user_prefs;
    pallete palleteC({ 0.f, 0.f }, { 190.f, 490.f }); //palleteCanvas
    camera cameraC(750, 500);
    cameraC.view = window.getDefaultView();
    //sf::Vector2f checkPoint{0.f, 0.f};


    sf::RectangleShape selected({ 50.f, 50.f });    

    while (window.isOpen()) {
       
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (event->is<sf::Event::KeyPressed>()) {

                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }               
            }
            if (event->is<sf::Event::MouseMoved>()) {
                if ((sf::Mouse::getPosition(window).x + palleteC.shape.getPosition().x) >= palleteC.shape.getPosition().x && (sf::Mouse::getPosition(window).x + palleteC.shape.getPosition().x) <= palleteC.shape.getPosition().x + palleteC.shape.getSize().x
                    && (sf::Mouse::getPosition(window).y + palleteC.shape.getPosition().y) >= palleteC.shape.getPosition().y && (sf::Mouse::getPosition(window).y + palleteC.shape.getPosition().y) <= palleteC.shape.getPosition().y + palleteC.shape.getSize().y) {
                    user_prefs.canvasSleshTilemap = false;
                }
                else if ((sf::Mouse::getPosition(window).x + palleteC.shape.getPosition().x >= grid_.grid_map[0][0].shape.getPosition().x && sf::Mouse::getPosition(window).y + palleteC.shape.getPosition().y >= grid_.grid_map[0][0].shape.getPosition().y) &&
                    (sf::Mouse::getPosition(window).x + palleteC.shape.getPosition().x <= grid_.grid_map[grid_.grid_map.size() - 1][grid_.grid_map[grid_.grid_map.size() - 1].size() - 1].shape.getPosition().x + 50.f &&
                     sf::Mouse::getPosition(window).y + palleteC.shape.getPosition().y <= grid_.grid_map[grid_.grid_map.size() - 1][grid_.grid_map[grid_.grid_map.size() - 1].size() - 1].shape.getPosition().y + 50.f)) {
                    user_prefs.canvasSleshTilemap = true;
                }                
            }
            if (event->is<sf::Event::MouseButtonPressed>()) {                         
                if (event->getIf<sf::Event::MouseButtonPressed>()->button == sf::Mouse::Button::Left) {
                    grid_.thecolor(selected.getPosition().x, selected.getPosition().y, user_prefs.current_texture);
                    if (user_prefs.canvasSleshTilemap) {
                        grid_.thecolor(selected.getPosition().x, selected.getPosition().y, user_prefs.current_texture);
                    }
                    else {
                        palleteC.switchTexture(selected.getPosition().x, selected.getPosition().y, user_prefs);
                    }
                }
            }
        }
        cameraC.moving(&cameraC, &palleteC, &window);
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            grid_.thecolor(selected.getPosition().x, selected.getPosition().y, user_prefs.current_texture);
        }
        
        if (user_prefs.canvasSleshTilemap) {
            selected.setPosition({std::floor((float)(sf::Mouse::getPosition(window).x + palleteC.shape.getPosition().x) / 50.f) * 50.f,
            std::floor((float)(sf::Mouse::getPosition(window).y + palleteC.shape.getPosition().y) / 50.f) * 50.f});
        }
        else {
            selected.setPosition({ (std::floor((float)sf::Mouse::getPosition(window).x / 60.f) * 60.f) + 10.f,
            (std::floor((float)sf::Mouse::getPosition(window).y / 60.f) * 60.f) + 10.f });
        }
        //std::cout << "Mouse Pos without window " << sf::Mouse::getPosition().x << " " << sf::Mouse::getPosition().y << std::endl;
        //std::cout << "Mouse Pos with window " << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y << std::endl;

/*        cameraC.view.setCenter({ cameraC.shape.getPosition().x, cameraC.shape.getPosition().y });
        window.setView(cameraC.view);*/
        window.clear();

        grid_.render(&window);
        palleteC.render(&window);
        //window.draw(selected);
        //window.draw(cameraC.shape);

        window.display();

    }
    

    return 0;
}