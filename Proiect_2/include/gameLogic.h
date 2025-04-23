#pragma once
#include "singleton.h"
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"
#include "imguiThemes.h"

#include "errorHandling.h"
// singleton?

class Game : public Singleton<Game>
{
private:
	bool m_player1Turn;
	sf::Sprite m_backgroundSprite;
public:
	Game() = default;
	~Game() = default;

	void init();
	/*void proccesEvents();
	void update();*/
	void draw(sf::RenderWindow& window);
};