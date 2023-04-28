#pragma once
#include <memory>
#include "SealEngine.h"
using namespace SealEngine;

class AssetManager {
public:
	static const Texture2D Hector_Run;
	static const AnimationClip Hector_Idle;
	static const AnimationClip Hector_IdleN;
	static const AnimatorController Hector_Controller;
	static const GameObject HectorObject;

	static const Texture2D XwingTexture;
	static const AnimationClip Xwing_Idle;
	static const AnimationClip Xwing_Left;
	static const AnimationClip Xwing_Right;
	static const AnimatorController Xwing_Controller;
	static const GameObject XwingObject;

	static const Texture2D Projectile_Blue_Texture;
	static const AnimationClip Projectile_Blue_Idle;
	static const AnimatorController Projectile_Blue_Controller;
	static const GameObject ProjectileObject_Blue;

	static const Texture2D GreenSlime;
	static const AnimationClip GreenSlime_Idle;
	static const AnimatorController GreenSlime_Controller;

	//Nario
	static const Texture2D Nario;
	static const AnimationClip Nario_Idle;
	static const AnimationClip Nario_Left;
	static const AnimationClip Nario_Right;
	static const AnimationClip Nario_Jump;
	static const AnimatorController Nario_Controller;
	static const GameObject NarioObject;

	//Big TikeMyson
	static const Texture2D BigTikeMyson;
	static const AnimationClip BigTikeMyson_Idle;
	static const AnimationClip BigTikeMyson_Walk;
	static const AnimationClip BigTikeMyson_Jump;
	static const AnimationClip BigTikeMyson_Punch;
	static const AnimatorController BigTikeMyson_Controller;
	static const GameObject BigTikeMysonObject;

	//Mini TikeMyson
	static const Texture2D MiniTikeMyson;
	static const AnimationClip MiniTikeMyson_Idle;
	static const AnimationClip MiniTikeMyson_Walk;
	static const AnimationClip MiniTikeMyson_Jump;
	static const AnimationClip MiniTikeMyson_Punch;
	static const AnimatorController MiniTikeMyson_Controller;
	static const GameObject MiniTikeMysonObject;

	//Obstacle
	static const Texture2D ObstacleTexture;
	static const AnimationClip Obstacle_Idle;
	static const AnimatorController Obstacle_Controller;
	static const GameObject ObstacleObject;

	//Spawner
	static const GameObject ObstacleSpawnerObject;

	//Misc
	static const Texture2D Googleplex;

	static const Texture2D SpaceBackground;
	static const Texture2D GalaxyBackground;

	static const Texture2D Font;

	static const Texture2D GameTitle;
	static const Texture2D MenuOptions;
	static const Texture2D PauseScreen;
	static const Texture2D PauseMessage;

	static const Texture2D SkyBackground;
	static const Texture2D MountainBackground;
};
