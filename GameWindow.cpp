#include "GameWindow.h"

GameWindow::GameWindow()
{
  displaySurface = NULL;
  gameView = NULL;

  running = true;
}

GameWindow::~GameWindow()
{ }

SDL_Surface* GameWindow::loadImage(std::string imagePath)
{
  SDL_Surface* originImage = NULL;
  SDL_Surface* returnImage = NULL;

  if ((originImage = IMG_Load(imagePath.c_str())) == NULL)
    return false;

  returnImage = SDL_DisplayFormat(originImage);
  SDL_FreeSurface(originImage);

  return returnImage;
}

bool GameWindow::drawSurface(SDL_Surface* dest, SDL_Surface* src, int x, int y)
{
  if (dest == NULL || src == NULL)
    return false;

  SDL_Rect destRect;

  destRect.x = x;
  destRect.y = y;

  SDL_BlitSurface(src, NULL, dest, &destRect);

  return true;
}

void GameWindow::cleanupSDL()
{
  SDL_FreeSurface(displaySurface);
  SDL_FreeSurface(gameView);
  SDL_Quit();
}

void GameWindow::renderSurface()
{
  GameWindow::drawSurface(displaySurface, gameView, 0, 0);
  SDL_Flip(displaySurface);
}

void GameWindow::onEvent(SDL_Event* eventInput)
{
  if (eventInput->type == SDL_QUIT)
    running = false;
}

int GameWindow::runGame()
{
  SDL_Event SDLEvent;

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  if ((displaySurface = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;

  if ((gameView = GameWindow::loadImage("gameWindow_withoutText.png")) == NULL)
    return false;

  while (running)
  {
    while (SDL_PollEvent(&SDLEvent))
    {
      onEvent(&SDLEvent);
    }
    GameWindow::drawSurface(displaySurface, gameView, 0, 0);
    SDL_Flip(displaySurface);
  }

  GameWindow::cleanupSDL();

  return 0;
}

int main()
{
  GameWindow windoz;
  windoz.runGame();
  windoz.cleanupSDL();
  return 0;
}
