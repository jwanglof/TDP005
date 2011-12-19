#ifndef PLAYER_H_
#define PLAYER_H_

#include <map>
#include <vector>

#include "Entity.h"
#include "Projectile.h"
#include "Enemy.h"

class Player : public Entity
{
private:
	std::map<std::string, bool> isPressed;
	int velocity;
	int lives;

	bool shieldUp;
public:
	void move();
	void check_events(SDL_Event&);
	std::string get_type();
	Player();
	~Player();
	int get_lives() const;
	void set_lives(int);

	bool getShieldUp();
	void setShieldUp(bool);
};

#endif
