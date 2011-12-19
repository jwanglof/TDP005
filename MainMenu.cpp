#include "MainMenu.h"

MainMenu::MainMenu(std::string Nickname) : HardcoreMode(false), MenuMovementy(310), Nickname(Nickname)
{
	DisplaySurface = init("SUPER", 800, 600, 32);
	EnterNickname = true;
	Running = true;
}

MainMenu::~MainMenu()
{ }

SDL_Surface* MainMenu::init(const std::string Title, int Width, int Height, int Bpp)
{
  TTF_Init();

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_WM_SetCaption(Title.c_str(), NULL);

  DisplaySurface = SDL_SetVideoMode(Width, Height, Bpp, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_FillRect(DisplaySurface, NULL, 0x000000);

  return DisplaySurface;
}

void MainMenu::set_menu_movement_y(const int Value)
{
  MenuMovementY = Value;
}

int MainMenu::get_menu_movement_y()
{
  return MenuMovementY;
}

void MainMenu::set_hardcore(bool Hardcore)
{
	HardcoreMode = Hardcore;
}

bool MainMenu::get_hardcore()
{
	return HardcoreMode;
}

void MainMenu::handle_events(SDL_Event &Event)
{
  while (SDL_PollEvent(&Event))
  {
    switch (Event.type)
    {
      case SDL_KEYDOWN:
        switch (Event.key.keysym.sym)
        {
          case SDLK_w:
          case SDLK_UP:
            if (get_menu_movement_y() <= 310)
              set_menu_movement_y(430);
            set_menu_movement_y(get_menu_movement_y() - 30);
            break;

          case SDLK_s:
          case SDLK_DOWN:
            if (get_menu_movement_y() >= 400)
              set_menu_movement_y(280);
            set_menu_movement_y(get_menu_movement_y() + 30);
            break;

					case SDLK_u:
						if (get_hardcore())
						{
							set_hardcore(false);
						}
						else
						{
							set_hardcore(true);
						}
						break;

					case SDLK_SPACE:
					case SDLK_RETURN:
						// If you wanna start the game
						if (get_menu_movement_y() == 310) {
							GameWindow *r = new GameWindow(Nickname);
							r->run_game(get_hardcore());
							delete r;
							r = 0;
						}

						// If you wanna check the highscore
						else if (get_menu_movement_y() == 340) {
							Highscore *s = new Highscore();
							s->run_highscore();
							delete s;
							s = 0;
						}
						
						// If you wanna quit
						else if (get_menu_movement_y() == 370) {
							run = false;
						}

						// If you wanna change your initiales
						else if (get_menu_movement_y() == 400)
						{
							EnterNickname = true;
						}
						break;

					case SDLK_ESCAPE:
						Running = false;
						break;
        }
    }
  }
}

void MainMenu::run_menu()
{
	Draw *d = new Draw();

  while(Running)
  {
	if (EnterNickname) {
		Nickname *n = new Nickname(Nickname);
		n->run_nickname();
		Nickname = n->get_nickname();
		delete n;
		n = 0;
		EnterNickname = false;

		// If the user hits ESCAPE before entering 3 characters it will end this loop
		if (Nickname.size() < 3)
			Running = false;
	}

    // Set the background to black
    SDL_FillRect(DisplaySurface, NULL, 0x000000);

    // The title and subtitle
    d->draw_text(DisplaySurface, "SUPER", 137, 120, -1, 51, 108, 184);
    d->draw_text(DisplaySurface, "Super    Unique    Death    Efficient    Rally", 25, 260, -1, 176, 54, 56);
    
    // The menu entries
    if (get_menu_movement_y() == 310)
      d->draw_text(DisplaySurface, "new    game", 18, 300, -1, 255, 0, 0);
    else
      d->draw_text(DisplaySurface, "new    game", 18, 300, -1, 255, 255, 255);

    if (get_menu_movement_y() == 340)
      d->draw_text(DisplaySurface, "highscore", 18, 330, -1, 255, 255, 0);
    else
      d->draw_text(DisplaySurface, "highscore", 18, 330, -1, 255, 255, 255);

    if (get_menu_movement_y() == 370)
      d->draw_text(DisplaySurface, "quit", 18, 360, -1, 0, 255, 0);
    else
      d->draw_text(DisplaySurface, "quit", 18, 360, -1, 255, 255, 255);

    if (get_menu_movement_y() == 400)
      d->draw_text(DisplaySurface, "change    initials", 18, 390, -1, 255, 0, 255);
    else
      d->draw_text(DisplaySurface, "change    initials", 18, 390, -1, 255, 255, 255);

    // Draw the "choose arrow" in the menu
    d->draw_menu_arrow(DisplaySurface, get_menu_movement_y(), 250);
	
    SDL_Delay(10);
    SDL_Flip(DisplaySurface);

    handle_events(Events);
  }
}
