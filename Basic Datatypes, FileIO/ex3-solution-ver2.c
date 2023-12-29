#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPHABET_LEN 26

int main() {
    int count[ALPHABET_LEN] = {0};
    char s[20];
    printf("Please enter a line of text: \n"); 
    fgets(s, sizeof(s), stdin);
    for (int i=0; i<strlen(s); i++) {
        char c = s[i];
        if (c <= 'z' && c >= 'a') ++count[c - 'a'];
        if (c <= 'Z' && c >= 'A') ++count[c - 'A'];
    }
    for (int i=0; i < ALPHABET_LEN; i++) {
        if (count[i] > 0) 
            printf("The letter '%c' appears %d times.\n", 'a' +i, count[i]);
    }
    return 0;
}
