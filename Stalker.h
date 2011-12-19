#ifndef STALKER_H_
#define STALKER_H_

#include <cmath>

#include "Enemy.h"

class Stalker : public Enemy
{
	private:
		int velocity;
		SDL_Rect chase;
	public:
		Stalker(double, double);
		~Stalker();

		//bool hasCollided(SDL_Rect);
		void move();
		void set_chase(SDL_Rect);
		std::string get_type();
};

#endif
