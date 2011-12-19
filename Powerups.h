#include "Entity.h"

class Powerups : public Entity
{
	private:
		int counter;
		std::string type;
	public:
		Powerups(int, int, int, std::string);
		~Powerups();

		void move();
		std::string get_type();
		void set_counter(int);
		bool has_expired();
};
