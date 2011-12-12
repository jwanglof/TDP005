#include "Highscore.h"

Highscore::Highscore()
{
	run = true;
	gameCurrentscore = 0;
}

Highscore::Highscore(SDL_Surface* screen)
{
	displaySurface = screen;
	run = true;
	gameCurrentscore = 0;
}

Highscore::~Highscore()
{ }

int Highscore::getHighscore()
{
  return gameHighscore;
}

int Highscore::getCurrentscore()
{
	return gameCurrentscore;
}

void Highscore::runHighscore()
{
	SDL_Event Events;

	std::ifstream highscoreFile;
	std::string line;
	std::list<std::string> highscoreList;
	highscoreFile.open("score/HIGHSCORE", std::ios::in | std::ios::binary);

	while (run)
	{
    // Set the background to black
    SDL_FillRect(displaySurface, NULL, 0x000000);

		DrawText(displaySurface, "asd", 100, 100, 100);
		
		if (highscoreFile.is_open())
		{
			while (!highscoreFile.eof())
			{
				highscoreFile >> line;
				highscoreList.push_back(line);
			}
		}
		highscoreFile.close();

		while (SDL_PollEvent(&Events))
		{
			if (Events.type == SDL_KEYDOWN)
			{
				if (Events.key.keysym.sym == SDLK_ESCAPE)
				{
					// Need to change this so it return to the mainmenu
					run = false;
				}
			}
		}
		SDL_Delay(1);
		SDL_Flip(displaySurface);
	}

	highscoreList.sort();

	std::list<std::string>::iterator it = highscoreList.begin();
	for (; it != highscoreList.end(); ++it)
	{
		std::cout << *it << std::endl;
	}

	SDL_FreeSurface(displaySurface);
	SDL_Quit();
	highscoreFile.close();
	return;
}

void Highscore::setHighscore(const int highscore, const std::string nickname)
{
  std::ofstream highscoreFile;

  highscoreFile.open("score/HIGHSCORE", std::ios::out | std::ios::binary | std::ios::app);

  if (highscoreFile.is_open())
  {
		highscoreFile << nickname;
		highscoreFile << ":";
		highscoreFile << highscore;
		highscoreFile << "\n";
  }

	highscoreFile.close();
	
  return;
}

void Highscore::addToCurrentscore(const int currentscore)
{
  gameCurrentscore += currentscore;
}

void Highscore::setCurrentscore(const int currentscore)
{
	gameCurrentscore = currentscore;
}

void Highscore::DrawText(SDL_Surface* src, const std::string funcText, int size, int y, int x)
{
/*
 * Blue for the menu: 51, 108, 184
 * Red for the menu: 176, 54, 56
 */

  SDL_Color color = {255, 255, 255};

  TTF_Font* font = TTF_OpenFont("fonts/m06.TTF", size);
  SDL_Surface* text = TTF_RenderText_Blended(font, funcText.c_str(), color);

  // To get the width in pixels of the text
  int width, height;
  TTF_SizeText(font, funcText.c_str(), &width, &height);

  SDL_Rect rect;
  rect.x = x;
  rect.y = y;
  SDL_BlitSurface(text, NULL, src, &rect);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}

bool Highscore::drawSurface(SDL_Surface* dest, SDL_Surface* src, int x, int y)
{
  if (dest == NULL || src == NULL)
    return false;

  SDL_Rect destRect;

  destRect.x = x;
  destRect.y = y;

  SDL_BlitSurface(src, NULL, dest, &destRect);

  return true;
}
