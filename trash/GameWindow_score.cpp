#include "GameWindow.h"

int GameWindow::getHighscore()
{
  return gameHighscore;
}

int GameWindow::getCurrentscore()
{
  return gameCurrentscore;
}

void GameWindow::setHighscore(const int highscore)
{
  gameHighscore = highscore;
}

void GameWindow::setCurrentscore(const int currentscore)
{
  gameCurrentscore = currentscore;
}
