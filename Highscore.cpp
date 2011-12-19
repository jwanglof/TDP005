#include "Highscore.h"

Highscore::Highscore()
{
	DisplaySurface = SDL_GetVideoSurface();
	Running = true;
	GameCurrentscore = 0;
}

Highscore::~Highscore()
{ }

int Highscore::get_highscore()
{
  return GameHighscore;
}

int Highscore::get_currentscore()
{
	return GameCurrentscore;
}

void Highscore::run_highscore()
{
	SDL_Event Events;

	Draw *d = new Draw();

	std::ifstream HighscoreFile;

	std::map<int, std::string> HighscoreMap;

	// Used for the map
	std::string Nickname;
	int Highscore = 0;

	// Used for the run-loop
	std::string ScoreString;
	int YValue = 100;
	int ShowNumberOfScores = 0;
	int Score = 0;

	HighscoreFile.open("score/HIGHSCORE", std::ios::in | std::ios::binary);

	if (HighscoreFile.is_open())
	{
		while (HighscoreFile.good())
		{
			HighscoreFile >> Nickname >> Highscore;
			HighscoreMap[Highscore] = Nickname;
		}
		HighscoreFile.close();
	}

	std::map<int, std::string>::reverse_iterator ReversedHighscoreIterator = HighscoreMap.rbegin();
	
	while (Running)
	{
		// Set the background to black
		SDL_FillRect(DisplaySurface, NULL, 0x000000);

		d->draw_text(DisplaySurface, "Top 15", 55, 20, -1, 51, 108, 184);
		d->draw_text(DisplaySurface, "Initials", 30, 80, 50, 176, 54, 56);
		d->draw_text(DisplaySurface, "Score", 30, 80, 640, 176, 54, 56);

		while (ReversedHighscoreIterator != HighscoreMap.rend() && ShowNumberOfScores < 15)
		{
			// If there isn't any highscores yet
			if (ReversedHighscoreIterator->first == 0)
			{
				d->draw_text(DisplaySurface, "No score", 15, 140, 50, 255, 255, 255);
			}
			else
			{
				Score = ReversedHighscoreIterator->first;
				std::stringstream ScoreStream;
				ScoreStream << Score;
				ScoreString = ScoreStream.str();
				
				d->draw_text(DisplaySurface, ReversedHighscoreIterator->second, 15, YValue+40, 50, 255, 255, 255);
				d->draw_text(DisplaySurface, ScoreString, 15, YValue+40, 640, 255, 255, 255);
				
				YValue += 30;

			}

			++ShowNumberOfScores;
			++ReversedHighscoreIterator;

			SDL_Flip(DisplaySurface);
			SDL_Delay(1000/60);
		}

		while (SDL_PollEvent(&Events))
		{
			if (Events.type == SDL_KEYDOWN)
			{
				if (Events.key.keysym.sym == SDLK_ESCAPE)
				{
					Running = false;
				}
			}
		}
	}
	
	return;
}

void Highscore::set_highscore(const std::string Nickname, const int Highscore)
{
  std::ofstream HighscoreFile;

  HighscoreFile.open("score/HIGHSCORE", std::ios::out | std::ios::binary | std::ios::app);

  if (HighscoreFile.is_open())
  {
		HighscoreFile << Nickname;
		HighscoreFile << " ";
		HighscoreFile << Highscore;
		HighscoreFile << "\n";
  }

	HighscoreFile.close();
	
  return;
}

void Highscore::add_to_currentscore(const int Currentscore)
{
  GameCurrentscore += Currentscore;
}

void Highscore::set_currentscore(const int Currentscore)
{
	GameCurrentscore = Currentscore;
}
