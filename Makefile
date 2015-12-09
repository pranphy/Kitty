#CC = /usr/bin/i586-mingw32msvc-g++


WXVERSION = 3.0
WXFLAGS   = `wx-config --version=$(WXVERSION) --cxxflags`
WXLIBS    = `wx-config --version=$(WXVERSION) --libs all --gl-libs`

INCDIR   = include
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
LIBDIR   = lib
EXEFILE  = KittyWx 

CC = g++


INCLUDES  =  -I./include -I/opt/include
#DYNLIB    =  -Wl,-rpath='$$ORIGIN/../../lib' -lwxcode_gtk2u_wxsqlite3-3.0
OGLIB     =  -lglut -lGLU -lGL -lSOIL -lpng


FLAGS     =  -Wall -g -Os -std=c++11  $(INCLUDES) $(WXFLAGS) 
LINKER    =  -L$(LIBDIR) -L/opt/lib $(WXLIBS) $(DYNLIB) $(OGLIB) 

HEADERS   =   $(shell find . -name '*.h')
SOURCE    =   $(shell find ./src -name '*.cpp')


#Target specific variables for Debug version.
DFLAG    = -DDEBUG
DBINDIR  =  bin/Debug
DOBJDIR  =  obj/Debug
DEXE     =  $(DBINDIR)/$(EXEFILE)
DOBJECTS = $(shell echo $(SOURCE) | sed s%$(SRCDIR)%$(DOBJDIR)%g | sed s/.cpp/.o/g )


#Target Specific variables for Release Version
RFLAG    = -DNDEBUG
RBINDIR  =  bin/Release
REXE     =  $(RBINDIR)/$(EXEFILE)
ROBJDIR  =  obj/Release
ROBJECTS = $(shell echo $(SOURCE) | sed s%$(SRCDIR)%$(ROBJDIR)%g | sed s/.cpp/.o/g)


#Default build is Debug
Debug:$(DEXE)
	
$(DEXE):$(DOBJECTS)
	mkdir -p bin $(DBINDIR)
	$(CC) -o $(DEXE) $(DOBJECTS) $(LINKER)

.ONESHELL:
$(DOBJECTS): $(SOURCE) $(HEADERS)
	mkdir -p obj $(DOBJDIR)
	for File in $(SOURCE)
	do
		$(CC) $(FLAGS) $(DFLAG) $(INCLUDE) -c $$File -o `echo $$File | sed s/.cpp/.o/g | sed s%$(SRCDIR)%$(DOBJDIR)%g`
	done


#Exact replica for release build
Release: $(REXE)

$(REXE):$(ROBJECTS)
	mkdir -p bin $(RBINDIR)
	$(CC) -o $(REXE) $(ROBJECTS) $(LINKER)

.ONESHELL:
$(ROBJECTS): $(SOURCE) $(HEADERS)
	mkdir -p obj $(ROBJDIR)
	for File in $(SOURCE)
	do
		$(CC) $(FLAGS) $(RFLAG) $(INCLUDE) -c $$File -o `echo $$File | sed s/.cpp/.o/g | sed s%$(SRCDIR)%$(ROBJDIR)%g`
	done
	
clean:
	rm  -f $(DOBJECTS) $(DEXE) $(ROBJECTS) $(REXE)
