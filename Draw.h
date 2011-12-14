#ifndef DRAW_H_
#define DRAW_H_

#include "GameWindow.h"

class Draw
{
private:
	SDL_Surface* displaySurface;
	SDL_Event Events;
public:
	Draw(SDL_Surface*, SDL_Event&);
	~Draw();

	void DrawText(SDL_Surface* src, const std::string text, int size, int y, int x, Uint8 R, Uint8 G, Uint8 B);
	void DrawSurface(SDL_Surface* src, SDL_Surface* dest, int x, int y);
  void DrawMenuArrow(SDL_Surface* src, const int y);
};

#endif
