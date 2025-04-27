#pragma once
#include <memory>
#include <string>
class PlayerInventory;
class Character;

class Player
{
public:
	std::shared_ptr<PlayerInventory> m_inventory;
	std::shared_ptr<Character> m_character;

	Player() = default;
	Player(std::shared_ptr<PlayerInventory> inventory, std::shared_ptr<Character> character)
		: m_inventory(inventory), m_character(character) {};

	~Player() = default;
};