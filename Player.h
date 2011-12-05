#include "Entity.h"

class Player : public Entity
{
	private:
		SDL_Surface *surface;
		SDL_Event Event;
	public:
		void move(SDL_Event *event);
		Player();
		~Player();
};
