#include "Player.h"

Player::Player() : Entity("./player.bmp")
{
	velocity = 4;

	// A map for checking if key is pressed down, and move if it is
	isPressed["SDLK_w"] = false;
	isPressed["SDLK_a"] = false;
	isPressed["SDLK_s"] = false;
	isPressed["SDLK_d"] = false;
}

Player::~Player()
{
}

void Player::move() {
	// Move the player accordingly	
	if (isPressed["SDLK_w"])
		y -= velocity;
	else if (isPressed["SDLK_s"])
		y += velocity;

	if (isPressed["SDLK_a"])
		x -= velocity;
	else if (isPressed["SDLK_d"])
		x += velocity;

	/*std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;*/
}

void Player::check_events(SDL_Event &event)
{
	// Get keyinput
	// Check if it's pressed or released

	if (event.type == SDL_KEYDOWN) {
		// Check up-down movement
		if (event.key.keysym.sym == SDLK_w)
			isPressed["SDLK_w"] = true;
		else if (event.key.keysym.sym == SDLK_s)
			isPressed["SDLK_s"] = true;

		// Check left-right movement
		if (event.key.keysym.sym == SDLK_a)
			isPressed["SDLK_a"] = true;
		else if (event.key.keysym.sym == SDLK_d)
			isPressed["SDLK_d"] = true;
	}
	else if (event.type == SDL_KEYUP) {
		// Check up-down movement
		if (event.key.keysym.sym == SDLK_w)
			isPressed["SDLK_w"] = false;
		else if (event.key.keysym.sym == SDLK_s)
			isPressed["SDLK_s"] = false;
		// Check left-right movement
		if (event.key.keysym.sym == SDLK_a)
			isPressed["SDLK_a"] = false;
		else if (event.key.keysym.sym == SDLK_d)
			isPressed["SDLK_d"] = false;
	}

	// If you click one of the mouse-buttons
	if (event.type == SDL_MOUSEBUTTONUP) {
	// If the player clicks mouse1, shoot
		if (event.button.button == SDL_BUTTON_LEFT) {
			std::cout << "Clicked Mouse1" << std::endl;
			Projectile *p = new Projectile(x, y);
			projectiles.push_back(p);
		}
	}
}
