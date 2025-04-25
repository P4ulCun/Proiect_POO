#pragma once
#include <memory>

class Inventory;
class Character;

class Player
{
public:
	std::shared_ptr<Inventory> m_inventory;
	std::shared_ptr<Character> m_character;

	Player() = default;
	Player(std::shared_ptr<Inventory> inventory, std::shared_ptr<Character> character)
		: m_inventory(inventory), m_character(character) {};

	~Player() = default;
};