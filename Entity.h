#ifndef ENTITY_H_
#define ENTITY_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

#include <iostream>
#include <vector>

class Entity
{
	private:
		SDL_Surface* surface;
	public:
		Entity(std::string);
		~Entity();

		virtual void move() = 0;
		void draw(SDL_Surface*);
		static std::vector<Entity *> EntityList;
		SDL_Surface* loadSurface(std::string File);

		double x;
		double y;
};

#endif
