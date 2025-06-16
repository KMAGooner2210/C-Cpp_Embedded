#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>

bool shift_Left_and_Check(uint8_t value, int n, uint8_t *result) {
    const int MAX_VAL = 255;
    unsigned int mathRe = value * (1U << n);
    *result = (value << n) & 0xFF;
    bool overflow = mathRe > MAX_VAL;
    return overflow;
}

int main() {
    uint8_t test, result;
    int pos;
    char ch;
    while (1) {
        printf("Nhap 1 so (0 den 255): ");
        if (scanf("%hhu", &test) != 1) {
            while (getchar() != '\n');
            printf("Gia tri khong hop le, vui long nhap lai.\n");
            continue;
        }
        printf("Nhap so vi tri can dich: ");
        if (scanf("%d", &pos) != 1) {
            while (getchar() != '\n');
            printf("Gia tri khong hop le, vui long nhap lai.\n");
            continue;
        }
        if (pos < 0) {
            printf("So vi tri dich phai khong am, vui long nhap lai.\n");
            continue;
        }
        
        bool overflow = shift_Left_and_Check(test, pos, &result);
        
        printf("Input: Number = %hhu, shift = %d\n", test, pos);
        printf("Output: %u, Overflow: %s\n", result, overflow ? "Co" : "Khong");
        
        printf("Nhan ESC de thoat, nhap ky tu khac de tiep tuc.\n");
        while (getchar() != '\n'); // Clear buffer
        ch = getch(); // Read key directly without Enter
        if (ch == 27) { // 27 is the ASCII code for ESC
            break;
        }
    }
    printf("End.\n");
    return 0;
}
