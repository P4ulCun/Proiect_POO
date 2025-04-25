#pragma once
#include "fighterClasses.h"

class CharacterFactory
{
public:
	static std::shared_ptr<Character> createCharacter(std::string& className, std::string& name)
	{
		if (className == "Rogue")
			return std::make_shared<Rogue>(name);
		else if (className == "Druid")
			return std::make_shared<Druid>(name);
		else if (className == "Warrior")
			return std::make_shared<Warrior>(name);
		else
		{
			std::cout << "eroare character factory!\n";
			return nullptr;
		}
	}
};