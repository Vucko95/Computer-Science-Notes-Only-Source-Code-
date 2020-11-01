//static_dynamic.c
#include <stdio.h>
#include <stdlib.h>

void staticEg() {
    int i;
    for (i=0; i < 5; i++)
        printf("S%d ", i);
}

void dynamicEg() {
    int *i = malloc(sizeof(int));
    for (*i=0; *i < 5; (*i)++)
        printf("D%d ", *i);

    // we will discuss free() later
    free(i); 
}
int main() {
    staticEg();
    dynamicEg();
}

