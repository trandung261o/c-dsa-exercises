#include <stdio.h>
#define MAX 100

int x[MAX]; 
int n = 3; // độ dài xâu nhị phân

void printSolution() {
	for (int k = 0; k < n; k++) {
		printf("%d", x[k]);
	}
	printf("\n");
}

void Try(int k) {
	for (int v = 0; v <= 1; v++) {
    //check
		if (x[k-1] + v < 2) { 
			x[k] = v;
			if (k == n-1) printSolution();
			else Try(k+1);
		}
	}
}

int main() {
	Try(0);
}
