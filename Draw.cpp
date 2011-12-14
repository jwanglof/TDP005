#include "Draw.h"

Draw::Draw(SDL_Surface* screen, SDL_Event& Events)
{
	displaySurface = screen;
	Events = Events;
}

Draw::~Draw()
{ }

void Draw::DrawText(SDL_Surface* Src, const std::string funcText, int Size, int y, int x, Uint8 R, Uint8 G, Uint8 B)
{
/*
 * Blue for the menu: 51, 108, 184
 * Red for the menu: 176, 54, 56
 */

  SDL_Color Color = {R, G, B};

  TTF_Font* Font = TTF_OpenFont("fonts/m06.TTF", Size);
  SDL_Surface* Text = TTF_RenderText_Blended(Font, funcText.c_str(), Color);

  // To get the width in pixels of the text
  int Width, Height;
  TTF_SizeText(Font, funcText.c_str(), &Width, &Height);

  SDL_Rect Rect;
	// If the text should be in the center of the screen or not
	if (x == -1)
		Rect.x = ((src->w - width) / 2);
	else
		Rect.x = x;

  Rect.y = y;

  SDL_BlitSurface(Text, NULL, Src, &Rect);
  SDL_FreeSurface(Text);
  TTF_CloseFont(Font);

	return;
}

bool Draw::DrawSurface(SDL_Surface* Src, SDL_Surface* Dest, int x, int y)
{
  SDL_Rect Rect;

  Rect.x = x;
  Rect.y = y;

  SDL_BlitSurface(Src, NULL, Dest, &Rect);

  return;
}

bool Draw::DrawMenuArrow(SDL_Surface* Src, const int y)
{
  SDL_Rect Rect = {300, y, 10, 2};

  SDL_Rect Rect2 = {310, y-7, 2, 16};
  SDL_Rect Rect3 = {312, y-6, 2, 14};
  SDL_Rect Rect4 = {314, y-5, 2, 12};
  SDL_Rect Rect5 = {316, y-4, 2, 10};
  SDL_Rect Rect6 = {318, y-3, 2, 8};
  SDL_Rect Rect7 = {320, y-2, 2, 6};
  SDL_Rect Rect8 = {322, y-1, 2, 4};
  SDL_Rect Rect9 = {324, y, 2, 2};

  SDL_FillRect(Src, &Rect, 0xFFFFFF);
  SDL_FillRect(Src, &Rect2, 0xFFFFFF);
  SDL_FillRect(Src, &Rect3, 0xFFFFFF);
  SDL_FillRect(Src, &Rect4, 0xFFFFFF);
  SDL_FillRect(Src, &Rect5, 0xFFFFFF);
  SDL_FillRect(Src, &Rect6, 0xFFFFFF);
  SDL_FillRect(Src, &Rect7, 0xFFFFFF);
  SDL_FillRect(Src, &Rect8, 0xFFFFFF);
  SDL_FillRect(Src, &Rect9, 0xFFFFFF);

	return;
}
