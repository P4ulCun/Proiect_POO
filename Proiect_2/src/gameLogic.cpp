#include "gameLogic.h"

void drawHP(sf::RenderWindow& window, Player& player1, Player& player2)
{
	sf::Text HPplayer1;
	std::string string1 = player1.m_character->getHealth();
	HPplayer1.setFont(Resources::getInstance().getFont());
	HPplayer1.setString(string1);
	HPplayer1.setCharacterSize(42);
	HPplayer1.setFillColor(sf::Color::White);
	HPplayer1.setPosition(100, 50);


	sf::Text HPplayer2;
	std::string string2 = player2.m_character->getHealth();
	HPplayer2.setFont(Resources::getInstance().getFont());
	HPplayer2.setString(string2);
	HPplayer2.setCharacterSize(42);
	HPplayer2.setFillColor(sf::Color::White);
	HPplayer2.setPosition(windowDetails::WINDOW_WIDTH - 280, 50);

	window.draw(HPplayer1);
	window.draw(HPplayer2);
	/*sf::RectangleShape shapeHPplayer2;
	shapeHPplayer2.setSize(sf::Vector2f(btnWidth, btnHeight));
	shapeHPplayer2.setPosition(windowDetails::WINDOW_WIDTH - btnWidth, 10);

	sf::FloatRect textBounds = shapeHPplayer2.getLocalBounds();
	shapeHPplayer2.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
	shapeHPplayer2.setPosition(shapeHPplayer2.getPosition().x + btnWidth / 2, shapeHPplayer2.getPosition().y + btnHeight / 2);*/
}

void centerText(sf::Text& textBox, sf::RectangleShape& textureBox)
{
	// Center text in button
	sf::FloatRect textRect = textBox.getLocalBounds();
	textBox.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	textBox.setPosition(textureBox.getPosition().x + textureBox.getSize().x / 2.0f,
		textureBox.getPosition().y + textureBox.getSize().y / 2.0f);
}

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
	centerText(m_signText, m_sign);
	//SIGN END

	//ANNOUNCEMENT CARD START
	sf::Texture& announceTexture = Resources::getInstance().getAnnouncementTexture();

	m_announcementSign = sf::RectangleShape(sf::Vector2f(announceTexture.getSize().x, announceTexture.getSize().y));
	m_announcementSign.setPosition(windowDetails::WINDOW_WIDTH / 2 - m_announcementSign.getSize().x / 2,
		windowDetails::WINDOW_HEIGHT - announceTexture.getSize().y);
	m_announcementSign.setTexture(&announceTexture);

	m_announcementText.setFont(Resources::getInstance().getFont());
	m_announcementText.setString("Announcements board!");
	centerText(m_announcementText, m_announcementSign);
	//signText.setColor(sf::Color::);
	m_announcementText.setCharacterSize(36);

	//ANNOUNCEMENT CARD END

	//END SCREEN START
	sf::Texture& endTexture = Resources::getInstance().getSignTexture();

	m_endScreen = sf::RectangleShape(sf::Vector2f(endTexture.getSize().x, endTexture.getSize().y));
	m_endScreen.setTexture(&endTexture);
	m_endScreen.setPosition((windowDetails::WINDOW_WIDTH - endTexture.getSize().x) / 2,
		(windowDetails::WINDOW_HEIGHT - endTexture.getSize().y) / 2);

	m_endScreenText.setFont(Resources::getInstance().getFont());
	//signText.setColor(sf::Color::);
	m_endScreenText.setCharacterSize(36);

	//END SCREEN END

	//SELECTION BUTTONS START
	m_classSelectionButtons = initClassSelectionButtons(Resources::getInstance().getFont());
	m_itemSelectionButtons = initItemSelectionButtons(Resources::getInstance().getFont());

	m_attackButtonsPlayer1 = initAttackButtons(Resources::getInstance().getFont(), 1);
	m_attackButtonsPlayer2 = initAttackButtons(Resources::getInstance().getFont(), 2);
	//SELECTION BUTTONS END
}

