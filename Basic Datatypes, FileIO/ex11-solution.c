#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]) {
    double a = atof(argv[1]);
    double b = atof(argv[2]);
    double c = atof(argv[3]);
    double delta = b*b - 4*(a*c);
    if (delta < 0) {
        printf("Phuong trinh vo nghiem!\n");
    } else if (delta == 0){
        printf("Phuong trinh co nghiem kep: x_1 = x_2 = %.2lf\n", -b/2*a);
    } else {
        printf("Phuong trinh co 2 nghiem: x_1 = %.2lf, x_2 = %.2lf\n", (-b+sqrt(delta))/2*a, (-b-sqrt(delta))/2*a);      
    }
    return 0;
}
