//include header files
#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "../prefabs.h"
#include "../components/cmp_button.h"

using namespace std;
using namespace sf;
//creates buttons
shared_ptr<Entity> btn_Start;
shared_ptr<Entity> btn_Options;
shared_ptr<Entity> btn_Quit;
//load main menu
void MenuScene::Load() {
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>(
        "Games Engineering Project");
	txt->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 100.0f });
  }
  //load start button
  btn_Start = create_button("Start");
  btn_Start->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 200.0f });
  //load option button
  btn_Options = create_button("Options");
  btn_Options->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 240.0f });
  //load quit button
  btn_Quit = create_button("Quit");
  btn_Quit->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });

  Engine::GetWindow().setView(Engine::GetWindow().getDefaultView());


  //load elements
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {

	//this changes the scene to level1
	if (btn_Start->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&level1);
	}
	//this changes the scene to the settings menu
	if (btn_Options->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&settings);	
	}
	//this closes the window
	if (btn_Quit->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::GetWindow().close();
	}

  Scene::Update(dt);
}
