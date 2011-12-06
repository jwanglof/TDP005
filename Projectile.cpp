#include "Projectile.h"

Projectile::Projectile(double start_x, double start_y, double mouse_x, double mouse_y) : Entity("./shot.bmp") {
	x = start_x;
	y = start_y;
	velocity = 5;

	// Calc how to walk for each loop
	double delta_y = (mouse_y - start_y);
	double delta_x = (mouse_x - start_x);

	const double PI = 3.141592;

	// Calculate the angle (in radians)
	if (delta_y < 0 && delta_x > 0)
		angle = -(atan(delta_y / delta_x));
	else if (delta_y < 0 && delta_x < 0)
		angle = -(atan(delta_y / delta_x) + PI);
	else if (delta_y > 0 && delta_x < 0)
		angle = -(atan(delta_y / delta_x)) + PI;
	else
		angle = -((atan(delta_y / delta_x)) - PI/2) + (PI * 1.5);

	/*
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "sin v: " << sin(angle) << std::endl;
	std::cout << "cos v: " << cos(angle) << std::endl;
	*/
}

Projectile::~Projectile()
{
}

void Projectile::move()
{ 
	// Move the projectile
	x += cos(angle) * velocity;
	y -= sin(angle) * velocity;
}
