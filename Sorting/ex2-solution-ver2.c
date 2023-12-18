//ex2 solution ver2 user input data from keyboard

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
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    insertionSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
