#include "Enemy.h"

Enemy::Enemy(std::string File) : Entity(File)
{
	enemyList.push_back(this);
}

Enemy::~Enemy()
{
	  Enemy::enemyList.clear();
}

std::list<Enemy *> Enemy::enemyList;

/*bool Enemy::hasCollided(SDL_Rect second)
{
	// The sides of the recangle
	int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = surfaceRectangle.x;
    rightA = surfaceRectangle.x + surfaceRectangle.w;
    topA = surfaceRectangle.y;
    bottomA = surfaceRectangle.y + surfaceRectangle.h;
        
    //Calculate the sides of rect B
    leftB = second.x;
    rightB = second.x + second.w;
    topB = second.y;
    bottomB = second.y + second.h;

	//If any of the sides from A are outside of B
    if(bottomA <= topB) {
        return false;
    }
    
    if(topA >= bottomB) {
        return false;
    }
    
    if(rightA <= leftB) {
        return false;
    }
    
    if(leftA >= rightB) {
        return false;
    }

	delete this;

	return true;
} */
