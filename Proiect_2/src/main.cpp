#include <iostream>
#include <string>
#include <memory>
#include "errorHandling.h"
#include "items.h"
#include "inventory.h"
#include "fighterClasses.h"
//#include "gameLogic_CLI.h"
#include "player.h"

#include "playerMaker.h" 
#include "characterAnimation.h"
#include "gameLogic.h"
#include "resourceHandler.h"
//std::string PATH = "C:\\Users\\Paul\\Desktop\\Lab_POO\\Proiect_POO\\Proiect_2\\resources\\";

//namespace windowDetails {
//	constexpr float WINDOW_WIDTH = 1200;
//	constexpr float WINDOW_HEIGHT = 675;
//}

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

void drawItemFrames(sf::RenderWindow& window, sf::Texture& texture, float signHeight)
{
	for (int i = 0; i < 3; i++)
	{
		sf::RectangleShape itemFrame(sf::Vector2f(80, 80));
		itemFrame.setTexture(&texture);
		itemFrame.setPosition(60 + i * 120, signHeight - itemFrame.getSize().y * 4 / 3);

		window.draw(itemFrame);
	}

	for (int i = 0; i < 3; i++)
	{
		sf::RectangleShape itemFrame(sf::Vector2f(80, 80));
		itemFrame.setTexture(&texture);
		itemFrame.setPosition(windowDetails::WINDOW_WIDTH - 60 - itemFrame.getSize().x - i * 120, 
							signHeight - itemFrame.getSize().y * 4 / 3);

		window.draw(itemFrame);
	}
}

int main()
{
	
	//TODO: have items that provide bonuses to a specific class ; use dynamic_cast to check 
	//what class is the player
	
	/*----------------------------------------- CLI GAME LOOP START -----------------------------------------*/

	//Game_CLI::getInstance().init();

	//while (Game_CLI::getInstance().playersAreAlive())
	//{
	//	//2 while cicles(turns) = 1 round
	//	//first is player 1
	//	Game_CLI::getInstance().processEvents();
	//	Game_CLI::getInstance().applyCooldownTicks();


	//	Game_CLI::getInstance().changeTurn();
	//}
	//Game_CLI::getInstance().showWinner();

	/*----------------------------------------- CLI GAME LOOP END -----------------------------------------*/

	//initializer iteme
	/*try
	{
		ItemShop::getInstance().init();
		ItemShop::getInstance().listItems();
	}
	catch (FileLoadError& err) { std::cout << err.what() << "\n"; }*/


	sf::RenderWindow window(sf::VideoMode(windowDetails::WINDOW_WIDTH, windowDetails::WINDOW_HEIGHT), "game!"); // , sf::Style::Fullscreen

	//RESOURCE LOADING START
	try
	{
		Resources::getInstance().initTextures();
	}
	catch (TextureLoadError& err) { std::cout << err.what() << std::endl; }

	try
	{
		Resources::getInstance().initFont();
	}
	catch (FontLoadError& err) { std::cout << err.what() << std::endl; }
	//RESOURCES LOADING STOP

	//ITEM SHOP START
	try
	{
		//load items from json and pu them in the shop
		ItemShop::getInstance().init();
	}
	catch (FileLoadError& err) { std::cout << err.what() << std::endl; }
	//ITEM SHOP END
	// 
	//// background

	// font style
	

	//SIGN START
	

	

	//SIGN END

	//ITEM FRAME START

	

	
	
	//ITEM FRAME END

	//PLAYER START
	/*sf::Texture player1Texture;

	sf::Sprite player1Sprite;
	player1Sprite.setTexture(player1Texture);
	player1Sprite.setPosition(100, windowDetails::WINDOW_HEIGHT - 450);

	CharacterAnimation animationPlayer1(1, player1Texture, sf::Vector2u(2, 1), 0.5f);

	sf::Sprite player1;
	player1.setTexture(player1Texture);

	if (animationPlayer1.m_choosePlayer == 1)
		player1.setPosition(100, windowDetails::WINDOW_HEIGHT - 450);
	else
		player1.setPosition(windowDetails::WINDOW_WIDTH - player1Texture.getSize().x / 2 - 100, windowDetails::WINDOW_HEIGHT - 450);

	float deltaTime = 0.0f;
	sf::Clock clock;*/

	//PLAYER END

	//game loop
	
	Game::getInstance().init();

	while (window.isOpen())
	{
		//deltaTime = clock.restart().asSeconds();
		Game::getInstance().updateDeltaTime();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::Resized)
			{
				// Adjust the viewport when the window is resized
				/*sf::FloatRect visibleArea(200, 200, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));*/
			}
		}
		//Game::getInstance().update();
		Game::getInstance().update();
		Game::getInstance().drawFrame(window);
		

		//window.clear();

		//window.draw(backgroundSprite);

		//animationPlayer1.update(0, deltaTime); // first animation aka row 0
		//player1.setTextureRect(animationPlayer1.m_uvRect);
		//window.draw(player1);
		//window.draw(sign);
		//window.draw(signText);
		////window.draw(itemFrame);
		//drawItemFrames(window, itemFrameTexture, sign.getSize().y);


		//window.draw(player1Sprite);
		//drawSettingsMenu(window, font);
		//Game::getInstance().draw(window);

		//window.display();
	}


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