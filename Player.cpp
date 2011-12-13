#include "Player.h"

Player::Player() : Entity("./gfx/ghostie.bmp")
{
	velocity = 4;
	lives = 3;

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
	isPressed["mouse1"] = false;

	shieldUp = false;
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

	if (isPressed["mouse1"]) {

	}

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
			isPressed["mouse1"] = false;			
			new Projectile(surfaceRectangle.x + (surfaceRectangle.w / 2),
										 surfaceRectangle.y + (surfaceRectangle.h / 2), 
										 event.button.x, event.button.y);

		}
		if (event.button.button == SDL_BUTTON_RIGHT)
		{

			// Find and delete the enemy from the Entity- and Enemylist
/*			std::list<Enemy*>::iterator eit = Enemy::enemyList.begin();
			std::list<Entity*>::iterator it2 = Entity::EntityList.begin();
			for (; eit != Enemy::enemyList.end(); eit++)
			{
				for (; it2 != Entity::EntityList.end(); it2++) {
					if (*it2 == *eit) 
					{
						Entity *del2 = *it2;
						eit = Enemy::enemyList.erase(eit);
						Entity::EntityList.erase(it2);
						delete del2;
						it2 = Entity::EntityList.begin();
					}
				}
			}*/
			// DrawText(BOOOOOOM)
		}


	}

		if (event.type == SDL_MOUSEBUTTONDOWN) {

			if (event.button.button == SDL_BUTTON_LEFT)
				isPressed["mouse1"] = true;
		}

		if (isPressed["mouse1"]) {

		}

/*	new Projectile(surfaceRectangle.x + (surfaceRectangle.w / 2),
								 surfaceRectangle.y + (surfaceRectangle.h / 2), 
								 event.button.x, event.button.y);
*/
	// If player clicks mouse2, check if he has bombs left, and remove all entites except player
}

std::string Player::get_type()
{
	return "Player";
}

int Player::get_lives() const
{
	return lives;
}

void Player::set_lives(int i)
{
	lives += i;
}

bool Player::getShieldUp()
{
	return shieldUp;
}

void Player::setShieldUp(bool value)
{
	if (value)
		shieldUp = true;
	else
		shieldUp = false;
}
