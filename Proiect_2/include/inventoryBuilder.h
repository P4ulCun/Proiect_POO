#pragma once
#include "inventory.h"

class InventoryBuilder
{
	std::shared_ptr<PlayerInventory> inventory;
public:
	InventoryBuilder() { inventory = std::make_shared<PlayerInventory>(); };

	InventoryBuilder& addItem(const std::shared_ptr<Item>& item)
	{
		inventory->addItem(item);
		return *this;
	}

	std::shared_ptr<PlayerInventory> build()
	{
		return inventory;
	}
};