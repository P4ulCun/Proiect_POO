#include "fighterClasses.h"

template<typename T>
void increaseStats(T& stat, T& boost)
{
	stat += boost;
}

void Character::increaseBaseHP(int value) { m_baseHP += value; }
void Character::increaseBasePower(int value) { m_basePower += value; }
int Character::increaseBaseArmour(int value) 
{ 
	if (m_baseArmour + value > 7)
	{
		m_baseArmour = 7;
		return 1; // increase unsuccessful
	}
	else
	{
		m_baseArmour += value;
		return 0; // increase successful
	}
}

void Character::takeDamage(int value) { m_currHP -= value; }
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
	target.takeDamage(m_currPower);
	std::cout << "took " << m_currPower << " damage!\n";
}

void Character::showStats()
{
	std::cout << "HP: " << m_baseHP << std::endl
			<< "Power: " << m_basePower << std::endl
			<< "Armour: " << m_baseArmour << std::endl;
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
		std::cout << "used Backstab to inflict " << m_currPower + 15 << " damage!!\n";
		target.takeDamage(m_currPower + 15);
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
		target.takeDamage(m_currPower + 5);
		std::cout << "used Sabre-Toothed Tiger bite to inflict " << m_currPower + 5 << " damage";
		
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
		target.takeDamage(m_currPower + 5);
		std::cout << "used Shield Bash to inflict " << m_currPower + 5 << " damage";

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