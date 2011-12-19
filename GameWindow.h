#ifndef GAMEWINDOW_H_
#define GAMEWINDOW_H_

#include <string>
#include <cstdlib>
#include <sstream>
#include <time.h>

#include "SDL/SDL.h"

#include "Player.h"
#include "Stalker.h"
#include "Dodger.h"
#include "Highscore.h"
#include "Draw.h"

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

	/// heartSurface loads the heart-images that represent the player's life
  SDL_Surface* bombSurface;

	/// SDLEvent handle all the events in the game
  SDL_Event SDLEvent;

	/// numberOfEnemies contain how many enemies that will be drawn on the screen
  int numberOfEnemies;

	/// currentLevel keeps track of which level the player is on
	int currentLevel;

	/// running decides if the game-loop is active or not
  bool running;

	/// Contains the nickname, required to set the highscore
	std::string nickname;

	/**
	 * spawnEnemy takes the player's x and y value
	 * Then it will pick out a random number between 0-800 or 0-600 for x and y, respectively
	 * If this number is closer then spawnDistance to the player it will randomize another x and y value
	 */
  void spawnEnemy(int, int);
public:
  GameWindow(std::string);
  ~GameWindow();

	void setLevel(int);
	int getLevel();

	/**
	 * LoadImage loads a bmp-picture
	 */
  static SDL_Surface* LoadImage(std::string File);

	/**
	 * cleanupSDL empties EntityList and enemyList and free heartSurface
	 */
  void cleanupSDL();

	/**
	 * runGame draws everything shown in the game
	 * The hearts, the score, the current level, the player, the enemies, the power-ups and the "bullets". It also handles all movement
	 */
  void runGame(bool hardcoreMode);

	/**
	 *	 onEvent handles all the events in the game
	 */
  void onEvent(SDL_Event* eventInput);

	/**
	 * Spawn an powerup for the player to grab
	 */
  void spawnPowerup();	
};

#endif
