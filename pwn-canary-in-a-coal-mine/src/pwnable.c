#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_flag();

void vuln() {
    char buffer[100];
    int len;
    puts("What is the capital of Canada?");
    printf("What is the length of your answer?\n");
    scanf("%d", &len);
    getchar();
    puts("Give me your answer");
    gets(buffer);
    puts("Your answer is:");
    for(int i=0;i<len;i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
    puts("Want to change your answer?");
    puts("Here is a second try");
    gets(buffer);
    puts("Still wrong! Nerd");
}

int main() {
    setbuf(stdout, NULL);
    vuln();
    return 0;
}

void get_flag() {
    char*  args[2] = {"/bin/sh", NULL};
    execve(args[0], args, NULL);
}
