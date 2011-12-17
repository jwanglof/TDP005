#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"
#include <cmath>

/**
 * Enemy class
 * Inherit from Entity's virtual functions
 * SOME MORE INFO
 */

class Enemy : public Entity
{
private:
	/// Velocity does something
	int velocity;

	/// chase does something
	SDL_Rect chase;
public:
	Enemy(std::string);
	~Enemy();

	//bool hasCollided(SDL_Rect);

	/**
	 * enemyList contains every enemy spawned on the screen
	 * Since it's static the game will only contain one of these lists
	 */
	static std::list<Enemy *> enemyList;

	/**
	 * move is a virtual function for Dodger and Stalker
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
