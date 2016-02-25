#################################################
## Filename:   makefile
## Author:     Daniel Guenther
## Sources:    Dr. J's makefile, but also partly inspired
##                by the makefile used in the JJAMBA lab
## Date:       2016-02-24
## Class:      CSCI 331
## Project:    Kitty Pirateer
## 
## Purpose: 
##    compile the project
###################################################

# compiler and flags
CC = g++
CFLAGS =
LDLIBS = -lSOIL -lglut -lGLU -lGL -lX11 -lm `sdl-config --cflags --libs`  -lSDL_mixer 

# list of source files
SRCDIR=src
SRCNAMES=Menu.cpp \
    ImageLoader.cpp \
    Jukebox.cpp \
    HUD.cpp \
    HealthHUD.cpp \
    Game.cpp
SRC=$(addprefix $(SRCDIR)/,$(SRCNAMES))

# list of object files to be created
OBJDIR=obj
OBJ=$(addprefix $(OBJDIR)/,$(SRCNAMES:.cpp=.o))

# Executeable targets
EXE=bin/game
      
all: bin $(OBJDIR) $(SRC) $(EXE)

bin:
	mkdir bin

$(OBJDIR):
	mkdir $(OBJDIR)

$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $< -o $@
