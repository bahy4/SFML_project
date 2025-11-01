#pragma once
#include <SFML/Graphics.hpp>

class Button : public sf::Drawable {
public:
    Button(const sf::Vector2f& position, const sf::Vector2f& size, const std::string& text, const sf::Font& font);
    void update(const sf::RenderWindow& window);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getSize() const;
    sf::FloatRect getGlobalBounds() const;
    
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    
    sf::RectangleShape shape;    
    sf::Text label;              
    sf::Color normalColor;       
    sf::Color hoverColor;        
    sf::Color pressColor;        
    bool isHovered = false;      
    bool isPressed = false;      
};