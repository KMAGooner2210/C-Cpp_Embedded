#include <stdio.h>

void recursive_function(int n) {
    printf("Call %d\n", n);
    recursive_function(n + 1); // Không có di?u ki?n d?ng
}

int main() {
    recursive_function(1);
    return 0;
}
