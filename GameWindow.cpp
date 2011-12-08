#include "GameWindow.h"
#include "Player.h"
#include "Enemy.h"

GameWindow::GameWindow(SDL_Surface* screen, SDL_Event& events)
{
  displaySurface = screen;
  SDLEvent = events;
  numberOfEnemies = 4;
  heartSurface = loadImage("./gfx/heart.png");
  

  running = true;
}

GameWindow::~GameWindow()
{ }

SDL_Surface* GameWindow::loadImage(std::string imagePath)
{
  SDL_Surface* originImage = NULL;
  SDL_Surface* returnImage = NULL;

  if ((originImage = IMG_Load(imagePath.c_str())) == NULL)
    return false;

  returnImage = SDL_DisplayFormat(originImage);
  SDL_FreeSurface(originImage);

  return returnImage;
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
	if (x > 750)
		x = 600;
	if (y > 550)
		y = 400;

	int spawnDistance = 200;

	// Randomize some coordinates that's < 100px from the edge
	if (rand() % 2 == 0 && (x - spawnDistance > 0))
		x -= spawnDistance;
	else 
		x += spawnDistance;

	if (rand() % 2 == 0 && (y - spawnDistance > 0))
		y -= spawnDistance;
	else 
		y += spawnDistance;

	//std::cout << "x: " << x << std::endl;
	//std::cout << "y: " << y << std::endl;

	new Enemy(x, y);
}

int GameWindow::runGame()
{

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    return false;

  if ((displaySurface = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return false;

	Player *p = new Player();
	std::list<Entity *>::iterator it;

  while (running && p->get_lives() > 0)
  {
	// Get all events
    while (SDL_PollEvent(&SDLEvent)) {
    	onEvent(&SDLEvent);
		p->check_events(SDLEvent);
	}

	//std::cout << Entity::EntityList.size() << std::endl;

	// Set max enemys on the playfield
	if (Enemy::enemyList.size() <= numberOfEnemies)
		spawnEnemy(p->surfaceRectangle.x, p->surfaceRectangle.y);

	// Check for collisions
	for (it = Entity::EntityList.begin(); it != Entity::EntityList.end(); it++) {
		/* if ((*it)->hasCollided((*it)->surfaceRectangle, e->surfaceRectangle) && (*it)->get_type() != e->get_type()) {
			Entity *del = *it;
			it = Entity::EntityList.erase(it);
			delete del;
		} */
		if (Enemy::enemyList.size() != 0)
		{
			std::list<Enemy *>::iterator eit = Enemy::enemyList.begin();
			for (; eit != Enemy::enemyList.end(); eit++) 
			{
				// If a projectile collides with an enemy
				if ((*it)->get_type() == "Projectile" && (*eit)->hasCollided((*it)->surfaceRectangle)) 
				{
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

				/*Enemy *enemy_del = *eit;
				std::cerr << "3" << std::endl;
				eit = Enemy::enemyList.erase(eit);
				std::cerr << "4" << std::endl;

				std::cerr << "5" << std::endl;
				delete enemy_del;
				std::cerr << "6" << std::endl; */
				}
				else if ((*eit)->hasCollided(p->surfaceRectangle)) {
					std::list<Entity*>::iterator it2 = Entity::EntityList.begin();
					for (; it2 != Entity::EntityList.end(); it2++) {
						if (*it2 == *eit) 
						{
							Entity *del2 = *it2;
							eit = Enemy::enemyList.erase(eit);
							it2 = Entity::EntityList.erase(it2);
							delete del2;
							it = Entity::EntityList.begin();
							p->set_lives(-1);
							std::cout << p->get_lives() << std::endl;
						}
					}
				} // Ends If

			}
		}
	}

	// Give all stalker-enemies the position of the player
	std::list<Enemy *>::iterator enemy_iterator;
	for (enemy_iterator = Enemy::enemyList.begin(); 
			enemy_iterator != Enemy::enemyList.end(); enemy_iterator++) {
		(*enemy_iterator)->set_chase(p->surfaceRectangle);
		//std::cout << (*enemy_iterator)->surfaceRectangle.x << " | y: " << (*enemy_iterator)->surfaceRectangle.y << std::endl;
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
	for (int i = 0; i < p->get_lives(); i++)
		drawSurface(displaySurface, heartSurface, 60*i, 10);

	// Draw everything
	it = Entity::EntityList.begin();
	for (; it != Entity::EntityList.end(); it++) {
		(*it)->draw(displaySurface);
	}

    SDL_Flip(displaySurface);
	SDL_Delay(1000/100);
  }

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
