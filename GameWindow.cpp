#include "GameWindow.h"
#include "Player.h"
#include "Stalker.h"
#include "Dodger.h"
#include "Highscore.h"

GameWindow::GameWindow(SDL_Surface* screen, SDL_Event& events)
{
  displaySurface = screen;
  SDLEvent = events;
  heartSurface = LoadImage("./gfx/heart.bmp");
  numberOfEnemies = 2;
  currentLevel = 1;

  running = true;
}

GameWindow::~GameWindow()
{ }

SDL_Surface* GameWindow::LoadImage(std::string File)
{
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* surface = NULL;
 
	Surf_Temp = SDL_LoadBMP(File.c_str());
 
	surface = SDL_DisplayFormat(Surf_Temp);
	SDL_SetColorKey(surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
									SDL_MapRGB(surface->format, 255, 0, 0));

	SDL_FreeSurface(Surf_Temp);

	return surface;
}

bool GameWindow::drawSurface(SDL_Surface* dest, SDL_Surface* src, int x, int y)
{
  if (dest == NULL || src == NULL)
    return false;

  SDL_Rect destRect;

  destRect.x = x;
  destRect.y = y;

  SDL_BlitSurface(src, NULL, dest, &destRect);

  return true;
}

void GameWindow::cleanupSDL()
{
  Entity::EntityList.clear();
  Enemy::enemyList.clear();
	SDL_FreeSurface(displaySurface);
	SDL_FreeSurface(heartSurface);
}

void GameWindow::onEvent(SDL_Event* eventInput)
{
	// Check for keyboard events
	if (eventInput->type == SDL_KEYDOWN) {
		// If escape, exit gameloop
		if (eventInput->key.keysym.sym == SDLK_ESCAPE)
			running = false;
		/*else if (eventInput->key.keysym.sym == SDLK_j)
			spawnEnemy();*/
	}
}

// Spawn an enemy
void GameWindow::spawnEnemy(int x, int y)
{
	int spawnX;
	int spawnY;

	spawnX = rand() % 800;
	spawnY = rand() % 600;

	int spawnDistance = 50;

	while (spawnX < (x + spawnDistance) && spawnX > (x - spawnDistance))
		spawnX = rand() % 800;

	while (spawnY < (y + spawnDistance) && spawnY > (y - spawnDistance))
		spawnY = rand() % 600;

	if (rand() % 2 == 0)
		new Stalker(spawnX, spawnY);
	else
		new Dodger(spawnX, spawnY);
}

