#ifndef DODGER_H_
#define DODGER_H_

#include <cmath>

#include "Enemy.h"

/**
 * Dodger class
 * Inherit from Enemy's virtual functions
 * Gives the enemy Dodger it's movement-path
 * Dodger will dodge the "bullets" and attack the player
 */

class Dodger : public Enemy
{
private:
	/// Velocity does something
	int Velocity;

	/// chase does something
	SDL_Rect Chase;
	
	/// dodge_projectile does something
	bool DodgeProjectile;
public:
	Dodger(double, double);
	~Dodger();

	//bool hasCollided(SDL_Rect);

	/**
	 * move moves the object accordingly
	 */
	void move();

	/**
	 * chase_move chases the player's coordinates
	 */
	void chase_move();

	/**
	 * set_dodge get's the coordinates of the closest projectile so it can
	 * avoid it.
	 */
	void set_dodge(bool);

	/**
	 * dodge_move looks for the set projectile and if it's close enough
	 * dodge it
	 */
	void dodge_move();

	/**
	 * set_chase get's the coordinates of the player so it can chase him
	 */
	void set_chase(SDL_Rect);

	/**
	 * get_type returns "Dodger" in this class
	 */
	std::string get_type();
};

#endif
