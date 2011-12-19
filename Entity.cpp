#include "Entity.h"

Entity::Entity(std::string File)
{
	// Set collision-rectangle
	Surface = loadSurface(File);
	EntityList.push_back(this);
}

Entity::~Entity()
{ 
	SDL_FreeSurface(Surface);
}

std::list<Entity *> Entity::EntityList;

SDL_Surface* Entity::loadSurface(std::string File)
{
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* Surface = NULL;
 
	Surf_Temp = SDL_LoadBMP(File.c_str());
 
	Surface = SDL_DisplayFormat(Surf_Temp);
	SDL_SetColorKey(Surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
									SDL_MapRGB(Surface->format, 255, 0, 0));


	SDL_FreeSurface(Surf_Temp);

	return Surface;
}

void Entity::move()
{ }

std::string Entity::get_type()
{ }

bool Entity::hasCollided(SDL_Rect second)
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

	return true;
}

void Entity::draw(SDL_Surface *destination)
{
    SDL_BlitSurface(Surface, NULL, destination, &SurfaceRectangle);
}
