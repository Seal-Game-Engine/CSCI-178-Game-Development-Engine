#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class GameEventManager : public MonoBehaviour{
public:
	SpriteRenderer* pausePanel;

	void Awake() override;
	void Update() override;

	std::shared_ptr<GameEventManager> Clone() const;

private:
	void TogglePause();

	bool _isPaused = false;

	GameEventManager* Clone_impl() const override;
};

