#include "MainMenu.h"

int main()
{
	MainMenu *n = new MainMenu("");
	n->run_menu();
	delete n;
	n = 0;

	return 0;
}
