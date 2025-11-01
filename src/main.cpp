#include <SFML/Graphics.hpp>
#include "button.hpp"
#include "HLayout.hpp"
#include "VLayout.hpp"


int main()
{
    sf::Font font("fonts/font1.ttf");

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(75);

    auto hButton1 = std::make_unique<Button>(
        sf::Vector2f(0, 0), sf::Vector2f(150, 50), "H Button 1", font);
    auto hButton2 = std::make_unique<Button>(
        sf::Vector2f(0, 0), sf::Vector2f(150, 50), "H Button 2", font);
    auto hButton3 = std::make_unique<Button>(
        sf::Vector2f(0, 0), sf::Vector2f(150, 50), "H Button 3", font);

    HLayout hLayout;
    hLayout.setPosition(sf::Vector2f(100, 100));
    hLayout.setSpacing(20.0f); 
    hLayout.addButton(std::move(hButton1));
    hLayout.addButton(std::move(hButton2));
    hLayout.addButton(std::move(hButton3));

    auto vButton1 = std::make_unique<Button>(
        sf::Vector2f(0, 0), sf::Vector2f(200, 60), "V Button 1", font);
    auto vButton2 = std::make_unique<Button>(
        sf::Vector2f(0, 0), sf::Vector2f(200, 60), "V Button 2", font);
    auto vButton3 = std::make_unique<Button>(
        sf::Vector2f(0, 0), sf::Vector2f(200, 60), "V Button 3", font);

    VLayout vLayout;
    vLayout.setPosition(sf::Vector2f(1000, 100));
    vLayout.setSpacing(15.0f); 
    vLayout.addButton(std::move(vButton1));
    vLayout.addButton(std::move(vButton2));
    vLayout.addButton(std::move(vButton3));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        hLayout.update(window);
        vLayout.update(window);
        window.clear(sf::Color::Black);
        window.draw(hLayout);
        window.draw(vLayout);
        window.display();
    }
}
