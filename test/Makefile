TOP = ..

CC = cc

OBJS  = test-logconf.o
PROGS = test-logconf

CFLAGS = -I$(TOP) -g
LFLAGS = -L$(TOP) -lcogutils

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c $<

$(PROGS): $(OBJS)
	$(CC) $(CFLAGS) -o test-logconf test-logconf.o $(LFLAGS)
