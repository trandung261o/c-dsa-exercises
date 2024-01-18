#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 1000001
int a[N];
int n, Q;
int cand[N];
int sz;
void initSet(int _sz) {
    for (int i = 1; i <= N; i++) cand[i] = i;
    for (int k = 1; k <= N; k++) {
        int i = rand()%N;
        int j = rand()%N;

        int tmp = cand[i];
        cand[i] = cand[j];
        cand[j] = tmp;
    }
    sz = _sz;
}

int selectAndRemove() {
    int i = rand()%sz;      int x = cand[i];
    cand[i] = cand[sz-1];   sz--;
    return x;
}

void genData(char *filename, int n, int Q) {
    for (int i = 1; i <= n; i++) cand[i] = i;
    srand(time(NULL));
    FILE *f = fopen(filename, "w");
    fprintf(f, "%d %d\n", n, Q); initSet(n);
    for (int i = 1; i <= n; i++) {
        int x = selectAndRemove(); fprintf(f, "%d ", x);
    }
    fclose(f);
}

void input(char *filename) {
    FILE *f = fopen(filename, "r");
    fscanf(f, "%d%d", &n, &Q);
    for (int i = 1; i <= n; i++) fscanf(f, "%d", &a[i]);
    fclose(f);
}

void bruteForceSolve() {
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++)
            if (a[i] + a[j] == Q)
                cnt++;
    }
    printf("result = %d\n", cnt);
}

void swap(int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void heapify(int i, int n) {
    int L = 2*i;
    int R = 2*i+1;
    int max = i;
    if (L <= n && a[L] > a[max]) max = L;
    if (R <= n && a[R] > a[max]) max = R;
    if (max != i) {
        swap(i, max); heapify(max, n);
    }
}

void buildHeap() {
    for (int i = n/2; i >= 1; i--) heapify(i, n);
}

void heapSort() {
    buildHeap();
    for (int i = n; i > 1; i--) {
        swap(1, i); heapify(1, i-1);
    }
}

//cài đặt tìm kiếm nhị phân bằng vòng lặp
/*
int binSearch(int List[], int Target, int Size) {
    int Mid, Lo = 0, Hi = Size - 1;
    while (Lo <= Hi) {
        Mid = (Lo + Hi)/2;
        if (List[Mid] == Target)
            return Mid;
        else if (Target < List[Mid])
            Hi = Mid - 1;
        else
            Low = Mid + 1;
    }
    return -1;
}
*/

//cài đặt tìm kiếm nhị phân bằng đệ quy
int binarySearch(int L, int R, int Y) {
    // return 1 nếu xuất hiện Y trong a[L, ..., R]
    if (L > R) return 0;
    if (L == R) if (a[L] == Y) return 1; else return 0;
    int m = (L + R)/2;
    if (a[m] == Y) return 1;
    if (a[m] > Y) return binarySearch(L, m-1, Y);
    return binarySearch(m+1, R, Y);
}

void binarySearchSolve(){
    heapSort();
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int ok = binarySearch(i+1, n, Q-a[i]);
        cnt += ok;
    }
    printf("result = %d\n", cnt);
}

int main() {
    genData("arr-100000.txt", 100000,100000);
    input("arr-1000000.txt");
    //bruteForceSolve();
    binarySearchSolve();
}
