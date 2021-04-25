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
    printf("hey %s\n",name);
    puts("you can set my registers any day of the week");
    long rax = 0;
    long rbx = 0;
    long rcx = 0;
    long rdx = 0;
    long rsi = 0;
    long rdi = 0;
    printf("rax: ");
    scanf("%ld",&rax);
    printf("rbx: ");
    scanf("%ld",&rbx);
    printf("rcx: ");
    scanf("%ld",&rcx);
    printf("rdx: ");
    scanf("%ld",&rdx);
    printf("rsi: ");
    scanf("%ld",&rsi);
    printf("rdi: ");
    scanf("%ld",&rdi);
    __asm__ (
            "mov %0, %%rax;"
            "mov %1, %%rbx;"
            "mov %2, %%rcx;"
            "mov %3, %%rdx;"
            "mov %4, %%rsi;"
            "mov %5, %%rdi;"
          :
          : "m"(rax),"m"(rbx),"m"(rcx),"m"(rdx),"m"(rsi),"m"(rdi)
          : );

    return 0;
}

void get_flag(long a, long b, long c, long d) {
    if(a == 0x1337 && b == 0xcafebabe && c == 0xdeadbeef && d == 4) {
        char*  args[2] = {"/bin/sh", NULL};
        execve(args[0], args, NULL);
    }
}
