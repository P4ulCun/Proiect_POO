#pragma once
#include "singleton.h"
#include <SFML/Graphics.hpp>

#include "errorHandling.h"
#include "playerMaker.h"
#include "resourceHandler.h"
#include "characterAnimation.h"
#include "button.h"

namespace windowDetails {
	constexpr float WINDOW_WIDTH = 1200;
	constexpr float WINDOW_HEIGHT = 675;
}

void drawClassSelectionScreen();

class Game : public Singleton<Game>
{
private:
	Player m_player1;
	Player m_player2;
	bool m_selectionPhase = true;
	bool m_player1sTurn = true;
	int m_round = 1;
private:
	sf::Sprite m_backgroundSprite;
	sf::RectangleShape m_sign;
	sf::Text m_signText;
	sf::Sprite player1Sprite;
	CharacterAnimation animationPlayer1 = CharacterAnimation(1,
		Resources::getInstance().getPlayer1Texture(), sf::Vector2u(2, 1), 0.5f);

	float m_deltaTime = 0.0f;
	sf::Clock m_clock;

public:
	Game() = default;
	~Game() = default;

	void init();
	bool playersAreAlive();
	bool isPlayer1sTurn();
	void changeTurn();
	void processEvents();
	void applyCooldownTicks();
	void showWinner();
	/*void proccesEvents();
	void update();*/
	void drawFrame(sf::RenderWindow& window);
	void update();
	void updateDeltaTime();
	float getDeltaTime();
};

//void processEventsForPlayerTurn(Player& player1, Player& player2);