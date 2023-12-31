#include <stdio.h>
#include <stdbool.h>

enum {SUCCESS, FAIL, MAX_LEN = 81};

void LineMerge(FILE *f1, FILE *f2, FILE *f3) {
    char buff1[MAX_LEN], buff2[MAX_LEN];

    while (1) {
        if (fgets(buff1, MAX_LEN, f1) != NULL) fputs(buff1, f3);

        if (fgets(buff2, MAX_LEN, f2) != NULL) fputs(buff2, f3);

        // Exit the loop when both files are at the end.
        if (feof(f1) && feof(f2)) break;
    }
}

int main(int argc, char *argv[]) {
    FILE *f1, *f2, *f3;
    char filename1[] = argv[1];
    char filename2[] = argv[2];
    char filename3[] = argv[3];
    if (argc != 4) {
        printf("Wrong number of argument!\n");
        printf("CORRECT SYNTAX: merge <file1> <file2> <file3>\n");
        return 1;
    }
    int reval = SUCCESS;

    if ((f1 = fopen(filename1, "r")) == NULL) {
        printf("cannot open %s.\n", filename1);
        reval = FAIL;
    } else if ((f2 = fopen(filename2, "r")) == NULL) {
        printf("cannot open %s.\n", filename2);
        reval = FAIL;
    } else if ((f3 = fopen(filename3, "w")) == NULL) {
        printf("cannot open %s.\n", filename3);
        reval = FAIL;
    } else {
        LineMerge(f1, f2, f3);
        fclose(f1);
        fclose(f2);
        fclose(f3);
    }

    return reval;
}