float Game::getDeltaTime() { return m_deltaTime; }
void Game::getMousePosition(sf::RenderWindow& window) { m_mousePosition = sf::Vector2f(sf::Mouse::getPosition(window)); }

void Game::changeTurns()
{
	if (m_player1sTurn)
	{
		applyCooldownTicks(m_player1);
		m_player1sTurn = !m_player1sTurn;
	}
	else
	{
		applyCooldownTicks(m_player2);
		m_player1sTurn = !m_player1sTurn;
	}
}

void Game::applyBasicAttack(Player player1, Player player2)
{
	player1.m_character->basicAttack(*player2.m_character);

	m_announcementText.setString("Basic attack!");

	changeTurns();
}

void Game::applySpecialAttack(Player player1, Player player2)
{
	if (!player1.m_character->specialAttack1(*player2.m_character))
	{
		//if unsuccessful
		m_announcementText.setString("Cooldown: " + std::to_string(player1.m_character->getCooldown()));
		//try again
	}
	else
	{
		//successful
		m_announcementText.setString("Special attack!!");
		//change turn
		changeTurns();
	}
}

void Game::applyItemActive(Player player1, Player player2, int index)
{
	index++;
	int result = player1.m_inventory->useActive(index, *player1.m_character, *player2.m_character);
	if (result == 2)
	{
		//do nothing
		//not an active
		m_announcementText.setString("Not Active Item");
	}
	else if (result == 0)
	{
		//item on cooldown
		m_announcementText.setString("Cooldown: " + std::to_string(player1.m_inventory->getItemCooldown(index)));
	}
	else
	{
		//successfully used active
		m_announcementText.setString(player1.m_character->getName() + " used active item!");
		changeTurns();
	}
}

