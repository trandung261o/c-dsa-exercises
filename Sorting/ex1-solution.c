#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int m, int M) {
    return m + rand() % (M - m + 1);
}

int main() {
    int n, m, M;
    FILE *f = fopen("arr-n.txt", "w");
    if (f == NULL) {printf("error!\n"); exit(0);}

    printf("enter n: "); scanf("%d", &n);
    printf("enter m: "); scanf("%d", &m);
    printf("enter M: "); scanf("%d", &M);

    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
        int r = random(m, M);
        printf("%d ", r);
        fprintf(f, "%d ", r);
    }
    fclose(f);
    return 0;
}
