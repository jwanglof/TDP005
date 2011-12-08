#include "Entity.h"
#include "Projectile.h"

#include <map>
#include <vector>

class Player : public Entity
{
	private:
		std::map<std::string, bool> isPressed;
		int velocity;
		int lives;
	public:
		void move();
		void check_events(SDL_Event&);
		std::string get_type();
		Player();
		~Player();
		int get_lives() const;
		void set_lives(int);
};
