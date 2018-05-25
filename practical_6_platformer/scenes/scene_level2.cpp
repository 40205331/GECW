//include header files
#include "scene_level2.h"
#include "../components/cmp_enemy_ai.h"
#include "../components/cmp_enemy_turret.h"
#include "../components/cmp_hurt_player.h"
#include "../components/cmp_physics.h"
#include "../components/cmp_player_physics.h"
#include "../game.h"
#include <LevelSystem.h>
#include <iostream>
using namespace std;
using namespace sf;
//create player
static shared_ptr<Entity> player;
//load level elements
void Level2Scene::Load() {
	//load levels tilemap
  ls::loadLevelFile("res/level_2.txt", 40.0f);
  auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
  ls::setOffset(Vector2f(0, ho));

  // load player
  {
    // *********************************
	  player = makeEntity();
	  player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));
	  auto s = player->addComponent<ShapeComponent>();
	  s->setShape<sf::RectangleShape>(Vector2f(20.f, 30.f));
	  s->getShape().setFillColor(Color::Magenta);
	  s->getShape().setOrigin(10.f, 15.f);

	  
    // *********************************
    player->addTag("player");
    player->addComponent<PlayerPhysicsComponent>(Vector2f(20.f, 30.f));
  }

  // Create Enemy
  {
    auto enemy = makeEntity();
    enemy->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[0]) +
                       Vector2f(0, 24));
    // *********************************
    // Add HurtComponent
	enemy->addComponent<HurtComponent>();
    // Add ShapeComponent, Red 16.f Circle
	auto s = enemy->addComponent<ShapeComponent>();
	s->setShape<sf::CircleShape>(16.f);
	s->getShape().setFillColor(Color::Red);
	s->getShape().setOrigin(16.f, 16.f);



    // Add EnemyAIComponent
	enemy->addComponent<EnemyAIComponent>();
    // *********************************
  }

  // Create Enemy
  {
	  auto enemy1 = makeEntity();
	  enemy1->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[1]) +
		  Vector2f(0, 36));
	  // *********************************
	  // Add HurtComponent
	  enemy1->addComponent<HurtComponent>();
	  // Add ShapeComponent, Red 16.f Circle
	  auto s = enemy1->addComponent<ShapeComponent>();
	  s->setShape<sf::CircleShape>(16.f);
	  s->getShape().setFillColor(Color::Red);
	  s->getShape().setOrigin(16.f, 16.f);



	  // Add EnemyAIComponent
	  enemy1->addComponent<EnemyAIComponent>();
	  // *********************************
  }

  // Create Enemy
  {
	  auto enemy2 = makeEntity();
	  enemy2->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[2]) +
		  Vector2f(0, 48));
	  // *****************************
	  // Add HurtComponent
	  enemy2->addComponent<HurtComponent>();
	  // Add ShapeComponent, Red 16.f Circle
	  auto s = enemy2->addComponent<ShapeComponent>();
	  s->setShape<sf::CircleShape>(16.f);
	  s->getShape().setFillColor(Color::Red);
	  s->getShape().setOrigin(16.f, 16.f);



	  // Add EnemyAIComponent
	  enemy2->addComponent<EnemyAIComponent>();
	  // **************************
  }

  // Create Enemy
  {
	  auto enemy3 = makeEntity();
	  enemy3->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[3]) +
		  Vector2f(0, 60));
	  // *************************
	  // Add HurtComponent
	  enemy3->addComponent<HurtComponent>();
	  // Add ShapeComponent, Red 16.f Circle
	  auto s = enemy3->addComponent<ShapeComponent>();
	  s->setShape<sf::CircleShape>(16.f);
	  s->getShape().setFillColor(Color::Red);
	  s->getShape().setOrigin(16.f, 16.f);



	  // Add EnemyAIComponent
	  enemy3->addComponent<EnemyAIComponent>();
	  // *********************************
  }

  // Create Enemy
  {
	  auto enemy4 = makeEntity();
	  enemy4->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[4]) +
		  Vector2f(0, 72));
	  // *********************************
	  // Add HurtComponent
	  enemy4->addComponent<HurtComponent>();
	  // Add ShapeComponent, Red 16.f Circle
	  auto s = enemy4->addComponent<ShapeComponent>();
	  s->setShape<sf::CircleShape>(16.f);
	  s->getShape().setFillColor(Color::Red);
	  s->getShape().setOrigin(16.f, 16.f);



	  // Add EnemyAIComponent
	  enemy4->addComponent<EnemyAIComponent>();
	  // **********************************
  }

  // Create Enemy
  {
	  auto enemy5 = makeEntity();
	  enemy5->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[5]) +
		  Vector2f(0, 84));
	  // *********************************
	  // Add HurtComponent
	  enemy5->addComponent<HurtComponent>();
	  // Add ShapeComponent, Red 16.f Circle
	  auto s = enemy5->addComponent<ShapeComponent>();
	  s->setShape<sf::CircleShape>(16.f);
	  s->getShape().setFillColor(Color::Red);
	  s->getShape().setOrigin(16.f, 16.f);



	  // Add EnemyAIComponent
	  enemy5->addComponent<EnemyAIComponent>();
	  // *********************************
  }

  // Create Enemy
  {
	  auto enemy6 = makeEntity();
	  enemy6->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[6]) +
		  Vector2f(0, 96));
	  // *********************************
	  // Add HurtComponent
	  enemy6->addComponent<HurtComponent>();
	  // Add ShapeComponent, Red 16.f Circle
	  auto s = enemy6->addComponent<ShapeComponent>();
	  s->setShape<sf::CircleShape>(16.f);
	  s->getShape().setFillColor(Color::Red);
	  s->getShape().setOrigin(16.f, 16.f);



	  // Add EnemyAIComponent
	  enemy6->addComponent<EnemyAIComponent>();
	  // *********************************
  }

  // Create Enemy
  {
	  auto enemy7 = makeEntity();
	  enemy7->setPosition(ls::getTilePosition(ls::findTiles(ls::ENEMY)[7]) +
		  Vector2f(0, 108));
	  // *********************************
	  // Add HurtComponent
	  enemy7->addComponent<HurtComponent>();
	  // Add ShapeComponent, Red 16.f Circle
	  auto s = enemy7->addComponent<ShapeComponent>();
	  s->setShape<sf::CircleShape>(16.f);
	  s->getShape().setFillColor(Color::Red);
	  s->getShape().setOrigin(16.f, 16.f);



	  // Add EnemyAIComponent
	  enemy7->addComponent<EnemyAIComponent>();
	  // *********************************
  }
  // Create Turret
  {
    auto turret = makeEntity();
    turret->setPosition(ls::getTilePosition(ls::findTiles('t')[0]) +
                        Vector2f(20, 0));
    auto s = turret->addComponent<ShapeComponent>();
    s->setShape<sf::CircleShape>(16.f, 3);
    s->getShape().setFillColor(Color::Red);
    s->getShape().setOrigin(16.f, 16.f);
    turret->addComponent<EnemyTurretComponent>();
  }


  // Add physics colliders to level tiles.
  {
    // *********************************
	  auto walls = ls::findTiles(ls::WALL);
	  for (auto w : walls) {
		  auto pos = ls::getTilePosition(w);
		  pos += Vector2f(20.f, 20.f); //offset to center
		  auto e = makeEntity();
		  e->setPosition(pos);
		  e->addComponent<PhysicsComponent>(false, Vector2f(40.f, 40.f));
	  }

    // *********************************
  }

  cout << " Scene 2 Load Done" << endl;
  setLoaded(true);
}
//unload level when complete
void Level2Scene::UnLoad() {
  cout << "Scene 2 UnLoad" << endl;
  player.reset();
  ls::unload();
  Scene::UnLoad();
}
//upade level throughout
void Level2Scene::Update(const double& dt) {
  Scene::Update(dt);
  const auto pp = player->getPosition();
  if (ls::getTileAt(pp) == ls::END) {
    Engine::ChangeScene((Scene*)&level3);
  } else if (!player->isAlive()) {
    Engine::ChangeScene((Scene*)&level2);
  }
}
//render level
void Level2Scene::Render() {
  ls::render(Engine::GetWindow());
  Scene::Render();
}
