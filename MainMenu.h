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
  SDL_Surface* DisplaySurface;

	/// If this is true the menu-loop will run
  bool Running;

	/// If this is true the nickname-loop will run
  bool EnterNickname;

	/// Captures events
  SDL_Event Events;

	/// Is to get the coordinates where the menu arrow is
  int MenuMovementY;

	/// Contains the nickname the player has chosen
	std::string Nickname;

	/// If this is true the enemies will move very fast
	bool HardcoreMode;

	/**
	 * Inits SDL with a window that have title as caption, width and height as size and bpp as resolution
	 */
  SDL_Surface* init(const std::string, int, int, int);
public:
  MainMenu(std::string);
  ~MainMenu();

	/**
	 * setHardcore sets hardcoreMode to true or false depending on the player's choice
	 * getHardcore returns hardcoreMode
	 */
	void set_hardcore(bool);
	bool get_hardcore();

	/**
	 * setMenuMovementY set the new movement of the menu-arrow
	 * getMenuMovementY get the coordinates of the menu-arrow
	 */
  void set_menu_movement_y(const int);
  int get_menu_movement_y();

	/**
	 * When this is called the menu-loop will run
	 */
  void run_menu();

	/**
	 * Handle the events of the main menu
	 */
  void handle_events(SDL_Event&);
};

#endif
