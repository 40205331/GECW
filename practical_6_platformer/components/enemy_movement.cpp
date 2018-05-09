#include "enemy_movement.h"
#include "engine.h"
#include <iostream>


void EnemyMovement::update(double dt)
{

}

void EnemyMovement::render()
{

}

void EnemyMovement::MoveValidate(std::shared_ptr<Entity> play)
{

}

EnemyMovement::EnemyMovement(Entity* p, float speed) : Component(p), _speed(speed) {}

void EnemyMovement::move(const sf::Vector2f& p)
{
	auto pp = _parent->getPosition() + p;
	_parent->setPosition(pp);
}

void EnemyMovement::move(float x, float y)
{
	move(sf::Vector2f(x, y));
}