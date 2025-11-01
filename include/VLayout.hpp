#pragma once
#include "layout.hpp"

class VLayout : public Layout {
public:
    sf::Vector2f getSize() const override;
    void arrange() override;
    
};