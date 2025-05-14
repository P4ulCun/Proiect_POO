#include "items.h"
#include <iostream>

std::ostream& operator<<(std::ostream& out, Item& item)
{
	std::cout << item.m_itemName << ": " << item.m_itemDesc << '\n';
	return out;
}
std::string Item::getName()
{
	return m_itemName;
}

std::string Item::getDesc()
{
	return m_itemDesc;
}

void BasicSword::applyPassive(Character& player)
{
	//increaseStats(player.m_basePower, m_power);
	player.increaseBasePower(m_power);
	//std::cout << "applied " << m_power << " base damage!" << std::endl;
}

void BasicHeal::applyPassive(Character& player)
{
	//increaseStats(player.m_baseHP, m_HP);
	player.increaseBaseHP(m_HP);
	//std::cout << "applied " << m_HP << " base healing!" << std::endl;
}

void BasicArmour::applyPassive(Character& player)
{
	player.increaseBaseArmour(m_armour);
	//std::cout << "applied " << m_armour << " base armour!" << std::endl;
}


int ActiveSword::useItemAbility(Character& target)
{
	//attack somebody
	if (isOffCooldown())
	{
		int actualDMG = target.takeDamage(m_activePower);
		std::cout << "used " << m_itemName << " and dealt " << actualDMG << " damage\n";
		applyCooldown();
		return 1; //successful
	}
	return 0; // unsuccessful
}

int ActiveHeal::useItemAbility(Character& player)
{
	//heal the user
	if (isOffCooldown()) {
		int actualHealAmount = player.heal(m_activeHeal);
		std::cout << "used " << m_itemName << " to heal " << actualHealAmount << " HP\n";
		applyCooldown();
		return 1;
	}
	return 0;
	// need to define it
}

int ActiveSword::getItemCooldown()
{
	return getCooldown(); // from status effect Cooldown
}
int ActiveHeal::getItemCooldown()
{
	return getCooldown();
}
//void ActiveArmour::useItemAbility(Character& player)
//{
//	std::cout << "used Chain Mail to increase armour by " << m_activeArmour << "\n";
//	// need to define it
//}