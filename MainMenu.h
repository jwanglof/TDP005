#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameWindow.h"
//class GameWindow;

class MainMenu
{
private:  
  SDL_Surface* screen;
  bool run;
  int menuMovementY;
public:
  MainMenu();
  ~MainMenu();

  void setMenuMovementY(const int value);
  int getMenuMovementY();

  void DrawText(SDL_Surface* src, const char* text, int size, int y, Uint8 R, Uint8 G, Uint8 B);
  void DrawMenuArrow(SDL_Surface* src, const int y);
  void RunMenu();
  SDL_Surface* Init(const char* title, int width, int height, int bpp);

  void HandleEvents(SDL_Event &event);
};

#endif
