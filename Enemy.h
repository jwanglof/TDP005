#include "Entity.h"

class Enemy : public Entity
{
	private:
		int velocity;
	public:
		Enemy(double, double);
		~Enemy();

		void move();
		std::string get_type();
};
