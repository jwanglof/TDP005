#ifndef ENEMY_H_
#define ENEMY_H_

#include "Entity.h"
#include <cmath>

class Enemy : public Entity
{
	private:
		int velocity;
		SDL_Rect chase;
	public:
		Enemy(std::string);
		~Enemy();

		//bool hasCollided(SDL_Rect);
		static std::list<Enemy *> enemyList;
		virtual void move() = 0;
		virtual void set_chase(SDL_Rect) = 0;
		virtual std::string get_type() = 0;
};

#endif
