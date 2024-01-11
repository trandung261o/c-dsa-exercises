#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Node {
    int row, col;
    int step;
    struct Node *next;
    struct Node *parent;
} Node;

Node *head, *tail;
Node *listNode[MAX*MAX];
int szList = 0;
int A[MAX][MAX];
int n, m; //numbers of rows and collums
int r0, c0; // current row and collum position
int r1, c1;
int visited[MAX][MAX];
int count = 0;

//              down up right left
const int dr[4] = {1, -1, 0, 0};
const int dc[4] = {0, 0, 1, -1};
Node *finalNode;

Node *makeNode(int row, int col, int step, Node *parent) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->step = step;
    node->next = NULL;
    node->parent = parent;
    return node;
}

void initQueue() {
    head = NULL;
    tail = NULL;
}

int queueEmpty() {
    return head == NULL && tail == NULL;
}

void pushQueue(Node *node) {
    if (queueEmpty()) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
}

Node *popQueue() {
    if (queueEmpty()) return NULL;

    Node *node = head;
    head = head->next;
    if (head == NULL) tail = NULL;

    return node;
}

/*
maze.txt example:
8 12 5 6 7 8
1 1 0 0 0 0 1 0 0 0 0 1
1 0 0 0 1 1 0 1 0 0 1 1
0 0 1 0 0 0 0 0 0 0 0 0
1 0 0 0 0 0 1 0 0 1 0 1
1 0 0 1 0 0 0 0 0 1 0 0
1 0 1 0 1 0 0 0 1 1 0 1
0 0 0 0 1 0 1 0 0 0 0 0
1 0 1 1 0 1 1 1 0 1 0 1
*/
void input() {
    scanf("%d%d%d%d%d%d", &n, &m, &r0, &c0, &r1, &c1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

int legal(int row, int col) {
    return A[row][col] == 0 && !visited[row][col];
}

int target(int row, int col) {
    return row == r1 && col == c1;
}

void finalize() {
    for (int i = 0; i < szList; i++) {
        free(listNode[i]);
    }
}

void addList(Node *node) {
    listNode[szList] = node;
    szList++;
}

int main() {
    // printf("MAZE\n");
    input();
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            visited[i][j] = 0;

    initQueue();
    Node *startNode = makeNode(r0, c0, 0, NULL);
    addList(startNode);
    pushQueue(startNode);
    visited[r0][c0] = 1;

    while (!queueEmpty()) {
        Node *node = popQueue();

        for (int k = 0; k < 4; k++) {
            int nr = node->row + dr[k];
            int nc = node->col + dc[k];

            if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && legal(nr, nc) && !visited[nr][nc]) {
                visited[nr][nc] = 1;
                Node *newnode = makeNode(nr, nc, node->step + 1, node);
                addList(newnode);
                if (target(nr, nc)) {
                    finalNode = newnode;
                    break;
                } else {
                    pushQueue(newnode);
                }
            }
        }

        if (finalNode != NULL) break;
    }


    Node *s = finalNode;
    // printf("\nshortest path is: \n");
    while (s != NULL) {
        ++count;
        //printf("(%d, %d) ", s->row, s->col);
        s = s->parent;
    }

    if (count == 0) {
        printf("-1");
    } else {
        printf("%d", count-1);
    }
    finalize();
    return 0;
}
