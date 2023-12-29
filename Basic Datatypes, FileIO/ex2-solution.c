#include <stdio.h>
#include <math.h>

double average(double a[], int size) {
    int sum = 0;
    for (int i=0; i<size; i++) {
        sum += a[i];
    }
    return sum*1.0/size;
}

double find(double a[], int size) {
    int medianindex;
    double avg = average(a, size);
    double mindiff = 10e7;
    for (int i=0; i<size; i++) {
        double diff = fabs(a[i] - avg);
        if (diff < mindiff){
            mindiff = diff;
            medianindex = i;
        }
    }
    return a[medianindex];
}

int main() {
    int n; 
    printf("enter size: "); scanf("%d", &n);

    double a[n];
    printf("enter array: \n");
    for (int i=0; i<n; i++) scanf("%lf", &a[i]);

    double res = find(a, n);
    printf("\nresult: %.2lf\n", res);
    return 0;
}
