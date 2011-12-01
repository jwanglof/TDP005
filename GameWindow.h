#include <iostream>
#include <string>

class GameWindow
{
private:
  int highscore;
  int currentscore;
public:
  GameWindow();
  ~GameWindow();

  int getHighscore();
  int getCurrentscore();
  
  void setHighscore(int highscore const);
  void setCurrentscore(int currentscore const);
};

