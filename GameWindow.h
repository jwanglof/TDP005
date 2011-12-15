#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <iostream>
#include <string>
#include <cstdlib>

#include <sstream>

#include <time.h>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

class GameWindow
{
private:
  SDL_Surface* displaySurface;
  SDL_Surface* heartSurface;
  SDL_Event SDLEvent;

  int numberOfEnemies;
  bool running;

  void spawnEnemy(int, int);
public:
  GameWindow(SDL_Surface*, SDL_Event&);
  ~GameWindow();

	int currentLevel;

  static SDL_Surface* LoadImage(std::string File);

  static bool drawSurface(SDL_Surface* dest, SDL_Surface* src, int x, int y);

  void cleanupSDL();

  int runGame(bool hardcoreMode);

  void onEvent(SDL_Event* eventInput);
};

#endif