int GameWindow::runGame(bool hardcoreMode)
{
	Player *p = new Player();
	std::list<Entity *>::iterator it;

	Highscore *score = new Highscore();

	int timeWhenHit;
	int timeWhenShieldOff;

	time_t seconds;

  while (running && p->get_lives() > 0)
	{
		seconds = time(NULL);

		// Get all events
    while (SDL_PollEvent(&SDLEvent)) {
    	onEvent(&SDLEvent);
			p->check_events(SDLEvent);
		}
		
		// Levels
		currentLevel = (1 + floor(score->getCurrentscore() / 1000));

		if (numberOfEnemies != (currentLevel*2) && score->getCurrentscore() != 0)
			numberOfEnemies += 1;

		// Set the shield off when it has reached it has reached timeWhenShieldOff
		if (seconds >= timeWhenShieldOff)
			p->setShieldUp(false);

		// Set max enemys on the playfield
		if (Enemy::enemyList.size() < numberOfEnemies)
			spawnEnemy(p->surfaceRectangle.x, p->surfaceRectangle.y);

		// Check for collisions
		for (it = Entity::EntityList.begin(); it != Entity::EntityList.end(); it++) 
		{
			if (Enemy::enemyList.size() != 0)
			{
				std::list<Enemy *>::iterator eit = Enemy::enemyList.begin();
				for (; eit != Enemy::enemyList.end(); eit++) 
				{
					// If a projectile collides with an enemy
					if ((*it)->get_type() == "Projectile" && (*eit)->hasCollided((*it)->surfaceRectangle)) 
					{
						// Set the player's currentscore depending on which enemy type that's killed
						if ((*eit)->get_type() == "Stalker")
							score->addToCurrentscore(100);
						else if ((*eit)->get_type() == "Dodger")
							score->addToCurrentscore(200);

						// Delete the projectile
						Entity *del = *it;
						it = Entity::EntityList.erase(it);
						delete del;
	
						// Find and delete the enemy from the Entity- and Enemylist
						std::list<Entity*>::iterator it2 = Entity::EntityList.begin();
						for (; it2 != Entity::EntityList.end(); it2++) {
							if (*it2 == *eit) 
							{
								Entity *del2 = *it2;
								eit = Enemy::enemyList.erase(eit);
								it2 = Entity::EntityList.erase(it2);
								delete del2;
								it = Entity::EntityList.begin();
							}
						}

					}
					// If the enemy collided with the player
					else if ((*eit)->hasCollided(p->surfaceRectangle)) {
						std::list<Entity*>::iterator it2 = Entity::EntityList.begin();
						for (; it2 != Entity::EntityList.end(); it2++) {
							if (*it2 == *eit)
							{
								// If the shield is up the player wont loose lifes when getting hit
								if (!p->getShieldUp())
								{
									Entity *del2 = *it2;
									eit = Enemy::enemyList.erase(eit);
									it2 = Entity::EntityList.erase(it2);
									delete del2;
									it = Entity::EntityList.begin();
									p->set_lives(-1);

									//std::cout << p->get_lives() << " " << p->getShieldUp() << std::endl;

									// Change the number to decide how long the shield is activated, in seconds
									timeWhenHit = seconds;
									timeWhenShieldOff = seconds + 5;

									p->setShieldUp(true);
								}
							}
						}
					} // Ends the enemy-collided-If

				}
			}
		}

		// Give all stalker-enemies the position of the player
		std::list<Enemy *>::iterator enemy_iterator;
		for (enemy_iterator = Enemy::enemyList.begin(); 
				 enemy_iterator != Enemy::enemyList.end(); enemy_iterator++) {
			if ((*enemy_iterator)->get_type() == "Stalker") {
				(*enemy_iterator)->set_chase(p->surfaceRectangle);
			}
			else if ((*enemy_iterator)->get_type() == "Dodger") {
				it = Entity::EntityList.begin();

				SDL_Rect dodge;
				// Check if there's an projectile on the screen
				for (it = Entity::EntityList.begin(); it != Entity::EntityList.end(); it++) {
					if ((*it)->get_type() == "Projectile") {
						dodge = (*it)->surfaceRectangle;
					}
				}

				// If there's prjectiles on the screen, else chase player
				Dodger *d = dynamic_cast<Dodger*>(*enemy_iterator);
				if (dodge.x != 0 && abs(dodge.x - (*enemy_iterator)->surfaceRectangle.x) < 50 || 
						dodge.y != 0 && abs(dodge.y - (*enemy_iterator)->surfaceRectangle.y) < 50)  {
					d->set_dodge(true);
					(*enemy_iterator)->set_chase(dodge);
				}
				else {
					d->set_dodge(false);
					(*enemy_iterator)->set_chase(p->surfaceRectangle);
				}

			}
		}

		// Move everything
		it = Entity::EntityList.begin();
		for (; it != Entity::EntityList.end(); it++) {
			// Move every entity
			(*it)->move();

			// Check if remove any Projectiles
			if ((*it)->get_type() == "Projectile") {
				if (((*it)->surfaceRectangle.x < 0 || (*it)->surfaceRectangle.x > 800) ||
						((*it)->surfaceRectangle.y < 0 || (*it)->surfaceRectangle.y > 600)) {
					Entity *del = *it;
					it = Entity::EntityList.erase(it);
					delete del;
				}
			}
		}

		// Draw background
		SDL_FillRect(displaySurface, NULL, 0x000000);
	
		// Draw the hearts
		// Thought that the hearts would be in a pre-defined rect and then move that rect to the center
		SDL_Rect heartRect;
		heartRect.x = 300;
		heartRect.y = 10;
		heartRect.h = 100;
		heartRect.w = 200;

		for (int i = 0; i < p->get_lives(); i++)
			drawSurface(displaySurface, heartSurface, 25*i, 10);

		// MOVE THE SCORE TO THE FAR LEFT WHEN THE HEARTS HAVE BEEN MOVED TO THE CENTER!
		// Draw the current score
		score->DrawText(displaySurface, "Score: ", 18, 10, 470);
		int currentScore = score->getCurrentscore();
		std::string scoreString;
		std::stringstream ss;
		ss << currentScore;
		scoreString = ss.str();
		score->DrawText(displaySurface, scoreString, 18, 10, 550);

		// Draw the current level
		score->DrawText(displaySurface, "Lvl: ", 18, 30, 470);
		std::string levelString;
		std::stringstream ss2;
		ss2 << currentLevel;
		levelString = ss2.str();
		score->DrawText(displaySurface, levelString, 18, 30, 550);

		// See if the shield is up or not
		if (p->getShieldUp())
			score->DrawText(displaySurface, "SHIELD    IS    UP!", 18, 30, 10);

		// Draw everything
		it = Entity::EntityList.begin();
		for (; it != Entity::EntityList.end(); it++) {
			(*it)->draw(displaySurface);
		}

    SDL_Flip(displaySurface);

		if (hardcoreMode)
			SDL_Delay(1);
		else
			SDL_Delay(1000/60);
  }

	// If a player exits the game it wont register any highscore
	if (p->get_lives() == 0)
		score->setHighscore(score->getCurrentscore(), "asd");

  GameWindow::cleanupSDL();

  return 0;
}

/*int main()
{
  GameWindow windoz;
  windoz.runGame();
  windoz.cleanupSDL();
  return 0;
}*/
