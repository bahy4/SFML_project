#include "button.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>


Button::Button(const sf::Vector2f& position, const sf::Vector2f& size, 
               const std::string& text, const sf::Font& font) 
    : shape(),
      label(font,text),
      normalColor(sf::Color::Blue),    
      hoverColor(sf::Color::Cyan),     
      pressColor(sf::Color::Red)       
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(normalColor);
    
    label.setCharacterSize(24);
    label.setFillColor(sf::Color::White);
    
    sf::FloatRect textBounds = label.getLocalBounds();
    
    label.setOrigin(sf::Vector2f(textBounds.position.x + textBounds.size.x / 2.0f, 
                                textBounds.position.y + textBounds.size.y / 2.0f));
    
    label.setPosition(sf::Vector2f(position.x + size.x / 2.0f, 
                                  position.y + size.y / 2.0f));
}

void Button::update(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    
    isHovered = shape.getGlobalBounds().contains(mousePosF);
    
    isPressed = isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
    
    if (isPressed) {
        shape.setFillColor(pressColor);
    } else if (isHovered) {
        shape.setFillColor(hoverColor);
    } else {
        shape.setFillColor(normalColor);
    }
}

void Button::setPosition(const sf::Vector2f& newPosition) {
    shape.setPosition(newPosition);
    
    // Пересчитываем позицию текста для центрирования
    sf::Vector2f size = shape.getSize();
    label.setPosition(sf::Vector2f(newPosition.x + size.x / 2.0f, 
                                  newPosition.y + size.y / 2.0f));
}

sf::Vector2f Button::getSize() const {
    return shape.getSize();
}

sf::FloatRect Button::getGlobalBounds() const {
    return shape.getGlobalBounds();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);  
    target.draw(label, states);  
}