#include "MainMenu.h"

MainMenu::MainMenu(std::string nickname) : hardcoreMode(false), menuMovementY(310), nickname(nickname)
{
	//displaySurface = SDL_GetVideoSurface();
	displaySurface = Init("SUPER", 800, 600, 32);
	enterNickname = true;
	run = true;
}

MainMenu::~MainMenu()
{ }

SDL_Surface* MainMenu::Init(const std::string title, int width, int height, int bpp)
{
  TTF_Init();

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_WM_SetCaption(title.c_str(), NULL);

  displaySurface = SDL_SetVideoMode(width, height, bpp, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_FillRect(displaySurface, NULL, 0x000000);

  std::cout << "Game initialized successfully" << std::endl;

  return displaySurface;
}

void MainMenu::setMenuMovementY(const int value)
{
  menuMovementY = value;
}

int MainMenu::getMenuMovementY()
{
  return menuMovementY;
}

void MainMenu::setHardcore(bool hardcore)
{
	hardcoreMode = hardcore;
}

bool MainMenu::getHardcore()
{
	return hardcoreMode;
}

void MainMenu::HandleEvents(SDL_Event &event)
{
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
          case SDLK_w:
          case SDLK_UP:
            if (getMenuMovementY() <= 310)
              setMenuMovementY(430);
            setMenuMovementY(getMenuMovementY() - 30);
            break;

          case SDLK_s:
          case SDLK_DOWN:
            if (getMenuMovementY() >= 400)
              setMenuMovementY(280);
            setMenuMovementY(getMenuMovementY() + 30);
            break;

					case SDLK_u:
						if (getHardcore())
						{
							std::cout << "Hardcore mode disabled!" << std::endl;
							setHardcore(false);
						}
						else
						{
							std::cout << "Hardcore mode!" << std::endl;
							setHardcore(true);
						}
						break;

					case SDLK_SPACE:
					case SDLK_RETURN:
						// If you wanna start the game
						if (getMenuMovementY() == 310) {
							GameWindow *r = new GameWindow();
							r->runGame(getHardcore());
							delete r;
						}
						// If you wanna check the highscore
						else if (getMenuMovementY() == 340) {
							Highscore s(displaySurface);
							s.runHighscore();
						}
						else if (getMenuMovementY() == 370) {
							run = false;
						}
						else if (getMenuMovementY() == 400)
						{
							Nickname *n = new Nickname(nickname);
							n->RunNickname();
							delete n;
						}
						break;

					case SDLK_ESCAPE:
						run = false;
						break;
        }
    }
  }
}

void MainMenu::DrawMenuArrow(SDL_Surface* src, const int y, const int x)
{
  SDL_Rect rect = {x, y, 10, 2};

  SDL_Rect rect2 = {x+10, y-7, 2, 16};
  SDL_Rect rect3 = {x+12, y-6, 2, 14};
  SDL_Rect rect4 = {x+14, y-5, 2, 12};
  SDL_Rect rect5 = {x+16, y-4, 2, 10};
  SDL_Rect rect6 = {x+18, y-3, 2, 8};
  SDL_Rect rect7 = {x+20, y-2, 2, 6};
  SDL_Rect rect8 = {x+22, y-1, 2, 4};
  SDL_Rect rect9 = {x+24, y, 2, 2};

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
	Draw d;
	std::cout << "MainMenu start" << std::endl;

	/*Nickname n(nickname);
	n.RunNickname(); */
  while(run)
  {
	if (enterNickname) {
		Nickname *n = new Nickname(nickname);
		n->RunNickname();
		nickname = n->getNickname();
		delete n;
		enterNickname = false;
	}

    // Set the background to black
    SDL_FillRect(displaySurface, NULL, 0x000000);

    // The title and subtitle
    d.DrawText(displaySurface, "SUPER", 137, 120, -1, 51, 108, 184);
    d.DrawText(displaySurface, "Super    Unique    Death    Efficient    Rally", 25, 260, -1, 176, 54, 56);
    
    // The menu entries
    if (getMenuMovementY() == 310)
      d.DrawText(displaySurface, "new    game", 18, 300, -1, 255, 0, 0);
    else
      d.DrawText(displaySurface, "new    game", 18, 300, -1, 255, 255, 255);

    if (getMenuMovementY() == 340)
      d.DrawText(displaySurface, "highscore", 18, 330, -1, 255, 255, 0);
    else
      d.DrawText(displaySurface, "highscore", 18, 330, -1, 255, 255, 255);

    if (getMenuMovementY() == 370)
      d.DrawText(displaySurface, "quit", 18, 360, -1, 0, 255, 0);
    else
      d.DrawText(displaySurface, "quit", 18, 360, -1, 255, 255, 255);

    if (getMenuMovementY() == 400)
      d.DrawText(displaySurface, "change    initials", 18, 390, -1, 255, 0, 255);
    else
      d.DrawText(displaySurface, "change    initials", 18, 390, -1, 255, 255, 255);

    // Draw the "choose arrow" in the menu
    d.DrawMenuArrow(displaySurface, getMenuMovementY(), 250);
	
    SDL_Delay(10);
    SDL_Flip(displaySurface);

    HandleEvents(Events);
  }
	std::cerr << "Game successfully exited." << std::endl;
}
