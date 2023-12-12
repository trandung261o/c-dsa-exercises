#include <stdio.h>
#define maxlength 1000
typedef int elementtype;
typedef struct list_tag {
	elementtype elements[maxlength];
	int last;
} list_type;

//ham tra ve vi tri last+1
int end(list_type *lp) {
	return lp->last +1;
}

//ham tao o nho
list_type *create() {
	list_type *p = (list_type *)malloc(sizeof(list_type));

	//check p
	if(p == NULL) {printf("error\n"); exit(0);}

	p->last = -1;
	return p;
}

//ham chen
void insert(elementtype x, int p, list_type *lp) {
	//check
	if (lp->last >= maxlength-1) {printf("list is full\n"); return;}
	if ((p<0) || p > lp->last +1) {printf("position doesn't exist\n"); return;}

	else {
		for (int q = lp->last; q >= p; q--)
			lp->elements[q+1] = lp->elements[q];

		lp->last = lp->last +1;
		lp->elements[p] = x;
	}
}

//ham xoa
void deleteL(int p, list_type *lp) {
	//check
	if ((p<0) || p > lp->last) {printf("position doesn't exist\n"); return;}

	else {
		lp->last --;
		for (int q = p; q <= lp->last; q++)
			lp->elements[q] = lp->elements[q+1];
	}
}

//ham in
void print(list_type *p) {
	for (int i = 0; i <= p->last; i++) {
		printf("%d ", p->elements[i]);
	}
	printf("\n");
}

int main() {
	list_type *lp = create();
	printf("danh sach ban dau: \n");
	print(lp);
	insert(0, 0, lp);
	insert(1, 1, lp);
	insert(2, 2, lp);
	printf("danh sach sau khi chen: \n");
	print(lp);
    insert(3, 3, lp);
	insert(4, 4, lp);
	insert(5, 5, lp);
    printf("danh sach sau khi chen: \n");
	print(lp);
	deleteL(3, lp);
	printf("danh sach sau khi xoa ptu o vt 3: \n");
	print(lp);
	return 0;
}
