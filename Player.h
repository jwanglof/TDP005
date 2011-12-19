#ifndef PLAYER_H_
#define PLAYER_H_

#include <map>
#include <vector>

#include "Entity.h"
#include "Enemy.h"
#include "Projectile.h"

class Player : public Entity
{
private:
	/*
	 * A map that check if a key is currently pressed down
	 */
	std::map<std::string, bool> isPressed;

	/*
	 * Set's the speed the player moves with
	 */
	int velocity;

	/*
	 * The number of lives left for the player
	 */
	int lives;

	/*
	 * The number of bombs left for the player to use
	 */
	int bombs;

	/*
	 * Check if the players' shield is up
	 */
	bool ShieldUp;
public:
	/*
	 * Virtual from Entity
	 */
	void move();

	/*
	 * Check events for moving the player
	 */
	void check_events(SDL_Event&);

	/*
	 * Returns "Player" in this class
	 */
	std::string get_type();

	Player();
	~Player();

	int get_lives() const;
	void set_lives(int);

	int get_bombs() const;
	void add_bombs();

	bool get_shield_up();
	void set_shield_up(bool);
};

#endif
