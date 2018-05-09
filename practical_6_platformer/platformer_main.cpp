#include "engine.h"
#include "game.h"
#include "scenes/scene_menu.h"

using namespace std;

MenuScene menu;
SettingsScene settings;
KeyMapScene KeyMap;
Level1Scene level1;
Level2Scene level2;
Level3Scene level3;
chresScene chres;

int main() {
  Engine::Start(1280, 720, "GECW",&menu);
 // sf::Window window(sf::VideoMode(1280, 720), "GECW", &menu);
}