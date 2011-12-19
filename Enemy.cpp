#include "Enemy.h"

Enemy::Enemy(std::string File) : Entity(File)
{
	EnemyList.push_back(this);
}

Enemy::~Enemy()
{
	  Enemy::EnemyList.clear();
}

std::list<Enemy *> Enemy::EnemyList;
