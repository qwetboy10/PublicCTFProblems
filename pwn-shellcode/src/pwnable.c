#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    puts("Give me some shellcode to recycle");
    char buf[500];
    fgets(buf, 500, stdin);

    ((void (*)())buf)();

    puts("Thanks for helping save the planet!");
}

