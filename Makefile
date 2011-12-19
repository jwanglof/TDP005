Super : Main.cpp Nickname.o
	g++ -o Super -lSDL -lSDL_ttf Main.cpp *.o

Nickname.o : Nickname.cpp MainMenu.o Draw.o
<<<<<<< HEAD
	g++ -c -lSDL -lSDL_ttf -lSDL_image Nickname.cpp
=======
	g++ -c -lSDL -lSDL_ttf Nickname.cpp GameWindow.o
>>>>>>> ee561c82c0ba10556e8044014bf10375e6e77009

Draw.o : Draw.cpp
	g++ -c Draw.cpp

<<<<<<< HEAD
GameWindow.o : GameWindow.cpp Player.o Stalker.o Dodger.o Highscore.o Powerups.o
	g++ -c -lSDL -lSDL_ttf -lSDL_image GameWindow.cpp
=======
GameWindow.o : GameWindow.cpp Player.o Stalker.o Dodger.o Highscore.o
	g++ -c -lSDL -lSDL_ttf GameWindow.cpp
>>>>>>> ee561c82c0ba10556e8044014bf10375e6e77009

MainMenu.o : MainMenu.cpp GameWindow.o
	g++ -c MainMenu.cpp 

Powerups.o : Powerups.cpp Powerups.h Entity.o
	g++ -c Powerups.cpp

Player.o : Player.cpp Projectile.o Entity.o
	g++ -c Player.cpp

Dodger.o : Dodger.cpp Enemy.o
	g++ -c Dodger.cpp

Stalker.o : Stalker.cpp Enemy.o
	g++ -c Stalker.cpp

Enemy.o : Enemy.cpp Entity.o
	g++ -c Enemy.cpp

Projectile.o : Projectile.cpp Entity.o
	g++ -c Projectile.cpp

Entity.o : Entity.cpp
	g++ -c Entity.cpp

Highscore.o : Highscore.cpp
	g++ -c Highscore.cpp

clean :
	rm Super *.o
