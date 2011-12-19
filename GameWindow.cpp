#include "GameWindow.h"
#include "Player.h"
#include "Stalker.h"
#include "Powerups.h"
#include "Dodger.h"
#include "Highscore.h"

GameWindow::GameWindow(std::string Nickname) : Nickname(Nickname)
{
  DisplaySurface = SDL_GetVideoSurface();
  HeartSurface = load_image("./gfx/heart.bmp");
  BombSurface = load_image("./gfx/bomb.bmp");
  NumberOfEnemies = 2;
  CurrentLevel = 1;

  Running = true;
}

GameWindow::~GameWindow()
{ }

SDL_Surface* GameWindow::load_image(std::string File)
{
	SDL_Surface* Surf_Temp = NULL;
	SDL_Surface* Surface = NULL;
 
	Surf_Temp = SDL_LoadBMP(File.c_str());
 
	Surface = SDL_DisplayFormat(Surf_Temp);
	SDL_SetColorKey(Surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, 
									SDL_MapRGB(Surface->format, 255, 0, 0));

	SDL_FreeSurface(Surf_Temp);

	return Surface;
}

void GameWindow::CleanupSDL()
{
  Entity::EntityList.clear();
  Enemy::EnemyList.clear();
  SDL_FreeSurface(HeartSurface);
}

void GameWindow::on_event(SDL_Event* EventInput)
{
	// Check for keyboard events
	if (EventInput->type == SDL_KEYDOWN) {
		// If escape, exit gameloop
		if (EventInput->key.keysym.sym == SDLK_ESCAPE) {
			Running = false;
		}
	}
}

void GameWindow::spawn_powerup() 
{
	// 40 is witdh and height of the powerup
	int X = rand() % (800 - 40);
	int Y = rand() % (600 - 40);

	int ChooseType = rand() % 3;
	std::string Type;

	// Check at collision what type to boost the p with
	switch(ChooseType) {
		case 0:
			Type = "Bomb";
			break;

		case 1:
			Type = "Life";
			break;
	}

	// Randomize a spawntime (max 300 updates/18 Seconds @ 60 FPS)
	int Lifetime = rand() % 300;

	new Powerups(X, Y, Lifetime, Type);
}

// Spawn an enemy
void GameWindow::spawn_enemy(int X, int Y)
{
	int SpawnX;
	int SpawnY;

	SpawnX = rand() % 800;
	SpawnY = rand() % 600;

	int SpawnDistance = 50;

	while (SpawnX < (X + SpawnDistance) && SpawnX > (X - SpawnDistance))
		SpawnX = rand() % 800;

	while (SpawnY < (Y + SpawnDistance) && SpawnY > (Y - SpawnDistance))
		SpawnY = rand() % 600;

	if (rand() % 2 == 0)
		new Stalker(SpawnX, SpawnY);
	else
		new Dodger(SpawnX, SpawnY);
}

