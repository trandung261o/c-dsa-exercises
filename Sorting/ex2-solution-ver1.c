//ex solution ver1 using data from arr-n.txt in ex1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int A[], int N) {
    for (int k = 0; k < N; k++) {
        int min = k;
        for (int j = k+1; j < N; j++) {
            if (A[min] > A[j]) 
                min = j;
        }
        int tmp = A[min];
        A[min] = A[k];
        A[k] = tmp;
    }
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
    selectionSort(a, n);
    printf("list after sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    fclose(f);
    return 0;
}
