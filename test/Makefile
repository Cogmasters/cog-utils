OBJS=specs-gen.o test-json-actor.o test-json-extract-inject.o test-json-extractor.o \
test-json-injector-1.o test-json-injector.o test-json-string.o test-logconf.o \
test-ns.o test-ntl.o test-spec.o

PROGS=specs-gen test-json-actor test-json-extract-inject test-json-extractor \
test-json-injector-1 test-json-injector test-json-string test-logconf \
test-ns test-ntl test-spec

CC=cc

.SUFFIXES: .c .o

.c.o:
	$(CC) -I.. -c $<

$(PROGS): $(OBJS)
	$(CC) -L.. -lcog-utils -o specs-gen specs-gen.o
	$(CC) -L.. -lcog-utils -o test-json-actor test-json-actor.o
	$(CC) -L.. -lcog-utils -o test-json-extract-inject test-json-extract-inject.o
	$(CC) -L.. -lcog-utils -o test-json-extractor test-json-extractor.o
	$(CC) -L.. -lcog-utils -o test-json-injector-1 test-json-injector-1.o
	$(CC) -L.. -lcog-utils -o test-json-injector test-json-injector.o
	$(CC) -L.. -lcog-utils -o test-json-string test-json-string.o
	$(CC) -L.. -lcog-utils -o test-logconf test-logconf.o
	$(CC) -L.. -lcog-utils -o test-ns test-ns.o
	$(CC) -L.. -lcog-utils -o test-ntl test-ntl.o
	$(CC) -L.. -lcog-utils -o test-spec test-spec.o