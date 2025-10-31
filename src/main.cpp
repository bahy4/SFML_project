#include <SFML/Graphics.hpp>
#include "button.hpp"


int main()
{
    sf::Font font("fonts/font1.ttf");
    if (!font.openFromFile("/home/vboxuser/proga/SFML_project/fonts/font1.ttf")) {
        return -1;  // Выход при ошибке загрузки шрифта
    }

    Button button(sf::Vector2f(100, 100), sf::Vector2f(200, 50), "Click me!", font);

    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(75);
    while (window.isOpen())
    {
        window.clear(sf::Color::Black);
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        button.update(window);
        window.clear(sf::Color::Black);
        window.draw(button);
        window.display();
    }
}
