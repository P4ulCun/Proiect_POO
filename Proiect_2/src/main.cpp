#include <iostream>
#include <string>
#include <memory>
#include "errorHandling.h"
#include "items.h"
#include "inventory.h"
#include "fighterClasses.h"
#include "gameLogic.h"
#include "player.h"

#include "playerMaker.h" 

namespace windowDetails {
	constexpr float WINDOW_WIDTH = 1200;
	constexpr float WINDOW_HEIGHT = 675;
}

enum MenuOption { FULLSCREEN, VOLUME, BACK };
void drawSettingsMenu(sf::RenderWindow& window, sf::Font& font)
{
	sf::RectangleShape menu(sf::Vector2f(windowDetails::WINDOW_WIDTH / 3, windowDetails::WINDOW_HEIGHT - 100));
	menu.setFillColor(sf::Color(139, 69, 19)); // brown
	menu.setPosition(windowDetails::WINDOW_WIDTH / 3, 50.0f);

	window.draw(menu);

	std::string options[3] = {
		"Fullscreen: ",
		"Volume: ",
		"Back"
	};

	for (int i = 0; i < 3; ++i)
	{
		//make a square
		sf::RectangleShape button(sf::Vector2f(200, 60));
		button.setFillColor(sf::Color(100, 100, 250)); // Blue-ish
		button.setPosition(menu.getPosition().x + menu.getSize().x / 3.0f,
			menu.getPosition().y + menu.getSize().y / 3.0f + i * 100);

		sf::Text buttonText;
		buttonText.setFont(font);
		buttonText.setString(options[i]);
		buttonText.setCharacterSize(36);
		buttonText.setFillColor(sf::Color::Yellow);

		// Center text in button
		sf::FloatRect textRect = buttonText.getLocalBounds();
		buttonText.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		buttonText.setPosition(button.getPosition().x + button.getSize().x / 2.0f,
			button.getPosition().y + button.getSize().y / 2.0f);


		window.draw(button);
		window.draw(buttonText);
	}

	
}


int main()
{
	//TODO: have items that provide bonuses to a specific class ; use dynamic_cast to check 
	//what class is the player
	
	//initialize game environment and characters
	Game::getInstance().init();

	while (Game::getInstance().playersAreAlive())
	{
		Game::getInstance().processEvents();
		// both players turns have passed
		//next round, and apply cooldown ticks
		Game::getInstance().applyCooldownTicks();
	}

	Game::getInstance().showWinner();

	/*if (player1.m_character->isAlive())
	{
		std::cout << "CONGRATS " << player1.m_character->getName() << " , YOU'VE WON!!!\n";
	}
	else
	{
		std::cout << "CONGRATS " << player2.m_character->getName() << " , YOU'VE WON!!!\n";
	}*/

	//not a use case ; only for testing
	/*(*player1.m_inventory).m_items[0]->useItemAbility(*player2.m_character);
	(*player2.m_inventory).m_items[0]->useItemAbility(*player1.m_character);*/
	//i need to remove the items from the shop
	//2 players will have the same item, the same object

	//size for players 250 x 450 pixels

	//initializer iteme
	/*try
	{
		ItemShop::getInstance().init();
		ItemShop::getInstance().listItems();
	}
	catch (FileLoadError& err) { std::cout << err.what() << "\n"; }*/


	//sf::RenderWindow window(sf::VideoMode(windowDetails::WINDOW_WIDTH, windowDetails::WINDOW_HEIGHT), "game!"); // , sf::Style::Fullscreen

	////// background
	//sf::Texture backgroundTexture;
	//try 
	//{
	//	if (!backgroundTexture.loadFromFile("C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\background_bamboo_1200_cut.png"))
	//		throw TextureLoadError("Couldn't load texture\n");
	//}
	//catch (TextureLoadError& err) { std::cout << err.what(); }
	//
	//sf::Sprite backgroundSprite;
	//backgroundSprite.setTexture(backgroundTexture);

	//// font style
	//sf::Font font;
	//try
	//{
	//	if (!font.loadFromFile("C:\\Users\\Paul\\Desktop\\lab_poo\\Proiect_POO\\Proiect_2\\resources\\Feelin_Teachy_TTF.ttf"))
	//		throw FontLoadError("Couldn't load font\n");
	//}
	//catch (FontLoadError& err) { std::cout << err.what(); }


	//sf::Texture player1Texture;
	//try
	//{
	//	if (!player1Texture.loadFromFile("C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\astarion_250-450.png"))
	//		throw TextureLoadError("Couldn't load texture\n");
	//}
	//catch (TextureLoadError& err) { std::cout << err.what(); }

	//sf::Sprite player1Sprite;
	//player1Sprite.setTexture(player1Texture);
	//player1Sprite.setPosition(100, windowDetails::WINDOW_HEIGHT - 450);
	////game loop
	//
	////Game::getInstance().init();

	//while (window.isOpen())
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			window.close();
	//		else if (event.type == sf::Event::Resized)
	//		{
	//			// Adjust the viewport when the window is resized
	//			/*sf::FloatRect visibleArea(200, 200, event.size.width, event.size.height);
	//			window.setView(sf::View(visibleArea));*/
	//		}
	//	}

	//	window.clear();

	//	window.draw(backgroundSprite);
	//	window.draw(player1Sprite);
	//	//drawSettingsMenu(window, font);
	//	//Game::getInstance().draw(window);

	//	window.display();
	//}


	//create window
	//selection menu
	//create a character: name, class, items
	//draw this on screen

	//after selection
	//game loop
	//turn based
	//check if alive
	//update visuals: health bar, player's turn on the top of the screen

	//take and procces input: apply heal, attacks



		
	//EXEMPLE DE UTILIZARE BASIC

	/*std::unique_ptr<Rogue> player = std::make_unique<Rogue>();

	std::shared_ptr<ActiveSword> sabie = std::make_shared<ActiveSword>("Grieving sword", "sabie foarte dureroasa", 10, 50);
	std::shared_ptr<ActiveHeal> mecanism = std::make_shared<ActiveHeal>("Mekansm", "mecanism ce ofera o salva vindecatoare", 0, 200);
	sabie->useItemAbility(*player);
	sabie->applyPassive(*player);

	mecanism->useItemAbility(*player);
	mecanism->applyPassive(*player);*/

	/*try
	{
		throw TextureLoadError("nume_textura");
	}
	catch (TextureLoadError& err)
	{
		std::cout << "nu a fost incarcata textura: " << err.what();
	}*/
	

	return 0;
}


