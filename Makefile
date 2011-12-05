GameWindow : GameWindow.cpp GameWindow_score.o
	g++ -o GameWindow -lSDL_ttf -lSDL_image GameWindow.cpp *.o

GameWindow_score.o : GameWindow_score.cpp
	g++ -c GameWindow_score.cpp

clean :
	rm GameWindow 