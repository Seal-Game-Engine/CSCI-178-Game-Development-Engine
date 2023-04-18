#pragma once
#include "SealEngine.h"
using namespace SealEngine;

#include "Projectile.h"
class Projectile;

class LandingScene : public Scene {
public:
	LandingScene();

	void Load() override;
	void Refresh() override;

	static std::vector<std::unique_ptr<Projectile>> projectiles;
};
