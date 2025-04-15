#include <iostream>
#include <string>
#include <memory>
#include "errorHandling.h"
#include "items.h"
#include "inventory.h"
#include "fighterClasses.h"

int main()
{
	try
	{
		ItemShop::getInstance().init();
		ItemShop::getInstance().listItems();
	}
	catch (FileLoadError& err) { std::cout << err.what() << "\n"; }
	//ItemShop itemShop = 5;

	//initialize item data
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