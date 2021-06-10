WXVERSION = 3.1
WXFLAGS   = $$(wx-config --version=$(WXVERSION) --cxxflags)
WXLIBS    = $$(wx-config --version=$(WXVERSION) --libs all --gl-libs)

MYUSER   = $$(whoami)
MYROOT   = /home/$(MYUSER)/MyRoot/usr

INCDIR   = include
SRCDIR   = src
SRCDIRS  = wxGUI Base Utility
#SRCDIRS  = Base
OBJDIR   = obj
BINDIR   = bin
LIBDIR   = lib
EXEFILE  = wxKitty 


#Source Files to looks for
SOURCES := $(wildcard $(SRCDIRS:%=src/%/*.cpp)) $(wildcard src/*.cpp)



INCLUDES  = -Iinclude -I$(MYROOT)/include
LINKDIR   = -L$(LIBDIR) -L$(MYROOT)/lib
OGLIB     = -lglut -lGL -lGLU
GENLIBS   = #-lSOIL

CXX       = g++
CXXLIBS   =
LDLIBS    = $(LINKDIR) $(WXLIBS) $(DYNLIB) $(OGLIB) $(GENLIBS)


CXXFLAGS  = -Wall $(INCLUDES) --std=c++17 $(WXFLAGS) $(CXXLIBS)
LDFLAGS   = -std=c++11 $(LDLIBS)



#Target specific variables for Debug version.
DFLAG    = -DDEBUG
DBINDIR  =  $(BINDIR)/Debug
DOBJDIR  =  $(OBJDIR)/Debug
DEXE     =  $(DBINDIR)/$(EXEFILE)
DOBJECTS =  $(filter-out $(DOBJDIR)/Test.o, $(addprefix $(DOBJDIR)/,$(SOURCES:$(SRCDIR)/%.cpp=%.o)))

# Test objects
TOBJECTS =  $(filter-out $(DOBJDIR)/wxGUI/KittyWxApp.o,$(DOBJECTS))


#Target specific variables for Release version.
RFLAG    = -DNDEBUG
RBINDIR  =  $(BINDIR)/Release
ROBJDIR  =  $(OBJDIR)/Release
REXE     =  $(RBINDIR)/$(EXEFILE)
ROBJECTS = $(filter-out $(ROBJDIR)/Test.o, $(addprefix $(ROBJDIR)/,$(SOURCES:src/%.cpp=%.o)))


## Default build target Debug
Debug: $(DEXE)


$(DEXE) : $(DOBJECTS) | $(DBINDIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(DOBJDIR)/%.o: $(SRCDIR)/%.cpp | $(DOBJDIR)
	$(CXX) -o $@ -c $< $(DFLAG) $(CXXFLAGS)




Release: $(REXE)

$(REXE) : $(ROBJECTS) | $(RBINDIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(ROBJDIR)/%.o: $(SRCDIR)/%.cpp | $(ROBJDIR)
	$(CXX) -c -o $@ $< $(RFLAG) $(CXXFLAGS)


testrun: test
	exec $(BINDIR)/Test


test: $(DOBJECTS) obj/Test.o
	$(CXX) -o $(BINDIR)/Test $(TOBJECTS) obj/Test.o   $(LDFLAGS)

obj/Test.o: test/Test.cpp
	$(CXX) -c test/Test.cpp -o obj/Test.o $(CXXFLAGS)


$(OBJDIR):
	mkdir $(OBJDIR)

$(BINDIR) :
	mkdir $(BINDIR)


$(DBINDIR): | $(BINDIR)
	mkdir $(DBINDIR)

$(DOBJDIR): | $(OBJDIR)
	mkdir $(DOBJDIR) $(SRCDIRS:%=$(DOBJDIR)/%)


$(RBINDIR): | $(BINDIR)
	mkdir $(RBINDIR)

$(ROBJDIR): | $(OBJDIR)
	mkdir $(ROBJDIR) $(SRCDIRS:%=$(ROBJDIR)/%)



clean:
	rm obj/Test.o
	rm -rf $(DOBJECTS) $(DEXE)

cleanDebug:
	rm $(DOBJECTS) $(DEXE)

cleanRelease:
	rm $(ROBJECTS) $(REXE)

## Include auto-generated dependencies rules
-include $(DOBJECTS:.o=.d)
