#pragma once

#include "ecm.h"

class EnemyMovement : public Component
{
protected:
	float _speed;

public:
	EnemyMovement() = delete;

	void update(double dt)override;
	void render()override;
	void move(float x, float y);
	void move(const sf::Vector2f&);
	explicit EnemyMovement(Entity* p, float speed = 2.f);
	void MoveValidate(std::shared_ptr<Entity> play);

};