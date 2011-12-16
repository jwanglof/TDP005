#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameWindow.h"
#include "Highscore.h"
#include "Nickname.h"

class MainMenu
{
private:  
  SDL_Surface* displaySurface;
  bool run;
  bool enterNickname;
  SDL_Surface* Init(const std::string title, int width, int height, int bpp);
  SDL_Event Events;
  int menuMovementY;
	std::string nickname;

	bool hardcoreMode;
public:
  MainMenu(std::string);
  ~MainMenu();

	void setHardcore(bool);
	bool getHardcore();

  void setMenuMovementY(const int value);
  int getMenuMovementY();

  void DrawText(SDL_Surface* src, const std::string text, int size, int y, Uint8 R, Uint8 G, Uint8 B);
  void DrawMenuArrow(SDL_Surface* src, const int y, const int x);
  void RunMenu();

  void HandleEvents(SDL_Event &event);
};

#endif
