#include "Player.h"
#include "Projectile.h"
#include "Prefab.h"
#include <cmath>

//void Player::TakeDamage(float damage)
//{
//}

Player::InputData Player::GetInputData(ControlScheme controlScheme) {
	switch (controlScheme) {
	case ControlScheme::Solo:
		return InputData{
			Input::GetAxisRaw(Input::Axis::Horizontal),
			Input::GetKeyUp(KeyCode::A) || Input::GetKeyUp(KeyCode::D) || Input::GetKeyUp(KeyCode::LeftArrow) || Input::GetKeyUp(KeyCode::RightArrow),

			Input::GetKeyDown(KeyCode::W) || Input::GetKeyDown(KeyCode::UpArrow),

			Input::GetKeyDown(KeyCode::H) || Input::GetKeyDown(KeyCode::Comma)
		};
	case ControlScheme::Player1:
		return InputData{
			(float)(Input::GetKey(KeyCode::A) ? -1 : 0) + (Input::GetKey(KeyCode::D) ? 1 : 0),
			Input::GetKeyUp(KeyCode::A) || Input::GetKeyUp(KeyCode::D),

			Input::GetKeyDown(KeyCode::W),

			Input::GetKeyDown(KeyCode::H)
		};
	case ControlScheme::Player2:
		return InputData{
			(float)(Input::GetKey(KeyCode::LeftArrow) ? -1 : 0) + (Input::GetKey(KeyCode::RightArrow) ? 1 : 0),
			Input::GetKeyUp(KeyCode::LeftArrow) || Input::GetKeyUp(KeyCode::RightArrow),

			Input::GetKeyDown(KeyCode::UpArrow),

			Input::GetKeyDown(KeyCode::Comma)
		};
	}
}

void Player::Awake(){
	_renderer = gameObject->GetComponent<SpriteRenderer>();
	_animator = gameObject->GetComponent<Animator>();
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
	_collider = gameObject->GetComponent<CircleCollider2D>();
	_audioSource = gameObject->GetComponent<AudioSource>();

	_collider->radius = miniColliderRadius;
	//_collider->offset = miniCollider.offset;
}

void Player::Update() {
	InputData inputData = GetInputData(controlScheme);

	if (inputData.horizontalUp) _rigidbody->velocity = Vector2::zero();
	else _rigidbody->velocity = Vector2(inputData.horizontal * _speed, _rigidbody->velocity.y());

	if (_canJump && inputData.jumpDown) { 
		switch (_powerState) {
		case PowerState::Mini: _animator->Play("Mini_Jump"); break;
		case PowerState::Big: _animator->Play("Big_Jump"); break;
		}
		_rigidbody->AddForce(Vector2::up() * 5.0f, Rigidbody2D::ForceMode2D::Impulse);
		_canJump = false;
	}
	if(_rigidbody->velocity.y() > _maxVerticalVelocity) _rigidbody->velocity = Vector2(_rigidbody->velocity.x(), _maxVerticalVelocity);

	if (Input::GetKeyDown(KeyCode::Space)) {
		_powerState = (PowerState)(((int)_powerState + 1) % 2);
		switch (_powerState) {
		case PowerState::Mini: 
			_animator->Play("Mini_Idle"); 
			_collider->radius = miniColliderRadius;
			_maxVerticalVelocity = 6;
			break;
		case PowerState::Big:
			_animator->Play("Big_Idle"); 
			_collider->radius = bigColliderRadius;
			_maxVerticalVelocity = 5;
			break;
		}
	}

	if (inputData.attackDown) {
		switch (_powerState) {
		case PowerState::Mini: _animator->Play("Mini_Attack"); break;
		case PowerState::Big: _animator->Play("Big_Punch"); break;
		}
	}

	_animator->SetBool("isWalking", std::abs(inputData.horizontal) > 0);
	_animator->SetBool("isJumping", !_canJump);
	if (std::abs(inputData.horizontal) > 0) transform()->scale.Set(inputData.horizontal > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

void Player::OnCollisionEnter2D(Collision2D collision) {
	if (collision.gameObject()->CompareTag("Ground")) _canJump = true;
}

void Player::OnCollisionStay2D(Collision2D collision) {
	//if (collision.gameObject()->CompareTag("Ground")) _canJump = true;
}

void Player::OnCollisionExit2D(Collision2D collision){

}

//Player::Player(ControlScheme controlScheme) :_controlScheme(controlScheme) {}
