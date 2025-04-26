#pragma once
#include "characterFactory.h"
#include "inventoryBuilder.h"
#include "player.h"

Player createPlayer()
{
	std::string className;
	std::string characterName;

	std::cout << "Introdu clasa pe care o doresti: (Rogue, Druid, Warrior)\n";
	std::getline(std::cin, className);
	//std::cout << std::endl;

	std::cout << "Introdu numele dorit: ";
	std::getline(std::cin, characterName);
	//std::cout << std::endl;

	auto character = CharacterFactory::createCharacter(className, characterName);


	// assuming item shop is initialized
	std::cout << std::endl;
	std::cout << "Select what items you want from the shop: (select 3) (select by index or by name)\n\n";
	ItemShop::getInstance().listItems();

	std::string item1, item2, item3;
	std::getline(std::cin, item1);
	std::shared_ptr<Item> item1_ptr = ItemShop::getInstance().getItem(item1);
	std::getline(std::cin, item2);
	std::shared_ptr<Item> item2_ptr = ItemShop::getInstance().getItem(item2);
	std::getline(std::cin, item3);
	std::shared_ptr<Item> item3_ptr = ItemShop::getInstance().getItem(item3);


	InventoryBuilder build;
	build.addItem(item1_ptr)
		.addItem(item2_ptr)
		.addItem(item3_ptr);
	auto inventory = build.build();

	ItemShop::getInstance().removeItem(item1_ptr);
	ItemShop::getInstance().removeItem(item2_ptr);
	ItemShop::getInstance().removeItem(item3_ptr);

	std::cout << "Character created successfully!\n";
	Player player(inventory, character);

	/*std::cout << "Character specs: \n";
	player.m_character->showSpecs();*/

	//apply item stats to player
	//for (const auto& item : (*player.m_inventory).m_items) // trec prin itemele selectate de player
	//{
	//	//si aplic statusurile
	//	(*item).applyPassive(*player.m_character);
	//}

	for (int i = 0; i < MAX_ITEMS; i++) // trec prin itemele selectate de player
	{
		//si aplic statusurile
		player.m_inventory->usePassive(i, *player.m_character);
	}

	std::cout << "Character specs after item passives: \n\n";
	player.m_character->showSpecs();

	return player;
}