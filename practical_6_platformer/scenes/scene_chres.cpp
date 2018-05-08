#include "scene_chres.h"
#include "../game.h"
#include "SFML/Window/Keyboard.hpp"
#include "../prefabs.h"
#include "../components/cmp_text.h"
#include "../components/cmp_button.h"

using namespace std;
using namespace sf;

shared_ptr<Entity> btn_win;
shared_ptr<Entity> btn_full;

void chresScene::Load() {
	{
		auto txt = makeEntity();
		auto t = txt->addComponent<TextComponent>("Resolution menu");
		txt->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 100.0f });
	}

	btn_full = create_button("Full screen");
	btn_full->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 240.0f });

	btn_win = create_button("Windowed");
	btn_win->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });


	Engine::GetWindow().setView(Engine::GetWindow().getDefaultView());

  setLoaded(true);
}

void chresScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

	if (btn_win->get_components<ButtonComponent>()[0]->isSelected())
	{
		
	}
	if (btn_full->get_components<ButtonComponent>()[0]->isSelected())
	{
		
	}

  Scene::Update(dt);
}
