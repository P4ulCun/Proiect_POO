#include "button.h"

void Button::draw(sf::RenderWindow& window)
{
    shape.setFillColor(hovered ? sf::Color(100, 100, 255) : sf::Color(70, 70, 70));
    window.draw(shape);
    window.draw(text);
}

bool Button::contains(sf::Vector2f point)
{
    return shape.getGlobalBounds().contains(point);
}

std::vector<std::string> labels = { "Rogue", "Druid", "Warrior" };


std::vector<Button> initClassSelectionButtons(sf::Font& font)
{
    std::vector<Button> buttons;
    for (int i = 0; i < labels.size(); i++) {
        Button btn;
        btn.shape.setSize(sf::Vector2f(buttonWidth, buttonHeight));
        btn.shape.setPosition((windowDetails::WINDOW_WIDTH - buttonWidth) / 2, 
            windowDetails::WINDOW_HEIGHT / 2 + i * (buttonHeight + 20));

        btn.text.setFont(font);
        btn.text.setString(labels[i]);
        btn.text.setCharacterSize(20);
        btn.text.setFillColor(sf::Color::White);
        sf::FloatRect textBounds = btn.text.getLocalBounds();
        btn.text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
        btn.text.setPosition(btn.shape.getPosition().x + buttonWidth / 2, btn.shape.getPosition().y + buttonHeight / 2);

        buttons.push_back(btn);
    }
    return buttons;
}