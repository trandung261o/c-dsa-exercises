#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNodeRec
{
    int key;
    struct TreeNodeRec *leftPtr;
    struct TreeNodeRec *rightPtr;
} TreeNode;


//tạo nốt mới
TreeNode *makeTreeNode(int value)
{
    TreeNode *newNodePtr = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNodePtr == NULL) {printf("Out of memory\n"); exit(1);}
    else {
        newNodePtr->key = value;
        newNodePtr->leftPtr = NULL;
        newNodePtr->rightPtr = NULL;
    }
    return newNodePtr;
}

//tìm phần tử nhỏ nhất
TreeNode *find_min(TreeNode *T)
{
    if (T == NULL) return NULL;
    else {
        if (T->leftPtr == NULL) return T;
        else return(find_min(T->leftPtr));
    }
}

//tìm phần tử lớn nhất
TreeNode *find_max(TreeNode *T)
{
    if (T != NULL) {
        while (T->rightPtr != NULL)
            T = T->rightPtr;
    }
    return T;
}

//tìm kiếm nút có giá trị target
TreeNode *search(TreeNode *nodePtr, int target)
{
    if (nodePtr != NULL) {
        if (target < nodePtr->key) nodePtr = search(nodePtr->leftPtr, target);
        else if (target > nodePtr->key) nodePtr = search(nodePtr->rightPtr, target);
    }

    return nodePtr;
}

// chèn vào cây nhị phân
TreeNode *insert(TreeNode *nodePtr, int item)
{
    if (nodePtr == NULL) nodePtr = makeTreeNode(item);
    else if (item < nodePtr->key) nodePtr->leftPtr = insert(nodePtr->leftPtr, item);
    else if (item > nodePtr->key) nodePtr->rightPtr = insert(nodePtr->rightPtr, item);
    return nodePtr;
}

// xóa phần tử có key = x
TreeNode *del(TreeNode *T, int x)
{
    TreeNode *tmp;
    if (T == NULL) return NULL;
    else if (x < T->key) T->leftPtr = del(T->leftPtr, x);
    else if (x > T->key) T->rightPtr = del(T->rightPtr, x);
    else if (T->leftPtr && T->rightPtr) {
        tmp = find_min(T->rightPtr);
        T->key = tmp->key;
        T->rightPtr = del(T->rightPtr, T->key);
    }
    else {
        tmp = T;
        if (T->leftPtr == NULL) T = T->rightPtr;
        else if (T->rightPtr == NULL) T = T->leftPtr;
        free(tmp);
    }
    return T;
}
void PREORDER(TreeNode *r) {
	if (r==NULL) return;
	printf("%d ", r->key);

	PREORDER(r->leftPtr);
	PREORDER(r->rightPtr);
}


int main()
{
    TreeNode *rootPtr = NULL;
    //printf("cmd list: insert, del, #\n");
    while (1) {
        char cmd[256];
        scanf("%s", cmd);
        if (strcmp(cmd, "#") == 0) break;
        else if (strcmp(cmd, "insert") == 0) {
            int x;
            scanf(" %d", &x);
            rootPtr = insert(rootPtr, x);
//            PREORDER(rootPtr);
//            printf("\n");
        }
        else if (strcmp(cmd, "del") == 0) {
            char x;
            scanf(" %c", &x);
            rootPtr = del(rootPtr, x);
//            PREORDER(rootPtr);
//            printf("\n");
        }
    }
    if (rootPtr == NULL) {
        printf("NONE");
        return 0;
    }
    PREORDER(rootPtr);
}
