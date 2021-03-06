#include "scene_level3.h"
#include "../components/cmp_physics.h"
#include "../components/cmp_player_physics.h"
#include "../game.h"
#include "../components/bullet_movement.h"
#include "../components/cmp_bullet.h"
#include "../components/cmp_hurt_player.h"
#include <LevelSystem.h>
#include "../components/enemy_movement.h"
#include "../components/cmp_actor_movement.h"
#include "../components/cmp_enemy_turret.h"
#include <iostream>
using namespace std;
using namespace sf;

static shared_ptr<Entity> player;
vector<shared_ptr<Entity>> enemies;
float fireTime = 0.0f;
void Level3Scene::Load() {
	ls::loadLevelFile("res/level_3.txt", 40.0f);
	auto ho = Engine::getWindowSize().y - (ls::getHeight() * 40.f);
	ls::setOffset(Vector2f(0, ho));

	// Create player
	{
		// *********************************
		player = makeEntity();
		player->setPosition(ls::getTilePosition(ls::findTiles(ls::START)[0]));

		// pl->setPosition({100, 100});

		auto s = player->addComponent<ShapeComponent>();
		s->setShape<sf::RectangleShape>(Vector2f(20.f, 30.f));
		s->getShape().setFillColor(Color::Magenta);
		s->getShape().setOrigin(10.f, 15.f);
		player->addTag("player");
		player->addComponent<PlayerPhysicsComponent>(Vector2f(20.f, 30.f));




		// *********************************
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
	}

	setLoaded(true);
}

void Level3Scene::UnLoad() {
	player.reset();
	ls::unload();
	Scene::UnLoad();
}



void Level3Scene::Update(const double& dt) {

	const auto pp = player->getPosition();
	if (ls::getTileAt(pp) == ls::END) {
		Engine::ChangeScene(&menu);
	}
	else if (!player->isAlive()) {
		Engine::ChangeScene((Scene*)&level3);
	}

	sf::Event event;
	while (Engine::GetWindow().pollEvent(event)) {
		if (event.type == Event::Closed) {
			Engine::GetWindow().close();
		}
	}

	//bool fired = false;
	if (Keyboard::isKeyPressed(Keyboard::Space) && fireTime <= 0.0f)
	{
		//fired = true;
		fireTime = 0.5f;
		auto bullet = makeEntity();
		bullet->setPosition(player->getPosition());
		bullet->addComponent<BulletComponent>();
		bullet->addComponent<BulletMovement>();
		bullet->addTag("bullet");
		auto b = bullet->addComponent<ShapeComponent>();
		b->setShape<sf::CircleShape>(8.0f);
		b->getShape().setFillColor(Color::Yellow);
		b->getShape().setOrigin(8.0f, 8.0f);
		
	}
	//if (fired = true)
	//{
	

//}
	
	static float rocktime = 0.0f;
	rocktime -= dt;

	if (rocktime <= 0.f) {
		rocktime = 2.f;
		auto enemy = makeEntity();
		enemy->setPosition(ls::getTilePosition(ls::findTiles('n')[0]) +
			Vector2f(0, 40));
		enemy->addComponent<BulletComponent>(30.f);
		enemy->addComponent<HurtComponent>();
		
		auto s = enemy->addComponent<ShapeComponent>();
		s->setShape<sf::CircleShape>(16.f);
		s->getShape().setFillColor(Color::Red);
		s->getShape().setOrigin(16.f, 16.f);

		enemy->addComponent<EnemyTurretComponent2>();
		enemy->addComponent<EnemyMovement>();
		enemy->addTag("enemy");


		//auto p = enemy->addComponent<PhysicsComponent>(true, Vector2f(75.f, 75.f));
		//p->setRestitution(.4f);
		//p->setFriction(.0001f);
		//p->impulse(Vector2f(-3.f, 0));
		//p->setMass(1000000000.f);
	}
	auto bullet_list = ents.find("bullet");
	auto enemy_list = ents.find("enemy");
	int enemyID = 0;
	for (auto &e : enemy_list)
	{
		auto sc = e->get_components<ShapeComponent>();
		auto mov = e->get_components<EnemyMovement>();

		float horizontal = 0.0f;
		float vertical = 0.0f;
		float dist_hor = player->getPosition().x - e->getPosition().x;
		float dist_vert = player->getPosition().y - e->getPosition().y;
		if (dist_hor < 0)
			horizontal--;
		else if (dist_hor > 0)
			horizontal++;
		if (dist_vert < 0)
			vertical--;
		else if (dist_vert > 0)
			vertical++;
		mov[0]->move(horizontal *0.05, vertical *0.05);


		
		for (auto &b : bullet_list)
		{
			auto bul = b->get_components<ShapeComponent>();
			if (bul[0]->getShape().getGlobalBounds().intersects(sc[0]->getShape().getGlobalBounds()))
			{
			e->setForDelete();
			b->setForDelete();
			}
		}
	}
	fireTime -= dt;
	Scene::Update(dt);

	if (sf::Keyboard::isKeyPressed(Keyboard::Escape)) {
		Engine::ChangeScene(&menu);
	}
}

	void Level3Scene::Render() {
		ls::render(Engine::GetWindow());
		Scene::Render();
	}
