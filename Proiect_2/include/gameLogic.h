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

	std::vector<Button> m_attackButtonsPlayer1;
	std::vector<Button> m_attackButtonsPlayer2;

	sf::Sprite m_backgroundSprite;

	sf::RectangleShape m_sign;
	sf::Text m_signText;

	sf::RectangleShape m_endScreen;
	sf::Text m_endScreenText;

	sf::RectangleShape m_announcementSign;
	sf::Text m_announcementText;

	sf::Sprite player1Sprite;
	CharacterAnimation animationPlayer1;

	sf::Sprite player2Sprite;
	CharacterAnimation animationPlayer2;

	float m_deltaTime = 0.0f;
	sf::Clock m_clock;

	float m_cooldownSignTime = 0.0f;

public:
	Game() = default;
	~Game() = default;

	void init();

	void handleInputs(sf::Event& event);
	void drawFrame(sf::RenderWindow& window);
	void update();

	void updateDeltaTime();
	void updateAnnouncementBoard(std::string string);

	void applyBasicAttack(Player player1, Player player2);
	void applySpecialAttack(Player player1, Player player2);
	void applyItemActive(Player player1, Player player2, int index);
	void applyCooldownTicks(Player player);
	bool playersAreAlive();
	void changeTurns();

	float getDeltaTime();
	void getMousePosition(sf::RenderWindow& window);

	void resetClassSelectionButtons();
	void resetItemSelectionButtons();
	void resetItemPlayerInventory();
	void resetAttackButtons();
};

void drawHP(sf::RenderWindow& window, Player& player1, Player& player2);

void centerText(sf::Text& textBox, sf::RectangleShape& textureBox);