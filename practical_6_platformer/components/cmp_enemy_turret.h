#pragma once
#include "cmp_physics.h"
#include <ecm.h>

class EnemyTurretComponent : public Component {
protected:
  void fire() const;
  float _firetime;

public:
  void update(double dt) override;
  void render() override {}
  explicit EnemyTurretComponent(Entity* p);
  EnemyTurretComponent() = delete;
};

class EnemyTurretComponent2 : public Component {
protected:
	void fire() const;
	float _firetime;

public:
	void update(double dt) override;
	void render() override {}
	explicit EnemyTurretComponent2(Entity* p);
	EnemyTurretComponent2() = delete;
};
