Super : MainMenu.cpp GameWindow.o
	g++ -o Super -lSDL_ttf -lSDL_image MainMenu.cpp *.o

GameWindow.o : GameWindow.cpp GameWindow_score.o Player.o Enemy.o
	g++ -c -lSDL_ttf -lSDL_image GameWindow.cpp *.o

GameWindow_score.o : GameWindow_score.cpp
	g++ -c GameWindow_score.cpp

Player.o : Player.cpp Projectile.o Entity.o
	g++ -c Player.cpp Projectile.o Entity.o

Enemy.o : Enemy.cpp Entity.o
	g++ -c Enemy.cpp Entity.o

Projectile.o : Projectile.cpp Entity.o
	g++ -c Projectile.cpp Entity.o

Entity.o : Entity.cpp
	g++ -c Entity.cpp

clean :
	rm Super *.o
