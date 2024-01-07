#include <stdio.h>
#define MAX 100

int x[MAX], m[MAX]; 
int n = 5; 

void printSolution() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
}

void Try(int i) {
	for (int v = 1; v <= n; v++) {
		if (!m[v]) {
			x[i] = v;
			m[v] = true;
			if (i == n) printSolution();
			else Try(i+1);
			m[v] = false;
		}
	}
}

int main() {
	for (int v = 0; v <= n; v++) 
		m[v] = false;

	Try(1);
}
