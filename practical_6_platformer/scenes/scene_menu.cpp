#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include "../prefabs.h"
#include "../components/cmp_button.h"

using namespace std;
using namespace sf;

shared_ptr<Entity> btn_Start;
shared_ptr<Entity> btn_Options;
shared_ptr<Entity> btn_Quit;

void MenuScene::Load() {
  {
    auto txt = makeEntity();
    auto t = txt->addComponent<TextComponent>(
        "Games Engineering Project");
	txt->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 100.0f });
  }
  btn_Start = create_button("Start");
  btn_Start->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 200.0f });
  
  btn_Options = create_button("Options");
  btn_Options->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 240.0f });

  btn_Quit = create_button("Quit");
  btn_Quit->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });

  Engine::GetWindow().setView(Engine::GetWindow().getDefaultView());


  
  setLoaded(true);
}

void MenuScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

	if (btn_Start->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&level1);
	}
	if (btn_Options->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&settings);	
	}
	if (btn_Quit->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::GetWindow().close();
		//Engine::Start(850, 720, "GECW", &menu);
	}

  Scene::Update(dt);
}
