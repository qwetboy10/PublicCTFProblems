#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_flag() {
  char*  args[2] = {"/bin/sh", NULL};
  execve(args[0], args, NULL);
}

int main() {
    puts("Can you get my got?");
    puts("Probably not tbh...");
    int64_t i,j;
    scanf("%ld",&i);
    scanf("%ld",&j);
    *(int64_t *) i = j;
    puts("Guess you failed");
}

