#include "Stalker.h"

Stalker::Stalker(double start_x, double start_y) : Enemy("./gfx/space.bmp")
{
	velocity = 2;

	SurfaceRectangle.x = start_x;
	SurfaceRectangle.y = start_y;
	SurfaceRectangle.w = 40;
	SurfaceRectangle.h = 40;
}

Stalker::~Stalker()
{ }

void Stalker::move()
{
	double delta_y = (chase.y - SurfaceRectangle.y);
	double delta_x = (chase.x - SurfaceRectangle.x);
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
		SurfaceRectangle.x += (cos(angle) * velocity);
	if (!SurfaceRectangle.y < 600)
		SurfaceRectangle.y -= (sin(angle) * velocity);

}

void Stalker::set_chase(SDL_Rect player)
{
	chase = player;
}

std::string Stalker::get_type()
{
	return "Stalker";
}

/*bool Stalker::hasCollided(SDL_Rect second)
{
	// The sides of the recangle
	int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = SurfaceRectangle.x;
    rightA = SurfaceRectangle.x + SurfaceRectangle.w;
    topA = SurfaceRectangle.y;
    bottomA = SurfaceRectangle.y + SurfaceRectangle.h;
        
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
