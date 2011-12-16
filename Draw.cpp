#include "Draw.h"

Draw::Draw()
{
//	displaySurface = SDL_GetVideoSurface();
}

Draw::~Draw()
{ }

void Draw::DrawText(SDL_Surface* src, const std::string funcText, int size, int y, int x, Uint8 R, Uint8 G, Uint8 B)
{
/*
 * Blue for the menu: 51, 108, 184
 * Red for the menu: 176, 54, 56
 */
//	std::cerr << 1 << std::endl;
  SDL_Color color = {R, G, B};

  TTF_Font* font = TTF_OpenFont("fonts/m06.TTF", size);
  SDL_Surface* text = TTF_RenderText_Blended(font, funcText.c_str(), color);
//	std::cerr << 2 << std::endl;
  // To get the width in pixels of the text
  int width, height;
  TTF_SizeText(font, funcText.c_str(), &width, &height);

  SDL_Rect rect;
	// If the text should be in the center of the screen or not
	if (x == -1)
	{
//		std::cout << width << " " << height << std::endl;
		rect.x = ((src->w - width) / 2);
	}
	else
		rect.x = x;
//	std::cerr << 3 << std::endl;
  rect.y = y;

  SDL_BlitSurface(text, NULL, src, &rect);

  SDL_FreeSurface(text);
  TTF_CloseFont(font);

//	std::cerr << 4 << std::endl;
	return;
}

void Draw::DrawSurface(SDL_Surface* src, SDL_Surface* dest, int x, int y)
{
  SDL_Rect rect;

  rect.x = x;
  rect.y = y;

  SDL_BlitSurface(src, NULL, dest, &rect);

  return;
}

void Draw::DrawMenuArrow(SDL_Surface* src, const int y, const int x)
{
  SDL_Rect rect = {x, y, 10, 2};

  SDL_Rect rect2 = {x+10, y-7, 2, 16};
  SDL_Rect rect3 = {x+12, y-6, 2, 14};
  SDL_Rect rect4 = {x+14, y-5, 2, 12};
  SDL_Rect rect5 = {x+16, y-4, 2, 10};
  SDL_Rect rect6 = {x+18, y-3, 2, 8};
  SDL_Rect rect7 = {x+20, y-2, 2, 6};
  SDL_Rect rect8 = {x+22, y-1, 2, 4};
  SDL_Rect rect9 = {x+24, y, 2, 2};

  SDL_FillRect(src, &rect, 0xFFFFFF);
  SDL_FillRect(src, &rect2, 0xFFFFFF);
  SDL_FillRect(src, &rect3, 0xFFFFFF);
  SDL_FillRect(src, &rect4, 0xFFFFFF);
  SDL_FillRect(src, &rect5, 0xFFFFFF);
  SDL_FillRect(src, &rect6, 0xFFFFFF);
  SDL_FillRect(src, &rect7, 0xFFFFFF);
  SDL_FillRect(src, &rect8, 0xFFFFFF);
  SDL_FillRect(src, &rect9, 0xFFFFFF);

	return;
}
