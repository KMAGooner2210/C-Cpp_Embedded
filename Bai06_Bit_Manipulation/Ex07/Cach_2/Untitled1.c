#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// Hàm d?ch trái và ki?m tra tràn bit
uint32_t shiftLeftAndCheckOverflow(uint32_t value, int n, bool *overflow) {
    const int BIT_SIZE = 8; 
    
   
    if (n < 0 || n >= BIT_SIZE) {
        *overflow = true;
        return 0;
    }
    
    
    uint32_t mask = ~0U << (BIT_SIZE - n);
    
   
    *overflow = (value & mask) != 0;
    
  
    uint32_t result = (value << n) & ((1U << BIT_SIZE) - 1);
    
    return result;
}

int main() {
    bool overflow;
    uint32_t value;
    int n;
    
  
    printf("Nhap gia tri so nguyen khong dau (value): ");
    if (scanf("%u", &value) != 1) {
        printf("Loi: Gia tri khong hop le!\n");
        return 1;
    }
    
    printf("Nhap so vi tri can dich trai (n): ");
    if (scanf("%d", &n) != 1) {
        printf("Loi: Gia tri khong hop le!\n");
        return 1;
    }
    
  
    uint32_t result = shiftLeftAndCheckOverflow(value, n, &overflow);
    
 
    printf("Input: value = %u, n = %d\n", value, n);
    printf("Output: %u, %s tran\n", result, overflow ? "co" : "khong");
    
    return 0;
}
