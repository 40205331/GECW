//include header files
#include "scene_level1.h"
#include "../components/cmp_player_physics.h"
#include "../components/cmp_sprite.h"
#include "../game.h"
#include <LevelSystem.h>
#include <system_resources.h>
#include <iostream>
#include <thread>

//include namespace's
using namespace std;
using namespace sf;

//create player
static shared_ptr<Entity> player;

//load level elements
void Level1Scene::Load() {
  //loading the levels tilemap
	ls::loadLevelFile("res/level_1.txt", 40.0f);

  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));
  //loading background music
  backGround_Music = Resources::get<Music>("background.wav");
  backGround_Music->play();
  backGround_Music->setLoop(true);
  // load player
  {
    player = makeEntity();
    player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
    auto s = player->addComponent<ShapeComponent>();
    s->setShape<sf::RectangleShape>(Vector2f(20.f, 30.f));
    s->getShape().setFillColor(Color::Magenta);
    s->getShape().setOrigin(10.f, 15.f);

    player->addComponent<PlayerPhysicsComponent>(Vector2f(20.f, 30.f));
  }

  // Add physics colliders to level tiles.
  {
    auto walls = ls::findTiles(ls::WALL);
    for (auto w : walls) {
      auto pos = ls::getTilePosition(w);
      pos += Vector2f(20.f, 20.f); //offset to center
      auto e = makeEntity();
      e->setPosition(pos);
      e->addComponent<PhysicsComponent>(false, Vector2f(40.f, 40.f));
    }
  }


  setLoaded(true);
}

//unload at the end of the level
void Level1Scene::UnLoad() {
  player.reset();
  ls::unload();
  Scene::UnLoad();
  backGround_Music->stop();
  backGround_Music.reset();
}

void Level1Scene::Update(const double& dt) {

  //once the player reaches the end goal, move to the next level
  if (ls::getTileAt(player->getPosition()) == ls::END) {
    Engine::ChangeScene((Scene*)&level2);
  }
  //if escape is hit, move to the main menu
  if (sf::Keyboard::isKeyPressed(Keyboard::Escape)) {
	  Engine::ChangeScene(&menu);
	  
  }
  //update the level
  Scene::Update(dt);
}
//render the level
void Level1Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
