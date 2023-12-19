#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int item;
    struct stackNode *next;
} stackNode;

typedef struct stack {
    stackNode *top;
} stack;

stack *createStack () {
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL) {printf("Loi!\n"); exit(0);}

    s->top = NULL;
    return s;
}

int isEmpty(stack *s) {
    if (s == NULL) return 1;
    if (s->top == NULL) return 1;
    else return 0;
} 

void push(stack *s, int x) {
    if (s == NULL) return;
    stackNode *newnode = (stackNode *)malloc(sizeof(stackNode));
    if (newnode == NULL) {printf("Error!\n"); exit(0);}

    newnode->item = x; 
    newnode->next = s->top;
    s->top = newnode;
}

int pop(stack *s) {
    if (s == NULL) return -10e8;
    if (isEmpty(s)) return -10e8;

    int x = s->top->item;
    stackNode *tmp = s->top;
    s->top = s->top->next;
    free(tmp);
    return x;
}

void destroyStack (stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }

    free(s);
}

/*solution function
input: n, b (b<10)
output: corresponding number in base b*/
long long baseConverse(int n, int b) {
    stack *s = createStack();
    long long res = 0;
    while (n != 0) {
        push(s, n%b);
        n /= b;
    }

    while (!isEmpty(s)) {
        res = res*10 + pop(s);
    } 

    destroyStack(s);
    return res;
}

int main() {
    stack *s = createStack();
    int n, b;
    /*printf("n = ");*/ scanf("%d", &n);
    /*printf("b = ");*/ scanf("%d", &b);

    long long res = baseConverse(n, b);
    //printf("the corresponding number in base %d is: ", b)

    printf("%lld", res);
    return 0;
}
