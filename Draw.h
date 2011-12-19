#ifndef DRAW_H_
#define DRAW_H_

#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

/**
 * Draw class
 * Have all the draw-functions used throughout the game
 * Centralize these functions makes it easier for various classes to use them
 */

class Draw
{
private:
public:
	Draw();
	~Draw();

	/**
	 * DrawText prints a string in the window
	 */
	void draw_text(SDL_Surface*, const std::string, int, int, int, Uint8, Uint8, Uint8);

	/**
	 * DrawSurface makes a rectangle and draws src in it at x and y
	 */
	void draw_surface(SDL_Surface*, SDL_Surface*, int, int);

	/**
	 * DrawMenuArrow is only used in MainMenu.
	 * It draws the choose-arrow the is shown in the menu
	 */
  void draw_menu_arrow(SDL_Surface*, const int, const int);
};

#endif
