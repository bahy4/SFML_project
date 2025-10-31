#include "button.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>


Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, 
               const std::string& text, const sf::Font& font) 
    : shape(),
      label(font,text),
      normalColor(sf::Color::Blue),    // Синий по умолчанию
      hoverColor(sf::Color::Cyan),     // Голубой при наведении
      pressColor(sf::Color::Red)       // Красный при нажатии
{
    // Настройка прямоугольника
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(normalColor);
    
    // Настройка текста
    //label.setFont(font);
    //label.setString(text);
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::White);
    
    // Центрирование текста
    sf::FloatRect textBounds = label.getLocalBounds();
    
    // Устанавливаем origin в центр текста (используем новые имена полей: x, y, w, h)
    label.setOrigin(sf::Vector2f(textBounds.position.x + textBounds.size.x / 2.0f, 
                                textBounds.position.y + textBounds.size.y / 2.0f));
    
    // Устанавливаем позицию текста в центр кнопки
    label.setPosition(sf::Vector2f(position.x + size.x / 2.0f, 
                                  position.y + size.y / 2.0f));
    //label.setPosition(sf::Vector2f(position.x + 10, position.y + 10));
}

void Button::update(const sf::RenderWindow& window) {
    // Получаем позицию мыши относительно окна
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    
    // Проверяем наведение курсора
    isHovered = shape.getGlobalBounds().contains(mousePosF);
    
    // Проверяем нажатие левой кнопки мыши
    isPressed = isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    
    // Обновляем цвет в зависимости от состояния
    if (isPressed) {
        shape.setFillColor(pressColor);
    } else if (isHovered) {
        shape.setFillColor(hoverColor);
    } else {
        shape.setFillColor(normalColor);
    }
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);  // Рисуем прямоугольник
    target.draw(label, states);  // Рисуем текст поверх
}