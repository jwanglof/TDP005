#ifndef NICKNAME_H_
#define NICKNAME_H_

#include "GameWindow.h"

class Nickname
{
private:
	SDL_Surface* displaySurface;
	SDL_Event Events;

	std::string nickname;
	bool run;
public:
	Nickname(SDL_Surface*, SDL_Event&);
	~Nickname();

	void setNickname(std::string nick);
	void RunNickname();

	std::string getNickname();
};

#endif
