#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#define ALPHABET_LEN 26

int main(void) {
    int count[ALPHABET_LEN] = {0};

    printf("Please enter a line of text: \n");
    char c = getchar();
    while (c != '\n' && c >= 0) {
        if (c <= 'z' && c >= 'a') 
            ++count[c - 'a'];
        if (c <= 'Z' && c >= 'A') 
            ++count[c - 'A'];
        c = getchar();
    }

    for (int i=0; i<ALPHABET_LEN; i++) {
        if (count[i] > 0) 
            printf("The letter %c appears %d times.\n", 'a' +i, count[i]);
    }
    return 0;
}
