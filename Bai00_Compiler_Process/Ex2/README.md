Bước 1: Mở Cygwin Terminal

Bước 2: Tạo file max_test.c:

`nano max_test.c`

Bước 3: Dán code

```
#include<stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int main() {
    int x = 5, y = 3;
    int result = MAX(x++, y++);
    printf("result = %d, x = %d, y = %d\n", result, x, y);
    return 0;
}
```
Lưu: Ctrl+O, Enter, thoát: Ctrl+X

Bước 4: Biên dịch

```
gcc -o max_test max_test.c
```

Bước 5: Chạy
```
./max_test
```