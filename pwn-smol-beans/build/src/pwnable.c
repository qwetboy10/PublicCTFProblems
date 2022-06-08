#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char type[100];
    char format[100];
    puts("What kind of beans do you have?");
    gets(type);
    if(strcmp(type, "long beans")) {
        format = strcat(format, "%10s");
    }
    else if(strcmp(type, "short beans")) {
        format = strcat(format, "%5s");
    }
    else {
        puts("Error");
    }
    char data[100];
    puts("Give me your beans");
    gets(data);
    printf(format, data);
    puts(data);
    
    return 0;
}

