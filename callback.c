#include <stdio.h>
#include <stdlib.h>

void myprint(char *s) {
    printf("\nMY (%s) PRINT\n", s);
}
int call(void *rec, void (*func)(void *)) {
    func(rec);
    return 1;
}
int* foreach(int array[], size_t len, int (*func)(int)) {
    int *rets = (int*) calloc(len, sizeof(int)), i;
    for (i = -1; ++i < len;) {
        rets[i] = func(array[i]);
    }
    return rets;
}
int doub(int val) {
    return val*2;
}
int main(void) {
    int values[] = {1,2,3,5}, i;
    int *res = foreach(values, 4, doub);
    for (i = -1; ++i < 4;) {
        printf("%d ", res[i]);
    }
    printf("\n");
    char *s = "superior";
    call(s,(void (*)(void *)) myprint);
    return 0;
}
