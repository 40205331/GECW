#pragma once

#include "cmp_physics.h"
#include <SFML/Audio.hpp>
class PlayerControlsComponent : public Component {
protected:
	float _groundspeed;
	bool _isSprinting;
	// Timer until player can sprint again
	double _sprintCooldown;
	float _sprintSpeed;
	// Player cannot change direction when sprinting
	sf::Vector2f _sprintDirection;
	// Has to press Space again to sprint (cannot keep Space pressed)
	bool _isStillPressingSprintKey;
	// Shoot cooldown
	float _shootCooldown;
	// Shooth direction (if 0.0f should be the previous one)
	sf::Vector2f _shootDirection;

public:
	void update(double dt) override;
	void render() override {};
	explicit PlayerControlsComponent(Entity* p);
	PlayerControlsComponent() = delete;
};
class PlayerPhysicsComponent : public PhysicsComponent {
protected:
  b2Vec2 _size;
  sf::Vector2f _maxVelocity;
  bool _grounded;
  float _groundspeed;

  bool isGrounded() const;
  sf::SoundBuffer _buffer_jump;
  sf::Sound _jump_sound;

public:
  void update(double dt) override;

  explicit PlayerPhysicsComponent(Entity* p, const sf::Vector2f& size);

  PlayerPhysicsComponent() = delete;
};
