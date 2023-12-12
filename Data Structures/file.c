#include <stdio.h>
#define MAX_SIZE 1000
typedef int DataType;
void mergesort(DataType A[], int first, int last) {
    if (first < last) {
        int mid = (first + last)/2;
        mergesort(A, first, mid);
        mergesort(A, mid+1, last);
        merge(A, first, mid, last);
    }
}
void merge(DataType A[], int first, int mid, int last) {
    DataType tempA[MAX_SIZE];
    int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;
    for (; (first1 <= last1) && (first2 <= last2); ++index) {
        if (A[first1] < A[first2]) {
            tempA[index] = A[first1];
            ++first1;
        } else {
            tempA[index] = A[first2];
            ++first2;
        }
    }
    for (; first1 <= last1; ++first1, ++index)
        tempA[index] = A[first1];
    for (; first2 <= last2; ++first2, ++index)
        tempA[index] = A[first2];
    for (index = first; index <= last; ++index)
        A[index] = tempA[index];
}


void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return;
}

int main() {
    int n;
    printf("do dai mang: ");
    scanf("%d", &n);
    int a[n];
    printf("nhap mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    mergesort(a, 0, n-1);
    print(a, n);
    return 0;
}













