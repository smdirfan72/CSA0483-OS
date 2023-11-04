#include <stdio.h>
#include <stdlib.h>

int globalVar = 10; 

void stackAllocationExample() {
    int stackVar = 20; 
    printf("Stack-Allocated Variable: %d\n", stackVar);
}

void heapAllocationExample() {
    int heapVar = (int)malloc(sizeof(int));
    if (heapVar == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    *heapVar = 30; 

    printf("Heap-Allocated Variable: %d\n", *heapVar);

    free(heapVar);
}

int main() {
    printf("Static-Allocated Variable: %d\n", globalVar);

    stackAllocationExample();

    heapAllocationExample();

    return 0;
}
