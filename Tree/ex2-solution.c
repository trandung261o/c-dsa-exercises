#include <stdio.h>
#include <stdlib.h>
typedef char elementtype;
typedef struct _Tnode {
	elementtype inf;
	struct _Tnode *left;
	struct _Tnode *right;
} Treenode;

Treenode *createnewnode(elementtype X){
	Treenode *newnode = (Treenode *)malloc(sizeof(Treenode));
	if (newnode == NULL) {printf("error in memory allocation!\n"); exit(0);}

	newnode->inf = X;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

void PREORDER(Treenode *r) {
	if (r==NULL) return;
	printf("%c ", r->inf);
	
	PREORDER(r->left);
	PREORDER(r->right);
}

void POSTORDER(Treenode *r) {
	if (r==NULL) return;
	POSTORDER(r->left);
	POSTORDER(r->right);

	printf("%c ", r->inf);
}

void INORDER(Treenode *r) {
	if (r == NULL) return;
	INORDER(r->left);
	printf("%c ", r->inf);
	INORDER(r->right);
}

void freeTree(Treenode *r) {
	if (r == NULL) return;
	freeTree(r->left);
	freeTree(r->right);
	free(r);
}

int countNode(Treenode *r) {
	if (r == NULL) return 0;
	else return 1 + countNode(r->left) + countNode(r->right);
}

int countInternalNode(Treenode *r) {
	if (r == NULL) return 0;
	if (r->left == NULL && r->right == NULL) return 0;
	return 1 + countInternalNode(r->left) + countInternalNode(r->right);
}

int countNodeWithKchild(Treenode *r, int k){
	if (k<0 || k>2) return -1;
	if (r == NULL) return 0;
	int i = 0, count = 0;
	if (r->left != NULL) i++;
	if (r->right != NULL) i++;
	if (i == k) count++;
	count += countNodeWithKchild(r->left, k);
	count += countNodeWithKchild(r->right, k);
	return count;
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

	root->left = nutB;

	nutB->left = nutE;
	nutB->right = nutC;

	nutC->left = nutG;
	nutC->right = nutD;

	nutE->right= nutF;
	nutG->left = nutH;
	nutH->right = nutI;
	nutI->right = nutJ;
	nutJ->right = nutK;

	printf("preorder: \n");
	PREORDER(root);
	printf("\n\npostorder: \n");
	POSTORDER(root);
	printf("\n\ninorder: \n");
	INORDER(root);
	printf("\n\nnumber of Nodes: %d", countNode(root));
	printf("\n\nnumber of Internal Nodes: %d", countInternalNode(root));
	printf("\n\nnumber of Node with %d childs: %d", 0, countNodeWithKchild(root, 0));
	printf("\nnumber of Node with %d childs: %d", 1, countNodeWithKchild(root, 1));
	printf("\nnumber of Node with %d childs: %d", 2, countNodeWithKchild(root, 2));
	printf("\nnumber of Node with %d childs: %d", 3, countNodeWithKchild(root, 3));
	freeTree(root);
	return 0;
}
