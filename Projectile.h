#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include <cmath>

#include "Entity.h"

class Projectile : public Entity
{
	private:
		/*
		 * The speed which the projectile moves with
		 */
		int velocity;

		double move_x;
		double move_y;

		/*
		 * The angle at which the projectile will go
		 */
		double angle;
	public:
		Projectile(double, double, double, double);
		~Projectile();
		std::string get_type();

		/*
		 * Virtual in Entity
		 */
		void move();
};

#endif
