//ex solution ver1 using data from arr-n.txt in ex1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int A[], int N) {
    for (int k = 1; k < N; k++) {
        int last = A[k];
        int j = k;
        while (j>0 && A[j-1] > last) {
            A[j] = A[j-1];
            j--;
        }
        A[j] = last;
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
    insertionSort(a, n);
    printf("list after sort: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    fclose(f);
    return 0;
}
