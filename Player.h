#include "Entity.h"
#include "Projectile.h"

#include <map>
#include <vector>

class Player : public Entity
{
	private:
		std::map<std::string, bool> isPressed;
		int velocity;
	public:
		void move();
		void check_events(SDL_Event&);
		std::string get_type();
		Player();
		~Player();
};
