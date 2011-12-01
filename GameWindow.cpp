#include "GameWindow.h"

GameWindow::GameWindow()
{ }

GameWindow::~GameWindow()
{ }

GameWindow::getHighscore()
{
  return highscore;
}

GameWindow::getCurrentscore()
{
  return currentscore;
}

GameWindow::setHighscore(int highscore const)
{
  GameWindow::highscore = highscore;
}
