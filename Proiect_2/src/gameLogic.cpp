#include "gamelogic.h"

void Game::init()
{
	/*m_player1Turn = true;

	sf::Texture backgroundTexture;
	try
	{
		if (!backgroundTexture.loadFromFile("C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\background_bamboo_1200_cut.png"))
			throw TextureLoadError("Couldn't load texture\n");
		m_backgroundSprite.setTexture(backgroundTexture);
	}
	catch (TextureLoadError& err) { std::cout << err.what(); }*/

	try
	{
		//load items from json and pu them in the shop
		ItemShop::getInstance().init();
	}
	catch (FileLoadError& err) { std::cout << err.what() << std::endl; }

	//CHARACTER CREATION

	std::cout << "PLAYER 1 - MAKE YOUR CHARACTER!\n\n";
	player1 = createPlayer();

	std::cout << "PLAYER 2 - YOUR TURN!\n\n";
	player2 = createPlayer();
}

void Game::draw(sf::RenderWindow& window)
{
	/*window.draw(m_backgroundSprite);
	std::cout << m_player1Turn << '\n';*/
}