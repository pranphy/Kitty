WXFLAGS   = $$(wx-config --cxxflags)
WXLIBS    = $$(wx-config --libs core)

MYUSER   = $$(whoami)

INCDIR   = include
SRCDIR   = src
MAINDIR  = wxGUI
#MAINDIR  = TUI
SRCDIRS  = $(MAINDIR) Base Utility
#SRCDIRS  = Base
OBJDIR   = obj
BINDIR   = bin
LIBDIR   = lib
EXEFILE  = wxKitty


#Source Files to looks for
SOURCES := $(wildcard $(SRCDIRS:%=src/%/*.cpp)) $(wildcard src/*.cpp)



INCLUDES  = -Iinclude
LINKDIR   = -L$(LIBDIR)
OGLIB     = 
GENLIBS   =

CXX       = g++
CXXLIBS   =
LDLIBS    = $(LINKDIR) $(WXLIBS) $(DYNLIB) $(OGLIB) $(GENLIBS)


CXXFLAGS  = -Wall $(INCLUDES) --std=c++23 $(WXFLAGS) $(CXXLIBS)
LDFLAGS   = -std=c++23 $(LDLIBS)



#Target specific variables for Debug version.
DFLAG    = -DDEBUG
DBINDIR  =  $(BINDIR)/Debug
DOBJDIR  =  $(OBJDIR)/Debug
DEXE     =  $(DBINDIR)/$(EXEFILE)
DOBJECTS =  $(filter-out $(DOBJDIR)/Test.o, $(addprefix $(DOBJDIR)/,$(SOURCES:$(SRCDIR)/%.cpp=%.o)))

# Test objects
TOBJECTS =  $(filter-out $(DOBJDIR)/$(MAINDIR)/%App.o,$(DOBJECTS))


#Target specific variables for Release version.
RFLAG    = -DNDEBUG
RBINDIR  =  $(BINDIR)/Release
ROBJDIR  =  $(OBJDIR)/Release
REXE     =  $(RBINDIR)/$(EXEFILE)
ROBJECTS = $(filter-out $(ROBJDIR)/Test.o, $(addprefix $(ROBJDIR)/,$(SOURCES:src/%.cpp=%.o)))

# Test



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
	rm -rf obj/
	rm -rf $(DOBJECTS) $(DEXE)
	rm -rf $(ROBJECTS) $(REXE)

cleanDebug:
	rm $(DOBJECTS) $(DEXE)

cleanRelease:
	rm $(ROBJECTS) $(REXE)

## Include auto-generated dependencies rules
-include $(DOBJECTS:.o=.d)
