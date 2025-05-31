#include <stdio.h>
#include "global.h"

int main() {
    printf("Access globalVar: %d\n", globalVar);
    globalVar = 200;
    printGlobal();
    return 0;
}
