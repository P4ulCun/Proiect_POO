#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "resourceHandler.h"
#include "nameSpaces.h"
#include "inventory.h"

struct Button {
    sf::RectangleShape shape;
    sf::RectangleShape itemIcon;
    sf::Text text;
    bool hovered = false;
    bool selected = false;
    sf::Color hoverColor;
    sf::Color color;
    int index = 0;

    void draw(sf::RenderWindow& window);

    bool contains(sf::Vector2f point);
};

const float ClassButtonWidth = 200;
const float ClassButtonHeight = 50;

const float ItemButtonWidth = 80;
const float ItemButtonHeight = 80;

std::vector<Button> initClassSelectionButtons(sf::Font& font);
std::vector<Button> initItemSelectionButtons(sf::Font& font);
std::vector<Button> initItemPlayerInventory(sf::Font& font, int item1, int item2, int item3);