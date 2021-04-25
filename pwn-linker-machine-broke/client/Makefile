CC=gcc

all:
	gcc -L../lib_v1 src/pwnable.c -lflag -Wl,-z,norelro -Wl,-z,lazy -o pwnable

.PHONY: clean
clean:
	-rm *.o
