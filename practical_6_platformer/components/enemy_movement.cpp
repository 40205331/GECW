#include "enemy_movement.h"
#include "engine.h"
#include <iostream>

using namespace std;
using namespace sf;

void EnemyMovement::update(double dt)
{
	auto mov = _direction * (float)(dt * _speed);
	mov.y += _direction.y * 16.f;
	if (!validMove(_parent->getPosition() + mov)) {
		_direction *= 1.f;
	}

	move(_direction * (float)(dt * _speed));
	ActorMovementComponent::update(dt);
}

void EnemyMovement::render()
{

}

void EnemyMovement::MoveValidate(std::shared_ptr<Entity> play)
{

}

EnemyMovement::EnemyMovement(Entity* p, float speed) : ActorMovementComponent(p), _speed(speed) {}

void EnemyMovement::move(const sf::Vector2f& p)
{
	auto pp = _parent->getPosition() + p;
	_parent->setPosition(pp);
}

void EnemyMovement::move(float x, float y)
{
	move(sf::Vector2f(x, y));
}