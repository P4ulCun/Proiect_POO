#pragma once
#include "singleton.h"
#include <SFML/Graphics.hpp>

#include "errorHandling.h"
#include "playerMaker.h"
#include "resourceHandler.h"
#include "characterAnimation.h"
#include "button.h"
#include "characterFactory.h"
#include "inventoryBuilder.h"

#include "nameSpaces.h"
//namespace windowDetails {
//	constexpr float WINDOW_WIDTH = 1200;
//	constexpr float WINDOW_HEIGHT = 675;
//}

class Game : public Singleton<Game>
{
private:
	Player m_player1;
	Player m_player2;
	bool m_selectClass = true;
	bool m_selectItems = false;
	bool m_player1sTurn = true;
	int m_round = 1;

	std::shared_ptr<PlayerInventory> inventory1;
	std::shared_ptr<PlayerInventory> inventory2;
	std::shared_ptr<Character> character1;
	std::shared_ptr<Character> character2;
	
private:
	sf::Vector2f m_mousePosition;

	std::vector<Button> m_classSelectionButtons;
	std::vector<Button> m_itemSelectionButtons;

	std::vector<Button> m_itemPlayer1Inventory;
	std::vector<Button> m_itemPlayer2Inventory;

	sf::Sprite m_backgroundSprite;
	sf::RectangleShape m_sign;
	sf::Text m_signText;

	sf::Sprite player1Sprite;
	CharacterAnimation animationPlayer1;

	sf::Sprite player2Sprite;
	CharacterAnimation animationPlayer2;

	float m_deltaTime = 0.0f;
	sf::Clock m_clock;

public:
	Game() = default;
	~Game() = default;

	void init();
	/*bool playersAreAlive();
	bool isPlayer1sTurn();
	void changeTurn();
	void processEvents();
	void applyCooldownTicks();
	void showWinner();*/
	/*void proccesEvents();
	void update();*/
	void handleInputs(sf::Event& event);
	void drawFrame(sf::RenderWindow& window);
	void update();

	void updateDeltaTime();

	float getDeltaTime();
	void getMousePosition(sf::RenderWindow& window);

	void resetClassSelectionButtons();
	void resetItemSelectionButtons();
	void resetItemPlayerInventory();
};

void drawHP(sf::RenderWindow& window, Player& player1, Player& player2);
//void processEventsForPlayerTurn(Player& player1, Player& player2);