#include <stdio.h>

int main(void) {
	int i; 
	double A[10];

	printf("please enter 10 numbers: \n");
	for (i=0; i<10; i++) 
		scanf("%lf", &A[i]);

	printf("numbers in reversed	order: \n");
	for (i=9; i>=0; i--) 
		printf("%3.4lf\n", A[i]);

	return 0;
}
