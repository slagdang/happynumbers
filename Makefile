
TARGETOS := 10.7

export MACOSX_DEPLOYMENT_TARGET=$(TARGETOS)

DEBUGFLAGS := -O3 -g

CFLAGS := -Wall -Wextra $(DEBUGFLAGS)
CPPFLAGS := $(CFLAGS)
LDFLAGS := -lc++ -lstdc++

TOOL := happychecker
TOOL2 := smallestgrowerfinder

TOOLOBJS := happychecker.o happynum1.o happynum2.o happynum3.o
TOOL2OBJS := smallestgrowerfinder.o

ALLBINS := $(TOOL) $(TOOL2)
ALLOBJS = $(TOOLOBJS) $(TOOL2OBJS)

.PHONY: all clean

all : $(ALLBINS)

$(TOOL) : $(TOOLOBJS)

$(TOOL2) : $(TOOL2OBJS)

happynum1.o : happynum1.cpp happynum1.h

happynum2.o : happynum1.cpp happynum2.h

happynum3.o : happynum1.cpp happynum2.h

happychecker.o : happychecker.cpp happynum1.h happynum2.h happynum3.h

smallestgrowerfinder.o : smallestgrowerfinder.cpp

clean:
	rm -f $(ALLOBJS); rm $(ALLBINS)
