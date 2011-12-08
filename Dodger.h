#include "Enemy.h"
#include <cmath>

class Dodger : public Enemy
{
	private:
		int velocity;
		SDL_Rect chase;
		bool dodge_projectile;
	public:
		Dodger(double, double);
		~Dodger();

		//bool hasCollided(SDL_Rect);
		void move();
		void chase_move();
		void set_dodge(bool);
		void dodge_move();
		void set_chase(SDL_Rect);
		std::string get_type();
};
