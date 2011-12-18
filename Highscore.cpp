#include "Highscore.h"

Highscore::Highscore()
{
	displaySurface = SDL_GetVideoSurface();
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

	Draw *d = new Draw();

	std::ifstream highscoreFile;
	std::string line;
	std::list<std::string> highscoreList;

	highscoreFile.open("score/HIGHSCORE", std::ios::in | std::ios::binary);

	while (run)
	{
    // Set the background to black
    SDL_FillRect(displaySurface, NULL, 0x000000);

		d->DrawText(displaySurface, "asd", 10, 100, 100, 255, 255, 255);
		
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
