#include "Draw.h"

Draw::Draw()
{ }

Draw::~Draw()
{ }

void Draw::draw_text(SDL_Surface* Src, const std::string FuncText, int Size, int Y, int X, Uint8 R, Uint8 G, Uint8 B)
{
/*
 * Blue for the menu: 51, 108, 184
 * Red for the menu: 176, 54, 56
 */
//	std::cerr << 1 << std::endl;
  SDL_Color Color = {R, G, B};

  TTF_Font* Font = TTF_OpenFont("fonts/m06.TTF", Size);
  SDL_Surface* Text = TTF_RenderText_Blended(Font, FuncText.c_str(), Color);

  // To get the width in pixels of the text
  int Width, Height;
  TTF_SizeText(Font, FuncText.c_str(), &Width, &Height);

  SDL_Rect Rect;

	// If X is -1 it will put the text in the middle of the screen
	if (X == -1)
	{
		Rect.x = ((Src->w - Width) / 2);
	}
	else
		Rect.x = X;

  rect.y = Y;

  SDL_BlitSurface(Text, NULL, Src, &Rect);

  SDL_FreeSurface(Text);
  TTF_CloseFont(Font);

	return;
}

void Draw::draw_surface(SDL_Surface* Src, SDL_Surface* Dest, int X, int Y)
{
  SDL_Rect Rect;

  Rect.x = X;
  Rect.y = Y;

  SDL_BlitSurface(Src, NULL, Dest, &Rect);

  return;
}

void Draw::draw_menu_arrow(SDL_Surface* Src, const int Y, const int X)
{
  SDL_Rect Rect = {X, Y, 10, 2};

  SDL_Rect Rect2 = {X+10, Y-7, 2, 16};
  SDL_Rect Rect3 = {X+12, Y-6, 2, 14};
  SDL_Rect Rect4 = {X+14, Y-5, 2, 12};
  SDL_Rect Rect5 = {X+16, Y-4, 2, 10};
  SDL_Rect Rect6 = {X+18, Y-3, 2, 8};
  SDL_Rect Rect7 = {X+20, Y-2, 2, 6};
  SDL_Rect Rect8 = {X+22, Y-1, 2, 4};
  SDL_Rect Rect9 = {X+24, Y, 2, 2};

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
