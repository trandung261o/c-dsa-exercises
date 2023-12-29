#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double width, height;
    if (argc != 3) {
        printf("Wrong number of arguments!\n");
        printf("CORRECT SYNTAX: ./a.out <WIDTH> <HEIGHT>\n");
        return 1;
    }
    width = atof(argv[1]);
    height = atof(argv[2]);
    printf("the rectangle's area is %.2f\n", width * height);
    printf("the rectangle's perimeter is %.2f\n", 2 * (width + height));
    return 0;
}
