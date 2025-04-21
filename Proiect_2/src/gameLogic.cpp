#include "gamelogic.h"
#include <iostream>

void Game::init()
{
	m_player1Turn = false;

	sf::Texture backgroundTexture;
	try
	{
		if (!backgroundTexture.loadFromFile("C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\background_bamboo_1200_cut.png"))
			throw TextureLoadError("Couldn't load texture\n");
		m_backgroundSprite.setTexture(backgroundTexture);
	}
	catch (TextureLoadError& err) { std::cout << err.what(); }
}

void Game::draw(sf::RenderWindow& window)
{
	window.draw(m_backgroundSprite);
	std::cout << m_player1Turn << '\n';
}