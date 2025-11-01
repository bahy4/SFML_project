#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "button.hpp"

// Базовый абстрактный класс Layout для управления расположением элементов
class Layout : public sf::Drawable {
public:
    // Виртуальный деструктор для правильного удаления производных классов
    virtual ~Layout() = default;
    
    // Добавляет кнопку в layout
    void addButton(std::unique_ptr<Button> button);
    
    // Обновляет все кнопки в layout
    void update(const sf::RenderWindow& window);
    
    // Устанавливает позицию всего layout
    void setPosition(const sf::Vector2f& position);
    
    // Возвращает общий размер layout
    virtual sf::Vector2f getSize() const = 0;
    
    // Чисто виртуальный метод для расположения кнопок (реализуется в наследниках)
    virtual void arrange() = 0;

protected:
    // Вектор умных указателей на кнопки (управляет временем жизни кнопок)
    std::vector<std::unique_ptr<Button>> buttons;
    
    // Позиция layout
    sf::Vector2f position;
    
    // Отступ между элементами
    float spacing = 10.0f;
    
    // Реализация отрисовки из sf::Drawable
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};