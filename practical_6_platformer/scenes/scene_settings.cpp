#include "scene_settings.h"
#include "../game.h"
#include "SFML/Window/Keyboard.hpp"
#include "../prefabs.h"
#include "../components/cmp_text.h"
#include "../components/cmp_button.h"
//#include "../keys.h"

using namespace std;
using namespace sf;

shared_ptr<Entity> btn_Back;
shared_ptr<Entity> btn_chres;
shared_ptr<Entity> btn_kmap;

void SettingsScene::Load() {
	{
		auto txt = makeEntity();
		auto t = txt->addComponent<TextComponent>("Options");
		txt->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 100.0f });
	}

	btn_kmap = create_button("Remap controlls");
	btn_kmap->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 160.0f });

	btn_chres = create_button("Back");
	btn_chres->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 200.0f });

	btn_Back = create_button("Change resolution");
	btn_Back->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });


	Engine::GetWindow().setView(Engine::GetWindow().getDefaultView());

  setLoaded(true);
}

void SettingsScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

	if (btn_kmap->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&KeyMap);
	}
	if (btn_Back->get_components<ButtonComponent>()[0]->isSelected())
	{
		//Engine::ChangeScene(&menu);
		Engine::ChangeScene(&chres);
	}
	if (btn_chres->get_components<ButtonComponent>()[0]->isSelected())
	{
		//Engine::ChangeScene(&chres);
		Engine::ChangeScene(&menu);
	}

  Scene::Update(dt);
}
