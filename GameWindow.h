#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <iostream>
#include <string>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

class GameWindow
{
private:
  int gameHighscore;
  int gameCurrentscore;

  SDL_Event SDLEvent;

/*  SDL_Surface* mainWindow;
  SDL_Surface* tempSurface;
  SDL_Surface* returnSurface;

  SDL_Surface* message;
  SDL_Surface* screen;

  bool running;*/

  bool running;
  SDL_Surface* displaySurface;
  SDL_Surface* testSurface;
public:
  GameWindow(SDL_Surface*, SDL_Event&);
  ~GameWindow();

  int getHighscore();
  int getCurrentscore();
  
  void setHighscore(const int highscore);
  void setCurrentscore(const int currentscore);

  static SDL_Surface* loadImage(std::string imagePath);
  static bool drawSurface(SDL_Surface* dest, SDL_Surface* src, int x, int y);

  void cleanupSDL();

  void renderSurface();

  int runGame();

  void onEvent(SDL_Event* eventInput);

/*  bool loadMenu();
  bool loadGamewindow();
  
  bool initSDL();
  void cleanSDL();
  bool loadFont(const int size);
  bool drawSurface(SDL_Surface* destination, SDL_Surface* source, int x, int y);
  bool runGame();
  static SDL_Surface* loadImage(std::string image);

  void onEvent(SDL_Event* event);*/
};

#endif
