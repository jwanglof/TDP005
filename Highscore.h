#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <fstream>
#include <list>

// To get SDL library
#include "GameWindow.h"
 
class Highscore
{
private:
  int gameHighscore;
  int gameCurrentscore;
	bool run;
	SDL_Surface* src;
	SDL_Surface* displaySurface;
public:
	Highscore();
	Highscore(SDL_Surface*);
	~Highscore();

  int getHighscore();
  int getCurrentscore();
  
  void setHighscore(const int highscore, const std::string nickname);
  void setCurrentscore(const int currentscore);
  void addToCurrentscore(const int currentscore);

	bool drawSurface(SDL_Surface* dest, SDL_Surface* src, int x, int y);
	void DrawText(SDL_Surface* src, const std::string funcText, int size, int y, int x);

	void runHighscore();
};

#endif
