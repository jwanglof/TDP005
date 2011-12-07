#include "Enemy.h"

Enemy::Enemy(double start_x, double start_y) : Entity("./gfx/space.bmp")
{
	velocity = 2;

	surfaceRectangle.x = start_x;
	surfaceRectangle.y = start_y;
	surfaceRectangle.w = 40;
	surfaceRectangle.h = 40;

	enemyList.push_back(this);
}

Enemy::~Enemy()
{ }

std::list<Enemy *> Enemy::enemyList;

void Enemy::move()
{
	double delta_y = (chase.y - surfaceRectangle.y);
	double delta_x = (chase.x - surfaceRectangle.x);
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
	if (surfaceRectangle.x < 800)
		surfaceRectangle.x += (cos(angle) * velocity);
	if (!surfaceRectangle.y < 600)
		surfaceRectangle.y -= (sin(angle) * velocity);

}

void Enemy::set_chase(SDL_Rect player)
{
	chase = player;
}

std::string Enemy::get_type()
{
	return "Enemy";
}
