#include "gamelogic.h"

void processEventsForPlayerTurn(Player player1, Player player2) // player1 e turn ul lui, player2 e enemy
{
	std::cout << std::endl << player1.m_character->getName() << "'S TURN!\n";

	bool makingAMove = true;
	while (makingAMove)
	{
		std::cout << player1.m_character->getName() << ", make your move!\n" << "('q' for a basic attack)\n"
			<< "('w' for special attack)\n" << "('1', '2', '3' for item active effects)\n"
			<< "('i' to check inventory)\n" << "('s' to check player stats)\n\n";

		std::string input;
		std::getline(std::cin, input);

		if (input == "i" || input == "I")
		{
			//check inventory
			player1.m_inventory->listItems();

			makingAMove = true; // the turn is still player1's
		}
		else if (input == "S" || input == "s")
		{
			player1.m_character->showStats();
			makingAMove = true;
		}
		else if (input == "Q" || input == "q")
		{
			player1.m_character->basicAttack(*player2.m_character);
			makingAMove = false;
		}
		else if (input == "W" || input == "w")
		{
			if (!player1.m_character->specialAttack1(*player2.m_character))
			{
				//if unsuccessful
				std::cout << "Special attack 1 is still on cooldown! Choose another ability!\n";
				makingAMove = true;
			}
			else
			{
				//successful
				makingAMove = false;
			}
		}
		else if (input == "1" || input == "2" || input == "3")
		{
			if (!player1.m_inventory->useActive(std::stoi(input), *player1.m_character, *player2.m_character))
			{
				std::cout << "Item " << input << " is still on cooldown or does not"
					<< " have an active ability! Choose another ability or item!\n";
				makingAMove = true;
			}
			else
			{
				//successful
				makingAMove = false;
			}
		}
	}
}

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

	std::cout << "GET READY!\n\n" << "FIGHT!\n\n";
}

bool Game::playersAreAlive()
{
	return player1.m_character->isAlive() && player2.m_character->isAlive();
}

void Game::processEvents() // for first players turn
{
	processEventsForPlayerTurn(player1, player2); // process events on player1's turn

	processEventsForPlayerTurn(player2, player1); // now for player2
}

void Game::draw(sf::RenderWindow& window)
{
	/*window.draw(m_backgroundSprite);
	std::cout << m_player1Turn << '\n';*/
}