#ifndef NICKNAME_H_
#define NICKNAME_H_

#include <string>

#include "SDL/SDL.h"

#include "Draw.h"

/**
 * Nickname class
 * Lets the user type in his, or hers, initials
 */

class Nickname
{
private:
	/// Where everything gets drawn onto
	SDL_Surface* displaySurface;

	/// Captures the events
	SDL_Event Events;

	/// Contains the nickname
	std::string nickname;

	/// If true the nickname-loop will run
	bool run;
public:
	Nickname(std::string);
	~Nickname();

	/**
	 * setNickname sets the nickname
	 * getNickname returns nickname
	 */
	void setNickname(std::string);
	std::string getNickname();

	/**
	 * Handle all the events for the nickname window
	 */
	void HandleEvents(SDL_Event&);

	/**
	 * If this is called it will run the nickname-loop
	 */
	void RunNickname();
};

#endif
