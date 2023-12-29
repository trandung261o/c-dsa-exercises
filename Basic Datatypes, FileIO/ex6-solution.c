#include <stdio.h>
#include <string.h>
int main() {
	char s[100];
	printf("enter a string: "); fgets(s, sizeof(s), stdin);
	for (int i=0; s[i] != '\0'; i++) {
		if (s[i] != ' ') printf("%c", s[i]);
		else {
			if (s[i+1] == ' ') continue;
			else {
				printf("\n");
			}
		}
	}
}
