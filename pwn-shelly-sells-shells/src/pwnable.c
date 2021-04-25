#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    char shellcode[500];
    gets(shellcode);
    ((void(*)())shellcode)();
    return 0;
}
