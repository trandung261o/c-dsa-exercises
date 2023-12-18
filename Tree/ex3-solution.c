#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int id;
    struct Node *leftchild;
    struct Node *rightchild;
} Node;

Node *root;

Node *makeNode (int id) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->id = id;
    p->leftchild = NULL;
    p->rightchild = NULL;
    return p;
}

Node *find(Node *r, int id) {
    if (r == NULL) return NULL;
    if (r->id == id) return r;
    Node *p = find(r->leftchild, id);
    if (p != NULL) return p;
    return find(r->rightchild, id);
}

void addLeftChild (int u, int left) {
    Node *pu = find(root, u);
    if (pu == NULL) {
        printf("not found %d\n", u);
        return;
    }
    if (pu->leftchild != NULL) {
        printf("node %d has already leftChild\n",u);
        return;
    }
    pu->leftchild = makeNode(left);
}

void addRightChild (int u, int right) {
    Node *pu = find(root, u);
    if (pu == NULL) {
        printf("not found %d\n", u); return;
    }
    if (pu->rightchild != NULL) {
        printf("node %d has already rightChild\n",u);
        return;
    }
    pu->rightchild = makeNode(right);
}

void load(char *filename) {
    FILE *f = fopen(filename, "r");
    root = NULL;
    while (1) {
        int u;
        fscanf(f, "%d", &u);
        if (u == -2) break;
        if (root == NULL) root = makeNode(u);
        int l, r;
        fscanf(f, "%d%d", &l, &r);
        if (l>-1) addLeftChild(u, l);
        if (r>-1) addRightChild(u, r);
    }
    fclose(f);
}

void printTree(Node *r) {
    if (r == NULL) return;
    printf("%d: ", r->id);
    if (r->leftchild == NULL) printf("leftchild == NULL ");
    else printf("leftchild = %d ", r->leftchild->id);
    if (r->rightchild == NULL) printf("rightchild == NULL ");
    else printf("rightchild = %d ", r->rightchild->id);
    printf("\n");

    printTree(r->leftchild);
    printTree(r->rightchild);
}

void printTreeF(Node *r, FILE *f) {
    if (r == NULL) return;
    fprintf(f, "%d ", r->id);
    if (r->leftchild == NULL) fprintf(f, "-1 ");
    else fprintf(f, "%d ", r->leftchild->id);
    if (r->rightchild == NULL) fprintf(f, "-1 ");
    else fprintf(f, "%d ", r->rightchild->id);
    fprintf(f, "\n");

    printTreeF(r->leftchild, f);
    printTreeF(r->rightchild, f);
}

void processLoad() {
    char filename[256];
    printf("enter filename: "); scanf("%s", filename);
    load(filename);
}

void printChildren (Node *p) {
    if (p->leftchild == NULL) printf(" Node %d does not has leftChild",p->id);
    else printf(", LeftChild = %d\n",p->leftchild->id);
    if (p->rightchild == NULL) printf(" Node %d does not has rightchild", p->id);
    else printf(", Rightchild = %d\n", p->rightchild->id);
}

void processFind () {
    int id;
    printf("enter id: "); scanf("%d", &id);
    Node *p = find(root, id);
    if (p == NULL) printf("not found %d\n", id);
    else {
        printf("found node %d: ", p->id);
        printChildren(p);
    }
}

void processPrint() {
    printTree(root);
}


void processAddLeftChild() {
    int id, left;
    printf("enter id and leftchild: "); scanf("%d%d", &id, &left);
    addLeftChild(id, left);
}

void processAddRightChild() {
    int id, right;
    printf("enter id and rightchild: "); scanf("%d%d", &id, &right);
    addRightChild(id, right);
}

int height(Node *p) {
    if (p == NULL) return 0;
    int maxH = 0;
    int hl = height(p->leftchild);
    if (maxH < hl) maxH = hl;
    int hr = height(p->rightchild);
    if (maxH < hr) maxH = hr;

    return maxH+1;
}

void processHeight() {
    int id;
    printf("enter id: "); scanf("%d", &id);
    Node *p = find(root, id);
    if (p == NULL) printf("not found %d\n", id);
    else printf("Height of %d is %d\n", id, height(p));
}


int count(Node *p) {
    if (p == NULL) return 0;
    return 1 + count(p->leftchild) + count(p->rightchild);
}

void printLeaves(Node *p) {
    if (p == NULL) return;
    if (p->rightchild == NULL && p->leftchild == NULL) {
        printf("%d ", p->id);
    }

    printLeaves(p->leftchild);
    printLeaves(p->rightchild);
}

void processFindLeaves() {
    printLeaves(root);
    printf("\n");
}

void processCount() {
    printf("number of nodes: %d\n", count(root));
}

void processStore() {
    char filename[256];
    printf("enter filename: "); scanf("%s", filename);
    FILE *f = fopen(filename, "w");
    printTreeF(root, f);
    fprintf(f, "-2");
    fclose(f);
}

void freeTree(Node *r) {
    if (r==NULL) return;
    freeTree(r->leftchild);
    freeTree(r->rightchild);
    free(r);
    r = NULL;
}

void main() {
    printf("command list:\n Load\n Print\n Find\n Height\n Count\n FindLeaves\n AddLeftChild\n AddRightChild\n Store\n Quit\n");

    //create root
    root = makeNode(5);
    while (1){
        char cmd[256];
        printf("enter command: "); scanf("%s", cmd);
        if(strcmp(cmd,"Quit") == 0) break;
        else if(strcmp(cmd,"Load")==0) processLoad();
        else if(strcmp(cmd,"Print")==0) processPrint();
        else if(strcmp(cmd,"Find")==0) processFind();
        else if(strcmp(cmd,"Height")==0) processHeight();
        else if(strcmp(cmd,"Count")==0) processCount();
        else if(strcmp(cmd,"FindLeaves")==0) processFindLeaves();
        else if(strcmp(cmd,"AddLeftChild")==0) processAddLeftChild();
        else if(strcmp(cmd,"AddRightChild")==0) processAddRightChild();
        else if(strcmp(cmd,"Store")==0) processStore();
    }
    freeTree(root);
}
