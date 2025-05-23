#include "inventory.h"
#include "errorHandling.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>

#include "json.hpp"
using json = nlohmann::json;

Inventory::Inventory(const Inventory& inventory)
{
	m_items = inventory.m_items;
}

std::string Inventory::getItemName(int index)
{
	index--;
	return m_items[index]->getName();
}
std::string Inventory::getItemDesc(int index)
{
	index--;
	return m_items[index]->getDesc();
}

void ItemShop::addItem(std::shared_ptr<Item> item) { m_items.push_back(item); }
void ItemShop::removeItem(std::shared_ptr<Item> item)
{
	m_items.erase(
		std::remove(m_items.begin(), m_items.end(), item),
		m_items.end()
	);

	// remove by searching the pointer to the item or remove by index
	// idk yet
	// remove as in can't be selected in the shop, but it's still there
	// hide element
}

std::shared_ptr<Item> ItemShop::getItem(std::string itemName)
{
	if (itemName[0] >= '0' && itemName[0] <= '9')
	{
		// daca e 1 2 3 4,, index
		int index = std::stoi(itemName);
		index--;
		if (index < m_items.size())
			return m_items[index];

		return nullptr;
	}

	for (const auto& item : m_items)
	{
		if (item->getName() == itemName)
			return item;
	}
	return nullptr;
}

void PlayerInventory::addItem(std::shared_ptr<Item> item) 
{ 
	if (m_currNumItems < m_maxNumItems)
	{
		m_items.push_back(item);
		m_currNumItems += 1;
	}
	else std::cout << "can't add more than " << m_maxNumItems << " items to player inventory\n";
}
void PlayerInventory::removeItem(std::shared_ptr<Item> item)
{
	// remove by searching the pointer to the item or remove by index
	// actual remove
}

void PlayerInventory::usePassive(int index, Character& player)
{
	m_items[index]->applyPassive(player);
}

int PlayerInventory::useActive(int index, Character& player1, Character& player2) // can be either target or user(player)
{	
	index--;
	if (auto sword = dynamic_cast<ActiveSword*>(m_items[index].get()))
	{
		//the selected item is an active sword
		return m_items[index]->useItemAbility(player2); // attack;
	}
	else if (auto heal = dynamic_cast<ActiveHeal*>(m_items[index].get()))
	{
		//the selected item is an active heal
		return m_items[index]->useItemAbility(player1); // heal
	}
	else
		return 2; // not an active ability
}

int PlayerInventory::getItemCooldown(int index)
{
	index--;
	//std::cout << "GET ITEM COOLDOWN AT INDEX: " << index << std::endl;
	return m_items[index]->getItemCooldown();
}

void PlayerInventory::applyItemsCooldownTicks()
{
	for (auto& item : m_items)
	{
		if (auto sword = dynamic_cast<ActiveSword*>(item.get()))
		{
			//the selected item is an active sword
			sword->tick();
		}
		else if (auto heal = dynamic_cast<ActiveHeal*>(item.get()))
		{
			//the selected item is an active heal
			heal->tick();
		}
	}
}

void Inventory::listItems()
{
	/*for (const auto& item : m_items)
		std::cout << *item << std::endl;*/

	for (int index = 0; index < m_items.size(); index++)
		std::cout << index + 1 << ". " << *m_items[index] << std::endl;
}



//INITIALIZING all the ITEMS
void ItemShop::init()
{
	std::string filename = "C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\items.json";
	std::ifstream file(filename);
	if (!file)
		throw FileLoadError("couldn't load file: " + filename);
	json data;
	file >> data;

	for (const auto& jItem : data["items"]) {
		std::string type = jItem["type"];
		std::string name = jItem["name"];
		std::string desc = jItem["description"];

		if (type == "BasicSword") {
			int power = jItem["power"];
			m_items.push_back(std::make_shared<BasicSword>(name, desc, power));
		}
		else if (type == "BasicHeal") {
			int hp = jItem["hp"];
			m_items.push_back(std::make_shared<BasicHeal>(name, desc, hp));
		}
		else if (type == "BasicArmour") {
			int armour = jItem["armour"];
			m_items.push_back(std::make_shared<BasicArmour>(name, desc, armour));
		}
		else if (type == "ActiveSword") {
			int power = jItem["power"];
			int activePower = jItem["activePower"];
			int cooldown = jItem["cooldown"];
			m_items.push_back(std::make_shared<ActiveSword>(name, desc, power, activePower, cooldown));
		}
		else if (type == "ActiveHeal") {
			int hp = jItem["hp"];
			int activeHp = jItem["activeHp"];
			int cooldown = jItem["cooldown"];
			m_items.push_back(std::make_shared<ActiveHeal>(name, desc, hp, activeHp, cooldown));
		}
	}
}