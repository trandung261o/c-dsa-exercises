#include <stdio.h>

int x[100]; 
int n = 4;
int row, col;

void printSolution() {
	for (int i = 1; i <= n; i++) {
		printf("%d ", x[i]);
	}
	printf("\n");
}

int check(int v, int k) {
	for (int i = 1; i < k; i++) {
		//kiểm tra v, k có phải hàng cột của con hẫu có sẵn không
		if (v == row || k == col) return 0;
		
		if (x[i] == v) return 0;
		if (x[i] + i == v + k) return 0;
		if (x[i] - i == v - k) return 0;
	}
	return 1;
}

void TRY(int k) {
	for (int v = 1; v <= n; v++) {
		if (check(v, k)) {
			x[k] = v;
			if (k == n) printSolution();
			else TRY(k+1);
		}
	}
}

int main() {
	//nhập giá trị hàng cột cho con hậu đã có sẵn
	scanf("%d%d", &row, &col);
	x[col] = row;

	TRY(1);
}
