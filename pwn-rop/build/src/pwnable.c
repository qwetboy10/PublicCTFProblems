#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_flag();

int main() {
    puts("Give me some recycling");
    char buf[100];
    gets(buf);
    puts("Thanks");
    return 0;
}

void get_flag(int x, int y) {
    if(x == 0xdeadbeef && y == 0xcafebabe) {
        char*  args[2] = {"/bin/sh", NULL};
        execve(args[0], args, NULL);
    }
}
