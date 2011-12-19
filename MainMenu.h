#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>

#include "SDL/SDL.h"

#include "GameWindow.h"
#include "Highscore.h"
#include "Nickname.h"

/**
 * MainMenu class
 * Handles the main menu in the game
 */

class MainMenu
{
private:
	/// Where everything gets drawn onto
  SDL_Surface* displaySurface;

	/// If this is true the menu-loop will run
  bool run;

	/// If this is true the nickname-loop will run
  bool enterNickname;

	/// Captures events
  SDL_Event Events;

	/// Is to get the coordinates where the menu arrow is
  int menuMovementY;

	/// Contains the nickname the player has chosen
	std::string nickname;

	/// If this is true the enemies will move very fast
	bool hardcoreMode;

	/**
	 * Inits SDL with a window that have title as caption, width and height as size and bpp as resolution
	 */
  SDL_Surface* Init(const std::string title, int width, int height, int bpp);
public:
  MainMenu(std::string);
  ~MainMenu();

	/**
	 * setHardcore sets hardcoreMode to true or false depending on the player's choice
	 * getHardcore returns hardcoreMode
	 */
	void setHardcore(bool);
	bool getHardcore();

	/**
	 * setMenuMovementY set the new movement of the menu-arrow
	 * getMenuMovementY get the coordinates of the menu-arrow
	 */
  void setMenuMovementY(const int value);
  int getMenuMovementY();

	/**
	 * When this is called the menu-loop will run
	 */
  void RunMenu();

	/**
	 * Handle the events of the main menu
	 */
  void HandleEvents(SDL_Event &event);
};

#endif
