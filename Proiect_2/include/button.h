#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "nameSpaces.h"

struct Button {
    sf::RectangleShape shape;
    sf::Text text;
    bool hovered = false;

    void draw(sf::RenderWindow& window);

    bool contains(sf::Vector2f point);
};

const float buttonWidth = 200;
const float buttonHeight = 50;
const float startY = 60;

std::vector<Button> initClassSelectionButtons(sf::Font& font);