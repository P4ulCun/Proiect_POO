#include "resourceHandler.h"

void Resources::initTextures()
{
	if (!m_backgroundTexture.loadFromFile(PATH + "background_bamboo_1200_cut.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_signTexture.loadFromFile(PATH + "wood_sign_360-200.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_itemFrameTexture.loadFromFile(PATH + "item_frame_3.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_player1Texture.loadFromFile(PATH + "astarion_idle_sprite.png"))
		throw TextureLoadError("Couldn't load texture\n");
}

void Resources::initFont()
{
	if (!m_font.loadFromFile(PATH + "Feelin_Teachy_TTF.ttf"))
		throw FontLoadError("Couldn't load font\n");
}

sf::Texture& Resources::getBGTexture() { return m_backgroundTexture; }
sf::Texture& Resources::getSignTexture() { return m_signTexture; }
sf::Texture& Resources::getItemFrameTexture() { return m_itemFrameTexture; }
sf::Texture& Resources::getPlayer1Texture() { return m_player1Texture; }
sf::Font& Resources::getFont() { return m_font; }