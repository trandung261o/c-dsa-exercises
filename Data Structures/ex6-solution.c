#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct stackNode {
    char item;
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

void push(stack *s, char x) {
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

    char x = s->top->item;
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

/*solution
input a string of parens
return 1 if match else return 0*/
int parenMatch(char *x, int n) {
    int check = 1;
    stack *s = createStack();
    for (int i = 0; i < n; i++) {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
            push(s, x[i]);
        } else {
            if (isEmpty(s)) {check = 0; break;}

            char c = pop(s);
            if ((c=='(' && x[i]!=')') || (c=='[' && x[i]!=']') || (c=='{' && x[i]!='}')) {
                check = 0; break;
            }
        }
    }

    if (!isEmpty(s)) check = 0;

    destroyStack(s);
    return check;
}

int main() {
    char s[256];
    //printf("enter paren string: "); 
    scanf("%s", s);  
    //printf("\nresult is: ");  
    printf("%d", parenMatch(s, strlen(s)));

    return 0;
}
