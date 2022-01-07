# This Makefile assumes the top folder has been built

TOP = ..
CC ?= gcc

OBJDIR     := $(TOP)/obj

OBJS   ?= $(wildcard $(OBJDIR)/*.o)

TEST_JSON    := test-json-extract-inject \
                test-json-extractor \
                test-json-injector-1 \
                test-json-injector \
                test-json-string

TEST_LOGCONF := test-logconf

TEST_NTL     := test-ntl

TEST_SPECS   := test-ns \
                test-json-struct \
                test-spec

EXES := $(TEST_JSON) $(TEST_LOGCONF) $(TEST_NTL)

CFLAGS  += -I$(TOP) -O0 -g -pthread -Wall
LDFLAGS += -lm

all: $(EXES)

$(EXES): %: %.c $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)


echo:
	@ echo -e 'CC: $(CC)\n'
	@ echo -e 'EXES: $(EXES)\n'
	@ echo -e 'OBJS: $(OBJS)\n'

clean:
	rm -rf $(EXES)

.PHONY: all echo clean
