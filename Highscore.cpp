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

	std::list<std::string> highscoreNickname;
	std::list<int> highscoreScore;

	std::map<int, std::string> highscoreMap;

	std::string nickname;
	int highscore;

	highscoreFile.open("score/HIGHSCORE", std::ios::in | std::ios::binary);
	if (highscoreFile.is_open())
	{
		while (highscoreFile.good())
		{
			highscoreFile >> nickname >> highscore;
			highscoreNickname.push_back(nickname);
			highscoreScore.push_back(highscore);

			highscoreMap[highscore] = nickname;
		}
		highscoreFile.close();
	}

/*
	highscoreNickname.sort();

	std::list<std::string>::iterator it = highscoreNickname.begin();
	for (; it != highscoreNickname.end(); ++it)
	{
		std::cerr << *it << std::endl;
	}
*/

	std::cerr << "Highscore start" << std::endl;

	int i = 1;

	while (run)
	{
    // Set the background to black
    SDL_FillRect(displaySurface, NULL, 0x000000);

		std::map<int, std::string>::iterator it2 = highscoreMap.begin();
		for (; it2 != highscoreMap.end(); ++it2)
		{
//			std::cerr << it2->first << std::endl;
			d->DrawText(displaySurface, it2->second, 10, (100*i), 100, 255, 255, 255);
			i += 50;
			std::cerr << i << std::endl;
		}

//		d->DrawText(displaySurface, "asd", 10, 100, 100, 255, 255, 255);
	 
//		d->DrawText(displaySurface, nickname, 10, 100, 100, 255, 255, 255);

		while (SDL_PollEvent(&Events))
		{
			if (Events.type == SDL_KEYDOWN)
			{
				if (Events.key.keysym.sym == SDLK_ESCAPE)
				{
					run = false;
				}
			}
		}

		SDL_Flip(displaySurface);

		SDL_Delay(1000/60);
	}

	std::cerr << "Highscore end" << std::endl;

	return;
}

void Highscore::setHighscore(const std::string nickname, const int highscore)
{
  std::ofstream highscoreFile;

  highscoreFile.open("score/HIGHSCORE", std::ios::out | std::ios::binary | std::ios::app);

  if (highscoreFile.is_open())
  {
		highscoreFile << nickname;
		highscoreFile << " ";
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
