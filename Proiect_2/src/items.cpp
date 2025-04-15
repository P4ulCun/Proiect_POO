#include "items.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, Item& item)
{
	std::cout << item.m_itemName << ": " << item.m_itemDesc << '\n';
	return out;
}

void BasicSword::applyPassive(Character& player)
{
	player.increaseBasePower(m_power);
	std::cout << "applied " << m_power << " base damage!" << std::endl;
}

void BasicHeal::applyPassive(Character& player)
{
	player.increaseBaseHP(m_HP);
	std::cout << "applied " << m_HP << " base healing!" << std::endl;
}

void BasicArmour::applyPassive(Character& player)
{
	player.increaseBaseArmour(m_armour);
	std::cout << "applied " << m_armour << " base armour!" << std::endl;
}


void ActiveSword::useItemAbility(Character& target)
{
	//attack somebody
	std::cout << "used " << m_itemName << " and dealt " << m_activePower << " damage\n";
	target.takeDamage(m_activePower);
	// need to define it
}

void ActiveHeal::useItemAbility(Character& player)
{
	//heal the user
	std::cout << "used " << m_itemName << " to heal " << m_activeHeal << " HP\n";
	player.heal(m_activeHeal);
	// need to define it
}


//void ActiveArmour::useItemAbility(Character& player)
//{
//	std::cout << "used Chain Mail to increase armour by " << m_activeArmour << "\n";
//	// need to define it
//}