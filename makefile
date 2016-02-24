CC = g++
LDLIBS = -lglut -lGL -lGLU -lX11 -lm `sdl-config --cflags --libs`  -lSDL_mixer 

OBJ = src/Game.cpp \
      src/ImageLoader.cpp \
      src/Jukebox.cpp \
      src/Menu.cpp
      
All: $(OBJ)
	$(CC) $(OBJ)  $(LDLIBS) -o bin/game
