#include "scene_keymap.h"
#include "../game.h"
#include "SFML/Window/Keyboard.hpp"
#include "../prefabs.h"
#include "../keys.h"
#include "../components/cmp_text.h"
#include "../components/cmp_button.h"

using namespace std;
using namespace sf;

//shared_ptr<Entity> btn_left;
shared_ptr<Entity> btn_ControlsRight;
shared_ptr<Entity> btn_back;
//shared_ptr<Entity> btn_jump;
vector<shared_ptr<Entity>> btns;
// Map button to control
map<shared_ptr<Entity>, string> controlsBtns;
// The control being changed
shared_ptr<Entity> changingControl = nullptr;

void KeyMapScene::Load() {
	//btn_left = create_button("Left");
	//btn_left->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 200.0f });
	{
		auto txt = makeEntity();
		auto t = txt->addComponent<TextComponent>("Keymap ");
		txt->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 100.0f });
	}
	btns.clear();
	btn_back = create_button("Back");
	btn_back->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });

	btn_ControlsRight = create_button("Right");
	btns.push_back(btn_ControlsRight);
	controlsBtns[btn_ControlsRight] = "Right";

	for (int i = 0; i < btns.size(); i++)
	{
		btns[i]->setPosition({ (float)Engine::GetWindow().getSize().x / 2, (40.0f * i) + 200.0f });
	}
	//btn_jump = create_button("Jump");
	//btn_jump->setPosition({ (float)Engine::GetWindow().getSize().x / 2, 280.0f });

	Engine::GetWindow().setView(Engine::GetWindow().getDefaultView());

  setLoaded(true);
}

void KeyMapScene::Update(const double& dt) 
	{
	if (btn_back->get_components<ButtonComponent>()[0]->isSelected())
	{
		Engine::ChangeScene(&menu);
	}
		// Select key to be changed
		if (changingControl == nullptr)
		{
			for (auto b : controlsBtns)
			{
				if (b.first->get_components<ButtonComponent>()[0]->isSelected())
				{
					changingControl = b.first;
					// Change text colour
					b.first->get_components<TextComponent>()[0]->getText()->setColor(Color::Red);
				}
			}
		}

		// Change key
		if (changingControl != nullptr)
		{
			// Since without events we cannot get the key pressed,
			// we loop though all the keys and if one is pressed, we set it to the
			// control that is being changed
			for (auto k = Keyboard::Unknown; k != Keyboard::Pause; k = static_cast<Keyboard::Key>(k + 1))
			{
				if (Keyboard::isKeyPressed(k))
				{
					keys::SetKeyboardKey(controlsBtns[changingControl], k);
					// Change back text colour
					changingControl->get_components<TextComponent>()[0]->getText()->setColor(Color::White);
					changingControl = nullptr;
				}
			}
		}

		Scene::Update(dt);
	}
