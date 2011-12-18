#include "Nickname.h"

Nickname::Nickname(std::string nickname) : nickname(nickname)
{
	run = true;
	displaySurface = SDL_GetVideoSurface();
	std::cout << displaySurface << std::endl;
	//displaySurface = Init("SUPER", 800, 600, 32);
}

Nickname::~Nickname()
{ }

void Nickname::HandleEvents(SDL_Event &Event)
{
	while (SDL_PollEvent(&Event))
  {

		if (Event.type == SDL_KEYDOWN)
		{

			if (Event.key.keysym.sym == SDLK_ESCAPE)
			{
				run = false;
			}

			if (Event.key.keysym.sym == SDLK_BACKSPACE)
			{
				if (nickname.size() > 0)
					nickname.erase(nickname.size()-1);
			}

			if (nickname.size() < 3)
			{
				int keystroke = Event.key.keysym.sym;
				if ((Uint16)keystroke >= 97 && (Uint16)keystroke <= 122)
				{
					nickname += toupper((Uint16)keystroke);
				}
			}
			else
			{
				if (Event.key.keysym.sym == SDLK_y)
				{
					run = false;
				}
			}

		}

	}
}

void Nickname::RunNickname()
{
	Draw d;
	std::cerr << "Nickname start" << std::endl;
	while(run)
	{
		SDL_FillRect(displaySurface, NULL, 0x000000);

		d.DrawText(displaySurface, "Initials    plz", 50, 100, -1, 51, 108, 184);

		d.DrawText(displaySurface, nickname, 30, 200, -1, 255, 255, 0);

		if (nickname.length() == 3)
		{
			d.DrawText(displaySurface, "Proceed    with    '"+ nickname +"'?", 20, 450, -1, 255, 0, 0);
			d.DrawText(displaySurface, "Y    /    Backspace", 20, 500, -1, 255, 0, 255);
		}

		SDL_Delay(10);
		SDL_Flip(displaySurface);

		HandleEvents(Events);
	}
	std::cerr << "Nickname end" << std::endl;
}

void Nickname::setNickname(std::string nick)
{
	nickname = nick;
}

std::string Nickname::getNickname()
{
	return nickname;
}