void Game::applyCooldownTicks(Player player)
{
	player.m_character->applyAbilityCooldownTicks();
	player.m_inventory->applyItemsCooldownTicks();
}

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
				{
					sf::Texture& t = Resources::getInstance().getRogueTexture();
					player1Sprite.setTexture(t);
					player1Sprite.setPosition(100, windowDetails::WINDOW_HEIGHT - t.getSize().y - 50);
					animationPlayer1 = CharacterAnimation(1, t, sf::Vector2u(2, 1), 0.5f);

					character1 = CharacterFactory::createCharacter("R", "Player1");
				}
				else
				{
					sf::Texture& t = Resources::getInstance().getRogueTexture();
					player2Sprite.setTexture(t);
					player2Sprite.setPosition(windowDetails::WINDOW_WIDTH - t.getSize().x / 2 - 100,
						windowDetails::WINDOW_HEIGHT - t.getSize().y - 50);
					animationPlayer2 = CharacterAnimation(2, t, sf::Vector2u(2, 1), 0.5f);

					character2 = CharacterFactory::createCharacter("R", "Player2");
				}

				break;

			case 2:
				//Druid
				if (m_player1sTurn)
				{
					sf::Texture& t = Resources::getInstance().getDruidTexture();
					player1Sprite.setTexture(t);
					player1Sprite.setPosition(100, windowDetails::WINDOW_HEIGHT - t.getSize().y - 50);
					animationPlayer1 = CharacterAnimation(2, t, sf::Vector2u(2, 1), 0.5f);

					character1 = CharacterFactory::createCharacter("D", "Player1");
				}
				else
				{
					sf::Texture& t = Resources::getInstance().getDruidTexture();
					player2Sprite.setTexture(t);
					player2Sprite.setPosition(windowDetails::WINDOW_WIDTH - t.getSize().x / 2 - 100,
						windowDetails::WINDOW_HEIGHT - t.getSize().y - 50);
					animationPlayer2 = CharacterAnimation(1, t, sf::Vector2u(2, 1), 0.5f);

					character2 = CharacterFactory::createCharacter("D", "Player2");
				}
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
			//pune itemele la player2!!
			std::vector<std::string> items;
			for (int i = 0; i < m_itemSelectionButtons.size(); i++)
				if (m_itemSelectionButtons[i].selected == true)
				{
					items.push_back(std::to_string(m_itemSelectionButtons[i].index));
					m_itemPlayer2Inventory.push_back(m_itemSelectionButtons[i]);
				}

			//position the player items accordingly
			for (int i = 0; i < m_itemPlayer2Inventory.size(); i++)
			{
				float shapeX = m_itemPlayer2Inventory[i].shape.getSize().x;
				m_itemPlayer2Inventory[i].shape.setPosition(
					windowDetails::WINDOW_WIDTH - 50 - shapeX - i * (shapeX + 20),
					m_sign.getSize().y / 2);
				m_itemPlayer2Inventory[i].itemIcon.setPosition(m_itemPlayer2Inventory[i].shape.getPosition());

				//reset buttons
				m_itemPlayer2Inventory[i].hovered = false;
				m_itemPlayer2Inventory[i].selected = false;
			}

			std::shared_ptr<Item> item1_ptr = ItemShop::getInstance().getItem(items[0]);
			std::shared_ptr<Item> item2_ptr = ItemShop::getInstance().getItem(items[1]);
			std::shared_ptr<Item> item3_ptr = ItemShop::getInstance().getItem(items[2]);

			InventoryBuilder build;
			build.addItem(item1_ptr)
				.addItem(item2_ptr)
				.addItem(item3_ptr);
			inventory2 = build.build();

			//gata cu selctionul
			//=> creeaza playerii
			m_player1 = Player(inventory1, character1);
			m_player2 = Player(inventory2, character2);

			for (int i = 0; i < MAX_ITEMS; i++) // trec prin itemele selectate de player
			{
				//si aplic statusurile
				m_player1.m_inventory->usePassive(i, *m_player1.m_character);
				m_player2.m_inventory->usePassive(i, *m_player2.m_character);
			}

			m_selectClass = false;
			m_selectItems = false;
		}
		else
		{
			std::vector<std::string> items;
			for (int i = 0; i < m_itemSelectionButtons.size(); i++)
				if (m_itemSelectionButtons[i].selected == true)
				{
					items.push_back(std::to_string(m_itemSelectionButtons[i].index));
					m_itemPlayer1Inventory.push_back(m_itemSelectionButtons[i]);
				}

			//position the player items accordingly
			for (int i = 0; i < m_itemPlayer1Inventory.size(); i++)
			{
				m_itemPlayer1Inventory[i].shape.setPosition(
					50 + i * (m_itemPlayer1Inventory[i].shape.getSize().x + 20),
					m_sign.getSize().y / 2);
				m_itemPlayer1Inventory[i].itemIcon.setPosition(m_itemPlayer1Inventory[i].shape.getPosition());
				m_itemPlayer1Inventory[i].hovered = false;
				m_itemPlayer1Inventory[i].selected = false;
			}

			//pune itemele la player1!!
			std::shared_ptr<Item> item1_ptr = ItemShop::getInstance().getItem(items[0]);
			std::shared_ptr<Item> item2_ptr = ItemShop::getInstance().getItem(items[1]);
			std::shared_ptr<Item> item3_ptr = ItemShop::getInstance().getItem(items[2]);

			InventoryBuilder build;
			build.addItem(item1_ptr)
				.addItem(item2_ptr)
				.addItem(item3_ptr);
			inventory1 = build.build();

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

void Game::resetItemPlayerInventory()
{
	if (!m_selectClass && !m_selectItems)
	{
		//fa ceva
		for (int i = 0; i < m_itemPlayer1Inventory.size(); i++)
		{
			if (m_itemPlayer1Inventory[i].hovered == true)
			{
				m_announcementText.setString(m_player1.m_inventory->getItemName(i + 1) + "\n" + m_player1.m_inventory->getItemDesc(i + 1));
				centerText(m_announcementText, m_announcementSign);
			}

			if (m_itemPlayer1Inventory[i].selected == true)
			{
				m_itemPlayer1Inventory[i].selected = false;
				m_itemPlayer1Inventory[i].hovered = false;

				if (m_player1sTurn)
					applyItemActive(m_player1, m_player2, i);
				//TODO: fa actiunea de la item!!!
				//!!
			}
		}

		for (int i = 0; i < m_itemPlayer2Inventory.size(); i++)
		{
			if (m_itemPlayer2Inventory[i].hovered == true)
			{
				m_announcementText.setString(m_player2.m_inventory->getItemName(i + 1) + "\n" + m_player2.m_inventory->getItemDesc(i + 1));
				centerText(m_announcementText, m_announcementSign);
			}

			if (m_itemPlayer2Inventory[i].selected == true)
			{
				m_itemPlayer2Inventory[i].selected = false;
				m_itemPlayer2Inventory[i].hovered = false;

				if (!m_player1sTurn)
					applyItemActive(m_player2, m_player1, i);
				//TODO: fa actiunea de la item!!!
				//!!
			}
		}
	}
}

void Game::resetAttackButtons()
{
	if (!m_selectClass && !m_selectItems)
	{
		//fa ceva
		for (auto& btn : m_attackButtonsPlayer1)
		{
			if (btn.hovered == true)
			{
				if (btn.index == 1)
				{
					m_announcementText.setString(m_player1.m_character->getSpecialName() + "\n" + m_player1.m_character->getSpecialDesc());
					centerText(m_announcementText, m_announcementSign);
				}
			}

			if (btn.selected == true)
			{
				btn.selected = false;
				btn.hovered = false;

				if (btn.index == 0)
				{
					//basic attack
					if (m_player1sTurn)
						applyBasicAttack(m_player1, m_player2);
				}
				else if (btn.index == 1)
				{
					//special attack
					if (m_player1sTurn)
						applySpecialAttack(m_player1, m_player2);
				}
			}
		}

		for (auto& btn : m_attackButtonsPlayer2)
		{
			if (btn.hovered == true)
			{
				if (btn.index == 1)
				{
					m_announcementText.setString(m_player2.m_character->getSpecialName() + "\n" + m_player2.m_character->getSpecialDesc());
					centerText(m_announcementText, m_announcementSign);
				}
			}

			if (btn.selected == true)
			{
				btn.selected = false;
				btn.hovered = false;

				if (btn.index == 0)
				{
					//basic attack
					if (!m_player1sTurn)
						applyBasicAttack(m_player2, m_player1);
				}
				else if (btn.index == 1)
				{
					//special attack
					if (!m_player1sTurn)
						applySpecialAttack(m_player2, m_player1);
				}
			}
		}
	}
	else
	{
		for (auto& btn : m_attackButtonsPlayer1)
			btn.selected = false;
		for (auto& btn : m_attackButtonsPlayer2)
			btn.selected = false;
	}
}

bool Game::playersAreAlive()
{
	return m_player1.m_character->isAlive() && m_player2.m_character->isAlive();
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

	if (m_selectClass == false && m_selectItems == false)
		if (!playersAreAlive())
		{
			if (m_player1.m_character->isAlive())
			{
				m_signText.setString(m_player1.m_character->getName() + " IS THE\n     WINNER!!");
				centerText(m_signText, m_sign);
			}
			else
			{
				m_signText.setString(m_player2.m_character->getName() + " IS THE\n     WINNER!!");
				centerText(m_signText, m_sign);
			}
			return;
		}


	animationPlayer1.update(0, m_deltaTime); // first animation aka row 0
	player1Sprite.setTextureRect(animationPlayer1.m_uvRect);

	animationPlayer2.update(0, m_deltaTime); // first animation aka row 0
	player2Sprite.setTextureRect(animationPlayer2.m_uvRect);
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
		else
		{
			//GAME LOOP DRAW
			//here are all the objects printed on screen after SELECTION PHASE
			for (auto& btn : m_itemPlayer1Inventory)
				btn.draw(window);
			for (auto& btn : m_itemPlayer2Inventory)
				btn.draw(window);

			for (auto& btn : m_attackButtonsPlayer1)
				btn.draw(window);
			for (auto& btn : m_attackButtonsPlayer2)
				btn.draw(window);

			drawHP(window, m_player1, m_player2);
		}

		if (m_selectClass == false && m_selectItems == false)
			if (!playersAreAlive())
			{
				/*window.draw(m_endScreen);
				window.draw(m_endScreenText);*/
			}
			else
			{
				window.draw(m_announcementSign);
				centerText(m_announcementText, m_announcementSign);
				window.draw(m_announcementText);
			}

		window.draw(player1Sprite);
		window.draw(player2Sprite);
	}
	
	window.display();
}

