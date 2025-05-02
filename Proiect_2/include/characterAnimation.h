#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class CharacterAnimation
{
public:
	sf::IntRect m_uvRect;
	int m_choosePlayer;
private:
	sf::Vector2u m_imageCount;
	sf::Vector2u m_currentImage;

	float m_totalTime;
	float m_switchTime;

public:
	//CharacterAnimation();
	CharacterAnimation(int choosePlayer, sf::Texture texture, sf::Vector2u imageCount, float switchTime);
	~CharacterAnimation();

	void update(int row, float deltaTime);
};