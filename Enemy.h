#include "Entity.h"
#include <cmath>

class Enemy : public Entity
{
	private:
		int velocity;
		SDL_Rect chase;
	public:
		Enemy(double, double);
		~Enemy();

		static std::list<Enemy *> enemyList;
		void move();
		void set_chase(SDL_Rect);
		std::string get_type();
};
