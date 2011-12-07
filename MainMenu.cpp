#include "MainMenu.h"

MainMenu::MainMenu()
{
  screen = Init("SUPER", 800, 600, 32);
  RunMenu();
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

void MainMenu::HandleEvents(SDL_Event &event)
{
  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
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

void MainMenu::DrawText(SDL_Surface* src, const char* funcText, int size, int y, Uint8 R, Uint8 G, Uint8 B)
{
/*
 * Blue for the menu: 51, 108, 184
 * Red for the menu: 176, 54, 56
 */

  SDL_Color color = {R, G, B};

  TTF_Font* font = TTF_OpenFont("fonts/m06.TTF", size);
  SDL_Surface* text = TTF_RenderText_Blended(font, funcText, color);

  // To get the width in pixels of the text
  int width, height;
  TTF_SizeText(font, funcText, &width, &height);

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
    SDL_Event MenuEvent;

    SDL_Delay(10);
    SDL_Flip(screen);

    // Set the background to black
    SDL_FillRect(screen, NULL, 0x000000);

    // The title and subtitle
    DrawText(screen, "SUPER", 100, 150, 51, 108, 184);
    DrawText(screen, "Super    Unique    Death    Efficient    Rally", 16, 260, 176, 54, 56);
    
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

    HandleEvents(MenuEvent);
  }
}

/*
int main()
{
  MainMenu asd;
  return 0;
}
*/
