#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "button.hpp"

class Layout : public sf::Drawable {
public:
    virtual ~Layout() = default;
    
    void addButton(std::unique_ptr<Button> button);
    
    void update(const sf::RenderWindow& window);
    
    void setPosition(const sf::Vector2f& position);
    
    void setSpacing (float newSpacing);
    
    virtual sf::Vector2f getSize() const = 0;
    
    virtual void arrange() = 0;

protected:
    std::vector<std::unique_ptr<Button>> buttons;
    
    sf::Vector2f position;
    
    float spacing = 10.0f;
    
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};