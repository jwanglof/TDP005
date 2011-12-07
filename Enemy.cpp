#include "Enemy.h"

Enemy::Enemy(double start_x, double start_y) : Entity("./pacman.bmp")
{
	velocity = 4;

	surfaceRectangle.x = 0;
	surfaceRectangle.y = 0;
	surfaceRectangle.w = 40;
	surfaceRectangle.h = 40;
}

Enemy::~Enemy()
{ }

void Enemy::move()
{
	
}

std::string Enemy::get_type()
{
	return "Enemy";
}
