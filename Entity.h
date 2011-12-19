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
	/// surface is a surface of a surface in a window! <-------
	SDL_Surface* surface;
	// SDL_Rect to contain coordinates and size of entity
public:
	Entity(std::string);
	~Entity();

	/**
	 * hasCollided check for a collision between two objects.
	 * It takes SDL_Rect from another class
	 * VARFOR AR DENNA VIRTUELL?
	 */
	virtual bool hasCollided(SDL_Rect);

	/**
	 * move is a virtual function for enemy
	 * KAN MAN TA BORT DENNA?
	 */
	virtual void move() = 0;

	/**
	 * get_type is a virtual function for enemy
	 * KAN MAN TA BORT DENNA?
	 */
	virtual std::string get_type() = 0;

	/**
	 * draw draws. 
	 * FLYTTA DENNA TILL DRAW.H?
	 */
	void draw(SDL_Surface*);

	/**
	 * EntityList contains almost everything shown on the screen
	 * "Bullets", enemies, power-ups <----??? and the player
	 */
	static std::list<Entity *> EntityList;

	/**
	 * loadSurface loads a bmp-picture
	 */
	SDL_Surface* loadSurface(std::string File);

	/**
	 * surfaceRectangle contains the collision-rectangle x and y value
	 */
	SDL_Rect surfaceRectangle;
};

#endif
