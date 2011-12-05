#include "Entity.h"

Entity::Entity()
{
	surface = NULL;
	loadSurface("./mario.bmp");
	right = false;

	x = 0;
	y = 0;
}

Entity::~Entity()
{ 
	SDL_FreeSurface(surface);
}

bool Entity::loadSurface(std::string File)
{
    SDL_Surface* Surf_Temp = NULL;
 
    if((Surf_Temp = SDL_LoadBMP(File.c_str())) == NULL) {
        return false;
    }
 
    surface = SDL_DisplayFormat(Surf_Temp);
    SDL_SetColorKey(surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
		SDL_MapRGB(surface->format, 255, 255, 255));

    SDL_FreeSurface(Surf_Temp);

	return true;
}

void Entity::move()
{ 

	if (x > 500)
		right = false;
	else if (x < 0)
		right = true;

	if (right)
		x++;
	else
		x--;
}

void Entity::draw(SDL_Surface *destination)
{
    SDL_Rect DestR;
 
    DestR.x = x;
    DestR.y = y;

    SDL_BlitSurface(surface, NULL, destination, &DestR);
}
