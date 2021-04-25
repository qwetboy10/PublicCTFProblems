CC=gcc

all:
	gcc -c -fPIC -o libflag.o src/libflag.c
	gcc -shared -o libflag.so libflag.o

.PHONY: clean
clean:
	-rm *.o
