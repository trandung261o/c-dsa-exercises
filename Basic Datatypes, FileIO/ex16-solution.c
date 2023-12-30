#include <stdio.h>
enum {SUCCESS, FAIL, MAX_ELEMENT = 10};

typedef struct {
	int no;
	char name[20];
	double price;
} product;

int main() {
	FILE *fp;
	product arr[MAX_ELEMENT];
	int i = 0, n;
	int reval = 0;
	printf("Loading file...\n");
	if ((fp = fopen("product.txt", "r")) == NULL) {
		printf("cannot open %s.\n", "product.txt");
		reval = FAIL;
	} else {
		while (fscanf(fp, "%d%s%lf", &arr[i].no, arr[i].name, &arr[i].price) != EOF)
			i++;
		n = i;
		printf("%-6s%-24s%-6s\n", "No", "Product Name", "Price");
		for (i=0; i<n; i++) 
			printf("%-6d%-24s%-6.2lf\n", arr[i].no, arr[i].name, arr[i].price);
	}
	fclose(fp);
	return reval;
}
