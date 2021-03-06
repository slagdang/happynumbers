
TARGETOS := 10.7

export MACOSX_DEPLOYMENT_TARGET=$(TARGETOS)

DEBUGFLAGS := -O4 -g
DEBUGLFLAGS := -O4

ARCHFLAGS := 

CFLAGS := -Wall -Wextra $(ARCHFLAGS) $(DEBUGFLAGS)
CPPFLAGS := $(CFLAGS)
LDFLAGS := -lc++ -lstdc++ $(ARCHFLAGS) $(DEBUGLFLAGS)

TOOL := happychecker
TOOL2 := smallestgrowerfinder
TOOL3 := calculatemaxtraverse

ALGOOBJS := happynum1.o happynum2.o happynum3.o happynum4.o happynum5.o happynum6.o happynum7.o
TOOLOBJS := happychecker.o happynum5.o
TOOL2OBJS := smallestgrowerfinder.o
TOOL3OBJS := calculatemaxtraverse.o

ALLBINS := $(TOOL) $(TOOL2) $(TOOL3)
ALLOBJS := $(TOOLOBJS) $(TOOL2OBJS) $(TOOL3OBJS) $(ALGOOBJS)

.PHONY: all clean allalgorithms

all : $(ALLBINS)

allalgorithms : $(ALGOOBJS)

$(TOOL) : $(TOOLOBJS)

$(TOOL2) : $(TOOL2OBJS)

$(TOOL3) : $(TOOL3OBJS)

happynum1.o : happynum1.cpp happynum.h

happynum2.o : happynum2.cpp happynum.h

happynum3.o : happynum3.cpp happynum.h

happynum4.o : happynum4.cpp happynum.h

happynum5.o : happynum5.cpp happynum.h

happynum6.o : happynum6.cpp happynum.h

happynum7.o : happynum7.cpp happynum.h

happychecker.o : happychecker.cpp happynum.h

smallestgrowerfinder.o : smallestgrowerfinder.cpp

calculatemaxtraverse.o : calculatemaxtraverse.cpp

clean:
	rm -f $(ALLOBJS)

distclean: clean
	rm -f $(ALLBINS)
