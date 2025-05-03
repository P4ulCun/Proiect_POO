#pragma once
#include "singleton.h"
#include <SFML/Graphics.hpp>
#include "errorHandling.h"

class Resources : public Singleton<Resources>
{
private:
	std::string PATH = "C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\"; // ResourcesPath
	sf::Font m_font;
	sf::Texture m_backgroundTexture;
	sf::Texture m_signTexture;
	sf::Texture m_itemFrameTexture;
	sf::Texture m_rogueTexture;
	sf::Texture m_druidTexture;

public:
	Resources() = default;
	~Resources() = default;

	void initTextures();
	void initFont();
	sf::Texture& getBGTexture();
	sf::Texture& getSignTexture();
	sf::Texture& getItemFrameTexture();
	sf::Texture& getRogueTexture();
	sf::Texture& getDruidTexture();
	sf::Font& getFont();
};