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
	int velocity;

	/// chase does something
	SDL_Rect chase;
	
	/// dodge_projectile does something
	bool dodge_projectile;
public:
	Dodger(double, double);
	~Dodger();

	//bool hasCollided(SDL_Rect);

	/**
	 * move does something
	 */
	void move();

	/**
	 * chase_move does something
	 */
	void chase_move();

	/**
	 * set_dodge does something
	 */
	void set_dodge(bool);

	/**
	 * dodge_move does something
	 */
	void dodge_move();

	/**
	 * set_chase does something
	 */
	void set_chase(SDL_Rect);

	/**
	 * get_type returns "Dodger" in this class
	 */
	std::string get_type();
};
