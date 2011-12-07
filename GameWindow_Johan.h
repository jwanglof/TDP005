#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <iostream>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

#include "Highscore.h"
#include "SDLFunctions.h"

//#include "GameStates.h"
//class GameState;

#include "MainMenu.h"
//class MainMenu;

class GameWindow
{
private:
  SDL_Surface* screen;


public:
  GameWindow(SDL_Surface* mainScreen);
  GameWindow();
  ~GameWindow();

  bool running;

//  MainMenu *menuClass;

  static SDL_Surface* loadImage(std::string imagePath);
  
//  void HandleEvents(GameWindow* game);
  void HandleEvents(SDL_Event &event);
  void Quit();
  void Update();
};

#endif
