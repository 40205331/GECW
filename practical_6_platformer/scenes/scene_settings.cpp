#include "scene_settings.h"
#include "../game.h"
#include "SFML/Window/Keyboard.hpp"
#include "../prefabs.h"
#include "../components/cmp_text.h"
#include "../components/cmp_button.h"

using namespace std;
using namespace sf;

shared_ptr<Entity> btn_Back;
shared_ptr<Entity> btn_res;

void SettingsScene::Load() {
	{
		auto txt = makeEntity();
		auto t = txt->addComponent<TextComponent>("Options");
		txt->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 100.0f });
	}

	btn_res = create_button("Res");
	btn_res->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 240.0f });

	btn_Back = create_button("Back");
	btn_Back->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });


	Engine::GetWindow().setView(Engine::GetWindow().getDefaultView());

  setLoaded(true);
}

void SettingsScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

	if (btn_res->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&menu);
	}
	if (btn_Back->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&menu);
	}

  Scene::Update(dt);
}
