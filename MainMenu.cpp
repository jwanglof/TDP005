#include "MainMenu.h"

MainMenu::MainMenu()
{
  screen = Init("SUPER", 800, 600, 32);
	RunNickname();
	setHardcore(false);
//  RunMenu();
}

MainMenu::~MainMenu()
{ }

void MainMenu::setMenuMovementY(const int value)
{
  menuMovementY = value;
}

int MainMenu::getMenuMovementY()
{
  return menuMovementY;
}

SDL_Surface* MainMenu::Init(const char* title, int width, int height, int bpp)
{
  TTF_Init();
  
  run = true;

  setMenuMovementY(310);

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_WM_SetCaption(title, NULL);

  screen = SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE | SDL_DOUBLEBUF);

  std::cout << "Game initialized successfully" << std::endl;

  return screen;
}

void MainMenu::setHardcore(bool hardcore)
{
	std::cout << 1 << std::endl;
	hardcoreMode = hardcore;
}

bool MainMenu::getHardcore()
{
	return hardcoreMode;
}

void MainMenu::HandleEvents(SDL_Event &event)
{
	std::cout << getHardcore() << std::endl;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
          case SDLK_w:
            if (getMenuMovementY() <= 310)
              setMenuMovementY(400);
            setMenuMovementY(getMenuMovementY() - 30);
            break;

          case SDLK_s:
            if (getMenuMovementY() >= 370)
              setMenuMovementY(280);
            setMenuMovementY(getMenuMovementY() + 30);
            break;

          case SDLK_UP:
            if (getMenuMovementY() <= 310)
              setMenuMovementY(400);
            setMenuMovementY(getMenuMovementY() - 30);
            break;

          case SDLK_DOWN:
            if (getMenuMovementY() >= 370)
              setMenuMovementY(280);
            setMenuMovementY(getMenuMovementY() + 30);
            break;

					case SDLK_u:
						if (getHardcore())
						{
							setHardcore(false);
							std::cout << "Hardcore mode disabled!" << std::endl;
						}
						else
						{
							setHardcore(true);
							std::cout << "Hardcore mode!" << std::endl;
						}
						break;

					case SDLK_SPACE:
						// If you wanna start the game
						if (getMenuMovementY() == 310) {
							std::cout << "Starting game" << std::endl;
							GameWindow *r = new GameWindow(screen, event);
							r->runGame(getNickname(), getHardcore());
							delete r;
						}
						// If you wanna check the highscore
						else if (getMenuMovementY() == 340) {
							Highscore *s = new Highscore(screen);
							s->runHighscore();
							delete s;
						}
						// If you wanna quit the game
						else if (getMenuMovementY() == 370) {
							run = false;
						}
						break;

					case SDLK_RETURN:
						// If you wanna start the game
						if (getMenuMovementY() == 310) {
							std::cout << "Starting game" << std::endl;
							GameWindow *r = new GameWindow(screen, event);
							r->runGame(getNickname(), getHardcore());
							delete r;
						}
						// If you wanna check the highscore
						else if (getMenuMovementY() == 340) {
							Highscore *s = new Highscore(screen);
							s->runHighscore();
							delete s;
						}
						// If you wanna quit the game
						else if (getMenuMovementY() == 370) {
							run = false;
						}
						break;

					case SDLK_ESCAPE:
						run = false;
						break;
        }
    }
  }
}

void MainMenu::DrawMenuArrow(SDL_Surface* src, const int y)
{
  SDL_Rect rect = {300, y, 10, 2};

  SDL_Rect rect2 = {310, y-7, 2, 16};
  SDL_Rect rect3 = {312, y-6, 2, 14};
  SDL_Rect rect4 = {314, y-5, 2, 12};
  SDL_Rect rect5 = {316, y-4, 2, 10};
  SDL_Rect rect6 = {318, y-3, 2, 8};
  SDL_Rect rect7 = {320, y-2, 2, 6};
  SDL_Rect rect8 = {322, y-1, 2, 4};
  SDL_Rect rect9 = {324, y, 2, 2};

  SDL_FillRect(src, &rect, 0xFFFFFF);
  SDL_FillRect(src, &rect2, 0xFFFFFF);
  SDL_FillRect(src, &rect3, 0xFFFFFF);
  SDL_FillRect(src, &rect4, 0xFFFFFF);
  SDL_FillRect(src, &rect5, 0xFFFFFF);
  SDL_FillRect(src, &rect6, 0xFFFFFF);
  SDL_FillRect(src, &rect7, 0xFFFFFF);
  SDL_FillRect(src, &rect8, 0xFFFFFF);
  SDL_FillRect(src, &rect9, 0xFFFFFF);
}

void MainMenu::DrawText(SDL_Surface* src, const std::string funcText, int size, int y, Uint8 R, Uint8 G, Uint8 B)
{
/*
 * Blue for the menu: 51, 108, 184
 * Red for the menu: 176, 54, 56
 */

  SDL_Color color = {R, G, B};

  TTF_Font* font = TTF_OpenFont("fonts/m06.TTF", size);
  SDL_Surface* text = TTF_RenderText_Blended(font, funcText.c_str(), color);

  // To get the width in pixels of the text
  int width, height;
  TTF_SizeText(font, funcText.c_str(), &width, &height);

  SDL_Rect rect;
  rect.x = (src->w - width) / 2;
  rect.y = y;
  SDL_BlitSurface(text, NULL, src, &rect);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}

void MainMenu::RunMenu()
{
  while(run)
  {
    // Set the background to black
    SDL_FillRect(screen, NULL, 0x000000);

    // The title and subtitle
    DrawText(screen, "SUPER", 137, 120, 51, 108, 184);
    DrawText(screen, "Super    Unique    Death    Efficient    Rally", 25, 260, 176, 54, 56);
    
    // The menu entries
    if (getMenuMovementY() == 310)
      DrawText(screen, "new    game", 18, 300, 255, 0, 0);
    else
      DrawText(screen, "new    game", 18, 300, 255, 255, 255);

    if (getMenuMovementY() == 340)
      DrawText(screen, "highscore", 18, 330, 255, 255, 0);
    else
      DrawText(screen, "highscore", 18, 330, 255, 255, 255);

    if (getMenuMovementY() == 370)
      DrawText(screen, "quit", 18, 360, 0, 255, 0);
    else
      DrawText(screen, "quit", 18, 360, 255, 255, 255);

    // Draw the "choose arrow" in the menu
    DrawMenuArrow(screen, getMenuMovementY());

    SDL_Delay(10);
    SDL_Flip(screen);

    HandleEvents(Events);

  }

	SDL_FreeSurface(screen);
	SDL_Quit();
	std::cout << "Game successfully exited." << std::endl;
}


void MainMenu::RunNickname()
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

	SDL_FreeSurface(screen);
	SDL_Quit();
}

void MainMenu::setNickname(std::string nick)
{
	nickname = nick;
}

std::string MainMenu::getNickname()
{
	return nickname;
}

int main()
{
  MainMenu asd;
  return 0;
}
