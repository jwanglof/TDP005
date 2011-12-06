#include "Entity.h"

Entity::Entity(std::string File)
{
	x = 0;
	y = 0;

	surface = loadSurface(File);
	EntityList.push_back(this);
}

Entity::~Entity()
{ 
	SDL_FreeSurface(surface);
}

std::vector<Entity *> Entity::EntityList;

/* SDL_Surface* Entity::get_surface() {
	return surface;
} */

SDL_Surface* Entity::loadSurface(std::string File)
{
    SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* surface = NULL;
 
    if((Surf_Temp = SDL_LoadBMP(File.c_str())) == NULL) {
    }
 
    surface = SDL_DisplayFormat(Surf_Temp);
    SDL_SetColorKey(surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
		SDL_MapRGB(surface->format, 255, 0, 0));


    SDL_FreeSurface(Surf_Temp);

	return surface;
}

void Entity::move()
{ }

void Entity::draw(SDL_Surface *destination)
{
    SDL_Rect DestR;
 
    DestR.x = x;
    DestR.y = y;

    SDL_BlitSurface(surface, NULL, destination, &DestR);
}
