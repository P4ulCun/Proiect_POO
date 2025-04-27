#pragma once
#include "inventory.h"

class InventoryBuilder
{
	std::shared_ptr<PlayerInventory> inventory;
public:
	InventoryBuilder();

	InventoryBuilder& addItem(const std::shared_ptr<Item>& item);

	std::shared_ptr<PlayerInventory> build();
};