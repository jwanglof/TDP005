#ifndef ENTITY_H_
#define ENTITY_H_

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

#include <iostream>
#include <list>

class Entity
{
	private:
		SDL_Surface* surface;
		// SDL_Rect to contain coordinates and size of entity
	public:
		Entity(std::string);
		~Entity();

		// Check collision between two objects  (takes SDL_Rect from other class)
		bool hasCollided(SDL_Rect, SDL_Rect);
		virtual void move() = 0;
		void draw(SDL_Surface*);
		static std::list<Entity *> EntityList;
		virtual std::string get_type() = 0;
		SDL_Surface* loadSurface(std::string File);

		SDL_Rect surfaceRectangle;
};

#endif
