CC = cc
AR = ar

OBJS = cog-utils.o log.o logconf.o jsmn-find.o json-build.o
LIBS = libcogutils.a

.SUFFIXES: .c .o

.c.o:
	$(CC) -c $< 

all: $(LIBS)

$(LIBS): $(OBJS)
	$(AR) cr libcogutils.a $(OBJS)

.PHONY: clean

clean:
	rm -rf $(LIBS) $(OBJS)
