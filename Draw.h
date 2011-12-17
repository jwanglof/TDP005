#ifndef DRAW_H_
#define DRAW_H_

#include "GameWindow.h"

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
	void DrawText(SDL_Surface* src, const std::string text, int size, int y, int x, Uint8 R, Uint8 G, Uint8 B);

	/**
	 * DrawSurface makes a rectangle and draws src in it at x and y
	 */
	void DrawSurface(SDL_Surface* src, SDL_Surface* dest, int x, int y);

	/**
	 * DrawMenuArrow is only used in MainMenu.
	 * It draws the choose-arrow the is shown in the menu
	 */
  void DrawMenuArrow(SDL_Surface* src, const int y, const int x);
};

#endif