//#include <SFML/Graphics.hpp>
//#include <iostream>
//
//#pragma region imgui
//#include "imgui.h"
//#include "imgui-SFML.h"
//#include "imguiThemes.h"
//#pragma endregion
//
//
////if you want to load OpenGL
////#include <glad/glad.h>
////#include <errorReporting.h>
//
//int main()
//{
//	
//	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
//
//
//
//
//	//if you want to load OpenGL.
//	// Note: SFML also uses OpenGL so it will interfere with your code.
//	// If you want to draw both with SFML and your OpenGL code, you will have
//	// to fight with it a little.
//	// I found that calling glDisableVertexAttribArray(0); for attributes 0 - 8
//	// solved some issues sometimes
//	//  
//	//if (!gladLoadGLLoader((GLADloadproc)sf::Context::getFunction))
//	//{
//	//	std::cerr << "Failed to initialize GLAD" << std::endl;
//	//	return -1;
//	//}
//	//enableReportGlErrors();
//
//
//#pragma region imgui
//	ImGui::SFML::Init(window);
//	//you can use whatever imgui theme you like!
//	//ImGui::StyleColorsDark();				
//	//imguiThemes::yellow();
//	//imguiThemes::gray();
//	imguiThemes::green();
//	//imguiThemes::red();
//	//imguiThemes::gray();
//	//imguiThemes::embraceTheDarkness();
//
//	ImGuiIO &io = ImGui::GetIO(); (void)io;
//	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
//	//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
//	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
//	io.FontGlobalScale = 2.f;
//	ImGuiStyle &style = ImGui::GetStyle();
//	style.Colors[ImGuiCol_WindowBg].w = 0.5f;
//	//style.Colors[ImGuiCol_DockingEmptyBg].w = 0.f;
//#pragma endregion
//
//
//
//	sf::CircleShape shape(100.f);
//	//window.setVerticalSyncEnabled(true);
//	shape.setFillColor(sf::Color::Green);
//
//	sf::Clock clock;
//
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//		while (window.pollEvent(event))
//		{
//			
//		#pragma region imgui
//			ImGui::SFML::ProcessEvent(window, event);
//		#pragma endregion
//
//
//			if (event.type == sf::Event::Closed)
//				window.close();
//			else if (event.type == sf::Event::Resized)
//			{
//				// Adjust the viewport when the window is resized
//				sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
//				window.setView(sf::View(visibleArea));
//			}
//		}
//
//		//calculate the delta time
//		sf::Time deltaTime = clock.restart();
//		float deltaTimeSeconds = deltaTime.asSeconds();
//
//		//make sure delta time stays within normal bounds, like between one FPS and zero FPS
//		deltaTimeSeconds = std::min(deltaTimeSeconds, 1.f);
//		deltaTimeSeconds = std::max(deltaTimeSeconds, 0.f);
//
//	#pragma region imgui
//		ImGui::SFML::Update(window, deltaTime);
//
//		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
//		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
//		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
//		ImGui::PopStyleColor(2);
//	#pragma endregion
//
//
//		ImGui::Begin("Hello, world!");
//		ImGui::Button("Look at this pretty button!");
//		ImGui::Text("Hello!");
//		ImGui::End();
//
//		//game code....
//		window.clear();
//		window.draw(shape);
//
//
//	#pragma region imgui
//		ImGui::SFML::Render(window);
//	#pragma endregion
//
//		window.display();
//	}
//
//#pragma region imgui
//	ImGui::SFML::Shutdown();
//#pragma endregion
//
//	return 0;
//}