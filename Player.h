#include "Entity.h"
#include "Projectile.h"

#include <map>
#include <vector>

class Player : public Entity
{
	private:
		std::map<std::string, bool> isPressed;
		std::vector<Projectile *> projectiles;
		int velocity;
	public:
		void move();
		void check_events(SDL_Event&);
		Player();
		~Player();
};
