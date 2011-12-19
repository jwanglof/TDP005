#ifndef ENTITY_H_
#define ENTITY_H_

#include <iostream>
#include <list>

#include "SDL/SDL.h"

/**
 * Entity class
 * MORE INFO
 */

class Entity
{
private:
	/**
	 * The surface of the current subclass
	 */
	SDL_Surface* Surface;
public:
	Entity(std::string);
	~Entity();

	/**
	 * hasCollided check for a collision between two objects.
	 * It takes SDL_Rect from another class
	 */
	virtual bool has_collided(SDL_Rect);

	/**
	 * Updates all the x- and y-coordinates all entities
	 */
	virtual void move() = 0;

	/**
	 * Return the type of a subclass
	 */
	virtual std::string get_type() = 0;

	/**
	 * draw draws it's surface to the surface it takes as a paramater 
	 */

	void draw(SDL_Surface*);

	/**
	 * EntityList contains everything that moves on the screen
	 */
	static std::list<Entity *> EntityList;

	/**
	 * loadSurface loads a bmp-picture
	 */
	SDL_Surface* loadSurface(std::string File);

	/**
	 * surfaceRectangle contains the collision-rectangle x and y value
	 */
	SDL_Rect SurfaceRectangle;
};

#endif
