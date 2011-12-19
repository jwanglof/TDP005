#ifndef POWERUPS_H_
#define POWERUPS_H_

#include "Entity.h"

class Powerups : public Entity
{
	private:
		/*
		 * The amount of loops the powerup is shown before it gets removed
		 */
		int counter;

		/*
		 * Sets what type of powerup it is
		 */
		std::string type;
	public:
		Powerups(int, int, int, std::string);
		~Powerups();

		/*
		 * Virtual from Entity
		 */
		void move();

		std::string get_type();
		void set_counter(int);

		/*
		 * Returns false if count < 0
		 */
		bool has_expired();
};

#endif
