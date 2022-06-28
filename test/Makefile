TOP = ..
CC ?= gcc

TESTS =

CFLAGS = -I$(TOP) -g

LDFLAGS = -L$(TOP)
LDLIBS  = -lcog-utils

all: $(TESTS)

clean:
	@ rm -f $(TESTS)

.PHONY: clean
