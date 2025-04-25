#pragma once
#include "characterFactory.h"
#include "inventoryBuilder.h"
#include "player.h"

Player& createPlayer()
{
	std::string className;
	std::string characterName;

	std::cout << "Introdu clasa pe care o doresti: ";
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
	std::getline(std::cin, item2);
	std::getline(std::cin, item3);

	InventoryBuilder build;
	build.addItem(ItemShop::getInstance().getItem(item1))
		.addItem(ItemShop::getInstance().getItem(item2))
		.addItem(ItemShop::getInstance().getItem(item3));
	auto inventory = build.build();

	std::cout << "Character created successfully!\n";
	return Player(inventory, character);
}