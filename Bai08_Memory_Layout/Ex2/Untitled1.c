#include <stdio.h>
#include <stdlib.h>

int initialized_global = 10;
int uninitialized_global;

int main() {
    static int static_local;
    int local_var = 5;
    int *heap_var = malloc(sizeof(int));
    if (heap_var == NULL) {
        printf("Heap allocation failed!\n");
        return 1;
    }
    *heap_var = 20;

    printf("Address of initialized_global (.data): %p\n", (void*)&initialized_global);
    printf("Address of uninitialized_global (.bss): %p\n", (void*)&uninitialized_global);
    printf("Address of static_local (.bss): %p\n", (void*)&static_local);
    printf("Address of local_var (stack): %p\n", (void*)&local_var);
    printf("Address of heap_var (heap): %p\n", (void*)heap_var);

    free(heap_var);
    return 0;
}
