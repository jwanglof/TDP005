#include "Powerups.h"

Powerups::Powerups(int x, int y, int live_time, std::string type) 
					: Entity("./gfx/random.bmp"), type(type), counter(live_time)
{
	surfaceRectangle.x = x;
	surfaceRectangle.y = y;
	surfaceRectangle.w = 40;
	surfaceRectangle.h = 40;
}

Powerups::~Powerups()
{ }

void Powerups::move()
{
	// Just tick down the counter instead of moving it
	counter--;
}

std::string Powerups::get_type() 
{
	return type;
}

bool Powerups::has_expired()
{
	return (counter < 0);
}

void Powerups::set_counter(int new_value)
{
	counter = new_value;
}
