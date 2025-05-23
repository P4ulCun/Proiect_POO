#include "button.h"

//ITEMS START
const int cellWidth = 80;
const int cellHeight = 80;
const int columns = 2;
const int rows = 5;

//ITEMS END

void Button::draw(sf::RenderWindow& window)
{
    if (shape.getTexture() == nullptr)
        shape.setFillColor((hovered) ? hoverColor : color);
    else
    {
        //mai complicat
        //trb sa schimb pozitia
        /*if (hovered)
            shape.setScale(1.2, 1.2);
        else
            shape.setScale(1, 1);*/

        shape.setOutlineThickness(2);
        if (hovered || selected)
            shape.setOutlineColor(sf::Color::Magenta);
        else
            shape.setOutlineColor(sf::Color::Transparent);
    }
    window.draw(shape);
    window.draw(text);

    if (shape.getTexture() != nullptr)
        window.draw(itemIcon);
}

bool Button::contains(sf::Vector2f point)
{
    return shape.getGlobalBounds().contains(point);
}

std::vector<std::string> labels = { "Rogue", "Druid", "Warrior" };


std::vector<Button> initClassSelectionButtons(sf::Font& font)
{
    std::vector<Button> buttons;
    for (int i = 0; i < labels.size(); i++) 
    {
        Button btn;
        btn.color = sf::Color(70, 70, 70);
        btn.hoverColor = sf::Color(100, 100, 255);
        btn.index = i + 1;

        btn.shape.setSize(sf::Vector2f(ClassButtonWidth, ClassButtonHeight));
        btn.shape.setPosition((windowDetails::WINDOW_WIDTH - ClassButtonWidth) / 2, 
            windowDetails::WINDOW_HEIGHT / 2 + i * (ClassButtonHeight + 20) - 100);
        btn.shape.setFillColor(btn.color);

        btn.text.setFont(font);
        btn.text.setString(labels[i]);
        btn.text.setCharacterSize(20);
        btn.text.setFillColor(sf::Color::White);
        sf::FloatRect textBounds = btn.text.getLocalBounds();
        btn.text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
        btn.text.setPosition(btn.shape.getPosition().x + ClassButtonWidth / 2, btn.shape.getPosition().y + ClassButtonHeight / 2);

        buttons.push_back(btn);
    }
    return buttons;
}

std::vector<Button> initItemSelectionButtons(sf::Font& font)
{
    std::vector<Button> buttons;
    int lin = 5;
    int col = 2;
    int index = 0;
    //std::cout << "item indeces: \n";
    for (int i = 0; i < lin; i++)
        for (int j = 0; j < col; j++)
        {
            Button btn;

            index++;
            //std::cout << index << '\n';
            btn.index = index;
            /*btn.color = sf::Color::Transparent;
            btn.hoverColor = sf::Color::Transparent;*/
            btn.shape.setSize(sf::Vector2f(ItemButtonWidth, ItemButtonHeight));

            btn.shape.setPosition(windowDetails::WINDOW_WIDTH / 2 - 2 * (ItemButtonWidth + 20) + index % 4 * (ItemButtonHeight + 20),
                windowDetails::WINDOW_HEIGHT - 5 * (ItemButtonHeight + 20) + index / 4 * (ItemButtonHeight + 20));
            /*if (j % 2)
                btn.shape.setPosition(windowDetails::WINDOW_WIDTH / 2 - (ItemButtonWidth + 20),
                    windowDetails::WINDOW_HEIGHT - 5 * (ItemButtonHeight + 20) + i * (ItemButtonHeight + 20));
            else
                btn.shape.setPosition(windowDetails::WINDOW_WIDTH / 2 + 20,
                    windowDetails::WINDOW_HEIGHT - 5 * (ItemButtonHeight + 20) + i * (ItemButtonHeight + 20));*/

            btn.itemIcon.setSize(sf::Vector2f(ItemButtonWidth, ItemButtonHeight));
            btn.itemIcon.setTexture(&Resources::getInstance().getItemsTexture());
            btn.itemIcon.setTextureRect(sf::IntRect(j * cellWidth, i * cellHeight, cellWidth, cellHeight));
            btn.itemIcon.setPosition(btn.shape.getPosition());

            btn.shape.setTexture(&Resources::getInstance().getItemFrameTexture());
            btn.text.setFillColor(sf::Color::Transparent);

            /*btn.text.setFont(font);
            btn.text.setString("item");
            btn.text.setCharacterSize(14);
            btn.text.setFillColor(sf::Color::White);
            sf::FloatRect textBounds = btn.text.getLocalBounds();
            btn.text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
            btn.text.setPosition(btn.shape.getPosition().x + ItemButtonWidth / 2, btn.shape.getPosition().y + ItemButtonHeight / 2);*/

            buttons.push_back(btn);
        }

    return buttons;
}

std::vector<Button> initAttackButtons(sf::Font& font, int player)
{
    std::vector<Button> buttons;
    for (int i = 0; i < 2; i++)
    {
        Button btn;
        btn.index = i;
        btn.shape.setSize(sf::Vector2f(cellWidth, cellHeight));

        if (player == 1)
            btn.shape.setPosition(windowDetails::WINDOW_WIDTH / 2 - cellWidth - 50 - i * 30,
                windowDetails::WINDOW_HEIGHT / 2 - cellHeight + i * (cellHeight + 20));
        else
            btn.shape.setPosition(windowDetails::WINDOW_WIDTH / 2 + 50 + i * 30,
                windowDetails::WINDOW_HEIGHT / 2 - cellHeight + i * (cellHeight + 20));

        btn.itemIcon.setSize(sf::Vector2f(cellWidth, cellHeight));
        btn.itemIcon.setPosition(btn.shape.getPosition());

        btn.itemIcon.setTexture(&Resources::getInstance().getBasicAttackTexture());
        btn.itemIcon.setTextureRect(sf::IntRect(i * cellWidth, 0, cellWidth, cellHeight));
        btn.shape.setTexture(&Resources::getInstance().getBasicAttackTexture());
        btn.shape.setTextureRect(sf::IntRect(i * cellWidth, 0, cellWidth, cellHeight));

        //btn.shape.setFillColor(sf::Color::Transparent);
        btn.text.setFillColor(sf::Color::Transparent);

        buttons.push_back(btn);
    }
    return buttons;
}