CC=cc
AR=ar
OBJS=cog-utils.o json-actor.o log.o ntl.o json-actor-boxed.o json-string.o \
     logconf.o specs-gen.o
LIBS=libcogutils.a

.SUFFIXES: .c .o

.c.o:
	$(CC) -c $< 

all: $(LIBS)

$(LIBS): $(OBJS)
	$(AR) cr libcogutils.a $(OBJS)

.PHONY: clean

clean:
	rm -rf $(LIBS) $(OBJS)
