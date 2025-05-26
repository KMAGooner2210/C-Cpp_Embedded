#include <stdio.h>

void printSizes(int *ptr, int arr[], int size) {
    printf("Trong ham:\n");
    printf("Kich thuoc ptr: %zu bytes\n", sizeof(ptr));
    printf("Kich thuoc kieu int: %zu bytes\n", sizeof(*ptr));
    printf("Kich thuoc arr: %zu bytes\n", sizeof(arr));
}

int main() {
    int x = 10;
    int *intPtr = &x;
    int arr[5] = {1, 2, 3, 4, 5};

    printf("Trong main:\n");
    printf("Kich thuoc intPtr: %zu bytes\n", sizeof(intPtr));
    printf("Kich thuoc kieu int: %zu bytes\n", sizeof(*intPtr));
    printf("Kich thuoc mang arr: %zu bytes\n", sizeof(arr));

    printSizes(intPtr, arr, 5);

    return 0;
}
