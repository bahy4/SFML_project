#include "layout.hpp"

void Layout::addButton(std::unique_ptr<Button> button) {
    buttons.push_back(std::move(button));  
    arrange();  
}

void Layout::update(const sf::RenderWindow& window) {
    for (auto& button : buttons) {  
        button->update(window);     
    }
}

void Layout::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;  
    arrange();               
}

void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto& button : buttons) {  
        target.draw(*button, states);  
    }
}

void Layout::setSpacing(float newSpacing) {
    spacing = newSpacing;
    arrange();  
}