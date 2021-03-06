#pragma once

#include "engine.h"

class KeyMapScene : public Scene {
public:
	KeyMapScene() = default;
  ~KeyMapScene() override = default;

  void Load() override;

  void Update(const double& dt) override;
};
