CC=gcc

all:
	gcc --static -no-pie -fno-stack-protector -o ${USER} src/pwnable.c

.PHONY: clean
clean:
	-rm *.o
