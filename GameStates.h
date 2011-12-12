#ifndef GAMESTATES_H_
#define GAMESTATES_H_

#include "GameWindow.h"

class GameStates
{
protected:
  GameState() { }
private:
public:
  virtual void Init() = 0;
  virtual void Cleanup() = 0;

  virtual void NewGame() = 0;
  virtual void Highscore() = 0;
  virtual void Quit() = 0;

  virtual void HandleEvents(GameWindow* game) = 0;
  virtual void Update(GameWindow* game) = 0;
  virtual void Draw(GameWindow* game) = 0;

  void ChangeState(GameWindow* game, GameState* state)
  {
    game->ChangeState(state);
  }
};

#endif
