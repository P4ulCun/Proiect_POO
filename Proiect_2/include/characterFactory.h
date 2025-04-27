#pragma once
#include "fighterClasses.h"

class CharacterFactory
{
public:
	static std::shared_ptr<Character> createCharacter(std::string& className, std::string& name)
	{
		if (className[0] == 'R' || className[0] == 'r')
			return std::make_shared<Rogue>(name);
		else if (className[0] == 'D' || className[0] == 'd')
			return std::make_shared<Druid>(name);
		else if (className[0] == 'W' || className[0] == 'w')
			return std::make_shared<Warrior>(name);
		else
		{
			std::cout << "eroare character factory!\n";
			return nullptr;
		}
	}
};