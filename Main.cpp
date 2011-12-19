#include "MainMenu.h"

int main()
{
	MainMenu *n = new MainMenu("");
	n->RunMenu();
	delete n;
	n = 0;

	return 0;
}
