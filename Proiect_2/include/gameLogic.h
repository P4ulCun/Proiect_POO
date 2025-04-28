#pragma once
#include "singleton.h"
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "imguiThemes.h"

#include "errorHandling.h"
#include "playerMaker.h"

class Game : public Singleton<Game>
{
private:
	Player m_player1;
	Player m_player2;
	bool m_player1sTurn = true;
	int m_round = 1;
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
	void draw(sf::RenderWindow& window);
};

void processEventsForPlayerTurn(Player& player1, Player& player2);