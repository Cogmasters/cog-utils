CC = cc

OBJS = cog-utils.o

ARLIB   = libcog-utils.a
ARFLAGS = -cqsv

all: $(ARLIB)

$(ARLIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

clean:
	@ rm -f $(ARLIB) $(OBJS)

.PHONY: clean
