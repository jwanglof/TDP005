#include "Nickname.h"

Nickname::Nickname(std::string Nickname) : Nickname(Nickname)
{
	Running = true;
	DisplaySurface = SDL_GetVideoSurface();
}

Nickname::~Nickname()
{ }

void Nickname::set_nickname(std::string Nick)
{
	Nickname = Nick;
}

std::string Nickname::get_nickname()
{
	return Nickname;
}

void Nickname::handle_events(SDL_Event &Event)
{
	while (SDL_PollEvent(&Event))
  {

		if (Event.type == SDL_KEYDOWN)
		{

			if (Event.key.keysym.sym == SDLK_BACKSPACE)
			{
				if (Nickname.size() > 0)
					Nickname.erase(Nickname.size()-1);
			}

			if (Nickname.size() < 3)
			{
				int keystroke = Event.key.keysym.sym;
				if ((Uint16)keystroke >= 97 && (Uint16)keystroke <= 122)
				{
					Nickname += toupper((Uint16)keystroke);
				}
			}
			else
			{
				if (Event.key.keysym.sym == SDLK_y)
				{
					set_nickname(Nickname);
					Running = false;
				}
			}

		}

	}
}

void Nickname::run_nickname()
{
	Draw *d = new Draw();

	while(Running)
	{
		SDL_FillRect(DisplaySurface, NULL, 0x000000);

		d->draw_text(DisplaySurface, "Initials    plz", 50, 100, -1, 51, 108, 184);

		d->draw_text(DisplaySurface, Nickname, 30, 200, -1, 255, 255, 0);

		if (Nickname.length() == 3)
		{
			d->draw_text(DisplaySurface, "Proceed    with    '"+ Nickname +"'?", 20, 450, -1, 255, 0, 0);
			d->draw_text(DisplaySurface, "Y    /    Backspace", 20, 500, -1, 255, 0, 255);
		}

		SDL_Delay(10);
		SDL_Flip(DisplaySurface);

		HandleEvents(Events);
	}

	delete d;
	d = 0;
}
