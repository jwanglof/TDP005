#ifndef STALKER_H_
#define STALKER_H_

#include <cmath>

#include "Enemy.h"

class Stalker : public Enemy
{
	private:
		/*
		 * The speed at which the Enemy will move
		 */
		int velocity;

		/*
		 * The coordinates of the player
		 */
		SDL_Rect chase;
	public:
		Stalker(double, double);
		~Stalker();

		/*
		 * Virtual in Entity
		 */
		void move();

		/*
		 * Sets the chase-variable
		 */
		void set_chase(SDL_Rect);

		std::string get_type();
};

#endif
