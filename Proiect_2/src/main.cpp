#include <iostream>
#include <string>
#include <memory>
#include "errorHandling.h"
#include "items.h"
#include "inventory.h"
#include "fighterClasses.h"
#include "gameLogic_CLI.h"
#include "player.h"

#include "playerMaker.h" 
#include "characterAnimation.h"
#include "gameLogic.h"
#include "resourceHandler.h"

#include "nameSpaces.h"

int main()
{
	//RESOURCE LOADING START
	try
	{
		Resources::getInstance().initTextures();
	}
	catch (TextureLoadError& err) { std::cout << err.what() << std::endl; }

	try
	{
		Resources::getInstance().initFont();
	}
	catch (FontLoadError& err) { std::cout << err.what() << std::endl; }
	//RESOURCES LOADING STOP

	//ITEM SHOP START
	try
	{
		//load items from json and pu them in the shop
		ItemShop::getInstance().init();
	}
	catch (FileLoadError& err) { std::cout << err.what() << std::endl; }
	//RESOURCE LOADING END

	std::cout << "CHOOSE MODE (1 - GUI, 2 - CLI): " << std::endl;
	std::string choice;
	
	std::getline(std::cin, choice);

	if (choice == "2")
	{
		/*----------------------------------------- CLI GAME LOOP START -----------------------------------------*/

		Game_CLI::getInstance().init();

		while (Game_CLI::getInstance().playersAreAlive())
		{
			Game_CLI::getInstance().processEvents();
			Game_CLI::getInstance().applyCooldownTicks();


			Game_CLI::getInstance().changeTurn();
		}
		Game_CLI::getInstance().showWinner();

		/*----------------------------------------- CLI GAME LOOP END -----------------------------------------*/
	}
	else if (choice == "1")
	{
		/*----------------------------------------- GUI GAME LOOP START -----------------------------------------*/

		sf::RenderWindow window(sf::VideoMode(windowDetails::WINDOW_WIDTH, windowDetails::WINDOW_HEIGHT), "game!"); // , sf::Style::Fullscreen

		Game::getInstance().init();

		while (window.isOpen())
		{
			//deltaTime = clock.restart().asSeconds();
			Game::getInstance().resetClassSelectionButtons();
			Game::getInstance().resetItemSelectionButtons();
			Game::getInstance().resetItemPlayerInventory();
			Game::getInstance().resetAttackButtons();

			Game::getInstance().updateDeltaTime();
			Game::getInstance().getMousePosition(window);

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				else if (event.type == sf::Event::Resized)
				{
					// Adjust the viewport when the window is resized
					/*sf::FloatRect visibleArea(200, 200, event.size.width, event.size.height);
					window.setView(sf::View(visibleArea));*/
				}

				Game::getInstance().handleInputs(event);
			}
			//Game::getInstance().update();
			Game::getInstance().update();
			Game::getInstance().drawFrame(window);
		}

		/*----------------------------------------- GUI GAME LOOP END -----------------------------------------*/
	}
	else
		std::cout << "Choose a valid mode!\n";

	return 0;
}