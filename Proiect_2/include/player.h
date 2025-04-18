#pragma once
#include <memory>

class Inventory;
class Character;

class Player
{
public:
	bool m_isBot;
	std::shared_ptr<Inventory> m_inventory;
	std::shared_ptr<Character> m_character;

	Player(std::shared_ptr<Inventory> inventory, std::shared_ptr<Character> character, bool isBot)
		: m_inventory(inventory), m_character(character), m_isBot(isBot) {};

	~Player() = default;
};