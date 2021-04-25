#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_flag();

void vuln() {
    puts("Gimme some input");
    char buffer[100];
    gets(buffer);
}

int main() {
    puts("Haha! I removed the if statement! You can never hack me now!");
    vuln();
    return 0;
}

void get_flag() {
    char*  args[2] = {"/bin/sh", NULL};
    execve(args[0], args, NULL);
}
