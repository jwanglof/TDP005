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
  SDL_Surface* DisplaySurface;

	/// heartSurface loads the heart-images that represent the player's life
  SDL_Surface* HeartSurface;

	/// heartSurface loads the heart-images that represent the player's life
  SDL_Surface* BombSurface;

	/// SDLEvent handle all the events in the game
  SDL_Event Events;

	/// numberOfEnemies contain how many enemies that will be drawn on the screen
  int NumberOfEnemies;

	/// currentLevel keeps track of which level the player is on
	int CurrentLevel;

	/// running decides if the game-loop is active or not
  bool Running;

	/// Contains the nickname, required to set the highscore
	std::string Nickname;

	/**
	 * spawnEnemy takes the player's x and y value
	 * Then it will pick out a random number between 0-800 or 0-600 for x and y, respectively
	 * If this number is closer then spawnDistance to the player it will randomize another x and y value
	 */
  void spawn_enemy(int, int);
public:
  GameWindow(std::string);
  ~GameWindow();

	void set_level(int);
	int get_level();

	/**
	 * LoadImage loads a bmp-picture
	 */
  static SDL_Surface* load_image(std::string);

	/**
	 * cleanupSDL empties EntityList and enemyList and free heartSurface
	 */
  void CleanupSDL();
	/**
	 * runGame draws everything shown in the game
	 * The hearts, the score, the current level, the player, the enemies, the power-ups and the "bullets". It also handles all movement
	 */
  void run_game(bool);

	/**
	 *	 onEvent handles all the events in the game
	 */
  void on_event(SDL_Event*);

	/**
	 * Spawn an powerup for the player to grab
	 */
  void spawn_powerup();
};

#endif
