#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"

#include <iostream>
#include <vector>

class Entity
{
	private:
		static std::vector<Entity *> EntityList;
		SDL_Surface *surface;
		bool right;
	public:
		Entity();
		~Entity();

		bool loadSurface(std::string File);
		virtual void move();
		void draw(SDL_Surface*);

		float x;
		float y;
		int width;
		int height;
};
