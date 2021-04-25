#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>


int main() {
    char flag[100] = {0};
    FILE* f = fopen("flag.txt","r");
    fgets(flag,100,f);

    char not_flag[100] = "";
    int first;
    int second;

    printf("Input a string:\n");
    scanf("%s",not_flag);
    printf("Input a first index:\n");
    scanf("%d",&first);
    printf("Input a second index:\n");
    scanf("%d",&second);
    printf("%d %d\n",first,second);
    for(int i=first;i<second;i++) {
        printf("%c",not_flag[i]);
    }
    printf("\n");
}

