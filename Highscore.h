#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <fstream>
#include <sstream>
#include <map>
#include <string>

#include "SDL/SDL.h"

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
  int GameHighscore;

	/// Contain the current score of the game
  int GameCurrentscore;

	/// If this is true the highscore window will be shown
	bool Running;

	/// Where everything gets drawn onto
	SDL_Surface* DisplaySurface;
public:
	Highscore();
	~Highscore();

	/**
	 * getHighscore gets the highscore from a file
	 * getCurrentscore gets the current score of the game
	 */
  int get_highscore();
  int get_current_score();
  
  /**
	 * setHighscore sets the highscore at the end of the game. Writes to a file
	 * setCurrentscore sets the current score to gameCurrentscore
	 * addToCurrentscore adds point in the current game
	 */
  void set_highscore(const std::string, const int);
  void set_current_score(const int);
  void add_to_current_score(const int);

	/**
	 * When this is called the highscore list is shownd
	 */
	void run_highscore();
};

#endif
