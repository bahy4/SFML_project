#include "HLayout.hpp"

sf::Vector2f HLayout::getSize() const {
    if (buttons.empty()) return sf::Vector2f(0, 0);
    
    float totalWidth = 0;
    float maxHeight = 0;
    
    for (size_t i = 0; i < buttons.size(); ++i) {
        sf::Vector2f size = buttons[i]->getSize();
        totalWidth += size.x;
        maxHeight = std::max(maxHeight, size.y);
        
        if (i < buttons.size() - 1) {
            totalWidth += spacing;
        }
    }
    
    return sf::Vector2f(totalWidth, maxHeight);
}

void HLayout::arrange() {
    float currentX = position.x;
    
    for (auto& button : buttons) {
        button->setPosition(sf::Vector2f(currentX, position.y));
        
        currentX += button->getSize().x + spacing;
    }
}

