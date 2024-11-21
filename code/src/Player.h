#pragma once

#include "Entity.h"
#include "SDL2/SDL.h"
#include "Box2D/Box2D.h"
#include "Animation.h"

enum class Player_State{
IDLE, WALK, JUMP, FALL, DIE};

enum class Player_Look {
	LEFT, RIGHT
};

struct SDL_Texture;

class Player : public Entity
{
public:

	Player();
	
	virtual ~Player();

	bool Awake();

	bool Start();

	bool Update(float dt);

	bool CleanUp();

	// L08 TODO 6: Define OnCollision function for the player. 
	void OnCollision(PhysBody* physA, PhysBody* physB);

	void OnCollisionEnd(PhysBody* physA, PhysBody* physB);

	void SetParameters(pugi::xml_node parameters) {
		this->parameters = parameters;
	}

	int GetXPos() {
		return position.getX();
	}

	Vector2D GetPosition();

public:

	bool respawn;
	//Declare player parameters
	float speed = 5.0f;
	SDL_Texture* texture = NULL;
	int texW, texH;

	//Audio fx
	int pickCoinFxId;

	// L08 TODO 5: Add physics to the player - declare a Physics body
	PhysBody* pbody;
	PhysBody* sensor;

	float jumpForce = 1.8f; // The force to apply when jumping
	bool isJumping = false; // Flag to check if the player is currently jumping
	bool isMoving = false;
	bool isDying = false;
	Player_State state = Player_State::IDLE;
	Player_Look look = Player_Look::RIGHT;

	SDL_RendererFlip flip = SDL_FLIP_NONE;
	pugi::xml_node parameters;
	Animation* currentAnimation = nullptr;
	Animation idle;
	Animation walking;
	Animation jumping;
	Animation death;

	Vector2D checkpoint;

	bool godMode;
};