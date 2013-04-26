
TARGETOS := 10.7

export MACOSX_DEPLOYMENT_TARGET=$(TARGETOS)

DEBUGFLAGS := -O3 -g

CFLAGS := -Wall -Wextra $(DEBUGFLAGS)
CPPFLAGS := $(CFLAGS)
LDFLAGS := -lc++ -lstdc++

TOOL := happychecker

ALLBINS := $(TOOL)
TARGBINS := $(ALLBINS)

TOOLOBJS := happychecker.o happynum1.o happynum2.o happynum3.o

ALLOBJS = $(TOOLOBJS)

.PHONY: all clean

all : happychecker

$(TOOL) : $(TOOLOBJS)

happynum1.o : happynum1.cpp happynum1.h

happynum2.o : happynum1.cpp happynum2.h

happynum3.o : happynum1.cpp happynum2.h

happychecker.o : happychecker.cpp happynum1.h happynum2.h happynum3.h

clean:
	rm -f $(ALLOBJS); rm $(ALLBINS)
