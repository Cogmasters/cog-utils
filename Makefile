CC = cc

OBJS = cog-utils.o

ARLIB   = libcog-utils.a
ARFLAGS = -cqsv

all: $(ARLIB)

$(ARLIB): $(OBJS)
	$(AR) $(ARFLAGS) $@ $<

clean:
	@ $(RM) $(ARLIB) $(OBJS)

.PHONY: clean
