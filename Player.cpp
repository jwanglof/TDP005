#include "Player.h"

Player::Player() : Entity("./gfx/ghostie.bmp")
{
	velocity = 4;
	// Init the player at this position
	surfaceRectangle.x = 400;
	surfaceRectangle.y = 300;

	// Set collision rectangle
	surfaceRectangle.h = 40;
	surfaceRectangle.w = 40;

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
	if (isPressed["SDLK_w"] && surfaceRectangle.y > 0)
		surfaceRectangle.y -= velocity;
	else if (isPressed["SDLK_s"] && surfaceRectangle.y < (600 - surfaceRectangle.h))
		surfaceRectangle.y += velocity;

	if (isPressed["SDLK_a"] && surfaceRectangle.x > 0)
		surfaceRectangle.x -= velocity;
	else if (isPressed["SDLK_d"] && surfaceRectangle.x < (800 - surfaceRectangle.w))
		surfaceRectangle.x += velocity;
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
			new Projectile(surfaceRectangle.x + (surfaceRectangle.w / 2),
				surfaceRectangle.y + (surfaceRectangle.h / 2), 
				event.button.x, event.button.y);
		}
	}
	// If player clicks mouse2, check if he has bombs left, and remove all entites except player
}

std::string Player::get_type()
{
	return "Player";
}
