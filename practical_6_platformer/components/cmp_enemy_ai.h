#pragma once

#include "cmp_actor_movement.h"

class EnemyAIComponent : public ActorMovementComponent {
protected:
  sf::Vector2f _direction;

public:
  void update(double dt) override;

  explicit EnemyAIComponent(Entity* p);

  EnemyAIComponent() = delete;
};

class EnemyAIComponent2 : public ActorMovementComponent {
protected:
	sf::Vector2f _direction;

public:
	void update(double dt) override;

	explicit EnemyAIComponent2(Entity* p);

	EnemyAIComponent2() = delete;
};
