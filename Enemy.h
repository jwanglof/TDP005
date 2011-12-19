#ifndef ENEMY_H_
#define ENEMY_H_

#include <cmath>

#include "Entity.h"

/**
 * Enemy class
 * Inherit from Entity's virtual functions
 * SOME MORE INFO
 */

class Enemy : public Entity
{
private:
	/// Velocity set's the speed the enemy will move with
	int Velocity;

	/// chase set's the player's position so it can chase it
	SDL_Rect Chase;
public:
	Enemy(std::string);
	~Enemy();

	/**
	 * enemyList contains every enemy spawned on the screen
	 * Since it's static the game will only contain one of these lists
	 */
	static std::list<Enemy *> EnemyList;

	/**
	 * Virtual in Entity
	 */
	virtual void move() = 0;

	/**
	 * chase_move is a virtual function for Dodger and Stalker
	 */
	virtual void set_chase(SDL_Rect) = 0;

	/**
	 * get_type is a virtual function for Dodger and Stalker
	 */
	virtual std::string get_type() = 0;
};

#endif
