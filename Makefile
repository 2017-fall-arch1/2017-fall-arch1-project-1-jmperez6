all: BSTDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

BSTDemo: Project1.o Project1Demo.o
	cc -o $@ $^

Project1.o: Project1.c Project1.h
	cc -c $(CFLAGS) Project1.c

Project1Demo.o: Project1Demo.c Project1.h
	cc -c $(CFLAGS) Project1Demo.c

clean:
	rm -f *.o BSTDemo

demo: BSTDemo
	./BSTDemo
