#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void get_flag();

int main() {
    puts("hey bb");
    puts("whats ur name");
    char name[50];
    gets(name);
    strcat("test");
    printf("hey %s\n",name);
    puts("see ya!");
    return 0;
}

void get_flag(long a, long b, long c, long d) {
    if(a == 0x1337 && b == 0xcafebabe && c == 0xdeadbeef && d == 4) {
        char*  args[2] = {"/bin/sh", NULL};
        execve(args[0], args, NULL);
    }
}
