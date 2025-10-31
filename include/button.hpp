#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& text, const sf::Font& font);
    void update(const sf::RenderWindow& window);
    
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    sf::RectangleShape shape;    // Прямоугольник кнопки
    sf::Text label;              // Текст кнопки
    sf::Color normalColor;       // Обычный цвет
    sf::Color hoverColor;        // Цвет при наведении
    sf::Color pressColor;        // Цвет при нажатии
    bool isHovered = false;      // Флаг наведения курсора
    bool isPressed = false;      // Флаг нажатия
};