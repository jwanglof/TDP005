#include "GameWindow.h"

SDL_Event event;
TTF_Font *font = NULL;
SDL_Color textColor = {255, 255, 255};

GameWindow::GameWindow()
{
  mainWindow = NULL;
}

GameWindow::~GameWindow()
{ }

bool GameWindow::loadFont(const int size)
{
  font = TTF_OpenFont("DejaVuSans.ttf", size);

  if (font == NULL)
    return false;

  return true;
}

bool GameWindow::initSDL()
{
  //Initialize all SDL subsystems
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;
    
  //Set up the screen
  if ((mainWindow = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE)) == NULL)
      return false;

  //Set the window caption
  SDL_WM_SetCaption("SUPER", NULL);

  //If everything initialized fine
  return true;
}

// Will NOT load .bmp files!
SDL_Surface* GameWindow::loadImage(std::string image)
{
  SDL_Surface* tempSurface = NULL;
  SDL_Surface* returnSurface = NULL;

  if ((tempSurface = IMG_Load(image.c_str())) == NULL)
    return false;

  returnSurface = SDL_DisplayFormat(tempSurface);
  SDL_FreeSurface(tempSurface);

  return returnSurface;
}

// Will load an image to x, y on destination from source
bool GameWindow::drawSurface(SDL_Surface* destination, SDL_Surface* source, int x, int y)
{
  if (destination == NULL || source == NULL)
    return false;

  SDL_Rect destinationRect;

  destinationRect.x = x;
  destinationRect.y = y;

  SDL_BlitSurface(source, NULL, destination, &destinationRect);

  return true;
}

// The gamewindow with score and highscore
bool GameWindow::loadGamewindow()
{
  if (!loadImage("gameWindow_withoutText.png"))
    return false;

  if (!drawSurface(screen, returnSurface, 0, 0))
    return false;

  return true;
}

bool GameWindow::runGame()
{
  if (!initSDL())
    return false;

  if (!loadGamewindow())
    return false;

  while (running)
  {
    while (SDL_PollEvent(&event))
      onEvent(&event);
  }

  cleanSDL();

  return true;
}

void GameWindow::onEvent(SDL_Event* event)
{
// Be able to close the window on the "X" button
  if(event->type == SDL_QUIT)
    running = false;
}

void GameWindow::cleanSDL()
{
//  SDL_FreeSurface(image);
  SDL_Quit();
}

int main()
{
  GameWindow windoz;
  windoz.runGame();
  bool asd;
  asd = windoz.loadImage("gameWindow_withoutText.png");
  if (asd)
    std::cout << 2 << std::endl;

  return 0;
}
