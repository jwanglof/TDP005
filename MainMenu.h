#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameWindow.h"
#include "Highscore.h"
//class GameWindow;

class MainMenu
{
private:  
  SDL_Surface* screen;
  bool run;
  SDL_Event Events;
  int menuMovementY;
	std::string nickname;
public:
  MainMenu();
  ~MainMenu();

  void setMenuMovementY(const int value);
  int getMenuMovementY();

  void DrawText(SDL_Surface* src, const std::string text, int size, int y, Uint8 R, Uint8 G, Uint8 B);
  void DrawMenuArrow(SDL_Surface* src, const int y);
  void RunMenu();
  SDL_Surface* Init(const char* title, int width, int height, int bpp);

  void HandleEvents(SDL_Event &event);

	// These should be moved to it's own class!
	// They are located above main()
	void setNickname(std::string nick);
	std::string getNickname();
	void RunNickname();
};

#endif
