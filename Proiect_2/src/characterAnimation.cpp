#include "characterAnimation.h"

CharacterAnimation::CharacterAnimation(int choosePlayer, sf::Texture texture, sf::Vector2u imageCount, float switchTime)
{
	m_choosePlayer = choosePlayer;
	m_imageCount = imageCount;
	m_switchTime = switchTime;
	m_totalTime = 0.0f;
	m_currentImage.x = 0;

	m_uvRect.width = texture.getSize().x / float(imageCount.x);
	m_uvRect.height = texture.getSize().y / float(imageCount.y);
}

CharacterAnimation::~CharacterAnimation()
{

}

void CharacterAnimation::update(int row, float deltaTime)
{
	m_currentImage.y = row;
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;

		if (m_currentImage.x >= m_imageCount.x)
			m_currentImage.x = 0;
	}

	m_uvRect.top = m_currentImage.y * m_uvRect.height;

	if (m_choosePlayer == 1) // face right
	{
		m_uvRect.left = m_currentImage.x * m_uvRect.width;
	}
	else // face left
	{
		m_uvRect.left = (m_currentImage.x + 1) * abs(m_uvRect.width);
		m_uvRect.width = -abs(m_uvRect.width);
	}
}