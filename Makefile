CC = g++
CFLAGS = -std=c++11 `wx-config --version=2.8 --cxxflags` -Wall -Iinclude -I/home/pranphy/MyRoot/include/SOIL
LINKDIR = /home/pranphy/MyRoot/lib/
LINKER = `wx-config --version=2.8 --libs --gl-libs` -L$(LINKDIR) -lglut -lGL -lGLU -lSOIL 
SRCDIR = src
OBJDIR = obj/Debug
SOURCE =  $(SRCDIR)/CardStuffs.cpp\
		  $(SRCDIR)/DisplayCanvas.cpp\
		  $(SRCDIR)/Mathematical.cpp\
		  $(SRCDIR)/ScoresAndDisplays.cpp\
		  $(SRCDIR)/KittyWxMain.cpp\
		  $(SRCDIR)/KittyWxApp.cpp\
		  $(SRCDIR)/common.cpp

OBJECT=   $(OBJDIR)/CardStuffs.o\
		  $(OBJDIR)/DisplayCanvas.o\
		  $(OBJDIR)/Mathematical.o\
		  $(OBJDIR)/ScoresAndDisplays.o\
		  $(OBJDIR)/KittyWxApp.o\
		  $(OBJDIR)/KittyWxMain.o\
		  $(OBJDIR)/common.o

EXE = bin/Debug/KittyWx

$(EXE):$(OBJECT)
	$(CC) -o $@ $^ $(LINKER)
$(OBJECT):$(SOURCE)
	$(CC) $(CFLAGS) -c $^
	mv *.o obj/Debug
clean:
	rm $(OBJECT) $(EXE)
