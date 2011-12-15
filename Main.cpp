#include "Nickname.h"

int main()
{
	Nickname* n = new Nickname;
	n->RunNickname();

	delete n;
	n = 0;

	return 0;
}
