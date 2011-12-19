#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <cmath>

#include "Entity.h"

class Projectile : public Entity
{
	private:
		int velocity;
	double move_x;
	double move_y;
		double angle;
	public:
		Projectile(double, double, double, double);
		~Projectile();
		std::string get_type();

		void move();
};

#endif
