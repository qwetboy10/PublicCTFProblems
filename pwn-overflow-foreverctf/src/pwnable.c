#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void get_flag() {
  char*  args[2] = {"/bin/sh", NULL};
  execve(args[0], args, NULL);
}

int main() {
  int x = 0;
  char buffer[100];
  printf("Enter some input!\n");
  gets(buffer);
  if(x) {
    get_flag();
  }
  return 0;
}

