Bước 1: Mở Cygwin Terminal

Bước 2: Tạo file max_test.c:

`nano debug_test.c`

Bước 3: Dán code

```
#include<stdio.h>
#ifdef DEBUG
#define DEBUG_PRINT(msg) printf("%s\n",msg)
#else
#define DEBUG_PRINT(msg)
#endif
int main(){
  printf("This is debug message);
  return 0;
}
```
Lưu: Ctrl+O, Enter, thoát: Ctrl+X

Bước 4: Biên dịch

```
gcc -o debug_test debug_test.c
```

Bước 5: Chạy
```
./debug_test

```

Trường hợp 1: Không định nghĩa DEBUG
```
Không in gì
```

Trường hợp 2: Định nghĩa DEBUG
Biên dịch:
```
gcc -DDEBUG -o debug_test debug_test.c
```
Lệnh này dùng cờ -DDEBUG để định nghĩa macro DEBUG trong quá trình biên dịch.

`
This is a debug message`

![Image](https://github.com/user-attachments/assets/54e27360-0f0b-4695-a2f0-8f6e302f30a7)