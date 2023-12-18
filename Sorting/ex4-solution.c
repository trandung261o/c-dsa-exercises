//ex4 solution using data from arr-n.txt in ex1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int A[], int n){
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < n-1; i++) {
            if (A[i] > A[i+1]){
                int tmp = A[i];
                A[i] = A[i+1];
                A[i+1] = tmp;
                swapped = 1;
            }
        }
    } while (swapped == 1);
}

int main() {
    int a[100], n;
    FILE *f = fopen("arr-n.txt", "r");
    fscanf(f,"%d", &n);
    printf("list before sort: \n");
    for (int i = 0; i < n; i++) {
        fscanf(f, "%d", &a[i]);
        printf("%d ", a[i]);
    }
    printf("\n\n");
    bubbleSort(a, n);
    printf("list after sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    fclose(f);
    return 0;
}
