#include "cmp_enemy_ai.h"

using namespace std;
using namespace sf;

void EnemyAIComponent2::update(double dt) {
	auto mov = _direction * (float)(dt * _speed);
	mov.x += _direction.x * 16.f;
	if (!validMove(_parent->getPosition() + mov)) {
		_direction *= -1.f;
	}

	move(_direction * (float)(dt * _speed));
	ActorMovementComponent::update(dt);
}

EnemyAIComponent2::EnemyAIComponent2(Entity* p) : ActorMovementComponent(p) {
	_direction = Vector2f(1.0f, 0.0f);
	_speed = 50.0f;
}