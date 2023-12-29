#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[]) {
    double x = atof(argv[1]);
    printf("%g\n", exp(x));
    return 0;
}
