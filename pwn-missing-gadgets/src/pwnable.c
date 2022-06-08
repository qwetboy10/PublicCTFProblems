#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_flag();

int main() {
    char buffer[100];
    gets(buffer);
    return 0;
}

void get_flag(int a, int b, int c, int d) {
    if(a == 0xdeadbeef && b == 0xcafebabe && c == 0xbeefcafe && d == 0xdeadbabe) {
        char*  args[2] = {"/bin/sh", NULL};
        execve(args[0], args, NULL);
    }
}
