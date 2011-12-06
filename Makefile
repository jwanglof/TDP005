GameWindow : GameWindow.cpp GameWindow_score.o Player.o
	g++ -o GameWindow -lSDL_ttf -lSDL_image GameWindow.cpp *.o

GameWindow_score.o : GameWindow_score.cpp
	g++ -c GameWindow_score.cpp

Player.o : Player.cpp Projectile.o Entity.o
	g++ -c Player.cpp Projectile.o Entity.o

Projectile.o : Projectile.cpp Entity.o
	g++ -c Projectile.cpp Entity.o

Entity.o : Entity.cpp
	g++ -c Entity.cpp

clean :
	rm GameWindow *.o
