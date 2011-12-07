#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

class Highscore
{
private:
  int gameHighscore;
  int gameCurrentscore;
public:
  int getHighscore();
  int getCurrentscore();
  
  void setHighscore(const int highscore);
  void setCurrentscore(const int currentscore);
};

#endif
