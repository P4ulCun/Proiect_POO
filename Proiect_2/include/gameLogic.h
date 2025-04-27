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
	Player player1;
	Player player2;
public:
	Game() = default;
	~Game() = default;

	void init();
	/*void proccesEvents();
	void update();*/
	void draw(sf::RenderWindow& window);
};