#include <stdio.h>

int x[100][100];


void printSolution() {
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++)
			printf("%d ", x[i][j]);
		printf("\n");
	}
	printf("\n");
}

int check(int v, int r, int c) {
	for (int i = 0; i < r; i++)
		if (x[i][c] == v) return 0;

	for (int j = 0; j < c; j++)
		if (x[r][j] == v) return 0;

	int I = r/3, J = c/3;
	int i = r - 3*I, j = c - 3*J;
	for (int i1 = 0; i1 <= i-1; i1++)
		for (int j1 = 0; j1 <= 2; j1++)
			if (x[3*I + i1][3*J + j1] == v)
				return 0;

	for (int j1 = 0; j1 <= j-1; j1++)
		if(x[3*I + i][3*J + j1] == v)
			return 0;

	return 1;
}

void TRY(int r, int c) {
	for (int v = 1; v <= 9; v++) {
		if (check(v, r, c)) {
			x[r][c] = v;
			if (r == 8 && c == 8) printSolution();
			else {
				if (c == 8) TRY(r+1, 0);
				else TRY(r, c+1);
			}
		}
	}
}

int main() {
	TRY(0, 0);
}
