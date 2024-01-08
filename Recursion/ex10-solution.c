#include <stdio.h>

#define MAX_N 100

int M, N;
int A[MAX_N];
int X[MAX_N];
int maxproduct = -10e4;
int count = 0;
void printSolution() {
    int product = 1;
    count++;
    for (int i = 0; i < N; i++) {
        product *= X[i];
        printf("%d ", X[i]);
    }
    if (product >= maxproduct) maxproduct = product;
    printf("\n");
}

void solve(int index, int remainingM) {
    if (index == N) {
        if (remainingM == 0) {
            printSolution();
        }
        return;
    }

    for (int i = 1; i <= remainingM; i++) {
        X[index] = i;
        solve(index + 1, remainingM - i * A[index]); // Nhân hệ số A[index] vào từng X[index]
    }
}

int main() {
    printf("Enter M: ");
    scanf("%d", &M);

    printf("Enter N: ");
    scanf("%d", &N);

    printf("Enter the values of A1, A2, ..., AN: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    solve(0, M);
    if (count == 0) {
        printf("-1");
        return 0;
    }
    printf("\nmaxproduct = %d", maxproduct);
    return 0;
}
