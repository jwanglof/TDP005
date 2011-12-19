#include "Nickname.h"

Nickname::Nickname(std::string Nickname) : CurrentNickname(Nickname)
{
	Running = true;
	DisplaySurface = SDL_GetVideoSurface();
}

Nickname::~Nickname()
{ }

void Nickname::set_nickname(std::string Nick)
{
	CurrentNickname = Nick;
}

std::string Nickname::get_nickname()
{
	return CurrentNickname;
}

void Nickname::handle_events(SDL_Event &Event)
{
	while (SDL_PollEvent(&Event))
  {

		if (Event.type == SDL_KEYDOWN)
		{

			if (Event.key.keysym.sym == SDLK_BACKSPACE)
			{
				if (CurrentNickname.size() > 0)
					CurrentNickname.erase(CurrentNickname.size()-1);
			}

			if (CurrentNickname.size() < 3)
			{
				int keystroke = Event.key.keysym.sym;
				if ((Uint16)keystroke >= 97 && (Uint16)keystroke <= 122)
				{
					CurrentNickname += toupper((Uint16)keystroke);
				}
			}
			else
			{
				if (Event.key.keysym.sym == SDLK_y)
				{
					set_nickname(CurrentNickname);
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

		d->draw_text(DisplaySurface, CurrentNickname, 30, 200, -1, 255, 255, 0);

		if (CurrentNickname.length() == 3)
		{
			d->draw_text(DisplaySurface, "Proceed    with    '"+ CurrentNickname +"'?", 20, 450, -1, 255, 0, 0);
			d->draw_text(DisplaySurface, "Y    /    Backspace", 20, 500, -1, 255, 0, 255);
		}

		SDL_Delay(10);
		SDL_Flip(DisplaySurface);

		handle_events(Events);
	}

	delete d;
	d = 0;
}
