#pragma once

#include "engine.h"

class chresScene : public Scene {
public:
	chresScene() = default;
  ~chresScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
