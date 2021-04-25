CC=gcc

all:
	gcc -fPIE -pie -Wl,-z,norelro -o ${USER} src/pwnable.c


.PHONY: clean
clean:
	-rm *.o
