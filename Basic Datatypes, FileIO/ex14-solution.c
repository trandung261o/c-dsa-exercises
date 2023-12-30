#include <stdio.h>
enum {SUCCESS, FAIL, MAX_LEN = 81};
int count = 0;
void LineReadWrite(FILE *fin, FILE *fout) {
	char buff[MAX_LEN];
	while (fgets(buff, MAX_LEN, fin) != NULL) {
		++count;
		fputs(buff, fout);
		printf("%s", buff);
	}
}

int main() {
	FILE *fptr1, *fptr2;
	char filename1[] = "lab1w.txt";
	char filename2[] = "lab1.txt";
	int reval = SUCCESS;
	if ((fptr1 = fopen(filename1, "w")) == NULL) {
		printf("cannot open %s.\n", filename1);
		reval = FAIL;
	} else if ((fptr2 = fopen(filename2, "r")) == NULL) {
		printf("cannot open %s.\n", filename2);
		reval = FAIL;
	} else {
		printf("Reading file %s...done!\n", filename2);
		LineReadWrite(fptr2, fptr1);
		printf("This file has %d lines\n", count);
		fclose(fptr2);
		fclose(fptr1);
	}
	return reval;
}