void GameWindow::run_game(bool HardcoreMode)
{
	Player *p = new Player();
	std::list<Entity *>::iterator it;

	Draw *d = new Draw();

	Highscore *s = new Highscore();

	int TimeWhenHit;
	int TimeWhenShieldOff;

	time_t Seconds;

  while (Running && p->get_lives() > 0)
	{
		Seconds = time(NULL);

		// Get all events
    while (SDL_PollEvent(&Events))
		{
    	on_event(&Events);
			p->check_events(Events);
		}
		
		// Randomize a bomb
		int RandomNumber = rand() % 5000;
		if (RandomNumber == 42)
			spawn_powerup();

		// Levels
		CurrentLevel = (1 + floor(s->get_current_score() / 1000));

		if (NumberOfEnemies != (CurrentLevel*2) && s->get_current_score() != 0)
			NumberOfEnemies += 1;

		// Set the shield off when it has reached it has reached timeWhenShieldOff
		if (Seconds >= TimeWhenShieldOff)
			p->set_shield_up(false);

		// Set max enemys on the playfield
		if (Enemy::EnemyList.size() < NumberOfEnemies)
			spawn_enemy(p->SurfaceRectangle.x, p->SurfaceRectangle.y);

		// Check for collisions
		for (it = Entity::EntityList.begin(); it != Entity::EntityList.end(); it++) 
		{
			if (Enemy::EnemyList.size() != 0)
			{
				std::list<Enemy *>::iterator eit = Enemy::EnemyList.begin();
				for (; eit != Enemy::EnemyList.end(); eit++) 
				{
					// If a projectile collides with an enemy
					if ((*it)->get_type() == "Projectile" && (*eit)->has_collided((*it)->SurfaceRectangle)) 
					{
						// Set the p's currentScore depending on which enemy type that's killed
						if ((*eit)->get_type() == "Stalker")
							s->add_to_current_score(100);
						else if ((*eit)->get_type() == "Dodger")
							s->add_to_current_score(200);

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
								eit = Enemy::EnemyList.erase(eit);
								it2 = Entity::EntityList.erase(it2);
								delete del2;
								it = Entity::EntityList.begin();
							}
						}

					}
					// If the enemy collided with the p
					else if ((*eit)->has_collided(p->SurfaceRectangle)) {
						std::list<Entity*>::iterator it2 = Entity::EntityList.begin();
						for (; it2 != Entity::EntityList.end(); it2++) {
							if (*it2 == *eit)
							{
								// If the shield is up the p wont loose lifes when getting hit
									Entity *del2 = *it2;
									eit = Enemy::EnemyList.erase(eit);
									it2 = Entity::EntityList.erase(it2);
									delete del2;
									it = Entity::EntityList.begin();
								if (!p->get_shield_up())
								{
									p->set_lives(-1);

									// Change the number to decide how long the shield is activated, in Seconds
									TimeWhenHit = Seconds;
									TimeWhenShieldOff = Seconds + 5;

									p->set_shield_up(true);
								}
							}
						}
					} // Ends the enemy-collided-If
				}
			}

			// If the p has collided with a powerup
			if ((*it)->get_type() == "Bomb") {
				Powerups *pu = dynamic_cast<Powerups *>(*it);
	
				// If the collided
				if ((*it)->has_collided(p->SurfaceRectangle)) {
					pu->set_counter(-1);
					p->add_bombs();
				}
	
				if (pu->has_expired()) {
					it = Entity::EntityList.erase(it);
					it = Entity::EntityList.begin();
					delete pu;
				}
			}
			else if ((*it)->get_type() == "Life") {
				Powerups *pu = dynamic_cast<Powerups *>(*it);

				// If they collided
				if (pu->has_collided(p->SurfaceRectangle)) {
					pu->set_counter(-1);
					p->set_lives(1);
				}

				if (pu->has_expired()) {
					it = Entity::EntityList.erase(it);
					it = Entity::EntityList.begin();
					delete pu;
				}
			}
		}

		// Give all stalker-enemies the position of the p
		std::list<Enemy *>::iterator EnemyIterator;
		for (EnemyIterator = Enemy::EnemyList.begin(); 
				 EnemyIterator != Enemy::EnemyList.end(); EnemyIterator++) {
			if ((*EnemyIterator)->get_type() == "Stalker") {
				(*EnemyIterator)->set_chase(p->SurfaceRectangle);
			}
			else if ((*EnemyIterator)->get_type() == "Dodger") {
				it = Entity::EntityList.begin();

				SDL_Rect dodge;
				// Check if there's an projectile on the screen
				for (it = Entity::EntityList.begin(); it != Entity::EntityList.end(); it++) {
					if ((*it)->get_type() == "Projectile") {
						dodge = (*it)->SurfaceRectangle;
					}
				}

				// If there's prjectiles on the screen, else chase p
				Dodger *d = dynamic_cast<Dodger*>(*EnemyIterator);
				if (dodge.x != 0 && abs(dodge.x - (*EnemyIterator)->SurfaceRectangle.x) < 50 || 
						dodge.y != 0 && abs(dodge.y - (*EnemyIterator)->SurfaceRectangle.y) < 50)  {
					d->set_dodge(true);
					(*EnemyIterator)->set_chase(dodge);
				}
				else {
					d->set_dodge(false);
					(*EnemyIterator)->set_chase(p->SurfaceRectangle);
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
				if (((*it)->SurfaceRectangle.x < 0 || (*it)->SurfaceRectangle.x > 800) ||
						((*it)->SurfaceRectangle.y < 0 || (*it)->SurfaceRectangle.y > 600)) {
					Entity *del = *it;
					it = Entity::EntityList.erase(it);
					delete del;
				}
			}
		}

		// Draw background
		SDL_FillRect(DisplaySurface, NULL, 0x000000);
	
		// Draw the hearts
		for (int i = 0; i < p->get_lives(); i++)
			d->draw_surface(HeartSurface, DisplaySurface, 25*i, 10);

		// Draw the bombs
		for (int i = 0; i < p->get_bombs(); i++)
			d->draw_surface(BombSurface, DisplaySurface, 25*i, 50);

		// Draw the current Score
		d->draw_text(DisplaySurface, "Score: ", 18, 10, 470, 255, 255, 255);
		int CurrentScore = s->get_current_score();
		std::string ScoreString;
		std::stringstream ScoreStream;
		ScoreStream << CurrentScore;
		ScoreString = ScoreStream.str();
		d->draw_text(DisplaySurface, ScoreString, 18, 10, 550, 255, 255, 255);

		// Draw the current level
		d->draw_text(DisplaySurface, "Lvl: ", 18, 30, 470, 255, 255, 255);
		std::string LevelString;
		std::stringstream LevelStream;
		LevelStream << CurrentLevel;
		LevelString = LevelStream.str();
		d->draw_text(DisplaySurface, LevelString, 18, 30, 550, 255, 255, 255);
		
		// Draw the players initiales
		d->draw_text(DisplaySurface, "Initiales", 18, 555, 10, 9, 9, 9);
		d->draw_text(DisplaySurface, Nickname, 18, 575, 10, 9, 9, 9);

		// If the shield is up it will print it on the screen
		if (p->get_shield_up())
			d->draw_text(DisplaySurface, "SHIELD    IS    UP!", 18, 30, 10, 255, 255, 255);
		// Draw everything
		it = Entity::EntityList.begin();
		for (; it != Entity::EntityList.end(); it++) {
			(*it)->draw(DisplaySurface);
		}

    SDL_Flip(DisplaySurface);

		if (HardcoreMode)
			SDL_Delay(1);
		else
			SDL_Delay(1000/60);
  }

	// If a player exits the game with lives left it wont register any highScore
	if (p->get_lives() == 0)
		s->set_highscore(Nickname, s->get_current_score());

  GameWindow::CleanupSDL();
}
