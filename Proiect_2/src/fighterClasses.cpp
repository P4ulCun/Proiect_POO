#include "fighterClasses.h"

//template<typename T>
//void increaseStats(T& stat, T& boost)
//{
//	stat += boost;
//}

void Character::increaseBaseHP(int value) { m_baseHP += value; m_currHP = m_baseHP; }
void Character::increaseBasePower(int value) { m_basePower += value; m_currPower = m_basePower; }
int Character::increaseBaseArmour(int value) 
{ 
	if (m_baseArmour + value > 7)
	{
		m_baseArmour = 7;
		m_currArmour = m_baseArmour;
		return 1; // increase unsuccessful
	}
	else
	{
		m_baseArmour += value;
		m_currArmour = m_baseArmour;
		return 0; // increase successful
	}
}

int Character::takeDamage(int value) 
{ 
	// need to occount for armour (damage reduction by %) : (m_armour + 1)^2
	value = value - (int)((value * pow(m_currArmour + 1, 2)) / 100);
	m_currHP = (m_currHP - value <= 0) ? 0 : m_currHP - value;
	//m_currHP -= value; 
	return value;
}
int Character::heal(int value)
{ 
	//returns the actual heal amount, accounting for the overflow of base health
	if (m_baseHP - m_currHP >= value)
	{
		//heal the value amount
		int actualHealAmount = value;
		m_currHP += value;
		return value;
	}
	else
	{
		//heal less than the specified value, because overflow of max HP
		int actualHealAmount = m_baseHP - m_currHP;
		m_currHP = m_baseHP;
		return actualHealAmount;
	}
}

void Character::basicAttack(Character& target)
{
	int actualDMG = target.takeDamage(m_currPower);
	std::cout << "took " << actualDMG << " damage!\n";
}

void Character::showStats()
{
	std::cout << std::endl;
	std::cout << "HP: " << m_currHP << std::endl
			<< "Power: " << m_currPower << std::endl
			<< "Armour: " << m_currArmour << std::endl;
	std::cout << std::endl;
}

int Character::getCooldown() 
{
	return m_special1Cooldown.getCooldown();
}

std::string Character::getSpecialName()
{
	return m_specialName;
}
std::string Character::getSpecialDesc()
{
	return m_specialDesc;
}

bool Character::isAlive()
{
	if (m_currHP <= 0)
		return false;
	return true;
}

std::string& Character::getName()
{
	return m_name;
}

void Character::applyAbilityCooldownTicks()
{
	m_special1Cooldown.tick();
	//special2Cooldown
}

//std::ostream& operator<<(std::ostream& out, Character player)
//{
//	std::cout << player.m_baseHP << '\n'
//		<< player.m_basePower << '\n'
//		<< player.m_baseArmour << '\n';
//	return out;
//}

int Rogue::specialAttack1(Character& target)
{
	//+15 damage
	if (m_special1Cooldown.isOffCooldown())
	{
		int actualDMG = target.takeDamage(m_currPower + 15);
		std::cout << "used " << m_specialName << " to inflict " << actualDMG << " damage!!\n";
		m_special1Cooldown.applyCooldown();
		return 1; // successful 
	}
	return 0; // unsuccessful
}

int Druid::specialAttack1(Character& target)
{
	//+ 5 damage
	//+20 HP
	if (m_special1Cooldown.isOffCooldown())
	{
		int actualDMG = target.takeDamage(m_currPower + 5);
		std::cout << "used " << m_specialName << " to inflict " << actualDMG << " damage";
		
		int actualHealAmount = this->heal(20);
		std::cout << " and heal for " << actualHealAmount << " HP!!\n";

		m_special1Cooldown.applyCooldown();
		return 1;
	}
	return 0;
}

int Warrior::specialAttack1(Character& target)
{
	if (m_special1Cooldown.isOffCooldown())
	{
		int actualDMG = target.takeDamage(m_currPower + 10);
		std::cout << "used " << m_specialName << " to inflict " << actualDMG << " damage";

		if (this->increaseBaseArmour(1) == 0)
		{
			std::cout << " and increase armour by " << "1!!\n";
		}
		else
		{
			std::cout << "!!\n";
		}

		m_special1Cooldown.applyCooldown();
		return 1;
	}
	return 0;
}

std::string Character::getHealth()
{
	std::string hp = std::to_string(m_currHP) + " / " + std::to_string(m_baseHP);
	return hp;
}