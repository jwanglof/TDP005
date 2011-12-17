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

/**
 * GameWindow class
 * This is where the game gets drawn
 */

class GameWindow
{
private:
	/// displaySurface is where the game gets drawn
  SDL_Surface* displaySurface;

	/// heartSurface loads the heart-images that represent the player's life
  SDL_Surface* heartSurface;

	/// SDLEvent handle all the events in the game
  SDL_Event SDLEvent;

	/// numberOfEnemies contain how many enemies that will be drawn on the screen
  int numberOfEnemies;

	/// currentLevel keeps track of which level the player is on
	int currentLevel;

	/// running decides if the game-loop is active or not
  bool running;

	/**
	 * spawnEnemy takes the player's x and y value
	 * Then it will pick out a random number between 0-800 or 0-600 for x and y, respectively
	 * If this number is closer then spawnDistance to the player it will randomize another x and y value
	 */
  void spawnEnemy(int, int);
public:
  GameWindow();
  ~GameWindow();

	void setLevel(int);
	int getLevel();

	/**
	 * LoadImage loads a bmp-picture
	 * EXAKT SAMMA FINNS I ENTITY. FLYTTA TILL ETT GEMENSAMT STALLE?
	 */
  static SDL_Surface* LoadImage(std::string File);

  /**
	 * drawSurface blabla
	 * DENNA BORDE TAS BORT OCH ANVANDA DEN SOM FINNS I DRAW.H IST!
	 */
  static bool drawSurface(SDL_Surface* dest, SDL_Surface* src, int x, int y);

	/**
	 * cleanupSDL empties EntityList and enemyList and free heartSurface
	 */
  void cleanupSDL();

	/**
	 * runGame draws everything shown in the game
	 * The hearts, the score, the current level, the player, the enemies, the power-ups and the "bullets"
	 */
  void runGame(bool hardcoreMode);

	/**
		 onEvent handles all the events in the game
	 */
  void onEvent(SDL_Event* eventInput);
};

#endif
