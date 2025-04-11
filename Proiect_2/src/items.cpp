#include "items.h"
#include <iostream>


void BasicSword::applyEffect(Character& player)
{
	player.increasePower(m_power);
	std::cout << "applied 10 damage!" << std::endl;
}

void BasicHealing::applyEffect(Character& player)
{
	player.increaseHP(m_healing);
	std::cout << "applied 10 healing!" << std::endl;
}

void BasicArmour::applyEffect(Character& player)
{
	player.increaseArmour(m_armour);
	std::cout << "applied 10 armour!" << std::endl;
}