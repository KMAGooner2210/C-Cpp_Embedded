
#include <stdio.h>
#include <stdint.h>
#include <conio.h> // Thu vi?n cho getch() trên Windows

// Ð?nh nghia struct cho thanh ghi 16 bit v?i bit fields
typedef struct {
    uint16_t interrupt : 1;  // Bit 0: B?t/T?t ng?t (0-1)
    uint16_t direction : 2;  // Bit 1-2: Hu?ng truy?n (0-3)
    uint16_t speed : 5;      // Bit 3-7: T?c d? l?y m?u c?m bi?n (0-31)
    uint16_t reserved : 3;   // Bit 8-10: D? phòng, luôn 0
    uint16_t data : 5;       // Bit 11-15: Nhi?t d? (0-31, tuong ?ng 0-62°C)
} __attribute__((packed)) ControlRegister; // Ð?m b?o không padding

// Hàm ki?m tra giá tr? h?p l?
int isValidInput(uint16_t interrupt, uint16_t direction, uint16_t speed, uint16_t data) {
    if (interrupt > 1) {
        printf("Loi: interrupt phai la 0 hoac 1.\n");
        return 0;
    }
    if (direction > 3) {
        printf("Loi: direction phai trong khoang 0-3.\n");
        return 0;
    }
    if (speed > 31) {
        printf("Loi: speed phai trong khoang 0-31.\n");
        return 0;
    }
    if (data > 31) {
        printf("Loi: data phai trong khoang 0-31.\n");
        return 0;
    }
    return 1;
}

// Hàm in giá tr? nh? phân c?a thanh ghi 16 bit (t? MSB d?n LSB)
void printBinary(uint16_t value) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 11 || i == 8 || i == 3 || i == 1) printf(" "); // Phân tách các tru?ng
    }
    printf("\n");
}

// Hàm hi?n th? thông tin chi ti?t v? các tru?ng
void displayFieldInfo(ControlRegister reg, int isAfterProcessing) {
    printf("\nThong tin cac truong %s:\n", isAfterProcessing ? "sau xu ly" : "ban dau");
    // Interrupt
    printf("Interrupt: %u (%s)\n", reg.interrupt, reg.interrupt ? "Bat" : "Tat");
    // Direction
    const char *dir_str[] = {"Dung", "Tien", "Lui", "Xoay"};
    printf("Direction: %u (%s)\n", reg.direction, dir_str[reg.direction]);
    // Speed
    const char *speed_level;
    if (reg.speed == 0) speed_level = "Tat";
    else if (reg.speed <= 10) speed_level = "Thap";
    else if (reg.speed <= 20) speed_level = "Trung binh";
    else speed_level = "Cao";
    printf("Speed: %u/31 (%s)\n", reg.speed, speed_level);
    // Reserved
    printf("Reserved: %u (Luon giu 0)\n", reg.reserved);
    // Data
    float temperature = (reg.data / 31.0) * 62.0; // Tính nhi?t d? (°C)
    printf("Data: %u/31 (Nhiet do: %.1f°C)%s\n", reg.data, temperature,
           isAfterProcessing && reg.speed > 10 && reg.data > 0 ? " [Da tang do speed > 10]" : "");
}

// Hàm nh?p giá tr? v?i co ch? nh?p l?i và thoát b?ng ESC
int inputValue(const char *prompt, const char *guide, uint16_t *value, int min, int max) {
    char choice;
    while (1) {
        printf("%s\n%s", prompt, guide);
        printf("Gia tri: ");
        if (scanf("%hu", value) != 1) { // Ki?m tra l?i nh?p không ph?i s?
            while (getchar() != '\n'); // Xóa buffer
            printf("Loi: Vui long nhap so nguyen.\n");
        } else if (*value < min || *value > max) {
            printf("Loi: Gia tri phai trong khoang %d-%d.\n", min, max);
        } else {
            while (getchar() != '\n'); // Xóa buffer
            return 1; // Nh?p h?p l?
        }
        printf("Nhan ESC de thoat, hoac bat ky phim nao de nhap lai...");
        choice = getch(); // S? d?ng getch() t? conio.h
        if (choice == 27) { // Phím ESC
            return 0; // Thoát
        }
        printf("\n");
    }
}

int main() {
    // Bi?n d? luu giá tr? nh?p t? ngu?i dùng
    uint16_t init_interrupt, init_direction, init_speed, init_data;

    // Nh?p interrupt
    if (!inputValue("Nhap interrupt (0-1):\n",
                    "  0: Tat ngat\n  1: Bat ngat\n",
                    &init_interrupt, 0, 1)) {
        printf("Chuong trinh ket thuc.\n");
        return 1;
    }

    // Nh?p direction
    if (!inputValue("\nNhap direction (0-3):\n",
                    "  0: Dung\n  1: Tien\n  2: Lui\n  3: Xoay\n",
                    &init_direction, 0, 3)) {
        printf("Chuong trinh ket thuc.\n");
        return 1;
    }

    // Nh?p speed
    if (!inputValue("\nNhap speed (0-31):\n",
                    "  0: Tat\n  1-10: Thap\n  11-20: Trung binh\n  21-31: Cao\n",
                    &init_speed, 0, 31)) {
        printf("Chuong trinh ket thuc.\n");
        return 1;
    }

    // Nh?p data
    if (!inputValue("\nNhap data (0-31):\n",
                    "  Gia tri nhiet do (0-31, tuong ung 0-62 do C)\n"
                    "  Vi du: 20 = 40 do C\n",
                    &init_data, 0, 31)) {
        printf("Chuong trinh ket thuc.\n");
        return 1;
    }

    // Kh?i t?o thanh ghi
    ControlRegister reg;
    reg.interrupt = init_interrupt;
    reg.direction = init_direction;
    reg.speed = init_speed;
    reg.reserved = 0; // Ð?m b?o reserved = 0
    reg.data = init_data;

    // Ép ki?u v? uint16_t d? thao tác v?i toàn b? thanh ghi
    uint16_t *reg_value = (uint16_t*)&reg; // S?a t? (uint16_t*)® thành (uint16_t*)®

    // In giá tr? ban d?u
    printf("\nGia tri thanh ghi ban dau (nhi phan, MSB -> LSB):\n");
    printBinary(*reg_value);
    displayFieldInfo(reg, 0); // Hi?n th? thông tin ban d?u

    // Xóa bit reserved (d?m b?o luôn 0)
    *reg_value &= ~(0x7 << 8); // Bitmask: 11111000 11111111 (xóa bit 8-10)

    // Ki?m tra speed và tang data n?u speed > 10
    if (reg.speed > 10) {
        if (reg.data < 31) { // Ð?m b?o data không vu?t quá 31
            reg.data += 1;
        }
    }

    // In giá tr? sau x? lý
    printf("\nGia tri thanh ghi sau xu ly (nhi phan, MSB -> LSB):\n");
    printBinary(*reg_value);
    displayFieldInfo(reg, 1); // Hi?n th? thông tin sau x? lý

    return 0;
}

