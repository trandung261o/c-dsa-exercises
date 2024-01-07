#include <stdio.h>
#include <cstring>
int x[100]; // mảng chứa lời giải
int n = 4; // kích thước bàn cờ (số hàng)
int row, col; // tọa độ hàng cột quân hẫu có sẵn
int count = 0; // số lời giải

void printSolution() {
	// in lời giải nếu lời giải thuộc trường hợp của quân hẫu xếp sẵn
	if (x[col] == row) { 
		count++;
		for (int i = 1; i <= n; i++) {
			printf("%d ", x[i]);
		}
		printf("\n");
	} 
}

int check(int v, int k) {
	for (int i = 1; i < k; i++) {
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
	TRY(1);

	// nếu không có lời giải, in -1
	if (count == 0) {
		printf("-1");
		return 0;
	}
}
