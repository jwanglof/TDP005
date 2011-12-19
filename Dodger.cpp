#include "Dodger.h"

Dodger::Dodger(double start_x, double start_y) : Enemy("./gfx/skull.bmp")
{
	Velocity = 2;

	SurfaceRectangle.x = start_x;
	SurfaceRectangle.y = start_y;
	SurfaceRectangle.w = 40;
	SurfaceRectangle.h = 40;

	DodgeProjectile = false;
}

Dodger::~Dodger()
{ }

void Dodger::set_dodge(bool dodge)
{
	DodgeProjectile = dodge;
}

void Dodger::move()
{
	if (DodgeProjectile)
		dodge_move();
	else
		chase_move();
}

void Dodger::chase_move()
{
	double delta_y = (Chase.y - SurfaceRectangle.y);
	double delta_x = (Chase.x - SurfaceRectangle.x);
	double angle = 0;

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

	// Move the enemy
	if (SurfaceRectangle.x < 800)
		SurfaceRectangle.x += (cos(angle) * Velocity);
	if (!SurfaceRectangle.y < 600)
		SurfaceRectangle.y -= (sin(angle) * Velocity);

	// Don't make it able to leave the screen
	if (SurfaceRectangle.x > 800 - SurfaceRectangle.w)
		SurfaceRectangle.x = 800 - SurfaceRectangle.w;
	if (SurfaceRectangle.y > 600 - SurfaceRectangle.h)
		SurfaceRectangle.y = 600 - SurfaceRectangle.h;

}

void Dodger::dodge_move()
{
	double delta_y = (Chase.y - SurfaceRectangle.y);
	double delta_x = (Chase.x - SurfaceRectangle.x);
	double angle = 0;

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

	// Move the enemy
	if (SurfaceRectangle.x < 800)
		SurfaceRectangle.x -= (cos(angle) * Velocity);
	if (!SurfaceRectangle.y < 600)
		SurfaceRectangle.y += (sin(angle) * Velocity);

	// Don't make it able to leave the screen
	if (SurfaceRectangle.x > 800 - SurfaceRectangle.w)
		SurfaceRectangle.x = 800 - SurfaceRectangle.w;
	if (SurfaceRectangle.y > 600 - SurfaceRectangle.h)
		SurfaceRectangle.y = 600 - SurfaceRectangle.h;
}


void Dodger::set_chase(SDL_Rect player)
{
	Chase = player;
}

std::string Dodger::get_type()
{
	return "Dodger";
}
