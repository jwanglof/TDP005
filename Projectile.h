#include "Entity.h"
#include <cmath>

class Projectile : public Entity
{
	private:
		int velocity;
		double move_x, move_y;
		double angle;
	public:
		Projectile(double start_x, double start_y);
		~Projectile();

		void move();
};
