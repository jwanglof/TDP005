#include "Nickname.h"

Nickname::Nickname(SDL_Surface* screen, SDL_Event& Events)
{
	displaySurface = screen;
	Events = Events;

	run = true;
}

Nickname::~Nickname()
{
	SDL_FreeSurface(screen);
	SDL_FreeSurface(displaySurface);
	SDL_Quit();
}

void Nickname::RunNickname()
{
	while(run)
	{
    // Set the background to black
    SDL_FillRect(screen, NULL, 0x000000);

		DrawText(screen, "Initials    plz", 50, 100, 51, 108, 184);

		// Events to write the nick and what will happen afterwards
		while (SDL_PollEvent(&Events))
		{
			if (Events.type == SDL_KEYDOWN)
			{
				if (nickname.size() < 3)
				{
					if ((Uint16)Events.key.keysym.sym >= 97 && (Uint16)Events.key.keysym.sym <= 122)
					{
						nickname += toupper((Uint16)Events.key.keysym.sym);
					}
				}
				else
				{
					if (Events.key.keysym.sym == SDLK_y)
					{
						RunMenu();
					}
				}

				if (Events.key.keysym.sym == SDLK_ESCAPE)
				{
					run = false;
				}
				if (Events.key.keysym.sym == SDLK_BACKSPACE)
				{
					nickname.erase(nickname.size()-1);
				}
			}
		}

		DrawText(screen, nickname, 30, 200, 255, 255, 0);

		if (nickname.length() == 3)
		{
			DrawText(screen, "Proceed    with    '"+ nickname +"'?", 20, 450, 255, 0, 0);
			DrawText(screen, "Y    /    Backspace", 20, 500, 255, 0, 255);
		}

		SDL_Delay(10);
		SDL_Flip(screen);
	}
}

void Nickname::setNickname(std::string nick)
{
	nickname = nick;
}

std::string Nickname::getNickname()
{
	return nickname;
}

