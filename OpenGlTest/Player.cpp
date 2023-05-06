#include "Player.h"
#include "Projectile.h"
#include "AssetManager.h"
#include <cmath>

const std::array<const AnimatorController*, 2> Player::animatorControllers{ &AssetManager::TikeMyson_Controller, &AssetManager::TikeMyson_Controller}; //change to small and big guy controller

void Player::TakeDamage(float damage)
{
}

void Player::Awake(){
	renderer = gameObject->GetComponent<SpriteRenderer>();
	animator = gameObject->GetComponent<Animator>();
	rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Player::Update() {
	int x = Input::GetAxisRaw(Input::Axis::Horizontal);
	Vector2 horizontalMovement = Vector2::right();
	rigidbody->velocity = Vector2((float)x * _speed, rigidbody->velocity.y());

	if (_canJump && (Input::GetKeyDown(KeyCode::W) || Input::GetKeyDown(KeyCode::UpArrow))) { 
		animator->Play("Jump");
		rigidbody->AddForce(Vector2::up() * 5.0f, Rigidbody2D::ForceMode2D::Impulse);
		_canJump = false;
	}

	if (Input::GetKeyDown(KeyCode::Space)) {
		InvokeRepeating([&]() {
			powerState = (PowerState)(((int)powerState + 1) % 2);
			animator->SetAnimatorController(animatorControllers[(int)powerState]);
			}, 1, 1);
	}

	if (Input::GetKeyDown(KeyCode::H)) {
		animator->Play("Punch");
	}

	animator->SetBool("isWalking", std::abs(x) > 0);
	animator->SetBool("isJumping", !_canJump);
	if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

void Player::OnCollisionEnter2D(Collision2D collision) {
	if (collision.gameObject()->CompareTag("Ground")) _canJump = true;
}

void Player::OnCollisionStay2D(Collision2D collision) {
	
}

void Player::OnCollisionExit2D(Collision2D collision){

}
