#include "resourceHandler.h"

void Resources::initTextures()
{
	if (!m_backgroundTexture.loadFromFile(PATH + "background_bamboo_1200_cut.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_signTexture.loadFromFile(PATH + "wood_sign_360-200.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_announcementTexture.loadFromFile(PATH + "announcement_sign.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_itemFrameTexture.loadFromFile(PATH + "item_frame_3.png"))
		throw TextureLoadError("Couldn't load texture\n");


	if (!m_rogueTexture.loadFromFile(PATH + "astarion_idle_fixed.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_druidTexture.loadFromFile(PATH + "druid_idle.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_warriorTexture.loadFromFile(PATH + "warrior_idle_fixed.png"))
		throw TextureLoadError("Couldn't load texture\n");


	if (!m_itemsTexture.loadFromFile(PATH + "item_sprite.png"))
		throw TextureLoadError("Couldn't load texture\n");

	if (!m_basicAttackTexture.loadFromFile(PATH + "attack_buttons.png"))
		throw TextureLoadError("Couldn't load texture\n");
}

void Resources::initFont()
{
	if (!m_font.loadFromFile(PATH + "Feelin_Teachy_TTF.ttf"))
		throw FontLoadError("Couldn't load font\n");
}

sf::Texture& Resources::getBGTexture() { return m_backgroundTexture; }
sf::Texture& Resources::getSignTexture() { return m_signTexture; }
sf::Texture& Resources::getAnnouncementTexture() { return m_announcementTexture; }
sf::Texture& Resources::getItemFrameTexture() { return m_itemFrameTexture; }
sf::Texture& Resources::getRogueTexture() { return m_rogueTexture; }
sf::Texture& Resources::getDruidTexture() { return m_druidTexture; }
sf::Texture& Resources::getWarriorTexture() { return m_warriorTexture; }
sf::Texture& Resources::getItemsTexture() { return m_itemsTexture; }
sf::Texture& Resources::getBasicAttackTexture() { return m_basicAttackTexture; }
sf::Font& Resources::getFont() { return m_font; }