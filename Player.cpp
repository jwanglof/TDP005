#include "Player.h"

Player::Player() : Entity("./gfx/ghostie.bmp")
{
	velocity = 4;
	lives = 3;
	bombs = 3;

	// Init the player at this position
	SurfaceRectangle.x = 400;
	SurfaceRectangle.y = 300;

	// Set collision rectangle
	SurfaceRectangle.h = 40;
	SurfaceRectangle.w = 40;

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
	if (isPressed["SDLK_w"] && SurfaceRectangle.y > 0)
		SurfaceRectangle.y -= velocity;
	else if (isPressed["SDLK_s"] && SurfaceRectangle.y < (600 - SurfaceRectangle.h))
		SurfaceRectangle.y += velocity;

	if (isPressed["SDLK_a"] && SurfaceRectangle.x > 0)
		SurfaceRectangle.x -= velocity;
	else if (isPressed["SDLK_d"] && SurfaceRectangle.x < (800 - SurfaceRectangle.w))
		SurfaceRectangle.x += velocity;

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
			new Projectile(SurfaceRectangle.x + (SurfaceRectangle.w / 2),
										 SurfaceRectangle.y + (SurfaceRectangle.h / 2), 
										 event.button.x, event.button.y);

		}
		if (event.button.button == SDL_BUTTON_RIGHT && bombs > 0)
		{

			// Find and delete the enemy from the Entity- and Enemylist
			std::list<Enemy*>::iterator eit = Enemy::EnemyList.begin();
			std::list<Entity*>::iterator it2 = Entity::EntityList.begin();
			for (; eit != Enemy::EnemyList.end(); eit++)
			{
				for (; it2 != Entity::EntityList.end(); it2++) {
					if (*it2 == *eit) 
					{
						Entity *del2 = *it2;
						eit = Enemy::EnemyList.erase(eit);
						Entity::EntityList.erase(it2);
						delete del2;
						it2 = Entity::EntityList.begin();
					}
				}
			}

			bombs--;
		}


	}

/*	new Projectile(SurfaceRectangle.x + (SurfaceRectangle.w / 2),
								 SurfaceRectangle.y + (SurfaceRectangle.h / 2), 
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

void Player::set_lives(int change)
{
	lives += change;
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

void Player::add_bombs()
{
	bombs++;
}

int Player::get_bombs() const
{
	return bombs;
}
