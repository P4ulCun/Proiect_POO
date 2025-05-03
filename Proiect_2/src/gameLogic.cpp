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
	sf::Texture& signTexture = Resources::getInstance().getSignTexture();

	m_sign = sf::RectangleShape(sf::Vector2f(signTexture.getSize().x, signTexture.getSize().y));
	m_sign.setPosition(windowDetails::WINDOW_WIDTH / 2 - m_sign.getSize().x / 2, 0);
	m_sign.setTexture(&signTexture);

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

	player1Sprite.setPosition(100, windowDetails::WINDOW_HEIGHT - 450);

	//trb schimbat!!
	player2Sprite.setPosition(windowDetails::WINDOW_WIDTH - characterSprite::WIDTH - 100,
		windowDetails::WINDOW_HEIGHT - 450);

	//PLAYER END

	//SELECTION BUTTONS START
	m_classSelectionButtons = initClassSelectionButtons(Resources::getInstance().getFont());
	m_itemSelectionButtons = initItemSelectionButtons(Resources::getInstance().getFont());
	//SELECTION BUTTONS END
	
	//CHARACTER CREATION

	/*std::cout << "PLAYER 1 - MAKE YOUR CHARACTER!\n\n";
	m_player1 = createPlayer();

	std::cout << "PLAYER 2 - YOUR TURN!\n\n";
	m_player2 = createPlayer();

	std::cout << "GET READY!\n\n" << "FIGHT!\n";*/
}

float Game::getDeltaTime() { return m_deltaTime; }
void Game::getMousePosition(sf::RenderWindow& window) { m_mousePosition = sf::Vector2f(sf::Mouse::getPosition(window)); }

void Game::resetClassSelectionButtons()
{
	if (m_selectClass == false)
		return;

	for (auto& btn : m_classSelectionButtons)
		if (btn.selected == true)
		{
			btn.hovered = false;
			btn.selected = false;

			for (auto& ItemBtn : m_itemSelectionButtons)
				ItemBtn.selected = false;
			//player chose CLASS!!!

			switch (btn.index)
			{
			case 1:
				//Rogue
				if (m_player1sTurn)
					player1Sprite.setTexture(Resources::getInstance().getRogueTexture());
				else
					player2Sprite.setTexture(Resources::getInstance().getRogueTexture());
				break;

			case 2:
				//Druid
				if (m_player1sTurn)
					player1Sprite.setTexture(Resources::getInstance().getDruidTexture());
				else
					player2Sprite.setTexture(Resources::getInstance().getDruidTexture());
				break;

			case 3:
				//Warrior
				break;
			}

			m_selectClass = false;
			m_selectItems = true;
		}
}

void Game::resetItemSelectionButtons()
{
	if (m_selectItems == false)
		return;

	int selectedCnt = 0;
	for (auto& btn : m_itemSelectionButtons)
		if (btn.selected == true)
			selectedCnt++;

	if (selectedCnt > 3)
		std::cout << "prea multe iteme!! eroare!!\n";
	else if (selectedCnt == 3)
	{
		if (m_player1sTurn == false)
		{
			//gata cu selctionul
			m_selectClass = false;
			m_selectItems = false;
			//pune itemele la player2!!
		}
		else
		{
			//pune itemele la player1!!
			//si scoatele din inventar

			//doar am scos butonale din gui
			for (auto item = m_itemSelectionButtons.begin(); item != m_itemSelectionButtons.end(); )
				if ((*item).selected)
					item = m_itemSelectionButtons.erase(item);
				else
					item++;

			for (auto& btn : m_classSelectionButtons)
				btn.selected = false;

			m_selectItems = false;
			m_selectClass = true;
		}
		m_player1sTurn = !m_player1sTurn;
	}
}

void Game::updateDeltaTime()
{
	m_deltaTime = m_clock.restart().asSeconds();
}

void Game::update()
{
	if (m_player1sTurn == true)
		m_signText.setString("Player 1's TURN");
	else
		m_signText.setString("Player 2's TURN");

	animationPlayer1.update(0, m_deltaTime); // first animation aka row 0
	player1Sprite.setTextureRect(animationPlayer1.m_uvRect);

	//animationPlayer2.update(0, m_deltaTime); // first animation aka row 0
	//player2Sprite.setTextureRect(animationPlayer2.m_uvRect);
}

void Game::drawFrame(sf::RenderWindow& window)
{
	window.clear();

	window.draw(m_backgroundSprite);
	window.draw(m_sign);
	window.draw(m_signText);

	if (m_selectClass == true)
	{
		if (m_player1sTurn == false)
			window.draw(player1Sprite);

		for (auto& btn : m_classSelectionButtons)
			btn.draw(window);
	}
	else
	{
		if (m_selectItems == true)
			for (auto& btn : m_itemSelectionButtons)
				btn.draw(window);

		window.draw(player1Sprite);
		window.draw(player2Sprite);
	}
	
	window.display();
}

void Game::handleInputs(sf::Event& event)
{
	// Mouse hover Class Select Buttons
	for (int i = 0; i < m_classSelectionButtons.size(); i++) {
		if (m_classSelectionButtons[i].contains(m_mousePosition)) {
			m_classSelectionButtons[i].hovered = true;
		}
		else
		{
			m_classSelectionButtons[i].hovered = false;
		}
	}

	// Mouse hover Item Select Buttons  (ITEM SOHP)
	for (int i = 0; i < m_itemSelectionButtons.size(); i++) {
		if (m_itemSelectionButtons[i].contains(m_mousePosition)) {
			m_itemSelectionButtons[i].hovered = true;
		}
		else
		{
			m_itemSelectionButtons[i].hovered = false;
		}
	}

	// Mouse click Class Select
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		for (int i = 0; i < m_classSelectionButtons.size(); i++) {
			if (m_classSelectionButtons[i].contains(m_mousePosition)) {
				m_classSelectionButtons[i].selected = true;
				std::cout << "pressed " << i << "nd button!\n";
				//std::cout << "Selected: " << labels[i] << std::endl;
			}
		}
	}

	// Mouse click (ITEM SOHP)
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		for (int i = 0; i < m_itemSelectionButtons.size(); i++) {
			if (m_itemSelectionButtons[i].contains(m_mousePosition)) {
				m_itemSelectionButtons[i].selected = true;
				std::cout << "pressed " << i << "nd button!\n";
				//std::cout << "Selected: " << labels[i] << std::endl;
			}
		}
	}
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