#ifndef NICKNAME_H_
#define NICKNAME_H_

// To get SDL libs
#include "GameWindow.h"
#include "MainMenu.h"
#include "Draw.h"

class Nickname
{
private:
	SDL_Surface* displaySurface;

	std::string nickname;
	bool run;
public:
	Nickname();
	~Nickname();

	void setNickname(std::string);
	void RunNickname();

	std::string getNickname();

  SDL_Surface* Init(const std::string, int, int, int);

	void HandleEvents(SDL_Event*);
};

#endif
