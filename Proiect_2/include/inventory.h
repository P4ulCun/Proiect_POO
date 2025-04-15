#pragma once
#include "items.h"
#include "singleton.h"
#include <string>
#include <memory>
#include <vector>


//class Item;

class Inventory
{
protected:
	std::vector<std::shared_ptr<Item>> m_items;
public:
	Inventory() = default;
	Inventory(const Inventory& inventory);
	virtual ~Inventory() = default;

	virtual void addItem(std::shared_ptr<Item> item) = 0;
	virtual void removeItem(std::shared_ptr<Item> item) = 0;
	//virtual void listItems() = 0;
	// asta pt afisare cu sprites si chestii
};

class ItemShop : public Inventory , public Singleton<ItemShop>
{
public:
	ItemShop() : Inventory() {};
	void init();
	void addItem(std::shared_ptr<Item> item);
	void removeItem(std::shared_ptr<Item> item);
	void listItems();

	//void moveToPlayerInventory(int index, Inventory& playerInventory);
};

class PlayerInventory : public Inventory
{
	int m_maxItems;
public:
	PlayerInventory() : m_maxItems(3) {};
	void addItem(std::shared_ptr<Item> item);
	void removeItem(std::shared_ptr<Item> item);

	/*void usePassive(int index, Character& player);
	void useActive(int index, Character& player);*/ // can be either target or user
};