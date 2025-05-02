#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
struct Button {
    sf::RectangleShape shape;
    sf::Text text;
    bool hovered = false;

    void draw(sf::RenderWindow& window);

    bool contains(sf::Vector2f point);
};


std::vector<std::string> labels = { "Rogue", "Druid", "Warrior" };
std::vector<Button> buttons;
const float buttonWidth = 200;
const float buttonHeight = 50;
const float startY = 60;

void initClassSelectionButtons(sf::Font font);