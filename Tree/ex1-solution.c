#include <stdio.h>
#include <stdlib.h>
typedef char elementtype;
typedef struct _Tnode {
	elementtype inf;
	struct _Tnode *leftmost_child;
	struct _Tnode *right_sibling;
} Treenode;

Treenode *createnewnode(elementtype X){
	Treenode *newnode = (Treenode *)malloc(sizeof(Treenode));
	if (newnode == NULL) {printf("error in memory allocation!\n"); exit(0);}

	newnode->inf = X;
	newnode->leftmost_child = NULL;
	newnode->right_sibling = NULL;
	return newnode;
}

void PREORDER(Treenode *r) {
	if (r==NULL) return;
	printf("%c ", r->inf);
	Treenode *temp = r->leftmost_child;
	while(temp != NULL) {
		PREORDER(temp);
		temp = temp->right_sibling;
	}
}

void POSTORDER(Treenode *r) {
	if (r == NULL) return;
	Treenode *temp = r->leftmost_child;
	while(temp != NULL) {
		POSTORDER(temp);
		temp = temp->right_sibling;
	}
	printf("%c ", r->inf);
}

void INORDER(Treenode *r) {
	if (r == NULL) return;
	if (r->leftmost_child == NULL) 
		printf("%c ", r->inf);
	else {
		INORDER(r->leftmost_child);
		printf("%c ", r->inf);
		Treenode *temp = r->leftmost_child->right_sibling;
		while(temp != NULL) {
			INORDER(temp);
			temp = temp->right_sibling;
		}
	}
}

void freeTree(Treenode *r) {
	if (r == NULL) return;
	Treenode *temp = r->leftmost_child;
	free(r);
	while(temp != NULL) {
		freeTree(temp);
		temp = temp->right_sibling;
	}
}

int main() {
	Treenode *root = NULL;
	Treenode *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH, *nutI, *nutJ, *nutK; 
	root = createnewnode('A');
	nutB = createnewnode('B');
	nutC = createnewnode('C');
	nutD = createnewnode('D');
	nutE = createnewnode('E');
	nutF = createnewnode('F');
	nutG = createnewnode('G');
	nutH = createnewnode('H');
	nutI = createnewnode('I');
	nutJ = createnewnode('J');
	nutK = createnewnode('K');

	root->leftmost_child = nutB;

	nutB->leftmost_child = nutE;
	nutB->right_sibling = nutC;

	nutC->leftmost_child = nutG;
	nutC->right_sibling = nutD;

	nutE->right_sibling = nutF;
	nutG->leftmost_child = nutH;
	nutH->right_sibling = nutI;
	nutI->right_sibling = nutJ;
	nutJ->right_sibling = nutK;

	printf("preorder: \n");
	PREORDER(root);
	printf("\npostorder: \n");
	POSTORDER(root);
	printf("\ninorder: \n");
	INORDER(root);

	freeTree(root);
	return 0;
}
