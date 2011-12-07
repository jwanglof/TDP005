#include "GameWindow.h"

GameWindow::GameWindow(SDL_Surface* mainScreen)
{
  screen = mainScreen;
}

GameWindow::GameWindow()
{ }

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

void GameWindow::HandleEvents(SDL_Event &event)
{
//  SDL_Event event;

  if (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        Quit();
        break;

      case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            Quit();
            break;
        }
    }
  }

/*          case SDLK_UP:
            if (getMenuMovementY() <= 310)
              setMenuMovementY(400);
            setMenuMovementY(getMenuMovementY() - 30);
            break;

          case SDLK_DOWN:
            if (getMenuMovementY() >= 370)
              setMenuMovementY(280);
            setMenuMovementY(getMenuMovementY() + 30);
            break;

          case SDLK_RETURN:
//            std::cout << menuMovementY<< std::endl;
break;
        }
        break;
    }
  }*/
}

void GameWindow::Quit()
{
  running = false;
  SDL_FreeSurface(screen);
  SDL_Quit();
  std::cout << "Game exited successfully" << std::endl;
}

void GameWindow::Update()
{
  SDL_Delay(10);
  SDL_Flip(screen);
}

int main()
{
  MainMenu menuClass;
  GameWindow windoz;
  windoz.running = true;

  return 0;
}
