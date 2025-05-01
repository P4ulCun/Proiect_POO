#pragma once
#include "singleton.h"
#include <SFML/Graphics.hpp>

#include "errorHandling.h"
#include "playerMaker.h"

namespace windowDetails {
	constexpr float WINDOW_WIDTH = 1200;
	constexpr float WINDOW_HEIGHT = 675;
}

class Game : public Singleton<Game>
{
private:
	Player m_player1;
	Player m_player2;
	bool m_player1sTurn = true;
	int m_round = 1;
private:
	std::string PATH = "C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\";
	sf::Font m_font;
	sf::Sprite m_backgroundSprite;
	sf::RectangleShape m_sign;
	sf::Text m_signText;
	sf::Texture m_itemFrameTexture;

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
};

//void processEventsForPlayerTurn(Player& player1, Player& player2);