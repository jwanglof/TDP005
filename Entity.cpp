#include "Entity.h"

Entity::Entity(std::string File)
{
	// Set collision-rectangle
	surfaceRectangle.x = 0;
	surfaceRectangle.y = 0;

	surface = loadSurface(File);
	EntityList.push_back(this);
}

Entity::~Entity()
{ 
	SDL_FreeSurface(surface);
}

std::list<Entity *> Entity::EntityList;

SDL_Surface* Entity::loadSurface(std::string File)
{
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* surface = NULL;
 
	Surf_Temp = SDL_LoadBMP(File.c_str());
 
	surface = SDL_DisplayFormat(Surf_Temp);
	SDL_SetColorKey(surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
									SDL_MapRGB(surface->format, 255, 0, 0));


	SDL_FreeSurface(Surf_Temp);

	return surface;
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

	return true;
}

void Entity::draw(SDL_Surface *destination)
{
    SDL_BlitSurface(surface, NULL, destination, &surfaceRectangle);
}
