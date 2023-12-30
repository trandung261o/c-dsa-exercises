#include <stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 81};
int count = 0;
void LineReadWrite(FILE *fin) {
	char buff[MAX_LEN];
	while (fgets(buff, MAX_LEN, fin) != NULL) {
		++count;
		printf("%s", buff);
	}
}

int main() {
	FILE *fptr2;
	char filename2[] = "lab1.txt";
	int reval = SUCCESS;
	if ((fptr2 = fopen(filename2, "r")) == NULL) {
		printf("cannot open %s.\n", filename2);
		reval = FAIL;
	} else {
		printf("Reading file %s...done!\n", filename2);
		LineReadWrite(fptr2);
		printf("\nThis file has %d lines\n", count);
		fclose(fptr2);
	}
	return reval;
}
