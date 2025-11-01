#include "layout.hpp"

// Добавляет кнопку в layout (передача владения кнопкой layout'у)
void Layout::addButton(std::unique_ptr<Button> button) {
    buttons.push_back(std::move(button));  // Перемещаем владение кнопкой в вектор
    arrange();  // Перерасполагаем все кнопки после добавления новой
}

// Обновляет все кнопки в layout
void Layout::update(const sf::RenderWindow& window) {
    for (auto& button : buttons) {  // Проходим по всем кнопкам
        button->update(window);     // Обновляем каждую кнопку
    }
}

// Устанавливает позицию всего layout
void Layout::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;  // Сохраняем новую позицию
    arrange();               // Перерасполагаем кнопки относительно новой позиции
}

// Отрисовывает все кнопки в layout
void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (auto& button : buttons) {  // Проходим по всем кнопкам
        target.draw(*button, states);  // Отрисовываем каждую кнопку
    }
}