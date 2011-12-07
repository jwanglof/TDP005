#include "Projectile.h"

Projectile::Projectile(double start_x, double start_y, double mouse_x, double mouse_y) : Entity("./gfx/shot.bmp") {

	velocity = 8;
	// Set start-positions and the size of the entity
	surfaceRectangle.x = start_x;
	surfaceRectangle.y = start_y;

	surfaceRectangle.w = 3;
	surfaceRectangle.h = 3;

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
	surfaceRectangle.x += (cos(angle) * velocity);
	surfaceRectangle.y -= (sin(angle) * velocity);

}

std::string Projectile::get_type()
{
	return "Projectile";
}
