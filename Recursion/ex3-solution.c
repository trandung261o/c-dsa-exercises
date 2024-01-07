#include <stdio.h>
#include <cstring>
#define MAX 100

int M[MAX][MAX];

int tohop(int k, int n) {
	if (k == 0 || k == n) M[k][n] = 1;
	else {
		if (M[k][n] < 0) {
			int C1 = tohop(k-1, n-1);
			int C2 = tohop(k, n-1);
			M[k][n] = C1 + C2;
		}
	}
	return M[k][n];
}

void init() {
	memset(M, -1, sizeof(M));
}

int main() {
	init();
	for (int k = 0; k < 5; k++) {
		printf("C(%d, %d) = %d\n", k, 4, tohop(k, 4));
	}
	
}
