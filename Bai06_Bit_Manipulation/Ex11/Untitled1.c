// ## **Ex11.Sử Dụng Bit Fields**

// Yêu cầu:

// •  Định nghĩa struct: 

// •	Sử dụng bit fields để lưu trữ thông tin cấu hình cho một thiết bị phần cứng: 
// ```
// o	enabled: 1 bit (bật/tắt thiết bị, 0 = tắt, 1 = bật).
// o	mode: 3 bit (chế độ hoạt động, giá trị từ 0-7, với các chế độ được xác định như sau): 
// 	0: Tắt (Off).
// 	1: Tiết kiệm năng lượng (Low Power).
// 	2: Bình thường (Normal).
// 	3: Hiệu suất cao (High Performance).
// 	4: Chẩn đoán (Diagnostic).
// 	5: Cập nhật firmware (Firmware Update).
// 	6: Chờ (Idle).
// 	7: Khẩn cấp (Emergency).
// o	priority: 4 bit (mức độ ưu tiên, giá trị từ 0-15, được phân loại như sau): 
// 	0-3: Thấp (Low).
// 	4-7: Trung bình (Medium).
// 	8-11: Cao (High).
// 	12-15: Rất cao (Critical).
// ```
// •	Tổng cộng 8 bit, giả định đóng gói trong 1 byte.

// •  Viết chương trình: 

// •	Khởi tạo: Khởi tạo struct với enabled = 1 (thiết bị bật), mode = 3 (chế độ hiệu suất cao), priority = 10 (ưu tiên cao).

// •	Kiểm tra tính hợp lệ: 
// ```
// o	Đảm bảo enabled là 0 hoặc 1.
// o	Đảm bảo mode từ 0 đến 7.
// o	Đảm bảo priority từ 0 đến 15.
// o	Nếu bất kỳ giá trị nào không hợp lệ, in thông báo lỗi và dừng chương trình.
// ```
// •	In trạng thái: 
// ```
// o	In giá trị của enabled với mô tả "Thiết bị: Bật" hoặc "Tắt".
// o	In giá trị của mode với tên chế độ tương ứng (ví dụ: "Chế độ: Hiệu suất cao").
// o	In giá trị của priority với mức ưu tiên tương ứng (ví dụ: "Ưu tiên: Cao").
// o	In biểu diễn nhị phân của toàn bộ struct (8 bit, dự kiến: 11001011).
// ```
#include <stdio.h>
#include <stdint.h>

union ConfigUnion {
    struct {
        uint8_t enabled : 1;   // LSB
        uint8_t mode : 3;
        uint8_t priority : 4;  // MSB
    } config;
    uint8_t raw;
};

void printBinary(uint8_t value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
    }
    printf("\n");
}

int isValidConfig(uint8_t enabled, uint8_t mode, uint8_t priority) {
    if (enabled > 1) {
        printf("Loi: Gia tri enabled khong hop le (%d), phai la 0 hoac 1.\n", enabled);
        return 0;
    }
    if (mode > 7) {
        printf("Loi: Gia tri mode khong hop le (%d), phai tu 0 den 7.\n", mode);
        return 0;
    }
    if (priority > 15) {
        printf("Loi: Gia tri priority khong hop le (%d), phai tu 0 den 15.\n", priority);
        return 0;
    }
    return 1;
}

const char* getModeName(uint8_t mode) {
    switch (mode) {
        case 0: return "Tat";
        case 1: return "Tiet kiem nang luong";
        case 2: return "Binh thuong";
        case 3: return "Hieu suat cao";
        case 4: return "Chan doan";
        case 5: return "Cap nhat Firmware";
        case 6: return "Cho";
        case 7: return "Khan cap";
        default: return "Khong xac dinh";
    }
}

const char* getPriorityLevel(uint8_t priority) {
    if (priority <= 3) return "Thap";
    if (priority <= 7) return "Trung binh";
    if (priority <= 11) return "Cao";
    return "Rat cao";
}

int main() {
    union ConfigUnion config;
    int input;

    printf("Nhap cau hinh thiet bi:\n");

    printf("Nhap enabled (0 = Tat, 1 = Bat): ");
    if (scanf("%d", &input) != 1 || input < 0 || input > 1) {
        printf("Loi: Nhap 0 va 1 cho enabled.\n");
        return 1;
    }
    config.config.enabled = input;

    printf("Nhap mode (0-7: 0=Tat, 1=Tiet kiem, 2=Binh thuong, 3=Hieu suat cao, 4=Chan doan, 5=Cap nhat, 6=Cho, 7=Khan cap): ");
    if (scanf("%d", &input) != 1 || input < 0 || input > 7) {
        printf("Loi: Nhap tu so 0 den 7 cho mode.\n");
        return 1;
    }
    config.config.mode = input;

    printf("Nhap priority (0-15): ");
    if (scanf("%d", &input) != 1 || input < 0 || input > 15) {
        printf("Loi: Nhap lai.\n");
        return 1;
    }
    config.config.priority = input;

    printf("Kiem tra cau hinh thiet bi:\n");
    if (!isValidConfig(config.config.enabled, config.config.mode, config.config.priority)) {
        printf("Cau hinh khong hop le, khong the tiep tuc.\n");
        return 1;
    }

    printf("Trang thai cau hinh:\n");
    printf("enabled = %d (Thiet bi: %s)\n", config.config.enabled, config.config.enabled ? "Bat" : "Tat");
    printf("mode = %d (Che do: %s)\n", config.config.mode, getModeName(config.config.mode));
    printf("priority = %d (Uu tien: %s)\n", config.config.priority, getPriorityLevel(config.config.priority));
    printf("Bieu dien nhi phan: ");
    printBinary(config.raw);

    return 0;
}
