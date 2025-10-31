#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    sf::Font font("fonts/font1.ttf");
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
        window.display();
    }
}
