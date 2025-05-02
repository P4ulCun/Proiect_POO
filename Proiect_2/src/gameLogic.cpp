#include "gameLogic.h"

void drawClassSelectionScreen()
{

}
//void processEventsForPlayerTurn(Player& player1, Player& player2) // player1 e turn ul lui, player2 e enemy
//{
//	std::cout << std::endl << player1.m_character->getName() << "'S TURN!\n\n";
//
//	bool makingAMove = true;
//	while (makingAMove)
//	{
//		std::cout << player1.m_character->getName() << ", make your move!\n" << "('q' for a basic attack)\n"
//			<< "('w' for special attack)\n" << "('1', '2', '3' for item active effects)\n"
//			<< "('i' to check inventory)\n" << "('s' to check player stats)\n\n";
//
//		std::string input;
//		std::getline(std::cin, input);
//
//		if (input == "i" || input == "I")
//		{
//			//check inventory
//			player1.m_inventory->listItems();
//
//			makingAMove = true; // the turn is still player1's
//		}
//		else if (input == "S" || input == "s")
//		{
//			player1.m_character->showStats();
//			makingAMove = true;
//		}
//		else if (input == "Q" || input == "q")
//		{
//			player1.m_character->basicAttack(*player2.m_character);
//			makingAMove = false;
//		}
//		else if (input == "W" || input == "w")
//		{
//			if (!player1.m_character->specialAttack1(*player2.m_character))
//			{
//				//if unsuccessful
//				std::cout << "Special attack 1 is still on cooldown"
//					<< "(" << player1.m_character->getCooldown() << ")"
//					<< "! Choose another ability!\n";
//				makingAMove = true;
//			}
//			else
//			{
//				//successful
//				makingAMove = false;
//			}
//		}
//		else if (input == "1" || input == "2" || input == "3")
//		{
//			int result = player1.m_inventory->useActive(std::stoi(input), *player1.m_character, *player2.m_character);
//			if (result == 2)
//			{
//				std::cout << "Item " << input << " does not have an active ability! Choose another ability or item!\n";
//				makingAMove = true;
//			}
//			else if (result == 0)
//			{
//				std::cout << "Item " << input << " is still on cooldown"
//					<< "(" << player1.m_inventory->getItemCooldown(std::stoi(input)) << ")"
//					<< "! Choose another ability or item!\n";
//				makingAMove = true;
//			}
//			else
//			{
//				//successful
//				makingAMove = false;
//			}
//		}
//	}
//}

void Game::init()
{
	//BACKGROUND START
	m_backgroundSprite.setTexture(Resources::getInstance().getBGTexture());
	//BACKGROUND END

	//SIGN START

	m_sign = sf::RectangleShape(sf::Vector2f(360, 200));
	m_sign.setPosition(windowDetails::WINDOW_WIDTH / 2 - m_sign.getSize().x / 2, 0);
	m_sign.setTexture(&Resources::getInstance().getSignTexture());

	m_signText.setFont(Resources::getInstance().getFont());
	m_signText.setString("Player 1's TURN");
	//signText.setColor(sf::Color::);
	m_signText.setCharacterSize(36);

	// Center text in button
	sf::FloatRect textRect = m_signText.getLocalBounds();
	m_signText.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	m_signText.setPosition(m_sign.getPosition().x + m_sign.getSize().x / 2.0f,
		m_sign.getPosition().y + m_sign.getSize().y / 2.0f);
	//SIGN END

	//PLAYER START
	sf::Texture &player1Texture = Resources::getInstance().getPlayer1Texture();
	player1Sprite.setTexture(player1Texture);

	if (animationPlayer1.m_choosePlayer == 1)
		player1Sprite.setPosition(100, windowDetails::WINDOW_HEIGHT - 450);
	else
		player1Sprite.setPosition(windowDetails::WINDOW_WIDTH - player1Texture.getSize().x / 2 - 100, 
			windowDetails::WINDOW_HEIGHT - 450);

	//PLAYER END

	//CLASS SELECTION BUTTONS START
	m_classSelectionButtons = initClassSelectionButtons(Resources::getInstance().getFont());
	//CLASS SELECTION BUTTONS END
	
	//CHARACTER CREATION

	/*std::cout << "PLAYER 1 - MAKE YOUR CHARACTER!\n\n";
	m_player1 = createPlayer();

	std::cout << "PLAYER 2 - YOUR TURN!\n\n";
	m_player2 = createPlayer();

	std::cout << "GET READY!\n\n" << "FIGHT!\n";*/
}

float Game::getDeltaTime() { return m_deltaTime; }

void Game::updateDeltaTime()
{
	m_deltaTime = m_clock.restart().asSeconds();
}

void Game::update()
{
	if (m_player1sTurn)
		m_signText.setString("Player 1's TURN");
	else
		m_signText.setString("Player 2's TURN");

	if (m_selectionPhase == true)
	{

	}
	else
	{
		animationPlayer1.update(0, m_deltaTime); // first animation aka row 0
		player1Sprite.setTextureRect(animationPlayer1.m_uvRect);
	}
}

void Game::drawFrame(sf::RenderWindow& window)
{
	window.clear();

	window.draw(m_backgroundSprite);
	window.draw(m_sign);
	window.draw(m_signText);

	if (m_selectionPhase == true)
	{
		for (auto& btn : m_classSelectionButtons)
			btn.draw(window);
	}
	else
	{
		window.draw(player1Sprite);
	}
	
	window.display();
}
//bool Game_CLI::playersAreAlive()
//{
//	return m_player1.m_character->isAlive() && m_player2.m_character->isAlive();
//}
//
//bool Game_CLI::isPlayer1sTurn()
//{
//	return m_player1sTurn;
//}
//
//void Game_CLI::processEvents() // for first players turn
//{
//	if (m_player1sTurn)
//	{
//		std::cout << "\n\n---------It is now round " << m_round << "!!!---------\n\n";
//		m_round++;
//		processEventsForPlayerTurn(m_player1, m_player2); // process events on player1's turn
//	}
//	else
//	{
//		processEventsForPlayerTurn(m_player2, m_player1); // now for player2
//	}
//}
//
//void Game_CLI::applyCooldownTicks() // 1 or 2
//{
//	if (m_player1sTurn)
//	{
//		m_player1.m_character->applyAbilityCooldownTicks();
//		m_player1.m_inventory->applyItemsCooldownTicks();
//	}
//	else
//	{
//		m_player2.m_character->applyAbilityCooldownTicks();
//		m_player2.m_inventory->applyItemsCooldownTicks();
//	}
//}
//
//void Game_CLI::changeTurn()
//{
//	m_player1sTurn = !m_player1sTurn;
//}
//
//void Game_CLI::showWinner()
//{
//	if (m_player1.m_character->isAlive())
//	{
//		std::cout << "-------CONGRATS " << m_player1.m_character->getName() << ", YOU'VE WON!!-------\n";
//	}
//	else
//	{
//		std::cout << "-------CONGRATS " << m_player2.m_character->getName() << ", YOU'VE WON!!-------\n";
//	}
//}
//