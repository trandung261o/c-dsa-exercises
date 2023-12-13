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
	Treenode *store = NULL;
	while(temp != NULL) {
		store = temp->right_sibling;
		freeTree(temp);
		temp = store;
	}
	free(r);
}

int countNode(Treenode *r) {
	if (r == NULL) return 0;
	int count = 1;
	Treenode *temp = r->leftmost_child;
	while(temp!=NULL){
		count += countNode(temp);
		temp = temp->right_sibling;
	}
	return count;
}

int countLeaf(Treenode *r) {
	if (r==NULL) return 0;
	if (r->leftmost_child == NULL) return 1;
	int count = 0;
	Treenode *temp = r->leftmost_child;
	while(temp!=NULL) {
		count += countLeaf(temp);
		temp = temp->right_sibling;
	}
	return count;
}

int countNodeWithKchild(Treenode *r, int k){
	if (k < 0) return -1;
	if (r == NULL) return 0;
	int count = 0, i = 0;
	Treenode *temp = r->leftmost_child;
	while(temp != NULL) {
		i++;
		count += countNodeWithKchild(temp, k);
		temp = temp->right_sibling;
	}
	if (i==k) count++;
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
	printf("\n\npostorder: \n");
	POSTORDER(root);
	printf("\n\ninorder: \n");
	INORDER(root);
	printf("\n\nnumber of Nodes: %d", countNode(root));
	printf("\n\nnumber of Leaf: %d", countLeaf (root));
	int k = 3;
	printf("\n\nnumber of Node with %d childs: %d", k, countNodeWithKchild(root, k));
	freeTree(root);
	return 0;
}
