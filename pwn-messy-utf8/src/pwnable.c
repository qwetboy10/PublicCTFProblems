#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100

#define char unsigned char

void parseUTF8(char* dest, char* src) {
    char* out = dest;
    for(char* cur = src; *cur != '\0'; cur++) {
        if((*cur >> 7) == 0) {
            *out++ = *cur;
        }
        else if((*cur >> 5) == 0b110) {
            int codePoint = *cur & 0b11111;
            codePoint <<= 6;
            cur++;
            codePoint |= *cur & 0b111111;
            printf("Invalid Code Point Found: %d\n",codePoint);
        }
        else if((*cur >> 4) == 0b1110) {
            int codePoint = *cur & 0b1111;
            codePoint <<= 6;
            cur++;
            codePoint |= *cur &  0b111111;
            codePoint <<= 6;
            cur++;
            codePoint |= *cur &  0b111111;
            printf("Invalid Code Point Found: %d\n",codePoint);
        }
        else if((*cur >> 3) == 0b11110) {
            int codePoint = *cur & 0b111;
            codePoint <<= 6;
            cur++;
            codePoint |= *cur &  0b111111;
            codePoint <<= 6;
            cur++;
            codePoint |= *cur &  0b111111;
            codePoint <<= 6;
            cur++;
            codePoint |= *cur &  0b111111;
            printf("Invalid Code Point Found: %d\n",codePoint);
        }
    }
}

void escape(char* dest, char* src) {
    char* out = dest;
    for(char* cur=src; *cur != '\0'; cur++) {
        if(*cur == '\'') {
            *out++ = '\'';
            *out++ = '\\';
            *out++ = '\'';
            *out++ = '\'';
        }
        else {
            *out++ = *cur;
        }
    }
}


int main(int argc, char** argv) {
    char input[BUFFER_SIZE] = {0};
    char escaped[BUFFER_SIZE*5] = {0};
    fgets(input,BUFFER_SIZE, stdin);
    //printf("Input: %s\n",input);
    escape(escaped,input);
    //printf("Escaped: %s\n",escaped);
    char command[6 * BUFFER_SIZE] = {0};
    strcat(command, "echo '");
    strcat(command, escaped);
    strcat(command, "'");
    //printf("Command: %s\n", command);
    char output[7 * BUFFER_SIZE] = {0};
    parseUTF8(output, command);
    //printf("Parsed: %s\n",output);
    system(output);
}