void Game::handleInputs(sf::Event& event)
{
	if (!m_selectClass && !m_selectItems)
		if (!playersAreAlive())
			return;

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

	// Mouse click (ITEM SOHP)
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		for (int i = 0; i < m_itemSelectionButtons.size(); i++) {
			if (m_itemSelectionButtons[i].contains(m_mousePosition)) {
				m_itemSelectionButtons[i].selected = true;
				std::cout << "pressed " << m_itemSelectionButtons[i].index << "nd button!\n";
				//std::cout << "Selected: " << labels[i] << std::endl;
			}
		}
	}


	// Mouse hover Item Player Inventory Buttons
	if (m_player1sTurn)
		for (int i = 0; i < m_itemPlayer1Inventory.size(); i++) {
			if (m_itemPlayer1Inventory[i].contains(m_mousePosition)) {
				m_itemPlayer1Inventory[i].hovered = true;
			}
			else
			{
				m_itemPlayer1Inventory[i].hovered = false;
			}
		}
	else
		for (int i = 0; i < m_itemPlayer2Inventory.size(); i++) {
			if (m_itemPlayer2Inventory[i].contains(m_mousePosition)) {
				m_itemPlayer2Inventory[i].hovered = true;
			}
			else
			{
				m_itemPlayer2Inventory[i].hovered = false;
			}
		}

	// Mouse click Player Inventory
	if (m_player1sTurn)
	{
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < m_itemPlayer1Inventory.size(); i++) {
				if (m_itemPlayer1Inventory[i].contains(m_mousePosition)) {
					m_itemPlayer1Inventory[i].selected = true;
					std::cout << "pressed " << m_itemPlayer1Inventory[i].index << "nd button!\n";
					//std::cout << "Selected: " << labels[i] << std::endl;
				}
			}
		}
	}
	else
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < m_itemPlayer2Inventory.size(); i++) {
				if (m_itemPlayer2Inventory[i].contains(m_mousePosition)) {
					m_itemPlayer2Inventory[i].selected = true;
					std::cout << "pressed " << m_itemPlayer2Inventory[i].index << "nd button!\n";
					//std::cout << "Selected: " << labels[i] << std::endl;
				}
			}
		}


	// Mouse hover Attack Buttons
	if (m_player1sTurn)
		for (int i = 0; i < m_attackButtonsPlayer1.size(); i++) {
			if (m_attackButtonsPlayer1[i].contains(m_mousePosition)) {
				m_attackButtonsPlayer1[i].hovered = true;
			}
			else
			{
				m_attackButtonsPlayer1[i].hovered = false;
			}
		}
	else
		for (int i = 0; i < m_attackButtonsPlayer2.size(); i++) {
			if (m_attackButtonsPlayer2[i].contains(m_mousePosition)) {
				m_attackButtonsPlayer2[i].hovered = true;
			}
			else
			{
				m_attackButtonsPlayer2[i].hovered = false;
			}
		}

	// Mouse click Attack Buttons
	if (m_player1sTurn)
	{
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < m_attackButtonsPlayer1.size(); i++) {
				if (m_attackButtonsPlayer1[i].contains(m_mousePosition)) {
					m_attackButtonsPlayer1[i].selected = true;
					std::cout << "pressed attack button " << m_attackButtonsPlayer1[i].index << "!\n";
				}
			}
		}
	}
	else
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			for (int i = 0; i < m_attackButtonsPlayer2.size(); i++) {
				if (m_attackButtonsPlayer2[i].contains(m_mousePosition)) {
					m_attackButtonsPlayer2[i].selected = true;
					std::cout << "pressed attack button " << m_attackButtonsPlayer2[i].index << "!\n";
				}
			}
		}
}