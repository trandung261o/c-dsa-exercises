#include <stdio.h>
#include <cstring>
#define N 100
int m[N];

int fibonacci(int n) {
	if (n <= 1) m[n] = 1;
	else {
		if (m[n] == 0) {
			int n1 = fibonacci(n-1);
			int n2 = fibonacci(n-2);
			m[n] = n1 + n2;
		}	
	}
	return m[n];
}

void init() {
	memset(m, 0, sizeof(int)*N);
}

int main() {
	init();
	for (int i = 0; i < 10; i++) {
		printf("fib[%d] = %d\n", i, fibonacci(i));
	}
}
