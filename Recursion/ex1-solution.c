#include <stdio.h>

int tong(int n) {
	if (n == 1) return 1;
	else {
		int s = tong(n-1);
		return n + tong(n-1);
	}
}

int tohop(int k, int n) {
	if (k == 0 || k == n) return 1;
	else {
		int C1 = tohop(k-1, n-1);
		int C2 = tohop(k, n-1);
		return C1 + C2;
	}
}

int fibonacci(int n) {
	if (n <= 1) return 1;
	else {
		int n1 = fibonacci(n-1);
		int n2 = fibonacci(n-2);
		return n1 + n2;
	}
}

void thaphn(int n, char A, char B, char C) {
	if (n == 1) {
		printf("Move 1 disk from %c to %c\n", A, B);
	} else {
		thaphn(n-1, A, C, B);
		thaphn(1, A, B, C);
		thaphn(n-1, C, B, A);
	}
}

int main() {
  	printf("%d\n", tong(5));
  	printf("%d\n", tohop(2, 3));
	printf("%d\n", fibonacci(6));
	thaphn(3, 'A', 'B', 'C');
	return 0;
}
