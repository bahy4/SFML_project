#include "VLayout.hpp"


sf::Vector2f VLayout::getSize() const {
    if (buttons.empty()) return sf::Vector2f(0, 0);
    
    float maxWidth = 0;
    float totalHeight = 0;
    
    
    for (size_t i = 0; i < buttons.size(); ++i) {
        sf::Vector2f size = buttons[i]->getSize();
        maxWidth = std::max(maxWidth, size.x);
        totalHeight += size.y;
        
        
        if (i < buttons.size() - 1) {
            totalHeight += spacing;
        }
    }
    
    return sf::Vector2f(maxWidth, totalHeight);
}


void VLayout::arrange() {
    float currentY = position.y;
    
    for (auto& button : buttons) {
        
        button->setPosition(sf::Vector2f(position.x, currentY));
        
        
        currentY += button->getSize().y + spacing;
    }
}

