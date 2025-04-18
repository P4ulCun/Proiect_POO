#pragma once
#include "singleton.h"
// singleton?

class Game
{
private:
	bool m_player1Turn;

	void init();
	void proccesEvents();
	void update();
	void draw();
public:
};