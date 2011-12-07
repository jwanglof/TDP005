#include "Highscore.h"

int Highscore::getHighscore()
{
  return gameHighscore;
}

int Highscore::getCurrentscore()
{
  return gameCurrentscore;
}

void Highscore::setHighscore(const int highscore)
{
  gameHighscore = highscore;
}

void Highscore::setCurrentscore(const int currentscore)
{
  gameCurrentscore = currentscore;
}
