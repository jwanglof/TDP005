#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <fstream>
#include <list>
#include <map>

// To get SDL library
#include "GameWindow.h"
#include "Draw.h"

/**
 * Highscore class
 * Handles everything that has to do with scoring
 * Current score and highscore
 */
 
class Highscore
{
private:
	/// Contain the highsore. NOT SURE IF THIS IS NEEDED!
  int gameHighscore;

	/// Contain the current score of the game
  int gameCurrentscore;

	/// If this is true the highscore window will be shown
	bool run;

	/// Where everything gets drawn onto
	SDL_Surface* displaySurface;
public:
	Highscore();
	~Highscore();

	/**
	 * getHighscore gets the highscore from a file
	 * getCurrentscore gets the current score of the game
	 */
  int getHighscore();
  int getCurrentscore();
  
  /**
	 * setHighscore sets the highscore at the end of the game. Writes to a file
	 * setCurrentscore sets the current score to gameCurrentscore
	 * addToCurrentscore adds point in the current game
	 */
  void setHighscore(const std::string nickname, const int highscore);
  void setCurrentscore(const int currentscore);
  void addToCurrentscore(const int currentscore);

	/**
	 * When this is called the highscore list is shownd
	 */
	void runHighscore();
};

#endif
