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
shared_ptr<Entity> btn_back1;

void chresScene::Load() {
	{
		auto txt = makeEntity();
		auto t = txt->addComponent<TextComponent>("Resolution menu");
		txt->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 100.0f });
	}

	btn_full = create_button("Full screen");
	btn_full->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 160.0f });

	btn_win = create_button("Windowed");
	btn_win->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 200.0f });

	btn_back1 = create_button("Back");
	btn_back1->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });

    Engine::GetWindow().setView(Engine::GetWindow().getDefaultView());

  setLoaded(true);
}

void chresScene::Update(const double& dt) {
  // cout << "Menu Update "<<dt<<"\n";

	if (btn_win->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::GetWindow().close();
		Engine::Start(1280, 720, "GECW", &chres);
	}
	if (btn_full->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::GetWindow().close();
		Engine::GetWindow().create(sf::VideoMode(Engine::getWindowSize().x, Engine::getWindowSize().y), "GECW", sf::Style::Fullscreen);
		Engine::ChangeScene(&menu);
	}
	if (btn_back1->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&menu);
	}
  Scene::Update(dt);
}
