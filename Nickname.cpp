#include "Nickname.h"

Nickname::Nickname(std::string nickname) : nickname(nickname)
{
	run = true;
	displaySurface = Init("SUPER", 800, 600, 32);
}

Nickname::~Nickname()
{
	SDL_FreeSurface(displaySurface);
	SDL_Quit();
}

SDL_Surface* Nickname::Init(const std::string title, int width, int height, int bpp)
{
  run = true;

  TTF_Init();

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_WM_SetCaption(title.c_str(), NULL);

  displaySurface = SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_FillRect(displaySurface, NULL, 0x000000);
  std::cout << "Game initialized successfully" << std::endl;

  return displaySurface;
}

void Nickname::HandleEvents(SDL_Event *Event)
{
	while (SDL_PollEvent(Event))
  {
		if (Event->type == SDL_KEYDOWN)
		{
			if (Event->key.keysym.sym == SDLK_ESCAPE)
			{
				run = false;
			}

			if (Event->key.keysym.sym == SDLK_BACKSPACE)
			{
				if (nickname.size() > 0)
					nickname.erase(nickname.size()-1);
			}

			if (nickname.size() < 3)
			{
				if ((Uint16)Event->key.keysym.sym >= 97 && (Uint16)Event->key.keysym.sym <= 122)
				{
					nickname += toupper((Uint16)Event->key.keysym.sym);
				}
			}
			else
			{
				if (Event->key.keysym.sym == SDLK_y)
				{
					MainMenu* m = new MainMenu(nickname);
					m->RunMenu();
					delete m;
					m = 0;
				}
			}

		}
	}
}

void Nickname::RunNickname()
{
	Draw* d = new Draw();

	SDL_Event* Events;
	std::cout << nickname << std::endl;
	while(run)
	{
		SDL_FillRect(displaySurface, NULL, 0x000000);
		d->DrawText(displaySurface, "Initials    plz", 50, 100, -1, 51, 108, 184);

		d->DrawText(displaySurface, nickname, 30, 200, -1, 255, 255, 0);

		if (nickname.length() == 3)
		{
			d->DrawText(displaySurface, "Proceed    with    '"+ nickname +"'?", 20, 450, -1, 255, 0, 0);
			d->DrawText(displaySurface, "Y    /    Backspace", 20, 500, -1, 255, 0, 255);
		}

		SDL_Delay(10);
		SDL_Flip(displaySurface);

		HandleEvents(Events);
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
