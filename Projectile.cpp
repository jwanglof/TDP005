#include "Projectile.h"

Projectile::Projectile(double start_x, double start_y) : Entity("./shot.bmp") {
	x = start_x;
	y = start_y;

	// Calc how to walk for each loop
	/*double delta_y = (mouse_y - start_y);
	double delta_x = (mouse_x - start_x);

	const double PI = 3.141592;
	angle = atan(delta_y / delta_x) * (180 / PI);

	std::cout << angle << std::endl; */
}

Projectile::~Projectile()
{
}

void Projectile::move()
{ 
	// Move the projectile
	//x += move_x;
	//y += move_y;
}
