//ex2 solution ver2 user input data from keyboard

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
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    selectionSort(a, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}
