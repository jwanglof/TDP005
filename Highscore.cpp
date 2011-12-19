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

	std::map<int, std::string> highscoreMap;

	// Used for the map
	std::string nickname;
	int highscore = 0;

	// Used for the run-loop
	std::string scoreString;
	int yValue = 100;
	int showNumberOfScores = 0;
	int score = 0;

	highscoreFile.open("score/HIGHSCORE", std::ios::in | std::ios::binary);

	if (highscoreFile.is_open())
	{
		while (highscoreFile.good())
		{
			highscoreFile >> nickname >> highscore;
			highscoreMap[highscore] = nickname;
		}
		highscoreFile.close();
	}

	std::cerr << "Highscore start" << std::endl;

	std::map<int, std::string>::reverse_iterator rIt = highscoreMap.rbegin();
	
	while (run)
	{
		// Set the background to black
		SDL_FillRect(displaySurface, NULL, 0x000000);

		d->DrawText(displaySurface, "Top 15", 55, 20, -1, 51, 108, 184);
		d->DrawText(displaySurface, "Initials", 30, 80, 50, 176, 54, 56);
		d->DrawText(displaySurface, "Score", 30, 80, 640, 176, 54, 56);

		while (rIt != highscoreMap.rend() && showNumberOfScores < 15)
		{
			if (rIt->first == 0)
			{
				d->DrawText(displaySurface, "No score", 15, 140, 50, 255, 255, 255);
			}
			else
			{
				score = rIt->first;
				std::stringstream ss;
				ss << score;
				scoreString = ss.str();
				
				d->DrawText(displaySurface, rIt->second, 15, yValue+40, 50, 255, 255, 255);
				d->DrawText(displaySurface, scoreString, 15, yValue+40, 640, 255, 255, 255);
				
				yValue += 30;				

			}

			++showNumberOfScores;
			++rIt;

			SDL_Flip(displaySurface);
			SDL_Delay(1000/60);
		}

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
