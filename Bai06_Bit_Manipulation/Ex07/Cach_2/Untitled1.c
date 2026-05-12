// ## **Ex7.	Dịch Bit và Kiểm Tra Tràn**
// o	Yêu cầu: Viết hàm dịch trái một số nguyên không dấu n vị trí và kiểm tra xem có xảy ra tràn bit không (bit bị mất ở bên trái).
// ```
// o	Ví dụ: 
// 	Input: value = 5 (nhị phân: 00000101), n = 2, giả sử 8 bit
// 	Output: 20 (nhị phân: 00010100), không tràn
// 	Input: value = 100 (nhị phân: 01100100), n = 3, giả sử 8 bit
// 	Output: 16 (nhị phân: 00010000), có tràn
// o	Gợi ý: Kiểm tra các bit cao trước khi dịch bằng bitmask.
// ```

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
