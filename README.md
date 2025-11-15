# PHẦN 1: C ADVANCED
<details>
	<summary><strong>BÀI 1: COMPILER PROCESS VÀ C STANDARD</strong></summary>

## **BÀI 1: COMPILER PROCESS VÀ C STANDARD**

### **I. Compiler GCC-Quy trình biên dịch**

#### **1.1. Khái niệm**

* Trình biên dịch GCC (GNU Compiler Collection) là công cụ phổ biến để biên dịch mã C/C++

* Quá trình biên dịch một file .c thành file thực thi thường trải qua 4 giai đoạn chính.: **Preprocessing, Compilation, Assembly, Linking**

#### **1.2. Giai đoạn 1: Preprocessing (Tiền xử lý)**

*  **Mô tả:** Xử lý các chỉ thị tiền xử lý (#include, #define, #ifdef,...).
   
*  **Output:** Thường là file `.i`

*  **VD các lệnh:** 

    ◦ Tiền xử lý file source.c

        gcc -E source.c -o source.i

    ◦ Xem kết quả tiền xử lý

        cat source.i | head -20  # xem 20 dòng đầu

    ◦ Tiền xử lý với cảnh báo đầy đủ

        gcc -E -Wall source.c -o source.i

#### **1.3. Giai đoạn 2: Compilation (Biên dịch)**

*  **Mô tả:** Dịch mã C đã qua tiền xử lý thành mã Assembly (ngôn ngữ assembly).
   
*  **Output:** Thường là file `.s`

*  **VD các lệnh:** 

    ◦ Biên dịch từ file .i sang assembly

        gcc -S source.i -o source.s

    ◦ Hoặc biên dịch trực tiếp từ .c sang .s

        gcc -S source.c -o source.s

    ◦ Biên dịch với thông tin debug

        gcc -S -g source.c -o source.s

    ◦ Xem mã assembly

        cat source.s

#### **1.4. Giai đoạn 3: Assembly**

*  **Mô tả:** Dịch mã Assembly thành mã máy dưới dạng object code (binary).
   
*  **Output:** Thường là file `.o` hoặc `.obj`

*  **VD các lệnh:** 

    ◦ Dịch assembly sang object code

        gcc -c source.s -o source.o

    ◦ Hoặc dịch trực tiếp từ .c sang .o

        gcc -c source.c -o source.o

    ◦ Kiểm tra file object

        file source.o

    ◦ Xem disassembly

        objdump -d source.o

#### **1.5. Giai đoạn 4: Linking**

*  **Mô tả:** Kết hợp object code từ các file nguồn khác nhau và các thư viện (static/dynamic library) để tạo thành file thực thi cuối cùng.
   
*  **Output:** File thực thi (ví dụ: `.exe`)

*  **VD các lệnh:** 

    ◦ Liên kết một file object

        gcc source.o -o executable

    ◦ Liên kết nhiều file object

        gcc main.o utils.o math.o -o program

    ◦ Liên kết với thư viện math

        gcc source.o -o calculator -lm

    ◦ Liên kết với thư viện static

        gcc source.o -o app -static


### **II.The Preprocessor - Tiền xử lý trong C**

#### **2.1. Khái niệm**

* Bộ tiền xử lý là giai đoạn đầu tiên của quá trình biên dịch.Nó hoạt động dựa trên các chỉ thị(directives) bắt đầu bằng dấu `#`

* Nó biến đổi mã nguồn trước khi biên dịch chính thức, giúp mã linh hoạt và portable.

#### **2.2. Các chỉ thị tiền xử lý cơ bản**

* **#include <file>:** Chèn nội dung file header của hệ thống

  VD: `#include <iostream>`

* **#include "file":** Chèn nội dung file header do người dùng định nghĩa

  VD:  `#include "my_utility.h"`

* **#define NAME value:** Định nghĩa macro dạng hằng số.Mọi ký hiệu `NAME` sau đó sẽ được thay bằng `value`

  VD: `#define MAX_SIZE 100`

* **#define MACRO(params) body:** Định nghĩa macro dạng hàm

  VD: `#define SQUARE(x) ((x)*(x))`

* **#undef NAME:** Hủy định nghĩa 1 macro

  VD: `#undef MAX_SIZE`

* **#ifdef NAME, #ifndef NAME, #if expression, #else, #elif expression, #endif**

        #ifdef _WIN64
        // Mã chỉ biên dịch trên hệ thống Windows 64-bit
        #define PLATFORM "Windows 64-bit"
        #elif __linux__
        // Mã chỉ biên dịch trên Linux
        #define PLATFORM "Linux"
        #else
        // Mã cho các hệ thống khác
        #define PLATFORM "Unknown"
        #endif

#### **2.3. Built-in Macros**

* C cung cấp các macro tự động để hỗ trợ debug và logging:

  ◦ `__FILE__`: Tên file hiện tại.

  ◦ `__LINE__`: Số dòng hiện tại.

  ◦ `__DATE__`: Ngày biên dịch.

  ◦ `__TIME__`: Giờ biên dịch.

        #include <stdio.h>

        int main() {
            printf("File: %s\n", __FILE__);
            printf("Line: %d\n", __LINE__);
            printf("Date: %s\n", __DATE__);
            printf("Time: %s\n", __TIME__);
            return 0;
        }

        //Output

        File: example.c
        Line: 5
        Date: May 06 2025
        Time: 14:30:00

#### **2.4. Built-in Macros**

* `#error` và `#warning:` Báo lỗi hoặc cảnh báo trong preprocessing.

  ◦ Kiểm tra phiên bản C

        #if !defined(__STDC_VERSION__) || __STDC_VERSION__ < 201112L
        #error "This code requires C11 or later. Please use -std=c11 flag."
        #endif

  ◦ Kiểm tra compiler

        #ifndef __GNUC__
        #warning "This code is optimized for GCC. Other compilers may not work optimally."
        #endiff

  ◦ Kiểm tra kiến trúc

        #if !defined(__x86_64__) && !defined(__aarch64__)
        #error "Unsupported architecture. Only x86_64 and ARM64 are supported."
        #endif

* `Variadic Macros (C99+):` Macro với số lượng tham số biến đổi, hữu ích cho logging.

  ◦ Basic logging macro

        #define LOG(fmt, ...) printf("[%s:%d] " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)

  ◦ Logging với levels

        #define LOG_ERROR(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", ##__VA_ARGS__)
        #define LOG_WARN(fmt, ...)  printf("WARN:  " fmt "\n", ##__VA_ARGS__)
        #define LOG_INFO(fmt, ...)  printf("INFO:  " fmt "\n", ##__VA_ARGS__)
        #define LOG_DEBUG(fmt, ...) printf("DEBUG: " fmt "\n", ##__VA_ARGS__)

  ◦ Conditional debugging

        #ifdef DEBUG
        #define DBG(fmt, ...) printf("DBG: " fmt "\n", ##__VA_ARGS__)
        #else
        #define DBG(fmt, ...) // Trở thành no-op khi không debug
        #endif

  ◦ Assert với thông tin chi tiết

        #define ASSERT(condition, fmt, ...) \
            do { \
                if (!(condition)) { \
                    fprintf(stderr, "ASSERT FAILED [%s:%d]: " fmt "\n", \
                            __FILE__, __LINE__, ##__VA_ARGS__); \
                    abort(); \
                } \
            } while(0)

  ◦ Macro để đo thời gian

        #define TIME_EXECUTION(code) \
            do { \
                clock_t start = clock(); \
                code; \
                clock_t end = clock(); \
                printf("Execution time: %.2f ms\n", \
                    ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC); \
            } while(0)

### **III.C coding Standard & Misra C**

#### **3.1.Quy tắc đặt tên**

* Sử dụng tên biến/hàm rõ ràng,mang tính mô tả, tránh viết tắt khó hiểu

* Quy ước camelCase hay snake_case phải được nhất quán trong dự án

* Các hằng số thường viết hoa với dấu gạch dưới `MAX_BUFFER_SIZE`

#### **3.2.Thụt lề và định dạng**

* Sử dụng spaces hoặc tab nhất quán (thường là 2 hoặc 4 spaces)

* Đặt dấu `{ }` theo kiểu Allman hoặc K&R ,nhưng phải thống nhất

*  VD: Kiểu Allman
  
        if(condition)
        {
            //code
        }
  

*  VD: Kiểu K&R 
  
        if(condition){
            //code
        }

#### **3.3.Error Handling**

##### **3.3.1. Khái niệm**

* `errno` là biến global được định nghĩa trong `<errno.h>`

* Thread-safe trong các hệ thống hiện đại

* Mỗi thread có errno riêng

* Được set tự động bởi các hàm thư viện chuẩn khi có lỗi

##### **3.3.2. Các hàm xử lý lỗi**

* Trả về string mô tả lỗi từ errno

        char *strerror(int errnum);

* In thông báo lỗi ra stderr

        void perror(const char *s);

* VD:

        FILE *fp = fopen("nonexistent.txt", "r");
        if (fp == NULL) {
            perror("fopen failed");  // In: "fopen failed: No such file or directory"
            printf("Error code: %d, Message: %s\n", errno, strerror(errno));
        }

* Được set tự động bởi các hàm thư viện chuẩn khi có lỗi
  

##### **3.3.3. Các loại error codes phổ biến**

* **EACCES** - Permission denied

* **EEXIST** - File already exists  

* **EINVAL** - Invalid argument

* **ENOENT** - No such file or directory

* **ENOMEM** - Out of memory

* **ERANGE** - Math result not representable


#### **3.4. Misra C**

##### **3.4.1. Khái niệm**

* Là bộ coding standard nghiêm ngặt dùng để phát triển chủ yếu cho ngành công nghiệp ô tô và hệ thống nhúng yêu cầu độ tin cậy cao 

* Tránh các hành vi không xác định, không xác định cụ thể, và cấu trúc các ngôn ngữ C tiềm ẩn rủi ro
   
##### **3.4.2.Quy tắc 8.1(MISRA C:2012): Kiểu dữ liệu tường trình**

* Yêu cầu khai báo kiểu dữ liệu rõ ràng tránh sử dụng các kiểu mặc định như int không ký hiệu

* VD sai:

         int x = 10; //không rõ signed hay unsigned

* VD đúng:

         int32_t x = 10; //Rõ ràng là signed 32 bit
     

##### **3.4.3.Quy tắc 12.1(MISRA C:2012): Sử dụng dấu () để đảm bảo thứ tự ưu tiên**

* Tránh dựa vào thứ tự ưu tiên của toán tử

* VD sai:

         if (a + b * c > d)

* VD đúng:

         if ((a + (b*c)) > d)


##### **3.4.4.Quy tắc 17.7(MISRA C:2012): Kiểm tra giá trị trả về của hàm**

* Giá trị trả về của hàm không được bỏ qua trừ khi khi được ghi chú rõ ràng

* VD sai:

        printf("Hello"); //không kiểm tra giá trị trả về
       
* VD đúng:

    
        int result = printf("Hello");

        if(result < 0) {
        //Xử lý lỗi
        }

##### **3.4.5.Quy tắc 21.1(MISRA C:2012): Cấm cấp phát bộ nhớ động**

* Các hàm như **malloc,free** bị cấm vì gây rò rỉ trong hệ thống nhúng

* Thay vào đó sử dụng bộ nhớ tĩnh hoặc stack

* Bộ nhớ tĩnh: tồn tại suốt vòng đời chương trình,chỉ khởi tạo 1 lần

     
        static uint8_t static_buffer[128]={0};

        //Hàm sử dụng bộ nhớ tĩnh
        void a_buffer(uint8_t input){
        if(input >= 128){
            printf("Input too large for static buffer");
            return;
        }
        static_buffer[0] = input;
        printf("Static_buffer[0]= %u\n",static_buffer[0]);
        }
     

* Bộ nhớ stack: tồn tại trong phạm vi hàm, khởi tạo mỗi lần hàm gọi

     
        void b_buffer(uint8_t input){
        uint8_t stack_buffer[128] = {0};
        if (input >= 128){
            printf("Input too large for static buffer");
            return;
        }
        stack_buffer[0] = input;
        printf("Stack_buffer[0]= %u\n",stack_buffer[0]);
        }
    
    

##### **3.4.6.Quy tắc 9.1(MISRA C:2012): Khởi tạo biến**

* Tất cả biến phải được khởi tạo trước khi sử dụng để tránh undefined behavior

* VD sai:

        int x;
        if (x == 0) //x chưa khởi tạo
     
* VD đúng:


        int x = 0;
        if (x == 0)

##### **3.4.7.Quy tắc 14.4(MISRA C:2012): Hạn chế sử dụng goto**

* goto chỉ được phép trong các trường hợp đặc biệt như xử lý lỗi thống nhất

     
        if(error_condition){
        goto cleanup;
        }
        cleanup;
     

##### **3.4.8.Quy tắc 5.3(MISRA C:2012): Biến/hàm nội bộ nên là static**

* Các biến hoặc hàm chỉ sử dụng trong 1 fie nên được khai báo static để tránh xung đột tên

     
        static int cter = 10;
        static void inter_function(void){
        counter++;
        }
     
  
##### **3.4.9.Quy tắc 16.3(MISRA C:2012): Mỗi file.c nên có file.h tương ứng**

* Header file định nghĩa prototypes và guards (`#ifndef HEADER_H #define HEADER_H ... #endif`).

        #ifndef MY_MODULE_H
        #define MY_MODULE_H
        void my_function(void);
        #endif
        
     </details> 
<details>
	<summary><strong>BÀI 2: ADVANCED FUNCTION CONCEPTS AND DEBUG</strong></summary>

## **Bài 2: ADVANCED FUNCTION CONCEPTS AND DEBUG**

### **I.Variadic Functions**

#### **1.1.Định nghĩa**

*  Cho phép định nghĩa hàm với số lượng tham số không cố định, đánh dấu bằng `...` ở cuối danh sách tham số

*  Triển khai thông qua thư viện <stdarg.h>, cung cấp các macro và kiểu dữ liệu để xử lý danh sách tham số biến thiên.

#### **1.2.Thành phần chính**

*  **va_list:** 
   
    ◦ Đây là một kiểu dữ liệu đặc biệt dùng để lưu trữ danh sách tham số biến thiên. 
   
    ◦ Hoạt động như một con trỏ hoặc cấu trúc nội bộ để theo dõi các tham số trong danh sách

*  **va_start(ap, last_fixed_arg)**

    ◦ Macro này khởi tạo đối tượng `va_list(thường được gọi là ap)` để bắt đầu truy cập danh sách tham số biến thiên

    ◦ `last_fixed_arg` là tham số cố định cuối cùng được truyền vào hàm trước dấu ...(phần tham số biến thiên)

    ◦ Macro này thiết lập `ap` để trỏ đến tham số biến thiên đầu tiên

* **va_arg(ap,type):**

    ◦ Lấy giá trị của tham số tiếp theo trong danh sách được lưu trong `va_list`

    ◦ `type` là kiểu dữ liệu của tham số được truy xuất

    ◦ Mỗi lần gọi `va_arg`, con trỏ nội bộ của `va_list` sẽ di chuyển đến tham số tiếp theo 


* **va_end(ap):**

    ◦ Macro này dọn dẹp đối tượng `va_list` sau khi hoàn tất việc truy cập danh sách tham số 

    ◦ Nó đảm bảo giải phóng mọi tài nguyên được cấp phát bởi `va_start` và phải được gọi trước khi hàm kết thúc

   
#### **1.3.Quy tắc và lưu ý**

* **Tham số cố định:** Hàm này phải có ít nhất một tham số cố định trước dấu `...` .Tham số thường được dùng để xác định số lượng hoặc kiểu của các tham số biến thiên

* **Kiểu dữ liệu:** Phải biết chính xác kiểu dữ của từng tham số biến thiên để gọi `va_arg` đúng cách.Nếu chỉ định sai kiểu,chương trình có thể trả về sai hoặc lỗi

* **Không thể đếm trực tiếp số tham số:** Không có cách nào để tự động biết được số lượng tham số biến thiên, trừ khi sử dụng một tham số cố định để chỉ định

* **Cấu trúc chung:**
 
        #include<stdarg.h>

        return_type Function_name(fixed_arg, ...){
            va_list ap;
            va_start(ap, fixed_arg);
            //Xử lý các tham số biến thiên bằng va_arg
            va_end(ap);
            return result;
        } 
 
 * **VD:**
 
        #include<stdio.h>
        #include<stdarg.h>

        int sum(int count, ...){
            va_list ap;           // Khai báo khởi tạo va_list
            va_start(ap, count);  // Khởi tạo va_list với tham số cố định cuối cùng là count

            int total = 0;
            for(int i = 0; i < count; i++){
                total += va_arg(ap,int);
            }

            va_end(ap);
            return total;
        }

        int main(){
            printf("Sum of 1,2,3: %d\n",sum(3, 1, 2, 3));
            printf("Sum ofn 10,20,30,40: %d\n",sum(4, 10, 20, 30, 40));
            return 0;
        }
 
#### **1.4.Khi không sử dụng Variadic Function**

*   **Cú pháp phức tạp khi gọi hàm:**

    ◦ Người dùng phải tạo một mảng (int numbers[] = {1, 2, 3}) trước khi gọi hàm, ngay cả khi chỉ cần truyền một vài số.

    ◦ Điều này làm tăng số lượng mã lệnh và giảm tính trực quan so với cách gọi đơn giản của variadic functions, như sum(3, 1, 2, 3).

*   **Thiếu tính linh hoạt:**

    ◦ Nếu muốn truyền các số riêng lẻ (không phải từ một mảng có sẵn), người dùng phải tự xây dựng mảng trước. 

    ◦ Ví dụ, không thể gọi trực tiếp sum_array(1, 2, 3) mà phải làm như sau:

        int temp[] = {1, 2, 3};
        sum_array(temp, 3);

        Với variadic functions, bạn chỉ cần gọi sum(3, 1, 2, 3) mà không cần tạo mảng trung gian.


*  **Khó xử lý các tham số không đồng nhất:**

    ◦ Nếu bạn muốn mở rộng hàm để xử lý các kiểu dữ liệu khác nhau (ví dụ: tổng của int, double, hoặc thậm chí chuỗi), việc sử dụng mảng trở nên phức tạp hơn nhiều.  

    Bạn sẽ cần:

    ◦ Một mảng cho mỗi kiểu dữ liệu.

    ◦ Hoặc một cơ chế phức tạp để lưu trữ và phân tích các kiểu dữ liệu khác nhau.

    ◦ Với variadic functions, bạn có thể sử dụng chuỗi định dạng hoặc các tham số cố định để chỉ định kiểu, như trong `printf("%d %f %s", 42, 3.14, "hello")`

### **II. Inline Functions**

#### **2.1.Định nghĩa**

*  Từ khóa `inline` gợi ý trình biên dịch thay thế lời gọi hàm bằng nội dung thân hàm tại điểm gọi, thay vì thực hiện lời gọi hàm thông thường.

*  **Mục đích:** Giảm chi phí gọi hàm (lưu trữ trạng thái, chuyển ngăn xếp), tăng hiệu suất, đặc biệt trong hệ thống nhúng yêu cầu thời gian thực.


#### **2.2.Đặc điểm**

*  **Không đảm bảo:** 
   
    ◦ Trình biên dịch có thể bỏ qua gợi ý inline nếu hàm quá lớn hoặc không phù hợp. 

        #include <math.h>

        inline double complex_calculation(double x) {
            double result = 0.0;
            for(int i = 0; i < 100; ++i) {
                result += sin(x) * cos(x);
            }
            return result;
        }

        int main() {
            double a = complex_calculation(1.57);
            return 0;
        }
    
    
   
*  **Ứng dụng:**

    ◦ Thường dùng cho hàm nhỏ, đơn giản, được gọi thường xuyên trong vòng lặp hoặc mã thời gian thực.

* **Nhược điểm:**

    ◦ Tăng kích thước mã trong file thực thi do nội dung hàm được sao chép tại mỗi điểm gọi.

        inline int calculate(int a, int b) {
            return (a + b) * (a - b);
        }

        int main() {
            int x1 = calculate(5, 3);   // Trở thành: (5 + 3) * (5 - 3)
            int x2 = calculate(10, 2);  // Trở thành: (10 + 2) * (10 - 2)  
            int x3 = calculate(7, 4);   // Trở thành: (7 + 4) * (7 - 4)
            int x4 = calculate(8, 1);   // Trở thành: (8 + 1) * (8 - 1)
            
            return x1 + x2 + x3 + x4;
        }

* **Vị trí bộ nhớ:**

    ◦ Mã hàm inline thường nằm trong Text Segment, không có địa chỉ hàm riêng.

        #include <stdio.h>

        inline int multiply(int a, int b) {
            return a * b;
        }

        int main() {
            int result = multiply(3, 4);  // Trở thành: int result = 3 * 4;
            
            // LỖI: Không thể lấy địa chỉ hàm inline
            // int (*func_ptr)(int, int) = &multiply;
            
            printf("Result: %d\n", result);
            return 0;
        }

#### **2.3.Cú pháp**


        inline return_type function_name(parameters) {
            // Thân hàm
        }

#### **2.4.VD**


        #include <stdio.h>

        inline uint16_t square(uint16_t x) {
            return x * x;
        }

        int main() {
            uint16_t result = square(5); // Trình biên dịch thay thế bằng 5 * 5
            printf("Square: %u\n", result); // In: Square: 25
            return 0;
        }

#### **2.5.Lưu ý**

* **Kích thước hàm:** Chỉ inline hàm < 10 dòng để tránh tăng kích thước mã.

* **Tính tương thích:** Một số trình biên dịch nhúng (như GCC) yêu cầu khai báo inline trong file header hoặc cùng file với lời gọi.

* **Hiệu suất:** Hữu ích trong hệ thống nhúng cho các hàm điều khiển phần cứng hoặc xử lý ngắt nhanh.

### **III.Assert**

#### **3.1.Định nghĩa**

* **Macro** `assert(expression)` :

    ◦ Kiểm tra biểu thức tại runtime, nếu false (0), in lỗi và dừng chương trình qua `abort`

* **Mục đích:**

    ◦ Phát hiện bug trong development, không ảnh hưởng release (vô hiệu hóa bằng `NDEBUG`)   

#### **3.2.Thành phần chính** 

* **assert(expression):**

    ◦ Đánh giá biểu thức; thành công thì tiếp tục, thất bị thì in thông báo chi tiết (file, line, function)

        #include <stdio.h>
        #include <assert.h>

        int divide(int a, int b) {
            assert(b != 0);  // Đảm bảo không chia cho 0
            return a / b;
        }

        int main() {
            int result = divide(10, 2);  // Thành công: tiếp tục
            printf("Result: %d\n", result);
            
            result = divide(10, 0);     // Thất bại: dừng chương trình
            return 0;
        }

        // Output:

        Assertion failed: (b != 0), function divide, file test.c, line 5.

* **Thông báo lỗi:**

    ◦ Ví dụ: Assertion failed: (ptr != NULL), function myFunc, file main.c, line 42.

* **Vô hiệu hóa:**

    ◦ Định nghĩa `#define NDEBUG` trước `#include <assert.h>` để bỏ qua assert trong release


        #define NDEBUG  // VÔ HIỆU HÓA TẤT CẢ ASSERT - ĐẶT TRƯỚC KHI INCLUDE
        #include <stdio.h>
        #include <assert.h>

        void check_values(int x) {
            assert(x > 0);      // Bị vô hiệu hóa
            assert(x < 100);    // Bị vô hiệu hóa  
            printf("x = %d\n", x);
        }

        int main() {
            check_values(-5);   // Vẫn chạy bình thường dù giá trị sai
            check_values(200);  // Vẫn chạy bình thường
            printf("All assertions are disabled!\n");
            return 0;
        }

        //Output:

        x = -5
        x = 200
        All assertions are disabled!        


#### **3.3.Mục đích và cách sử dụng** 

* **Preconditions: Kiểm tra đầu vào**

    ◦  Đảm bảo các điều kiện phải đúng trước khi thực thi hàm,ví dụ: con trỏ NULL,chỉ số mảng hợp lệ

    ◦  VD: `assert(ptr!=NULL);`

* **Postconditions: Kiểm tra đầu ra**

    ◦ Đảm bảo các điều kiện phải đúng sau khi thực thi,ví dụ: giá trị trả về nằm trong khoảng mong đợi

    ◦ VD: `assert(result >=0);`

* **Invariants: Kiểm tra trạng thái cố định**

    ◦ Đảm bảo các điều kiện luôn đúng tại một thời điểm cụ thể trong chương trình, ví dụ: biến đếm không âm

    ◦ VD: `assert(counter>=0);`

#### **3.4. Cú pháp**

        #include <assert.h>

        return_type function_name(parameters) {
            assert(condition); // Kiểm tra điều kiện
            // Xử lý logic
            return result;
        }

#### **3.5. VD**

        #include <stdio.h>
        #include <assert.h>

        void print_array(int* arr, int size) {
            assert(arr != NULL); // Precondition: Con trỏ không được NULL
            assert(size > 0);    // Precondition: Kích thước phải dương
            for (int i = 0; i < size; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        }

        int main() {
            int numbers[] = {1, 2, 3};
            print_array(numbers, 3); // In: 1 2 3
            print_array(NULL, 0);    // Lỗi Assert
            return 0;
        }

#### **3.6. Lưu ý**

* **Không sử dụng cho logic chương trình:**

    ◦ Vì assert bị vô hiệu hóa trong chế độ release, không đặt mã logic quan trọng trong assert (e.g., assert(x = 5);).

        #include <stdio.h>
        #include <assert.h>

        //CÁCH SAI - DÙNG ASSIGNMENT TRONG ASSERT

        void bad_example(int x) {
            assert(x = 5);  // Gán x = 5 thay vì so sánh!
            printf("x = %d\n", x);
        }

        //CÁCH ĐÚNG - TÁCH BIỆT KIỂM TRA VÀ GÁN GIÁ TRỊ

        void good_example(int x) {
            // Kiểm tra điều kiện
            assert(x == 5);
            
            // Logic gán giá trị riêng (nếu cần)
            x = 10;
            printf("x = %d\n", x);
        }

        int main() {
            bad_example(3);   // Vẫn chạy nhưng sai logic!
            good_example(5);  // Chạy đúng
            return 0;
        }

* Không dùng cho lỗi runtime thông thường:

    ◦ assert chỉ dùng để phát hiện lỗi lập trình trong giai đoạn phát triển, không phù hợp cho lỗi runtime như input sai (dùng if-else hoặc try-catch).

        #include <stdio.h>
        #include <stdlib.h>
        #include <assert.h>

        // CÁCH SAI - DÙNG ASSERT CHO INPUT NGƯỜI DÙNG
        int bad_divide(int a, int b) {
            assert(b != 0);  // Nguy hiểm: bị disable trong release!
            return a / b;
        }

        // CÁCH ĐÚNG - DÙNG IF-ELSE CHO RUNTIME ERROR
        int good_divide(int a, int b) {
            if (b == 0) {
                fprintf(stderr, "Error: Division by zero!\n");
                exit(EXIT_FAILURE);
                // Hoặc return giá trị đặc biệt/error code
            }
            return a / b;
        }

        // CÁCH TỐT HƠN - DÙNG ASSERT KẾT HỢP ERROR HANDLING
        int better_divide(int a, int b) {
            // Assert cho developer errors (internal logic)
            assert(a != INT_MIN || b != -1);  // Tránh tràn số
            
            // Error handling cho runtime errors
            if (b == 0) {
                fprintf(stderr, "Runtime Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            
            return a / b;
        }

        int main() {
            int x, y;
            printf("Enter two numbers: ");
            scanf("%d %d", &x, &y);
            
            // good_divide(x, y);    //  An toàn
            // bad_divide(x, y);     //  Nguy hiểm khi dùng NDEBUG
            better_divide(x, y);     //  Tốt nhất
            
            return 0;
        }

* Khi không sử dụng Assert:

    ◦ Phải tự viết if-else để kiểm tra lỗi, làm tăng độ dài và phức tạp mã:


        if (ptr == NULL) {
            fprintf(stderr, "Error: NULL pointer in file %s, line %d\n", __FILE__, __LINE__);
            exit(1);
        }


</details> 
<details>
	<summary><strong>BÀI 3: ADVANCED POINTER</strong></summary>

## **BÀI 3: ADVANCED POINTER**

### **I.Function Pointers - Con trỏ hàm**

#### **1.1.Định nghĩa**

* Con trỏ hàm là một loại con trỏ đặc biệt trỏ đến địa chỉ của hàm thay vì trỏ đến dữ liệu như (`int*` hay `char*`)

*  **Mục đích:** 
   
    ◦  Lưu trữ địa chỉ của hàm để gọi hàm đó tại runtime
   
    ◦  Cho phép truyền hàm như một tham số(callback) hoặc lưu trữ trong cấu trúc dữ liệu

    ◦  Triển khai pattern như Strategy hoặc State Machine

 *  **Đặc điểm:**

    ◦ Hàm có địa chỉ cố định trong bộ nhớ (Text Segment)

    ◦ Con trỏ hàm phải khớp với **kiểu trả về(return type)** và **danh sách tham số** của hàm mà nó trỏ tới

#### **1.2.Cú pháp khai báo**

        `return_type (*pointer_name)(parameter_types);`
 
* **return_type:** Kiểu dữ liệu mà hàm trả về(VD: `int`,`void`, `double`)

* **pointer_name:** Tên của con trỏ hàm, được bao quanh bởi dấu `*`

* **parameter_type:** Danh sách các kiểu tham số mà hàm có thể nhận

        int (*opera)(int, int);     // Con trỏ đến hàm nhận 2 int, trả int
        void (*callback)(void);     // Con trỏ đến hàm không tham số, không trả về
        double (*compute)(float, int);      // Con trỏ đến hàm nhận float và int, trả double


*  => **Dấu `*(pointer_name)` là cần thiết** để phân biệt `con trỏ hàm` với `hàm thông thường`, nếu không có dấu `*`, khai báo sẽ trở thành function prototype thay vì con trỏ

#### **1.3.Gán giá trị cho con trỏ hàm**

* Để gán một hàm cho con trỏ hàm, có thể sử dụng tên hàm hoặc &function_name

 
        pointer_name = function_name;
        // hoặc
        pointer_name = &function_name;
 

* VD:
 
        #include<stdio.h>

        int add(int a, int b){
            return a + b;
        }

        int main(){

            int (*opera)(int, int);
            opera = add;        // Hoặc opera = &add;
            return 0;
        }
 

#### **1.4.Gọi hàm thông qua con trỏ**

* Có 2 cách để gọi hàm thông qua con trỏ hàm 

 
        (*pointer_name)(arguments);     // Dereference rõ ràng
        //hoặc
        pointer_name(arguments);        // Ngầm định
 

* VD:

        #include<stdio.h>

        int multiply(int a, int b){
            return a * b;
        }

        int subtract(int a, int b){
            return a - b;
        }

        int max(int a, int b){
            return (a > b) ? a : b;
        }

        int main(){

            int (*operation)(int, int);

            operation = multiply;
            printf("5 * 3 = %d\n", operation(5, 3));        // 15

            operation = multiply;
            printf("5 - 3 = %d\n", operation(5, 3));        // 2

            operation = max;
            printf("max(5, 3) = %d\n", operation(5, 3));    // 5

            return 0;
        }

#### **1.5.Ứng dụng**

* **Callbacks:**
   
    ◦ Truyền một hàm làm tham số cho hàm khác để gọi lại sau này

    ◦ VD: Hàm `qsort` trong thư viện chuẩn C

    
        #include <stdlib.h>
        #include <stdio.h>

        int compare(const void* a, const void* b) {
            return (*(int*)a - *(int*)b);
        }

        int main() {
            int arr[] = {5, 2, 8, 1};
            qsort(arr, 4, sizeof(int), compare);
            for (int i = 0; i < 4; i++) printf("%d ", arr[i]);  // 1 2 5 8
            return 0;
        }
    

* **State Machines:**

    ◦ Dùng con trỏ hàm để biểu diễn các trạng thái và hành vi trong máy trạng thái

    ◦ VD: Một chương trình chuyển đổi dựa trên trạng thái đầu vào

    
        #include <stdio.h>

        void state1() { 
            printf("In state 1\n"); 
            }
        void state2() { 
            printf("In state 2\n"); 
            }

        int main() {
            void (*current_state)() = state1;
            current_state();  // In: In state 1
            current_state = state2;
            current_state();  // In: In state 2
            return 0;
        }
    

* **Array của con trỏ hàm: Lưu nhiều hàm**

        #include <stdio.h>

        int add(int a, int b) { 
            return a + b; 
            }
        int subtract(int a, int b) {
             return a - b; 
            }


        int main() {
            int (*operations[])(int, int) = {add, subtract};
            printf("%d\n", operations[0](5, 3));  // 8
            printf("%d\n", operations[1](5, 3));  // 2
            return 0;
        }

* **Typedef cho con trỏ hàm:**

        typedef int (*Operation)(int, int);
        Operation opera = add;

#### **1.6.Lưu ý**

* **Kiểm tra khớp kiểu**

        #include <stdio.h>

        int add(int a, int b) { 
            return a + b; 
            }
        float divide(float a, float b) { 
            return a / b; 
            }

        int main() {
            // CON TRỎ SAI KIỂU - UNDEFINED BEHAVIOR
            int (*wrong_ptr)(int, int) = (int(*)(int,int))divide;  // Ép kiểu nguy hiểm
            
            int result = wrong_ptr(5, 2);  // UB! Hàm divide mong đợi float
            printf("Wrong result: %d\n", result); 
            
            return 0;
        }

* **Kiểm tra NULL**

        #include <stdio.h>

        int multiply(int a, int b) { return a * b; }

        int main() {
            int (*operation)(int, int) = NULL;  // Khởi tạo NULL
            
            // KHÔNG KIỂM TRA NULL - CRASH NẾU operation LÀ NULL
            // printf("Result: %d\n", operation(5, 3));  // SEGFAULT!
            
            // KIỂM TRA NULL TRƯỚC KHI GỌI
            if (operation != NULL) {
                printf("Result: %d\n", operation(5, 3));
            } else {
                printf("Operation is NULL!\n");
            }
            
            // Gán hàm hợp lệ
            operation = multiply;
            
            if (operation != NULL) {
                printf("Result: %d\n", operation(5, 3));  // 15
            }
            
            return 0;
        }

* **Quên `*` trong khai báo**

        #include <stdio.h>

        int add(int a, int b) { 
            return a + b; 
            }

        int main() {
            // QUÊN * TRONG KHAI BÁO CON TRỎ HÀM
            // int opera(int, int) = add;  // LỖI BIÊN DỊCH!
            
            // KHAI BÁO ĐÚNG
            int (*opera)(int, int) = add;
            
            // GỌI SAI THAM SỐ
            // printf("Result: %d\n", opera(5));  // LỖI: thiếu tham số
            
            // GỌI ĐÚNG THAM SỐ
            printf("Result: %d\n", opera(5, 3));  // 8
            
            return 0;
        }

### **II.Void Pointers - Con trỏ void**

#### **2.1.Định nghĩa**

* Con trỏ void`(void*)` là một loại con trỏ đặc biệt trong C,được gọi là con trỏ "generic" vì nó **có thể trỏ đến bất kỳ kiểu dữ liệu nào(int,char,float,struct,...)** mà không bị ràng buộc bởi kiểu cụ thể

* **Mục đích:**

   ◦ Cho phép xử lý dữ liệu một cách tổng quát, mà không cần biết trước kiểu dữ liệu

   ◦ Được sử dụng trong các tình huống cần cấp phát bộ nhớ động hoặc truyền dữ liệu mà kiểu chưa được xác Định

 * **Đặc điểm:**

   ◦ **Không thể dereference trực tiếp:** Vì trình biên dịch không biết kích thước hoặc kiểu dữ liệu mà `void*` trỏ đến, nên `*void_ptr` sẽ gây lỗi biên dịch

        #include <stdio.h>

        int main() {
            int x = 42;
            void* void_ptr = &x;
            
            // LỖI BIÊN DỊCH: Không thể dereference void*
            // printf("Value: %d\n", *void_ptr);
            
            // PHẢI ÉP KIỂU TRƯỚC
            printf("Value: %d\n", *(int*)void_ptr);  // Ép về int* trước
            
            return 0;
        }

        ???

        Compiler không biết: Kích thước dữ liệu (int = 4 bytes, char = 1 byte, ...)

   ◦ **Không hỗ trợ số học con trỏ:** Các phép toán như `void_ptr++` hoặc `void_ptr + n` không hợp lệ(hoặc không chuẩn) vì trình biên dịch không biết kích thước của kiểu dữ liệu

        #include <stdio.h>

        int main() {
            int arr[] = {10, 20, 30, 40, 50};
            void* void_ptr = arr;
            
            // LỖI: Số học con trỏ không hợp lệ
            // void_ptr++;  // error: increment of void pointer
            // void_ptr = void_ptr + 1;  // error: arithmetic on void pointer
            
            // PHẢI ÉP KIỂU TRƯỚC
            int* int_ptr = (int*)void_ptr;
            int_ptr++;  // Hợp lệ: nhảy 4 bytes
            printf("Second element: %d\n", *int_ptr);  // 20
            
            return 0;
        }

   ◦ **Ép kiểu:** Trước khi dereference hoặc thực hiện các thao tác, con trỏ void phải được ép kiểu sang một kiểu con trỏ cụ thể

        #include <stdio.h>

        int main() {
            float pi = 3.14159;
            void* generic_ptr = &pi;
            
            // SAI: Ép kiểu không phù hợp
            // int wrong_value = *(int*)generic_ptr;  // Interpret bits float như int
        
            // ĐÚNG: Ép về đúng kiểu gốc
            float correct_value = *(float*)generic_ptr;
            printf("Pi: %f\n", correct_value);  // 3.141590
            
            // VÍ DỤ ĐA KIỂU
            int number = 100;
            char letter = 'A';
            
            void* ptr;
            
            // Trỏ đến int
            ptr = &number;
            printf("As int: %d\n", *(int*)ptr);      // 100
            
            // Trỏ đến char  
            ptr = &letter;
            printf("As char: %c\n", *(char*)ptr);    // A
            
            return 0;
        }

  
#### **2.2.Cú pháp khai báo**


    void *pointer_name;

* `void`: Chỉ định rằng con trỏ không gắn với kiểu dữ liệu cụ thể

* `pointer_name`: Tên của con trỏ void

VD:

    void *generic_ptr;
    void *memory_block;


#### **2.3.Gán giá trị cho con trỏ void**

* Cách gán:

        pointer_name = &variable; //Gán địa chỉ của biến
        pointer_name = another_pointer; //Gán từ con trỏ khác


* VD:


        #include<stdio.h>
        int main(){
        int x = 42;
        char c = 'A';
        float f = 3.14;

        void *ptr;
        ptr = &x;
        ptr = &c;
        ptr = &f;

        return 0;
        }

#### **2.4.Sử dụng con trỏ void**

* Để sử dụng con trỏ void, cần **ép kiểu** sang kiểu con trỏ cụ thể trước khi **dereference** hoặc thực hiện thao tác

* **Cách sử dung:**

        *(type_cast *)pointer_name; //dereference sau khi ép kiểu

* **VD:**

        #include<stdio.h>

        int main(){
        int x = 42;
        void *ptr = &x;

        // Ép kiểu void* sang int* để dereference
        int *int_ptr = (int *)ptr;
        printf("Value of x: %d\n", *int_ptr);

        return 0;
        }

#### **2.5.Ứng dụng**

* **Hàm generic:**

    ◦ Các hàm như `memset`,`memcpy`,`qsort` trong thư viện C sử dụng `void*` để hoạt động trên bất kỳ kiểu dữ liệu nào

* VD:

  
        #include <stdio.h>
        #include <string.h>

        int main() {
            // KHỞI TẠO MẢNG INT VỚI GIÁ TRỊ 0
            int numbers[5];
            memset(numbers, 0, sizeof(numbers));  // void* memset(void* ptr, int value, size_t num)
            printf("After memset 0: ");
            for (int i = 0; i < 5; i++) {
                printf("%d ", numbers[i]);  // 0 0 0 0 0
            }
            printf("\n");
            
            //  KHỞI TẠO MẢNG CHAR VỚI GIÁ TRỊ 'A'
            char text[10];
            memset(text, 'A', sizeof(text) - 1);
            text[9] = '\0';
            printf("Text: %s\n", text);  // AAAAAAAAA
            
            // KHỞI TẠO CẤU TRÚC
            struct Point { 
                int x; 
                int y; 
                };
            struct Point p;
            memset(&p, -1, sizeof(p));  // Set all bytes to 0xFF
            printf("Point: (%d, %d)\n", p.x, p.y);  // (-1, -1)
            
            return 0;
        }

  

* **Cấp phát bộ nhớ động:**

    ◦ Các hàm như `malloc` và `calloc` trả về `void*` ,cho phép người dùng quyết định kiểu dữ liệu của bộ nhớ được cấp phát

    ◦ VD:

  
        #include<stdlib>

        int main(){
            //Cấp phát bộ nhớ cho 5 mảng số nguyên
            void *memory = malloc(5 * sizeof(int));
            int *int_array = (int *)memory;

            //Sử dụng mảng
            for(int i = 0;i < 5; i++){
            int_array[i] = i + 1;
            }

            //In mảng 
            for(int i = 0;i < 5; i++){
            printf("%d ", int_array[i]);
            }

            free(memory);
            return 0;
        }
  
* **Truyền tham số linh hoạt:**

    ◦ Dùng trong các hàm cần truyền dữ liệu mà kiểu không xác định trước 

    ◦ VD:
  
        #include<stdio.h>
        void print_data(void *data, char type){
            if (type == 'i'){
            printf("Integer: %d\n", *(int *)data);
            }else if (type == 'c'){
            printf("Char: %c\n", *(char *)data);
            }
        }

        int main(){
            int x = 100;
            char c = 'Z';

            print_data(&x,'i');
            print_data(&c, 'c');
            return 0;
        }
  

* **Lưu trữ trong cấu trúc dữ liệu:**

    ◦ Dùng để lưu trữ địa chỉ của các đối tượng có kiểu khác nhau trong danh sách liên kết, cây, hoặc các cấu trúc dữ liệu khác

    ◦ VD:
  
        #include <stdio.h>

        struct Node {
            void *data;
            char type;
        };

        int main() {
            struct Node node;
            int x = 42;
            node.data = &x;
            node.type = 'i';
            printf("Data: %d\n", *(int *)node.data);  // 42
            return 0;
        }
  

#### **2.6.Lưu ý**
  
*  **Kiểm tra ép kiểu:**

    ◦ Ép kiểu sai (ví dụ: ép void* trỏ đến int thành float*) có thể gây lỗi truy cập bộ nhớ hoặc kết quả không mong muốn.

    ◦ VD:
   
        int x = 42;
        void *ptr = &x;
        float *float_ptr = (float *)ptr; // Sai: Ép kiểu không đúng
        printf("%f\n", *float_ptr);     // Kết quả không xác định
   
* **Kiểm tra NULL:**

   ◦ Con trỏ void có thể là NULL, cần kiểm tra trước khi sử dụng.

   
        void *ptr = NULL;
        if (ptr != NULL) {
            int *int_ptr = (int *)ptr;
            printf("%d\n", *int_ptr);
            } else {
            printf("Pointer is NULL\n");
            }
   

* **Giải phóng bộ nhớ:**

   ◦ Khi dùng `void*` với `malloc` hoặc `calloc`, luôn nhớ giải phóng bộ nhớ bằng `free` để tránh rò rỉ bộ nhớ.

### **III.NULL Pointers - Con trỏ NULL**   

#### **3.1.Định nghĩa**

* Là một giá trị đặc biệt của con trỏ trong C/C++,biểu thị **con trỏ không trỏ đến bất kỳ địa chỉ bộ nhớ hợp lệ nào**.

* Nó thường được định nghĩa là `(void*)0` hoặc một macro tương đương(VD: `NULL` trong C hoặc `nullptr` trong C++)

* **Mục đích:**

    ◦ Khởi tạo con trỏ chưa được gán giá trị,tránh việc trỏ đến địa chỉ ngẫu nhiên

        #include <stdio.h>

        int main() {

                // AN TOÀN: Khởi tạo với NULL

            int *ptr = NULL;
            
                // NGUY HIỂM: Không khởi tạo (trỏ đến địa chỉ rác)

            // int *danger_ptr;
            // printf("%d", *danger_ptr);  // UNDEFINED BEHAVIOR!
            
            if (ptr == NULL) {
                printf("Pointer is safely initialized to NULL\n");
            }
            
            return 0;
        }

    ◦ Đánh dấu kết thúc của danh sách liên kết hoặc cấu trúc dữ liệu

        #include <stdio.h>
        #include <stdlib.h>

        struct Node {
            int data;
            struct Node* next;
        };

        int main() {

            // Tạo danh sách: 1 → 2 → NULL

            struct Node* head = malloc(sizeof(struct Node));
            head->data = 1;
            head->next = malloc(sizeof(struct Node));
            head->next->data = 2;
            head->next->next = NULL;  // Đánh dấu kết thúc
            
            // Duyệt danh sách

            struct Node* current = head;
            while (current != NULL) {  // Kiểm tra NULL để dừng
                printf("%d → ", current->data);
                current = current->next;
            }
            printf("NULL\n");
            
            return 0;
        }

    ◦ Biểu thị trạng thái lỗi hoặc không hợp lệ khi một hàm trả về con trỏ

        #include <stdio.h>
        #include <stdlib.h>

        // Hàm trả về con trỏ, NULL nếu lỗi

        int* create_array(int size) {
            if (size <= 0) {
                return NULL;  // Biểu thị lỗi
            }
            return malloc(size * sizeof(int));
        }

        int main() {
            int* arr = create_array(-5);  // Truyền size không hợp lệ
            
            if (arr == NULL) {
                printf("Error: Failed to create array\n");  // Xử lý lỗi
                return 1;
            }
            
            // Chỉ sử dụng arr nếu không NULL
            return 0;
        }

    ◦ Dùng để kiểm tra tính hợp lệ của con trỏ trước khi truy cập

        #include <stdio.h>

        void safe_print(int* ptr) {

            // LUÔN KIỂM TRA NULL TRƯỚC KHI TRUY CẬP
            if (ptr != NULL) {
                printf("Value: %d\n", *ptr);
            } else {
                printf("Error: NULL pointer encountered\n");
            }
        }

        int main() {
            int x = 42;
            int* ptr1 = &x;
            int* ptr2 = NULL;
            
            safe_print(ptr1);  // Value: 42
            safe_print(ptr2);  // Error: NULL pointer encountered
            
            return 0;
        }

* **Đặc điểm:**

    ◦ Gía trị của NULL Pointer thường là `0` trong bộ nhớ,nhưng cách biểu diên thực tế phụ thuộc vào hệ thống

    ◦ Trong C++,`nullptr` là lựa chọn an toàn hơn `NULL`,vì nó có kiểu riêng (`std::nullptr_t`) và tránh các lỗi liên quan đến ép Kiểu

    ◦ dereference một NULL Pointer (vd: `*ptr` hoặc ptr->member`) sẽ gây lỗi **segmentation fault**

        #include <stdio.h>

        int main() {
            int* ptr = NULL;
            
            //  SEGMENTATION FAULT: Truy cập bộ nhớ tại địa chỉ 0

            // printf("Value: %d\n", *ptr);
            // ptr->data = 10;  // Cũng gây segfault với struct
            
            printf("This line will print\n");
            // Bỏ comment dòng trên để thấy segfault
            printf("But this won't if we dereference NULL\n");
            
            return 0;
        }

#### **3.2.Gán giá trị NULL**

* Gán trị NULL cho con trỏ để đảm bao nó không trỏ đến địa chỉ không xác định

        int *ptr;
        ptr = NULL;


#### **3.3.Kiểm tra và sử dụng NULL Pointer**

* Kiểm tra con trỏ trước khi **dereference**
  
    ◦ Luôn kiểm tra xem con trỏ có phải là NULL hay không để tránh lỗi truy cập bộ nhớ

  
        if(ptr != NULL){
            *ptr  10;
        }else{
            printf("Con trỏ là NULL,không thể truy cập\n");
        }
  
* Trả về NULL từ hàm

    ◦ Hàm trả về con trỏ có thể trả về `NULL` để biểu thị lỗi hoặc không tìm thấy dữ liệu

  
        int *find_element(int arr[], int size, int value) {
            for(int i = 0; i < size; i++){
            if(arr[i] == value){
                return &arr[i];
            }
            }
            return NULL; //không tìm thấy
        }
  

#### **3.4.Ứng dụng**

* **Khởi tạo con trỏ:**

    ◦ Đảm bảo con trỏ không trỏ đến địa chỉ ngẫu nhiên trước khi được gán giá trị hợp lệ

  
        int *ptr = NULL;
        ptr = malloc(sizeof(int));
  

* **Kết thúc danh sách liên kết:**

    ◦ Trong danh sách liên kết, node cuối cùng có con trỏ `next` trỏ đến `NULL`

  
        struct Node{
            int data;
            struct Node *next;
        };
        struct Node *head = NULL; 
  

* **Kiểm tra lỗi:**

    ◦ Hàm cấp phát bộ nhớ như `malloc` hoặc `calloc` trả về `NULL` nếu không đủ bộ nhớ

  
        int *ptr = malloc(sizeof(int) * 10);
        if(ptr == NULL){
            printf("Cap phat bo nho that bai\n");
            exit(1);
        }
  

* **Callback và hàm trả về con trỏ:**

    ◦ Hàm trả về con trỏ có thể dùng `NULL` để báo trạng thái không hợp lệ

  
        void *process_data(){
            return NULL;
        }
  

#### **3.5.Lưu ý**

* **Kiểm tra NULL trước khi dereference**
  
    ◦ Luôn kiểm tra `if(ptr != NULL)` hoặc `if(ptr)`

* **Sự khác biệt giữa C và C++**
  
    ◦ Trong C,`NULL` là 1 macro, thường là `(void*)0`,có thể gây lỗi khi sử dụng ngữ cảnh ép kiểu

* **Tránh gán giá trị khác cho NULL**

* **Giải phóng bộ nhớ**

    ◦ Sau khi gọi `free(ptr)`,nên gán `ptr = NULL` để tránh sử dụng con trỏ đã được giải phóng

  
        free(ptr);
        ptr = NULL;
  

### **IV.Pointer to Pointer - Con trỏ trỏ đến con trỏ**

#### **4.1.Định nghĩa**

* Là biến lưu trữ **địa chỉ của 1 biến con trỏ khác**

* Quản lý con trỏ cấp thấp hơn hoặc hỗ trợ cấu trúc dữ liệu phức tạp

* **Mục đích:**
  
    ◦ Hỗ trợ quản lý cấu trúc dữ liệu, mảng động, danh sách liên kết

    ◦ Cho phép con trỏ thay đổi con trỏ gốc từ bên trong hàm

            #include <stdio.h>
            #include <stdlib.h>

            // CÁCH SAI - KHÔNG THAY ĐỔI ĐƯỢC CON TRỎ GỐC

            void allocate_wrong(int* ptr) {
                ptr = malloc(sizeof(int));  // Chỉ thay đổi bản sao
                *ptr = 42;
                printf("Inside wrong: %d\n", *ptr);  // 42 (nhưng chỉ là bản sao)
            }

            // GIẢI PHÁP - POINTER TO POINTER 

            void allocate_correct(int** ptr) {
                *ptr = malloc(sizeof(int));  // Thay đổi con trỏ gốc
                **ptr = 100;
                printf("Inside correct: %d\n", **ptr);  // 100
            }

            int main() {
                int* p = NULL;
                
                // CÁCH SAI
                allocate_wrong(p);
                // printf("After wrong: %d\n", *p);  // SEGFAULT! p vẫn là NULL
                
                // CÁCH ĐÚNG
                allocate_correct(&p);    
                printf("After correct: %d\n", *p);  // 100 - p đã được thay đổi
                
                free(p);
                return 0;
            }


            // Output:

                Inside wrong: 42
                Inside correct: 100  
                After correct: 100

* **Đặc điểm:**

    ◦ Con trỏ cấp 2(`**`) có thể trỏ đến con trỏ cấp 1 (`*`),và con trỏ cấp 1 trỏ đến dữ liệu thực tiếp

    ◦ Hỗ trợ nhiều cấp con trỏ(vd:`***` cho con trỏ cấp 3),nhưng cấp 2 là phổ biến nhất

        #include <stdio.h>

        int main() {
            int data = 42;          // Dữ liệu gốc
            
            //  CON TRỎ CẤP 1 - trỏ đến data

            int *ptr1 = &data;
            
            //  CON TRỎ CẤP 2 - trỏ đến ptr1 

            int **ptr2 = &ptr1;
            
            //  CON TRỎ CẤP 3 - trỏ đến ptr2

            int ***ptr3 = &ptr2;
            
            printf("Dữ liệu gốc: %d\n", data);           // 42
            
            printf("\n=== CẤP 1 ===\n");
            printf("ptr1 = %p\n", ptr1);                 // Địa chỉ của data
            printf("*ptr1 = %d\n", *ptr1);               // 42
            
            printf("\n=== CẤP 2 ===\n");
            printf("ptr2 = %p\n", ptr2);                 // Địa chỉ của ptr1
            printf("*ptr2 = %p\n", *ptr2);               // Địa chỉ của data  
            printf("**ptr2 = %d\n", **ptr2);             // 42
            
            printf("\n=== CẤP 3 ===\n");
            printf("ptr3 = %p\n", ptr3);                 // Địa chỉ của ptr2
            printf("*ptr3 = %p\n", *ptr3);               // Địa chỉ của ptr1
            printf("**ptr3 = %p\n", **ptr3);             // Địa chỉ của data
            printf("***ptr3 = %d\n", ***ptr3);           // 42
            
            return 0;
        }


        BỘ NHỚ:
        ┌───────────┐     ┌───────────┐     ┌───────────┐     ┌───────────┐
        │   data    │ ← ─ │    p1     │ ← ─ │    p2     │ ← ─ │    p3     │
        │    42     │     │ 0x1000    │     │ 0x2000    │     │ 0x3000    │
        └───────────┘     └───────────┘     └───────────┘     └───────────┘
        0x1000             0x2000             0x3000             0x4000

        *ptr1    = data    = 42
        **ptr2   = *ptr1   = data    = 42  
        ***ptr3  = **ptr2  = *ptr1   = data    = 42


* **Cú pháp:**

  
        type **pointer_name;
  
    ◦ `type:` Kiểu dữ liệu của biến cuối cùng mà con trỏ cấp 1 trỏ tới(vd: `int`,`char`,`float`)

    ◦ `pointer_name:` Tên con trỏ cấp 2

* **VD:**

        #include <stdio.h>

        int main() {
            int x = 10;
            int *ptr = &x;                  // Cấp 1
            int **ptr_to_ptr = &ptr;        // Cấp 2
            return 0;
        }


#### **4.2.Gán giá trị**

* Gán địa chỉ của một con trỏ cấp 1 cho con trỏ cấp 2


        pointer_name = &pointer_level_1;

* **VD:**


        int x = 10;
        int *ptr = &x;
        int **ptr_to_ptr = &ptr;

#### **4.3.Truy cập giá trị**

* `ptr_to_ptr:` Địa chỉ của con trỏ cấp 1

* `*ptr_to_ptr:` Giá trị của con trỏ cấp 1,tức là địa chỉ của dữ liệu cuối cùng

* `**ptr_to_ptr:` Giá trị dữ liệu cuối cùng mà con trỏ cấp 1 trỏ tới


        #include <stdio.h>
        int main() {
            int x = 10;
            int *ptr = &x;              // Con trỏ cấp 1 trỏ đến x
            int **ptr_to_ptr = &ptr;    // Con trỏ cấp 2 trỏ đến ptr
            
            printf("Địa chỉ của ptr: %p\n", ptr_to_ptr);        // Địa chỉ của ptr
            printf("Địa chỉ của x: %p\n", *ptr_to_ptr);         // Địa chỉ của x
            printf("Giá trị của x: %d\n", **ptr_to_ptr);        // Giá trị x = 10
            
            **ptr_to_ptr = 20; // Thay đổi giá trị x thông qua ptr_to_ptr
            printf("Giá trị mới của x: %d\n", x);               // x = 20
            return 0;
        }


#### **4.4.Ứng dụng**

* **Pass-by-reference cho con trỏ**

    ◦ Cho phép hàm thay đổi con trỏ cấp 1 được truyền vào

  
        #include <stdio.h>

        void change_pointer(int **pp, int *new_ptr) {
            *pp = new_ptr;  // Thay đổi con trỏ cấp 1
        }

        int main() {
            int x = 10, y = 20;
            int *ptr = &x;
            int **ptr_to_ptr = &ptr;
            printf("Before: %d\n", *ptr);  // 10
            change_pointer(ptr_to_ptr, &y);
            printf("After: %d\n", *ptr);   // 20
            return 0;
        }

* **Quản lý mảng các chuỗi:**

    ◦ Sử dụng `char **` để lưu trữ danh sách các chuỗi(mảng con trỏ kiểu `char *`)

  
        #include <stdio.h>

        int main(int argc, char **argv) {
            for (int i = 0; i < argc; i++) {
                printf("Arg %d: %s\n", i, argv[i]);
            }
            return 0;
        }

  

* **Cấp phát và quản lý mảng 2 chiều động**

    ◦ Mảng 2 chiều động được biểu diễn như mảng các con trỏ,mỗi con trỏ trỏ đến một hàng

  VD: Cấp phát mảng 2 chiều 3x4
  
        #include<stdio.h>
        #include<stdlib.h>

        int main(){
            int rows = 3, cols = 4;
            int **matrix;

            matrix = (int **)malloc(rows * sizeof(int *));
            for (int i = 0; i < rows; i++){
            matrix[i] = (int *)malloc(cols * sizeof(int));
            }

            //gán giá trị
            for (int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                matrix[i][j] = i * cols + j; 
            }
            }

            //In mảng
            for(int i = 0;i < rows; i++){
            for(int j = 0; j < cols; j++){
                printf("%d", matrix[i][j]);
            }
            printf("\n");
            }

            //Giải phóng bộ nhớ
            for(int i = 0;i < rows; i++){
            free(matrix[i]);
            }
            free(matrix);
            return 0;
            
        }
  

### **V.Const Pointer - Con trỏ hằng số và hằng con trỏ**   

#### **5.1.Định nghĩa**

* **Con trỏ hằng số và hằng con trỏ** là các con trỏ trong C/C++ sử dụng từ khóa `const` để hạn chế việc thay đổi giá trị mà con trỏ trỏ tới hoặc địa chỉ mà con trỏ lưu trữ

#### **5.2.Phân loại**

*  **1.** `const int *ptr` hoặc `int const *ptr`: 

    ◦  Con trỏ trỏ tới một giá trị hằng(`int` không thể thay đổi, nhưng địa chỉ mà `ptr` trỏ tới có thể thay đổi)

 *  **2.** `int * const ptr`: 

    ◦  Hằng con trỏ trỏ tới một giá trị `int`(**địa chỉ** mà `ptr` trỏ tới **không thể thay đổi**, **giá trị** tại địa chỉ đó **có thể thay đổi**)

 *  **3.** `const int * const ptr` hoặc `int const * const ptr`:

    ◦  Hằng con trỏ trỏ tới một giá trị hằng(**cả giá trị và địa chỉ đều không thể thay đổi**

#### **5.3.Đặc điểm**

* **Đọc từ phải sang trái:** Cú pháp `const` được hiểu theo cách đọc từ phải sang trái để xác định `const` áp dụng cho giá trị hay con trỏ

        const int *ptr     → "ptr là con trỏ đến int hằng"
        int * const ptr    → "ptr là con trỏ hằng đến int"  
        const int * const ptr → "ptr là con trỏ hằng đến int hằng"

* **Tính bất biến:** 
    
    ◦ `const int *ptr`: Giá trị tại `*ptr` là bất biến

            int a = 10, b = 20;
            
            // 1. const int *ptr - GIÁ TRỊ là bất biến
            const int *ptr1 = &a;
            // *ptr1 = 30;  //  LỖI: Không thể thay đổi giá trị
            ptr1 = &b;      //  ĐƯỢC: Có thể thay đổi địa chỉ
            printf("ptr1: %d\n", *ptr1);  // 20

    ◦ `int * const ptr`: Địa chỉ mà `ptr` lưu trữ là bất biến

            int a = 10, b = 20;
            int * const ptr2 = &a;
            *ptr2 = 30;     //  ĐƯỢC: Có thể thay đổi giá trị
            // ptr2 = &b;   //  LỖI: Không thể thay đổi địa chỉ
            printf("ptr2: %d\n", *ptr2);  // 30

    ◦ `const int * const ptr`: Cả giá trị và địa chỉ đều bất biến

            int a = 10, b = 20;
            const int * const ptr3 = &a;
            // *ptr3 = 40;  //  LỖI: Không thể thay đổi giá trị
            // ptr3 = &b;   //  LỚI: Không thể thay đổi địa chỉ
            printf("ptr3: %d\n", *ptr3);  // 30


* **Khởi tạo:** Hằng con trỏ phải được khởi tạo khi khai báo

            int x = 5;

            //  ĐÚNG - Khởi tạo ngay khi khai báo

            int * const ptr1 = &x;          
            const int * const ptr2 = &x;

            //  SAI - Thiếu khởi tạo

            // int * const ptr3;  // LỖI: hằng con trỏ phải được khởi tạo

#### **5.4.Cú pháp**


* **Con trỏ trỏ tới giá trị hằng**
    
        const [kiểu_dữ_liệu] *ptr;
    
* **Hằng con trỏ trỏ tới giá trị**
    
        [kiểu_dữ_liệu] * const ptr = &biến;
    
* **Hằng con trỏ tới giá trị hằng**
    
        const [kiểu_dữ_liệu] * const ptr = &biến;
    
#### **5.5.Gán giá trị và sử dụng**

* VD1: `const int *ptr`

  
        #include<stdio.h>
        int main(){
            int x = 10, y = 20;
            const int *ptr = &x; //ptr trỏ tới x
            ptr = &y; //thay đổi địa chỉ
            printf("%d\n", *ptr);
            return 0;
        }
  
* VD2: int * const ptr

  
        #include<stdio.h>
        int main(){
            int x = 10, y = 20;
            int * const ptr = &x;
            *ptr = 15;

            printf("%d\n", *ptr);
            return 0;
        }
  
* VD3: const int * const ptr
  

        #include<stdlib.h>
        int main(){
            int x = 10;
            const int * const ptr = &x;

            printf("%d\n", *ptr);
            return 0;
        }
  

### **VI.Size of Pointer - Kích thước của con trỏ**

#### **6.1.Định nghĩa**

* **Toán tử sizeof():**

    ◦ Toán tử `sizeof()` trả về kích thước (tính bằng byte) của 1 biến hoặc 1 kiểu dữ liệu

    ◦ Khi áp dụng với con trỏ, `sizeof(pointer_variable)` hoặc `sizeof(pointer_type)` trả về kích thước của chính biến con trỏ

    ◦ Khi áp dụng với toán tử giải tham chiếu `*`,`sizeof(*pointer_variable)` trả về kích thước của kiểu dữ liệu mà con trỏ trỏ tới

#### **6.2.Kích thước của con trỏ**

* Kích thước của con trỏ không phụ thuộc vào kiểu dữ liệu mà nó trỏ tới

    VD: `int*`, `char*`, `double*` hoặc `void*` đều có kích thước giống nhau trên cùng 1 hệ thống (4 bytes 32-bit; 8 bytes 64-bit).

* Kích thước của con trỏ phụ thuộc vào kiến trúc hệ thống

    ◦ **32-bit:** Con trỏ thường có kích thước **4 byte**

    ◦ **64-bit:** Con trỏ thường có kích thước 8 byte

* Con trỏ chỉ lưu trữ địa chỉ bộ nhớ,và kích thước của địa chỉ này phụ thuộc vào không gian địa chỉ mà hệ thống hỗ trợ

#### **6.3.Kích thước của kiểu dữ liệu mà con trỏ trỏ tới**

* Khi sử dụng `sizeof(*pointer_variable)`,kết quả trả về là kích thước của kiểu dữ liệu mà con trỏ trỏ tới


* VD:
        sizeof(int): thường là 4 byte
        sizeof(char): thường là 1 byte
        sizeof(double): thường là 8 byte


#### **6.4.Lưu ý**

* Kích thước của con trỏ có thể khác nhau giữa các hệ thống hoặc trình biên dịch

* Toán tử `sizeof()` là 1 toán tử thời gian biên dịch(compile-time) không phụ thuộc vào giá trị của biến tại thời điểm chạy


        #include<stdio.h>

        int main(){
        int *int_ptr;
        char *char_ptr;
        double *double_ptr;
        void *void_ptr;

        int a ='10';
        char b = 'A';
        double c = '3.14';
        
        //In kích thước của các con trỏ
        printf("Size cua int*: %zu bytes\n", sizeof(int_ptr));
        printf("Size cua char*: %zu bytes\n", sizeof(char_ptr));
        printf("Size cua double*: %zu bytes\n",sizeof(double_ptr));
        printf("Size cua void*: %zu bytes\n",sizeof(void_ptr));

        //In kích thước của các kiểu dữ liệu mà con trỏ trỏ tới
        printf("Size cua kieu int: %zu bytes\n",sizeof(*int_ptr));
        printf("Size cua kieu char: %zu bytes\n",sizeof(*char_ptr));
        printf("Size cua kieu double: %zu bytes\n",sizeof(*double_ptr));
        printf("Size cua kieu void: %zu bytes\n",sizeof(*void_ptr));

        //In kích thước của các biến
        printf("Size cua bien int: %zu bytes\n",sizeof(a));
        printf("Size cua bien char: %zu bytes\n",sizeof(b));
        printf("Size cua bien doublr: %zu bytes\n",sizeof(c));

        return 0;
        }


        // Output:

        Size cua int*: 8 bytes
        Size cua char*: 8 bytes
        Size cua double*: 8 bytes
        Size cua void*: 8 bytes
        Size cua kieu int: 4 bytes
        Size cua kieu char: 1 bytes
        Size cua kieu double: 8 bytes
        Size cua bien int: 4 bytes
        Size cua bien char: 1 bytes
        Size cua bien double: 8 bytes


* Kiểm tra kích thước con trỏ trong Mảng


        #include<stdio.h>
        int main(){
        int arr[5]={1, 2, 3, 4, 5};
        int *ptr = arr;

        printf("Size cua con tro ptr: %zu bytes \n",sizeof(ptr));
        printf("Size cua kieu du lieu ma ptr tro toi: %zu bytes\n", sizeof(*ptr));
        printf("Size cua mang arr: %zu bytes\n",sizeof(arr));

        return 0;
        }


        // Output:
        Size cua con tro ptr: 8 bytes
        Size cua kieu du lieu ma ptr tro toi: 4 bytes
        Size cua mang arr: 20 bytes


* Con trỏ hàm


        #include<stdio.h>

        void myFunction(){
        printf("This is a function.\");
        }

        int main(){
        void (*func_ptr)() = myFunction;

            printf("Kich thuoc cua con tro ham: %zu bytes\n", sizeof(func_ptr));

            return 0;
        }

        //Output:
        Kich thuoc cua con tro ham: 8 bytes

   </details> 


<details>
	<summary><strong>BÀI 4: SPECIAL VARIABLES</strong></summary>

## **BÀI 4: SPECIAL VARIABLES**

### **I.Tổng quan**

* Trong lập trình C, các biến và hàm được đặc trưng bởi bốn thuộc tính chính: **phạm vi (scope), thời gian sống (lifetime), vị trí bộ nhớ (memory location), và liên kết (linkage).** Những thuộc tính này quyết định cách truy cập, lưu trữ và liên kết các biến và hàm trong chương trình.

    ◦ **Phạm vi(Scope):** Xác định nơi mà tên biến hoặc hàm có thể được truy cập.

    ◦  **Thời gian tồn tại(Lifetime):** Khoảng thời gian biến tồn tại trong bộ nhớ

    ◦  **Vị trí bộ nhớ(Memory Location):** Khu vực bộ nhớ nơi biến được lưu trữ.

    ◦  **Liên kết(Linkage):** Quy định khả năng tham chiếu tên từ các tệp nguồn khác

#### **1.1. Phạm vi (Scope)** 

##### **1.1.1.Phạm vi khối (Block Scope):**

* Biến được khai báo bên trong một khối lệnh (giới hạn bởi cặp dấu `{}`).

* Chỉ có thể truy cập trong khối lệnh chứa nó.

* Ví dụ: Biến cục bộ trong hàm hoặc trong một khối for, while.

        #include <stdio.h>

        int main() {
            int x = 10;  // Block scope của main
            {
                int x = 20;  // Block scope con, che khuất x bên ngoài
                printf("Inner x: %d\n", x);  // 20
            }
            printf("Outer x: %d\n", x);  // 10
            return 0;
        }

##### **1.1.2.Phạm vi tệp (File Scope):**

* Biến hoặc hàm được khai báo bên ngoài tất cả các hàm trong một tệp.

        #include <stdio.h>

        // Khai báo bên ngoài tất cả hàm - file scope
        int globalCounter = 0;

        void increment() {
            globalCounter++;
        }

        void display() {
            printf("Counter: %d\n", globalCounter);
        }

        int main() {
            increment();
            display();  // Counter: 1
            increment();
            display();  // Counter: 2
            return 0;
        }

* Thường được gọi là biến hoặc hàm toàn cục (global) trong tệp đó.

        #include <stdio.h>

        int globalVar = 100;

        void functionA() {
            printf("functionA: %d\n", globalVar);  // Truy cập được
            globalVar = 200;
        }

        void functionB() {
            printf("functionB: %d\n", globalVar);  // Truy cập được
            globalVar = 300;
        }

        int main() {
            printf("main: %d\n", globalVar);  // Truy cập được
            functionA();
            functionB();
            printf("main: %d\n", globalVar);  // Truy cập được
            return 0;
        }

* Có thể truy cập ở bất kỳ đâu trong tệp, trừ khi bị hạn chế bởi từ khóa như `static`.

        #include <stdio.h>

        // Biến static - chỉ dùng trong tệp này
        static int privateCounter = 0;

        void increaseCounter() {
            privateCounter++;
            printf("Internal counter: %d\n", privateCounter);
        }

        int main() {
            increaseCounter();  // Internal counter: 1
            increaseCounter();  // Internal counter: 2
            // privateCounter không thể truy cập từ tệp khác
            return 0;
        }

##### **1.1.3.Phạm vi prototype hàm (Function Prototype Scope):**

* Áp dụng cho các tham số trong khai báo hàm (prototype).

* Chỉ tồn tại trong phần khai báo hàm và không ảnh hưởng đến định nghĩa hàm.


        int globalVar = 10; // File scope
        void myFunction(int param) { // param có Function Prototype Scope
            int localVar = 5; // Block scope
            printf("%d\n", localVar);
        }

#### **1.2.Thời gian sống (Lifetime)** 

##### **1.2.1.Tự động (Automatic):**

* Biến cục bộ (local variable) được khai báo trong một khối lệnh.

* Tồn tại chỉ khi khối lệnh chứa nó đang thực thi.

* Bị hủy khi thoát khỏi khối lệnh.

##### **1.2.2.Tĩnh (Static):**

* Bao gồm biến toàn cục, biến static cục bộ, và biến extern

* Tồn tại suốt vòng đời của chương trình, từ khi bắt đầu đến khi kết thúc.

* Chỉ được khởi tạo một lần khi chương trình khởi động.


        void counter() {
            static int count = 0; // Biến static, tồn tại suốt chương trình
            count++;
            printf("Count: %d\n", count);
        }

        int main() {
            counter(); // In: Count: 1
            counter(); // In: Count: 2
            counter(); // In: Count: 3
            return 0;
        }

##### **1.2.3.Động (Dynamic):**

* Bộ nhớ cấp phát qua `malloc/calloc/realloc`; tồn tại đến khi `free`.

* Không tự động giải phóng; quản lý thủ công để tránh leak.


		#include <stdio.h>
		#include <stdlib.h>  // Cho malloc/free
		
		int main() {
		    int n = 5;
		    int *arr = (int*)malloc(n * sizeof(int));  // Cấp phát động cho n phần tử int
		    
		    if (arr == NULL) {  // Kiểm tra lỗi cấp phát
		        printf("Lỗi cấp phát bộ nhớ!\n");
		        return 1;
		    }
		    
		    // Sử dụng: Gán giá trị
		    for (int i = 0; i < n; i++) {
		        arr[i] = i * 2;  // Ví dụ: 0, 2, 4, 6, 8
		    }
		    
		    // In ra
		    printf("Mảng: ");
		    for (int i = 0; i < n; i++) {
		        printf("%d ", arr[i]);
		    }
		    printf("\n");
		    
		    free(arr); 
		    arr = NULL; 
		    
		    return 0;
		}

#### **1.3. Vị trí bộ nhớ (Memory Location)** 

<img width="786" height="454" alt="Image" src="https://github.com/user-attachments/assets/66ad665c-7f57-4178-97d0-b01433a8e552" />

##### **1.3.1.Stack**

* Lưu trữ các biến cục bộ (automatic variables).

* Bộ nhớ được cấp phát và giải phóng tự động khi khối lệnh thực thi hoặc kết thúc.

        #include <stdio.h>

        void demoStack() {
            int localVar = 5;  //  Tự động hủy khi hàm kết thúc
            printf("Stack var: %d\n", localVar);
        }

        int main() {
            demoStack();
            // localVar ĐÃ BỊ HỦY - không tồn tại ở đây
            return 0;
        }

##### **1.3.2.Data Segment**

* Lưu trữ các biến toàn cục hoặc biến static đã được khởi tạo với giá trị khác 0.

    ◦  Biến global

        #include <stdio.h>

        int globalVar = 10;  //  Tồn tại suốt chương trình

        void useGlobal() {
            globalVar++;
            printf("Global: %d\n", globalVar);
        }

        int main() {
            useGlobal();  // Global: 11
            useGlobal();  // Global: 12 - giá trị được giữ lại
            return 0;
        }

    ◦  Biến static


        #include <stdio.h>

        void demoStatic() {
            static int staticVar = 5;  //  Tồn tại suốt chương trình
            staticVar++;
            printf("Static: %d\n", staticVar);
        }

        int main() {
            demoStatic();  // Static: 6
            demoStatic();  // Static: 7 - giá trị được giữ lại
            demoStatic();  // Static: 8 - giá trị được giữ lại
            return 0;
        }

##### **1.3.3.BSS Segment**

* Lưu trữ các biến toàn cục hoặc biến static chưa được khởi tạo hoặc được khởi tạo bằng 0.


        #include <stdio.h>

        // BSS Segment - chưa khởi tạo
        int uninitializedGlobal;

        // BSS Segment - khởi tạo = 0
        int zeroGlobal = 0;

        void demoBSS() {
            // BSS Segment - static chưa khởi tạo
            static int uninitializedStatic;
            
            // BSS Segment - static = 0
            static int zeroStatic = 0;
            
            printf("Uninit Global: %d\n", uninitializedGlobal);
            printf("Zero Global: %d\n", zeroGlobal);
            printf("Uninit Static: %d\n", uninitializedStatic);
            printf("Zero Static: %d\n", zeroStatic);
        }

        int main() {
            demoBSS();
            return 0;
        }

        //Output:

        Uninit Global: 0
        Zero Global: 0
        Uninit Static: 0
        Zero Static: 0

##### **1.3.4.Heap**

* Lưu trữ bộ nhớ được cấp phát động thông qua các hàm như malloc, calloc, hoặc realloc.

    ◦  Bộ nhớ động

        #include <stdio.h>
        #include <stdlib.h>

        int main() {
            //  Cấp phát heap
            int* heapVar = (int*)malloc(sizeof(int));
            *heapVar = 100;
            
            printf("Heap value: %d\n", *heapVar);  // 100
            
            //  Thay đổi giá trị
            *heapVar = 200;
            printf("After change: %d\n", *heapVar);  // 200
            
            //  Giải phóng heap
            free(heapVar);
            
            return 0;
        }

    ◦  Mảng động

        #include <stdio.h>
        #include <stdlib.h>

        int main() {
            //  Cấp phát mảng trên heap
            int size = 5;
            int* arr = (int*)malloc(size * sizeof(int));
            
            // Sử dụng mảng
            for(int i = 0; i < size; i++) {
                arr[i] = i * 10;
            }
            
            // In giá trị
            for(int i = 0; i < size; i++) {
                printf("arr[%d] = %d\n", i, arr[i]);
            }
            
            //  Giải phóng
            free(arr);
            
            return 0;
        }

##### **1.3.5.Text Segment (Code Segment)**

* Lưu trữ mã lệnh của chương trình (các hàm).

        #include <stdio.h>

        //  Text Segment - hàm được lưu ở đây
        void myFunction() {
            printf("This function is in Text Segment\n");
        }

        int add(int a, int b) {
            return a + b;  //  Mã thực thi trong Text Segment
        }

        int main() {
            //  Gọi hàm - thực thi code từ Text Segment
            myFunction();
            
            int result = add(5, 3);
            printf("Result: %d\n", result);
            
            return 0;
        }

#### **1.4. Liên kết (Linkage)** 

##### **1.4.1.Liên kết ngoài (External Linkage)**

* Tên có thể được truy cập từ các tệp khác.

* Áp dụng cho biến toàn cục (không có static) và hàm (không có static).

* Ví dụ: 

    ◦  file1.c

        #include <stdio.h>

        //  External linkage - có thể dùng từ file khác

        int globalCounter = 0;           // Biến toàn cục
        void displayMessage();           // Prototype hàm

        void incrementCounter() {
            globalCounter++;
            printf("Counter: %d\n", globalCounter);
        }

        int main() {
            displayMessage();            // Gọi hàm từ file2.c
            incrementCounter();
            displayMessage();            // Gọi hàm từ file2.c
            return 0;
        }

    ◦  file2.c

        #include <stdio.h>

        //  External linkage - khai báo lại biến từ file1.c
        extern int globalCounter;

        void displayMessage() {
            //  Truy cập biến từ file1.c
            printf("Message: Global counter = %d\n", globalCounter);
        }

    ◦  Cách biên dịch

        gcc file1.c file2.c -o program
        ./program

    ◦  Output

        Message: Global counter = 0
        Counter: 1
        Message: Global counter = 1

##### **1.4.2.Liên kết nội (Internal Linkage)**

* Tên chỉ có thể được truy cập trong tệp hiện tại.

* Áp dụng cho biến toàn cục hoặc hàm được khai báo với từ khóa static.

* VD:

    ◦  file1.c

        #include <stdio.h>

        //  Internal linkage - chỉ dùng trong file1.c
        static int privateCounter = 0;
        static void privateFunction();

        void publicFunction() {
            privateCounter++;
            printf("File1: privateCounter = %d\n", privateCounter);
            privateFunction();  //  Có thể gọi trong cùng file
        }

        static void privateFunction() {
            printf("This is private to file1.c\n");
            privateCounter += 10;  //  Có thể truy cập trong cùng file
        }

        int main() {
            publicFunction();
            publicFunction();
            return 0;
        }

    ◦  file2.c

        #include <stdio.h>

        //  KHÔNG THỂ truy cập từ file khác

        // extern int privateCounter;  // Lỗi biên dịch
        // void privateFunction();     // Lỗi biên dịch

        void tryToAccess() {

            //  Tất cả đều không thể truy cập

            // printf("Trying to access: %d\n", privateCounter);
            // privateFunction();
            printf("Cannot access private variables/functions from file1.c\n");
        }

    ◦   Biên dịch và chạy

        gcc file1.c file2.c -o program
        ./program

    ◦  Output

		File1: privateCounter = 1
		This is private to file1.c
		Private: 11
		File1: privateCounter = 12
		This is private to file1.c
		Private: 22

##### **1.4.3.Không liên kết (No Linkage)**

* Tên chỉ có thể truy cập trong phạm vi khai báo (thường là biến cục bộ).


        int globalVar = 10; // External Linkage
        static int staticGlobalVar = 20; // Internal Linkage
        void myFunction() {
            int localVar = 5; // No Linkage
        }


### **II.Special Variables**

#### **2.1. Extern**

##### **2.1.1.Khái niệm**

* extern khai báo tên có định nghĩa ở nơi khác (external linkage).

##### **2.1.2.Mục đích**

* **Khi dùng với biến:**

    ◦ Nó thông báo cho trình biên dịch biến này được định nghĩa ở đâu đó, có thể ở trong file này hoặc file khác.
    
    ◦ Đừng cấp phát bộ nhớ cho nó tại đây, chỉ cần biết kiểu và tên của nó thôi.
    
    ◦ Linker sẽ tìm định nghĩa sau

* **Khi dùng với hàm:**

    ◦ Nó khai báo một hàm mà định nghĩa của nó có thể ở file khác (hoặc ở phần sau của file hiện tại).

    ◦ Đối với hàm ,`extern` thường là ngầm định khi bạn khai báo prototype ở phạm vi toàn cục

##### **2.1.3.Ứng dụng**  

* **Chia sẻ biến toàn cục**
 
    ◦ File 1 (vd: config.c):

    
        //Định nghĩa biến toàn cục
        int max_users = 100;
        const char * server_name = "KMA";
    

    ◦ File 2 (vd: main.c):
    
        #include <stdio.h>

        
        extern int max_users;
        extern const char* server_name; // Quan trọng: phải khớp kiểu, kể cả const

        void display_config() {
        printf("Server Name: %s\n", server_name);
        printf("Max Users: %d\n", max_users);
        }

        int main() {
        display_config();
        max_users = 150; 
        printf("Updated Max Users: %d\n", max_users);
        return 0;
        }

    ◦ Cách biên dịch

        # Cách 1: Biên dịch cùng lúc
        gcc config.c main.c -o program
        ./program

        # Cách 2: Biên dịch riêng rẽ
        gcc -c config.c                # Tạo config.o
        gcc -c main.c                  # Tạo main.o  
        gcc config.o main.o -o program # Liên kết
        ./program
    
* **Khai báo hàm từ file khác**

    ◦ File 1 (vd:math_utils.c):
    
        //Định nghĩa hàm
        int add(int a, int b){
        return a + b;
        }
    
    ◦ File 2 (vd:math_utils.h):

    
        #ifndef MATH_UTILS_H
        #define MATH_UTILS_H

        // Khai báo hàm (extern là ngầm định cho khai báo hàm ở phạm vi file)
        // Viết tường minh extern cũng không sai: extern int add(int, int);
        int add(int a, int b);

        #endif


    ◦ File 3 (vd:main.c):

    
        #include <stdio.h>
        #include "math_utils.h" // Bao gồm khai báo hàm

        int main() {
        int result = add(5, 3);
        printf("Sum: %d\n", result);
        return 0;
        }
    
    ◦ Cách biến dịch:

        # Cách 1: Biên dịch trực tiếp
        gcc math_utils.c main.c -o math_program
        ./math_program

        # Cách 2: Biên dịch từng bước
        gcc -c math_utils.c           # Tạo math_utils.o
        gcc -c main.c                 # Tạo main.o
        gcc math_utils.o main.o -o math_program
        ./math_program


#### **2.2.Static**

##### **2.2.1.Biến static cục bộ**

* **Lifetime:** 

    ◦ Tồn tại suốt vòng đời chương trình, được cấp phát trong **data segment (khởi tạo khác 0)** hoặc **bss segment (khởi tạo bằng 0 hoặc không khởi tạo)**

* **Scope:** 

    ◦ Chỉ truy cập được bên trong Hàm

* **Khởi tạo:** 

    ◦  Chỉ khởi tạo **1 lần** khi hàm được gọi lần đầu, 

    ◦  Giữ giá trị giữa các lần gọi,Giá trị của nó không bị mất đi và được duy trì giữa các lần gọi hàm. 
    
    ◦  Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.


        void counter() {
            static int count = 0; // Chỉ khởi tạo một lần
            count++;
            printf("Count: %d\n", count);
        }

        int main() {
            counter(); // In: Count: 1
            counter(); // In: Count: 2
            counter(); // In: Count: 3
            return 0;
        }



##### **2.2.2.Biến static toàn cục**

* **Lifetime:** 

    ◦ Tồn tại **suốt vòng đời chương trình**,từ khi chương trình khởi động(trước khi hàm `main` chạy) đến khi chương trình kết thúc

* **Scope:** 

    ◦ Chỉ được truy cập **bên trong file`.c` được định nghĩa,không thể truy cập từ file khác,kể cả khi sử dụng extern

* **Khởi tạo:** 

    ◦ Chỉ khởi tạo một lần duy nhất tại thời điểm chương trình khởi động (trước khi main được gọi).

    ◦ Giá trị của biến toàn cục static không bị mất và được duy trì trong suốt thời gian chương trình chạy.

    ◦ Mỗi lần giá trị biến được thay đổi (bởi bất kỳ hàm nào trong cùng file), giá trị mới sẽ được giữ và sử dụng cho các lần truy cập tiếp theo trong file.


        // file1.c
        static int globalCount = 0; // Khởi tạo một lần khi chương trình chạy

        void increment() {
            globalCount++;
            printf("Global Count: %d\n", globalCount);
        }

        void print() {
            printf("Current Count: %d\n", globalCount); // Giá trị được duy trì
        }

        int main() {
            increment(); // In: Global Count: 1
            increment(); // In: Global Count: 2
            print();     // In: Current Count: 2
            return 0;
        }

        // file2.c
        extern int globalCount; // Lỗi: không tìm thấy globalCount


#### **2.3.Weak Symbols**  

##### **2.3.1.Định nghĩa**

* Từ khóa `__attribute__((weak))` (trong GCC) đánh dấu một hàm hoặc biến là`weak` symbol, cho phép định nghĩa khác thay thế nó trong quá trình liên kết (linking).

* Mục đích: Cung cấp một định nghĩa mặc định có thể được ghi đè bởi định nghĩa mạnh hơn (strong symbol) trong file khác.

##### **2.3.2.Đặc điểm**

* **Liên kết (Linkage):** Weak symbols có liên kết ngoài (external linkage), nhưng ưu tiên thấp hơn strong symbols.

* **Ứng dụng:**Thường dùng trong hệ thống nhúng để: 
  
    ◦ Cung cấp hàm mặc định cho xử lý ngắt (ISR) hoặc hàm khởi tạo phần cứng.

    ◦ Cho phép người dùng ghi đè hàm mặc định mà không sửa mã nguồn gốc.

* **Không bắt buộc:** Nếu không có định nghĩa mạnh hơn, weak symbol sẽ được sử dụng.

##### **2.3.3.Cú pháp**


    __attribute__((weak)) return_type function_name(parameters) {
        // Thân hàm mặc định
    }


##### **2.3.4.VD1**


    // default_isr.c
    #include <stdio.h>

    __attribute__((weak)) void TIM1_IRQHandler(void) {
        printf("Default TIM1 ISR\n");
    }

    // user_isr.c
    void TIM1_IRQHandler(void) {  // Strong, ghi đè
        printf("User TIM1 ISR\n");
    }

    // main.c
    int main() {
        TIM1_IRQHandler();  // User TIM1 ISR
        return 0;
    }


* **Kết quả:** In ra `User-defined TIM1 Interrupt Handler` vì định nghĩa mạnh trong `user_isr.c` ghi đè định nghĩa yếu

##### **2.3.5.VD2**


        // default_config.c
        #include <stdio.h>

        __attribute__((weak)) int default_value = 42;

        // user_config.c
        int default_value = 100;  // Strong, ghi đè

        // main.c
        int main() {
            printf("Value: %d\n", default_value);  // 100
            return 0;
        }


#### **2.3.6.Lưu ý**

* **Hỗ trợ trình biên dịch:** __attribute__((weak)) là tính năng của GCC; các trình biên dịch khác có thể sử dụng cú pháp khác (như `#pragma weak`).

* **Ứng dụng nhúng:** Thường dùng trong các thư viện hoặc mã khởi động (bootloader) để cho phép tùy chỉnh xử lý ngắt hoặc hàm khởi tạo.

* **Kiểm tra NULL:** Nếu không có định nghĩa mạnh, cần đảm bảo weak symbol xử lý an toàn.

#### **2.4.Volatile**  

##### **2.4.1.Định nghĩa**

* Từ khóa `volatile` ngăn trình biên dịch tối ưu hóa (như lưu trữ giá trị trong thanh ghi hoặc sắp xếp lại lệnh) các thao tác đọc/ghi biến, vì giá trị của biến có thể thay đổi bất ngờ từ các nguồn bên ngoài (phần cứng, ngắt, hoặc luồng khác).

##### **2.4.2.Hành vi**

* Buộc trình biên dịch đọc/ghi trực tiếp từ/tới bộ nhớ mỗi khi truy cập biến.

* Đảm bảo thứ tự thao tác không bị thay đổi do tối ưu hóa.

#### **2.4.3.Các trường hợp sử dụng**

* **Memory-mapped peripheral registers:** Truy cập các thanh ghi phần cứng(như GPIO,UART) để đảm bảo đọc/ghi chính xác giá trị hiện tại

        #define GPIO_PORTA_DATA (*(volatile uint32_t *)0x40058000) // Địa chỉ thanh ghi GPIO

        void toggle_pin(void) {
            GPIO_PORTA_DATA |= (1 << 5);  // Ghi giá trị để bật bit 5 (pin 5)
            GPIO_PORTA_DATA &= ~(1 << 5); // Ghi giá trị để tắt bit 5
        }

* **Biến toàn cục trong ISR:** Đảm bảo biến toàn cục được truy cập bởi các routine xử lý ngắt luôn phản ánh giá trị mới nhất


        #include <stdio.h>

        volatile uint8_t flag = 0;

        void ISR_Tim1(void) {
            flag = 1;
        }

        int main() {
            while (1) {
                if (flag) {
                    flag = 0;
                    printf("ISR triggered\n");
                }
            }
            return 0;
        }

* **Biến toàn cục trong xử lý đa nguồn:** Đảm bảo giá trị biến được cập nhật đúng khi được truy cập bởi nhiều tác vụ


        #include <stdio.h>
        #include <threads.h>  // C11

        volatile int shared_counter = 0;

        int thread1_func(void* arg) {
            for (int i = 0; i < 5; i++) {
                shared_counter++;
                printf("Thread 1: %d\n", shared_counter);
                thrd_yield();  // Yield để tránh race
            }
            return 0;
        }

        int thread2_func(void* arg) {
            for (int i = 0; i < 5; i++) {
                shared_counter++;
                printf("Thread 2: %d\n", shared_counter);
                thrd_yield();
            }
            return 0;
        }

        int main() {
            thrd_t t1, t2;
            thrd_create(&t1, thread1_func, NULL);
            thrd_create(&t2, thread2_func, NULL);
            thrd_join(t1, NULL);
            thrd_join(t2, NULL);
            printf("Final: %d\n", shared_counter);  // ~10
            return 0;
        }

#### **2.5.Register**

##### **2.5.1.Định nghĩa**

* Biến register được sử dụng để gợi ý cho trình biên dịch rằng 1 biến nên được lưu trữ trong **thanh ghi CPU thay vì RAM**

* Thường được sử dụng cho các biến được truy cập thường xuyên trong vòng lặp hoặc tính toán.

##### **2.5.2.Đặc điểm**

* **Tăng hiệu năng:** Giảm thời gian truy cập bằng cách lưu biến trong thanh ghi CPU.

* **Không đảm bảo:** Trình biên dịch có thể bỏ qua gợi ý register nếu không có thanh ghi khả dụng.

* **Không thể** lấy địa chỉ của biến register (vì nó không nằm trong RAM).

* **Không áp dụng** cho các biến lớn hoặc cấu trúc phức tạp.

        #include <stdio.h>

        void compute() {
            register int i;  // Gợi ý register
            long sum = 0;
            for (i = 0; i < 1000000; i++) {
                sum += i;
            }
            printf("Sum: %ld\n", sum);
        }

        int main() {
            compute();
            return 0;
        }

#### **2.6.Auto**

##### **2.6.1.Định nghĩa**

* `auto` là lớp mặc định cho local vars (block scope, automatic lifetime, stack).

* **Phạm vi:** Block scope

* **Thời gian sống:** Automatic lifetime

* **Vùng nhớ:** Stack

##### **2.6.2.Cú pháp**

* `auto kieudulieu tenbien [= giatri];`

##### **2.6.3.Đặc điểm**

* Phạm vi khối (Block Scope)

        #include <stdio.h>

        void demoBlockScope() {
            int outer = 10;  //  Auto - phạm vi hàm
            
            if (outer > 5) {
                auto int inner = 20;  //  Auto - phạm vi khối if
                printf("Inside if: outer=%d, inner=%d\n", outer, inner);
            }
            
            printf("Outside if: outer=%d\n", outer);
            // printf("inner=%d\n", inner);  //  LỖI: inner không tồn tại
        }

        int main() {
            demoBlockScope();
            // printf("outer=%d\n", outer);  //  LỖI: outer không tồn tại
            return 0;
        }

* Automatic Lifetime

        #include <stdio.h>

        void demoLifetime() {
            auto int counter = 0;  //  Tạo mới mỗi lần gọi hàm
            
            counter++;
            printf("Counter: %d (Địa chỉ: %p)\n", counter, &counter);
        }

        int main() {
            printf("Gọi hàm 3 lần:\n");
            demoLifetime();  // Counter: 1 (Địa chỉ: 0x7fff...1)
            demoLifetime();  // Counter: 1 (Địa chỉ: 0x7fff...2) ← ĐỊA CHỈ KHÁC
            demoLifetime();  // Counter: 1 (Địa chỉ: 0x7fff...3) ← ĐỊA CHỈ KHÁC
            return 0;
        }
        
 </details>


<details>
	<summary><strong>BÀI 5: CONTROL FLOW</strong></summary>

## **BÀI 5: CONTROL FLOW**

### **I.Goto**

#### **1.1.Định nghĩa**

* Câu lệnh `goto` cho phép chương trình **nhảy trực tiếp và vô điều kiện** đến một nhãn được định nghĩa trong cùng một hàm

* Nhãn là một điểm được đánh dấu trong mã nguồn,thường được **đặt tên bằng một định danh (identifier)** và kết thúc bằng dấu `:`


#### **1.2.Mục đích**

*  Dùng để thay đổi luồng điều khiển chương trình một cách thủ công, bỏ qua các cấu trúc điều khiển thông thường như vòng lặp,câu lệnh điều kiện hoặc hàm

*  Được sử dụng để thoát khỏi nested loops
    
        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                if(some_condition){
                    goto exit_loops; //Thoát khỏi cả 2 vòng lặp
                }
            }
        }
        exit_loops:
    

#### **1.3.Cú pháp**

    
        goto label_name; //Nhảy đến nhãn có tên label_name

        //... (các dòng mã khác)

        label_name: //Định nghĩa nhãn
        // khối mã được thực thi sau khi nhảy đến đây
    
    

#### **1.4.VD**

        #include <stdio.h>
        #include <stdlib.h>

        int main() {
            int *arr = malloc(sizeof(int) * 100);
            if (arr == NULL) { 
                goto error;
            }

            for (int i = 0; i < 5; i++) {
                arr[i] = i;
                printf("%d ", arr[i]);  // Thêm khoảng trắng
            }
            printf("\n");  // Thêm dòng mới sau mảng

            free(arr);
            goto done;

        error:
            printf("Loi: Khong the cap phat bo nho!\n");

        done:
            printf("End.\n");
            return 0;
        }



### **II.setjmp và longjmp**

#### **2.1.Định nghĩa**

* `setjmp:` Lưu trạng thái môi trường (stack pointer, registers) vào `jmp_buf`.

* `longjmp:` Khôi phục trạng thái, tiếp tục từ sau setjmp như thể nó vừa return.

* Khác `goto`: Có thể nhảy qua hàm (unwind stack), nhưng không gọi destructors (C không có).

#### **2.2.Mục đích**

* Triển khai cơ chế xử lý ngoại lệ đơn giản trong C

* Thoát khỏi các ngữ cảnh xử lý phức tạp khi xảy ra lỗi hoặc điều kiện đặc biệt

#### **2.3.Thư viện**

* Sử dụng thư viện `<setjmp.h>`

* `jmp_buf`: Kiểu mảng/cấu trúc lưu trạng thái (opaque type).

#### **2.4.Các hàm chính**

* **Hàm int setjmp(jmp_buf env)**

    ◦ **Chức năng:** Lưu trạng thái môi trường hiện tại(bao gồm con trỏ ngăn xếp, thanh ghi, và các thông tin liên quan đến luồng điều khiển) vào biến `jmp_buf_env`

    ◦ **Giá trị trả về:** 

        Trả về 0 khi được gọi trực tiếp (lần đầu tiên)

        Trả về giá trị val(hoặc 1 nếu val == 0)khi được khôi phục bởi longjmp


* **Hàm void longjmp(jmp_buf env,int val)**

    ◦ **Chức năng:** Khôi phục trạng thái môi trường đã được lưu trong `env` bởi `setjmp`.Sau khi gọi, luồng thực thi sẽ tiếp tục ngay sau lệnh `setjmp` tương ứng, như thể `setjmp` vừa trả về giá trị `val`

    ◦ **Tham số:** 

        env: Môi trường đã lưu bởi setjmp
        
        val: Giá trị trả về cho `setjmp`. Nếu val == 0, setjmp sẽ trả về 1

    
    ◦ **Lưu ý:**

        Hàm gọi long_jmp không bảo giờ trả về

        longjmp khôi phục trạng thái ngăn xếp và thanh ghi, nhưng không đảm bảo trạng thái của các biến cục bộ hoặc tài nguyên

* **VD:**

        #include <setjmp.h>
        #include <stdio.h>

        jmp_buf env;

        void check_even(int number) {
            if (number % 2 != 0) {
                printf("Loi: %d la so le!\n", number);
                longjmp(env, 1);  // Nhay ve setjmp voi ma loi 1
            }
            printf("%d la so chan\n", number);
        }

        int main() {
            if (setjmp(env) == 0) {
                printf("Kiem tra so...\n");
                check_even(7);
            } else {
                printf("Da phat hien loi, chuong trinh tiep tuc.\n");
            }
            return 0;
        }



        Kiem tra so...
        Loi: 7 la so le!
        Da phat hien loi,chuong trinh tiep tuc

 </details>
<details> 
 <summary><strong>BÀI 6: BIT MANIPULATION</strong></summary>

## **BÀI 6: BIT MANIPULATION**

### **I.Số nhị phân và bit**

#### **1.1.Định nghĩa**

* Máy tính lưu trữ và xử lý dữ liệu dưới dạng nhị phân (binary), sử dụng các bit (0 và 1)

* Một byte gồm 8 bit.Các giá trị lớn hơn(như 16,32,64 bit) được dùng cho các kiểu dữ liệu như `short`,`int`,`long`,...

* VD:
  
        Số thập phân 5: 00000101
        Số thập phân 13: 00001101

* VD: Kiểm tra binary

        #include <stdio.h>

        int main() {
            unsigned int num = 5;  // 00000101
            printf("5 in binary: ");
            for (int i = 7; i >= 0; i--) {
                printf("%u", (num >> i) & 1);
            }
            printf("\n");
            return 0;
        }

#### **1.2.Số có dấu và không dấu**

* Với **số không dấu (unsigned)**, các bit chỉ biểu diễn **giá trị dương**

* Với **số có dấu(signed)**

  ◦ bit cao nhất (MSB) biểu thị dấu **0 cho dương , 1 cho âm**
  
  ◦ Giá trị thường được biểu diễn dưới dạng bù 2 (`~positive + 1`)

  VD: 
  
        5 = 00000101
        -5 = 11111011
  

### **II.Bitwise Operators (Toán tử thao tác bit)**

#### **2.1.Định nghĩa**

*  Các toán tử này hoạt động trực tiếp trên biểu diễn bit của toán hạng, thường là kiểu số nguyên (`int`,`unsigned int`,...)

#### **2.2. & (Bitwise AND)**

* Kết quả bit là 1 nếu cả 2 bit tương ứng là 1

* Ứng dụng : Xóa bit, kiểm tra bit

* VD: 101 & 110 = 100

        #include <stdio.h>

        int main() {
            unsigned int a = 5;  // 101
            unsigned int b = 6;  // 110
            printf("%u & %u = %u\n", a, b, a & b);  // 4 (100)
            return 0;
        }

#### **2.3. | (Bitwise OR)**

* Kết quả bit là 1 nếu ít nhất 1 trong 2 bit tương ứng là 1

* Ứng dụng: Đặt bit

* VD: 101 | 110 = 111

#### **2.4. ^ (Bitwise XOR)**

* Kết quả bit là 1 nếu 2 bit tương ứng khác nhau

* Ứng dụng: Đảo bit, kiểm tra khác biệt

* VD: 101 ^ 110 = 011

        #include <stdio.h>

        int main() {
            unsigned int x = 5, y = 3;
            printf("Before: x=%u, y=%u\n", x, y);
            x ^= y; y ^= x; x ^= y;
            printf("After: x=%u, y=%u\n", x, y);  // x=3, y=5
            return 0;
        }

#### **2.5. ~ (Bitwise NOT)**

* Đảo tất cả các bit: 0 thành 1, 1 thành 0

* Kết quả phụ thuộc vào kích thước kiểu dữ liệu (8,16,32 bit,...)

* `~101` = `~00000101 = 11111010`

#### **2.6. << (Left Shift)**

* Dịch chuyển các bit sang trái n vị trí, các bit mới bên phải được điền bằng 0

* Tương đương nhân với `2^n` (cho số không dấu)

* VD: `101 << 1 = 1010  (Thập phân: 5 << 1 = 10)`

* Lưu ý: Nếu dịch quá nhiều, bit có thể bị mất, gây tràn

        #include <stdio.h>

        int main() {
            unsigned int num = 5;
            printf("%u << 1 = %u\n", num, num << 1);  // 10
            return 0;
        }

#### **2.7. >> (Right Shift)**

* Dịch chuyển các bit sang phải n vị trí, các bit mới bên trái được điền bằng 0 (thường cho số không dấu)

* Tương đương chia với `2^n` (cho số không dấu)

 VD: `1011 >> 1 = 0101 (Thập phân: 11 >> 1 = 5)`

        #include <stdio.h>

        int main() {
            unsigned int num = 11;  // 1011
            printf("%u >> 1 = %u\n", num, num >> 1);  // 5 (0101)
            return 0;
        }

* **Arithmetic Shift:** Bit mới bên trái điền bằng bit dấu (MSB) ban đầu (thường cho số có dấu)

 VD: `-5 (11111011) >> 1 = 11111101`

        #include <stdio.h>

        int main() {
            int num = -5;  // Giả sử 32-bit: ...11111011
            printf("%d >> 1 = %d\n", num, num >> 1);  // -3 (...11111101)
            return 0;
        }

### **III.Bitmasks (Mặt nạ bit)**

#### **3.1.Định nghĩa**

* Bitmask là một giá trị (thường là hằng số) được thiết kế để thao tác (set,clear,toggle,test) các bit cụ thể trong một biến bằng các toán tử Bitwise

* Mỗi bit trong mask địa diện cho một cờ (flag) hoặc tùy chọn

#### **3.2.Kỹ thuật phổ biến**

* **Tạo mask cho bit thứ n** 

    ◦  Công thức: `1 << n`

    ◦  VD: Mask cho bit 3: `1 << 3 = 00001000`

        // Tạo mask cho bit thứ n
        unsigned int mask = 1 << n;
        printf("Mask bit %d: %d (binary: ", n, mask);
        for(int i = 7; i >= 0; i--) {
            printf("%d", (mask >> i) & 1);
        }
        printf(")\n");

* **Set bit thứ n(đặt bit thành 1)**

    ◦  Công thức: `value |= (1 << n);`

    ◦ VD: Set bit 3 của `value = 5 (nhị phân: 00000101)`

  
        value |= ( 1 << 3); -> 00000101 | 00001000 = 00001101 (thập phân: 13)
  

        // Set bit thứ n
        unsigned char value = 5; // 00000101
        printf("Trước khi set bit %d: %d\n", n, value);
        value |= (1 << n);
        printf("Sau khi set bit %d: %d\n", n, value);


* **Clear bit thứ n(xóa bit, đặt thành 0)**

    ◦ Công thức: `value &= ~(1 << n);`

    ◦ VD: Clear bit thứ 3 của `value = 13 (nhị phân: 00001101)`
  
        value &= ~(1 << 3); -> 00001101 & 11110111 = 00000101
  
        // Clear bit thứ n
        unsigned char value = 13; // 00001101
        printf("Trước khi clear bit %d: %d\n", n, value);
        value &= ~(1 << n);
        printf("Sau khi clear bit %d: %d\n", n, value);

* **Toggle bit thứ n(đảo bit: 0 thành 1, 1 thành 0)**

    ◦ Công thức: `value ^= (1 << n);`

    ◦ VD: Toggle bit thứ 3 của `value = 5 (nhị phân: 00000101)`
  
        value ^= (1 << 3); -> 00000101 ^ 00001000 = 00001101
  
        // Toggle bit thứ n
        unsigned char value = 5; // 00000101
        printf("Trước khi toggle bit %d: %d\n", n, value);
        value ^= (1 << n);
        printf("Sau khi toggle bit %d: %d\n", n, value);

* **Test bit thứ n (kiểm tra bit có được set không)**

    ◦ Công thức: `if (value & (1 << n)) {...}`

    ◦ Kết quả khác 0 nếu bit được set (là 1)

    ◦ VD: Kiểm tra bit 2 của `value = 5 (nhị phân: 00000101)`
  
        5 & (1 << 2) -> 00000101 & 00000100 = 00000100 (khác 0, bit 2 được set)
  
        // Test bit thứ n
        unsigned char value = 5; // 00000101
        if (value & (1 << n)) {
            printf("Bit %d được SET (là 1)\n", n);
        } else {
            printf("Bit %d được CLEAR (là 0)\n", n);
        }

* **Set nhiều bit**

    ◦ Công thức: `value |= (MASK1 | MASK2);`

    ◦ VD: Set bit 2 và bit 3: `value |= (1 << 2 | 1 << 3);`

        00000000 | (00000100 | 00001000) = 00001100 (thập phân: 12)

        // Set nhiều bit
        unsigned char value = 0;
        printf("Trước khi set nhiều bit: %d\n", value);
        value |= (1 << 2 | 1 << 3);
        printf("Sau khi set bit 2 và 3: %d\n", value);


* **Clear nhiều bit**

    ◦ Công thức: `value &= ~(MASK1 | MASK2);`

    ◦ VD: Clear bit 2 và 3 của `value = 15 (nhị phân: 00001111)`

        value &= ~(1 << 2 | 1 << 3); -> 00001111 & 11110011 = 00000011 (thập phân: 3)

        // Clear nhiều bit
        unsigned char value = 15; // 00001111
        printf("Trước khi clear nhiều bit: %d\n", value);
        value &= ~(1 << 2 | 1 << 3);
        printf("Sau khi clear bit 2 và 3: %d\n", value);

* **Kiểm tra nhiều bit cùng được set**

    ◦ Công thức: `if ((value & (MASK1 | MASK2)) == (MASK1 | MASK2)) {...}`

    ◦ VD: Kiểm tra bit 2 và 3 của `value = 12 (nhị phân: 00001100)`

        (12 & (1 << 2 | 1 << 3)) == (1 << 2 | 1 << 3) -> (00001100 & 00001100) == 00001100 -> true

        // Kiểm tra nhiều bit cùng được set
        unsigned char value = 12; // 00001100
        unsigned int mask = (1 << 2 | 1 << 3);

        if ((value & mask) == mask) {
            printf("Cả bit 2 và 3 đều được SET\n");
        } else {
            printf("Bit 2 và 3 KHÔNG cùng được SET\n");
        }

### **IV.Bit Fields (Trường bit trong cấu trúc)**

#### **4.1.Lý thuyết**

*   Bit Fields cho phép định nghĩa các thành viên của một `struct` với số lượng bit cụ thể, giúp tiết kiệm bộ nhớ hoặc ánh xạ chính xác tới cấu trúc dữ liệu của phần cứng (như thanh ghi điều khiển)

*   Cú pháp:  `type member : width; (width = số bits, 1- sizeof(type)*8).`

*   VD:
        #include <stdio.h>

        struct Register {
            unsigned int flag1 : 1;   // 1 bit
            unsigned int config : 4;  // 4 bits (0-15)
            unsigned int status : 3;  // 3 bits (0-7)
            // Tổng: 8 bits (1 byte)
        };

        int main() {
            struct Register reg = {1, 5, 2};  // flag1=1, config=5, status=2
            printf("Flag1: %u, Config: %u, Status: %u\n", reg.flag1, reg.config, reg.status);
            reg.flag1 = 0;
            if (reg.status == 2) printf("Status OK\n");
            return 0;
        }

* Cách sử dụng:


   ◦ Khởi tạo :  struct Register reg = {1, 5, 2}; (gán flag1 = 1, config = 5, status = 2).

   ◦ Truy cập :  reg.flag1 = 0; hoặc if (reg.status == 2) { ... }.


#### **4.2.Lưu ý**

* Thứ tự bit và padding: 
   
   ◦ Thứ tự các bit field trong bộ nhớ (endianness) và cách đóng gói (padding) phụ thuộc vào trình biên dịch và kiến trúc máy, gây vấn đề về tính tương thích (portability).

        #include <stdio.h>

        int main() {
            int x = 0x12345678;
            char *p = (char*)&x;
            
            printf("Byte order: ");
            for(int i = 0; i < 4; i++) {
                printf("%02X ", p[i]);
            }
            // Kết quả khác nhau tùy Little/Big Endian
        }

   ◦ Một số trình biên dịch có thể chèn padding để căn chỉnh byte.

        #include <stdio.h>

        struct BadPadding {
            char a;      // 1 byte
            int b;       // 4 bytes - có thể bị padding 3 bytes
            char c;      // 1 byte
        };

        int main() {
            printf("Sizeof struct: %zu\n", sizeof(struct BadPadding));
            // Có thể là 12 thay vì 6 bytes do padding
        }

* Hạn chế:

   ◦ Không thể lấy địa chỉ của bit field (ví dụ: &reg.flag1 là lỗi).

        struct Register {
            unsigned int flag1 : 1;
            unsigned int flag2 : 1;
        };

        int main() {
            struct Register reg;
            
            // LỖI: không thể lấy địa chỉ bit-field
            // unsigned int *ptr = &reg.flag1; // COMPILE ERROR
            
            reg.flag1 = 1; // Chỉ gán giá trị trực tiếp
        }

   ◦ Kiểu dữ liệu cơ sở thường là `unsigned int` hoặc `int` để tránh vấn đề với số có dấu.

        struct InvalidBitfield {
            // char base : 1;    // Hành vi không xác định
            unsigned int valid : 1; // ĐÚNG: dùng unsigned int
            int signed_bit : 1;     // ĐÚNG: dùng int
        };

   ◦ UB - Width vượt quá giới hạn

        struct Overflow {
            unsigned int a : 40; // UB: vượt quá 32 bits
            unsigned int b : 0;  // UB: width = 0
            unsigned int c : -1; // UB: width âm
        };

        // ĐÚNG:
        struct Valid {
            unsigned int a : 4;  // OK: ≤ 32
            unsigned int b : 1;  // OK
        };

* Ứng dụng:

   ◦ Lập trình nhúng: Điều khiển thanh ghi phần cứng.

   ◦ Nén dữ liệu: Lưu trữ nhiều giá trị nhỏ trong không gian bộ nhớ hạn chế.
   
</details>
<details> 
 <summary><strong>BÀI 7: CUSTOM DATA TYPES</strong></summary>

## **BÀI 7: CUSTOM DATA TYPES**

### **I.Cấu trúc (Structs)**

#### **1.1.Định nghĩa**

* Struct là kiểu dữ liệu tùy chỉnh, nhóm các biến có kiểu dữ liệu khác nhau thành một đơn vị logic

* Các thành viên (members) được lưu trữ liên tiếp trong bộ nhớ, nhưng có thể có **padding** để đảm bảo căn chỉnh bộ nhớ theo kiến trúc CPU

#### **1.2.Đặc điểm**

* Mỗi thành viên có thể truy cập qua `.` (biến) hoặc `->` (con trỏ)

* Kích thước của struct (`sizeof(struct)`) là tổng kích thước của `members + padding`

* Padding đảm bảo các thành viên nằm ở địa chỉ chia cho hết kích thước căn chỉnh

* Có thể dùng `__attribute__(packed))` để loại bỏ padding

#### **1.3.Cú pháp**


        struct TenStruct {
            // Khai báo các thành viên (members)
            kiểu_dữ_liệu tên_biến1;
            kiểu_dữ_liệu tên_biến2;
            // ...
        };


#### **1.4.Khai báo và truy cập**

* Khai báo biến

        struct TenStruct bienStruct;
        struct TenStruct *conTro = &bienStruct;



* Truy cập thành viên

    ◦ Dùng `.` cho biến struct : `bienStruct.bien1 = 10`

    ◦ Dung `->` cho con trỏ struct: `conTro->bien1 = 20` 


* Khởi tạo với giá trị

        struct TenStruct ten_bien = {
            gia_tri1,
            gia_tri2,
            gia_tri3
        };

    ◦ VD:

            struct Employee emp1 = {
            101,                    // id
            "John Doe",             // name
            {15, 8, 1990},         // birth_date (struct lồng)
            5000.0                 // salary
        };

* Khởi tạo từng phần

        struct TenStruct ten_bien;
        ten_bien.thanh_vien1 = gia_tri1;
        ten_bien.thanh_vien2 = gia_tri2;
        ten_bien.struct_long.thanh_vien_inner = gia_tri3;

    ◦ VD:

                struct Employee emp2;
                emp2.id = 102;
                strcpy(emp2.name, "Jane Smith");
                emp2.birth_date.day = 20;
                emp2.birth_date.month = 5;
                emp2.birth_date.year = 1985;
                emp2.salary = 5500.0;

* Khởi tạo với designated initializers (C99)

            struct TenStruct ten_bien = {
                .thanh_vien1 = gia_tri1,
                .thanh_vien2 = gia_tri2,
                .struct_long = {
                    .thanh_vien_inner1 = gia_tri_a,
                    .thanh_vien_inner2 = gia_tri_b
                }
            };

    ◦ VD:

            struct Employee emp3 = {
                .id = 103,
                .salary = 6000.0,
                .birth_date = {
                    .year = 1992,
                    .month = 3,
                    .day = 10
                },
                .name = "Bob Johnson"
            };

#### **1.5.Struct lồng nhau**

##### **1.5.1.Đặc điểm**

* Cho phép tổ chức dữ liệu theo cấu trúc phân cấp

* Truy cập thành viên lồng nhau bằng cách dùng nhiều toán tử `.` hoặc `->`

* Padding vẫn áp dụng cho cả struct bên trong và bên ngoài

##### **1.5.2.Cấu trúc**

        struct OuterStruct {
            kiểu_dữ_liệu member1;
            struct InnerStruct {
                kiểu_dữ_liệu inner_member1;
                kiểu_dữ_liệu inner_member2;
            } inner_variable;
            kiểu_dữ_liệu member2;
        };

##### **1.5.3.Các dạng struct lồng nhau**

* **Dạng 1: Struct lồng trực tiếp**

        struct Date {
            int day;
            int month;
            int year;
        };

        struct Employee {
            int id;
            char name[50];
            struct Date birth_date;
            struct Date hire_date;
        };


* **Dạng 2: Struct lồng với typedef**

        typedef struct {
            float x;
            float y;
        } Point;

        typedef struct {
            Point top_left;             // Struct lồng
            Point bottom_right;         // Struct lồng
            char color[20];
        } Rectangle;

* **Dạng 3: Struct chứa mảng của struct**

        struct Student {
            char name[50];
            float gpa;
        };

        struct Classroom {
            int room_number;
            struct Student students[30];        // Mảng struct lồng
            int student_count;
        }

* **Dạng 4: Struct lồng nhiều cấp**

        struct Address {
            char street[100];
            char city[50];
            char zip_code[10];
        };

        struct Contact {
            char phone[15];
            char mail[50];
            struct Address address;     // Struct lồng cấp 1
        };

        struct Person {
            char name[50];
            struct Contact contact;     // Struct lồng cấp 2
        };




### **II.Unions**

#### **2.1.Định nghĩa**

* Cho phép lưu trữ nhiều kiểu dữ liệu khác nhau tại **cùng một vị trí bộ nhớ (cùng địa chỉ)**. 

* Chỉ một thành viên chứa giá trị hợp lệ tại một thời điểm

#### **2.2.Đặc điểm**

* `Kích thước` của union bằng kích thước của `thành viên lớn nhất + padding`

* Phải tự quản lý thành viên hợp lệ, thường dùng biến/enum bổ sung

* Type punning: Ghi dữ liệu bằng một kiểu và đọc bằng kiểu khác(ví dụ: xem bit của float qua int)

#### **2.3.Cú pháp**

        union TenUnion {
            kieu_du_lieu    ten_thanh_vien1;
            kieu_du_lieu    ten_thanh_vien2;
            kieu_du_lieu    ten_thanh_vien3;
        };

    ◦ VD:

        union DuLieu{
            int soNguyen;       //4 bytes
            float soThuc;       //4 bytes
            char chuoi[20];     //20 bytes
        };


#### **2.4.Khai báo biến, truy cập, khởi tạo**

##### **2.4.1.Khai báo**

* **Dạng 1: Khai báo biến union**

        union  TenUnion ten_bien;


* **Dạng 2: Khai báo cơ bản** 

        union TenUnion {
            // các thành viên
        };

    ◦ VD:

        union DuLieu {
            int soNguyen;
            float soThuc;
            char chuoi[20];
        };

* **Dạng 3: Khai báo với typedef** 

        typedef union {
            // các thành viên
        } TenUnion;

    ◦ VD:

        // Khai báo union với typedef
        typedef union {
            int soNguyen;
            float soThuc;
            char kyTu;
        } GiaTri;

* **Dạng 4: Khai báo và khai báo biến cùng lúc** 

        union TenUnion {
            // các thành viên
        } bien1, bien2;

    ◦ VD:

        union DuLieu {
            int soNguyen;
            float soThuc;
            char chuoi[10];
        } data1, data2, data3;

##### **2.4.2.Truy cập**

* **Truy cập với biến union thông thường:**

        union TenUnion bien;
        bien.thanh_vien = gia_tri;

* **Truy cập với con trỏ union:**

        union TenUnion *ptr;
        ptr->thanh_vien = gia_tri;

##### **2.4.3.Khởi tạo**

* **Khởi tạo thành viên đầu tiên:**

        union TenUnion bien = {gia_tri};

* **Khởi tạo với designated initializer (C99):**

        union TenUnion bien = {.thanh_vien = gia_tri};

#### **2.5.Union trong Struct**

##### **2.5.1.Đặc điểm**

* Union được sử dụng như một thành viên của struct để lưu trữ nhiều kiểu dữ liệu khác nhau tại cùng một vị trí bộ nhớ trong struct

* Padding của struct vẫn áp dụng, nhưng union chỉ chiếm kích thước của thành viên lớn nhất

##### **2.5.2.Cú pháp**


        struct TenStruct {
            kieu_du_lieu thanh_vien1;
            kieu_du_lieu thanh_vien2;
            union {
                kieu_du_lieu union_thanh_vien1;
                kieu_du_lieu union_thanh_vien2;
                //...
            } ten_union;
            kieu_du_lieu thanh_vien3;
        };

##### **2.5.3.Các dạng khai báo**

* **Dạng 1: Union ẩn danh trong struct**

        struct TenStruct {
            // các thành viên Thường
            union {
                // các thành viên union
            }
        }

    ◦ VD:

            struct SinhVien {
            char ten[50];
            int maSo;
            union {
                float diemThi;
                char xepLoai;
                int hocBong;
            }; // Union ẩn danh - truy cập trực tiếp
        };

* **Dạng 2: Union có tên trong struct**

        struct TenStruct {
            // các thành viên Thường
            union TenUnion {
                // các thành viên union;
            } ten_bien_union;
        };

    ◦ VD:

        struct HinhHoc {
            char loaiHinh[20];
            union DuLieu {
                float banKinh;           // Cho hình tròn
                struct {                 // Cho hình chữ nhật
                    float chieuDai;
                    float chieuRong;
                } hcn;
                float canh;              // Cho hình vuông
            } duLieu;
        };

* **Dạng 3: Union với typedef**

        typedef union {
            // các thành viên union 
        } KieuUnion;

        struct TenStruct {
            // các thành viên Thường
            KieuUnion ten_bien_union;
        };


    ◦ VD:

        // Định nghĩa union với typedef
        typedef union {
            int nguyen;
            float thuc;
            char kyTu;
            char chuoi[20];
        } GiaTri;

        struct Bien {
            char kieu[10];
            GiaTri giaTri;  // Sử dụng union đã định nghĩa
        };

### **III.Enum (Kiểu liệt kê)**

#### **3.1.Định nghĩa**

*  `enum` là một kiểu dữ liệu tùy chỉnh cho phép định nghĩa một tập hợp các hằng số nguyên được đặt tên (enumerators), giúp mã dễ đọc và bảo trì hơn.

*  Mục đích: Biểu diễn các giá trị rời rạc, ví dụ: trạng thái, chế độ, hoặc cờ (flag) trong hệ thống nhúng.

#### **3.2.Đặc điểm**

* **Kiểu dữ liệu:**

    ◦ Mặc định, enum được ánh xạ thành kiểu int, nhưng trình biên dịch có thể chọn kiểu nhỏ hơn (như char) để tối ưu bộ nhớ.

* **Giá trị:**

    ◦ Mỗi enumerator được gán một giá trị nguyên, bắt đầu từ 0 (mặc định) hoặc giá trị do người dùng chỉ định.

* **Ứng dụng:**

    ◦ Thường dùng trong hệ thống nhúng để định nghĩa trạng thái thiết bị, mã lỗi, hoặc chế độ hoạt động.

#### **3.3. Cú pháp**

        enum TenEnum {
            VALUE1,    // 0
            VALUE2,    // 1
            VALUE3 = 5 // 5, các giá trị tiếp theo tăng dần
        };

    ◦ vd:

        enum DeviceState {
            OFF = 0,
            ON,
            STANDBY,
            ERROR = 10
        };

        struct Device {
            enum DeviceState state;
        };

        int main() {
            struct Device dev;
            dev.state = ON;
            if (dev.state == ON) {
                printf("Device is ON\n");
            }
            printf("State value: %d\n", dev.state); // In: State value: 1
            return 0;
        }

#### **3.4. Các dạng khai báo**

* **Dạng 1: Khai báo cơ bản**

        enum TenEnum {
            // các giá trị
        };

    ◦ vd:

        enum NgayTrongTuan {
            THU_HAI,    // 0
            THU_BA,     // 1
            THU_TU,     // 2
            THU_NAM,    // 3
            THU_SAU,    // 4
            THU_BAY,    // 5
            CHU_NHAT    // 6
        };

* **Dạng 2: Khai báo với typedef**

        typedef enum {
            // các giá trị
        } TenEnum;

    ◦ vd:

        typedef enum {
            DO,
            VANG,
            XANH
        } MauSac;

* **Dạng 3: Khai báo và khai báo biến cùng lúc**

        enum TenEnum {
            // các giá trị
        } bien1, bien2;

    ◦ VD:

        // Khai báo enum và biến cùng lúc
        enum GioiTinh {
            NAM,
            NU,
            KHAC
        } gt1, gt2;

* **Dạng 4: Enum không tên**

        enum {
            // các giá trị
        } bien1, bien2;

    ◦ vd:

        enum {
            THAP,
            TRUNG_BINH,
            CAO
        } muc_do;

#### **3.5.Lưu ý**

* **Tối ưu bộ nhớ:**

   ◦ Trong hệ thống nhúng, có thể sử dụng enum với kiểu dữ liệu rõ ràng (như uint8_t) bằng cách kết hợp với typedef

        typedef enum { LOW = 0, HIGH } PinState_t __attribute__((packed));


* **Kết hợp với bit fields:**
   
   ◦ Có thể dùng enum trong struct với bit fields để tiết kiệm bộ nhớ.

* **Tính rõ ràng:**

   ◦ Sử dụng enum thay vì hằng số #define để tăng tính bảo trì và kiểm tra lỗi.


### **IV.Typedef (Tạo kiểu dữ liệu mới)**

#### **4.1.Định nghĩa**

*  `Typedef` tạo bí danh(alias) cho kiểu dữ liệu hiện có, giúp mã dễ đọc và tăng tính tương thích

#### **4.2. Đặc điểm**

*  Không tạo kiểu mới, chỉ đặt tên khác

*  Ứng dụng: 
    
   ◦ Rút gọn tên kiểu phức tạp (struct,union,con trỏ hàm), tăng tính rõ ràng
   
   ◦ Tăng tính rõ ràng và khả năng bảo trì.

   ◦ Cải thiện tính tương thích (portability) giữa các nền tảng.

#### **4.3. Cú pháp**


        typedef existing_type new_type_name;



#### **4.4. Ứng dụng**

* **Rút gọn struct:**

        #include <stdio.h>

        typedef struct {
            int x, y;
        } Diem;  // Alias cho struct

        int main() {
            Diem p = {1, 2};
            printf("Point: (%d, %d)\n", p.x, p.y);
            return 0;
        }

* **Rút gọn con trỏ hàm:**

        typedef int (*HamTinhToan)(int, int);  // Alias

        int add(int a, int b) { return a + b; }

        int main() {
            HamTinhToan op = add;
            printf("Sum: %d\n", op(5, 3));  // 8
            return 0;
        }

* portability: 

        typedef unsigned char BYTE;

### **V.SIZE của Struct và Union**

#### **5.1.SIZE của Struct**

##### **5.1.1.Khái niệm**

* Kích thước của struct là tổng kích thước của tất cả thành viên, cộng thêm **byte đệm (padding)** để đảm bảo **căn chỉnh bộ nhớ (alignment)** 

* Alignment là yêu cầu về địa chỉ bộ nhớ mà một biến phải bắt đầu. Địa chỉ này phải chia hết cho giá trị alignment.

* Offset là khoảng cách tính từ điểm bắt đầu của một cấu trúc (struct/union) đến vị trí của một thành viên cụ thể.

##### **5.1.2.Nguyên tắc căn chỉnh**

* **Quy tắc căn chỉnh:**

   ◦ Mỗi kiểu dữ liệu có alignment requirement riêng

   ◦ Biến phải được đặt tại địa chỉ chia hết cho alignment của nó

   ◦ Struct có alignment bằng alignment của thành viên lớn nhất

    | Kiểu dữ liệu | Kích thước | Alignment |
    |--------------|------------|-----------|
    | char         | 1 byte     | 1 byte    |
    | short        | 2 bytes    | 2 bytes   |
    | int          | 4 bytes    | 4 bytes   |
    | float        | 4 bytes    | 4 bytes   |
    | double       | 8 bytes    | 8 bytes   |
    | pointer      | 4/8 bytes  | 4/8 bytes |

##### **5.1.3.Các bước tính kích thước struct**

* **Bước 1: Xác định alignment của struct**

   ◦ Mỗi kiểu dữ liệu có alignment requirement riêng

        Alignment_struct = max(alignment_các_thành_viên)

* **Bước 2: Sắp xếp và thêm padding**

   ◦ Mỗi thành viên phải ở offset chia hết cho alignment của nó

   ◦ Thêm padding giữa các thành viên nếu cần 

   ◦ Thêm padding cuối struct để chia hết cho alignment_struct  

##### **5.1.4.VD**

* **Struct đơn giản:**

        struct Example1 {
            char a;     // 1 byte
            int b;      // 4 bytes
            char c;     // 1 byte
        };

   ◦ Tính toán

        Offset 0: char a (1 byte)
        Offset 1: padding (3 bytes) - vì int cần alignment 4 bytes
        Offset 4: int b (4 bytes)
        Offset 8: char c (1 byte)
        Offset 9: padding (3 bytes) - để size chia hết cho 4 (alignment của int)
        Tổng: 12 bytes

   ◦ Kiểm tra

        #include <stdio.h>

        struct Example1 {
            char a;
            int b;
            char c;
        };

        int main() {
            printf("Sizeof Example1: %lu bytes\n", sizeof(struct Example1));
            printf("Offset a: %lu\n", (size_t)&((struct Example1*)0)->a);
            printf("Offset b: %lu\n", (size_t)&((struct Example1*)0)->b);
            printf("Offset c: %lu\n", (size_t)&((struct Example1*)0)->c);
            return 0;
        }

* **Tối ưu hóa bằng sắp xếp lại:**

        // Struct chưa tối ưu
        struct BadLayout {
            char a;     // 1 byte
            int b;      // 4 bytes
            char c;     // 1 byte
            double d;   // 8 bytes
        };

   ◦ Tính toán

        Offset 0: char a (1 byte)
        Offset 1: padding (3 bytes)
        Offset 4: int b (4 bytes)
        Offset 8: char c (1 byte)
        Offset 9: padding (7 bytes) - vì double cần alignment 8 bytes
        Offset 16: double d (8 bytes)
        Offset 24: padding (0 bytes) - đã chia hết cho 8
        Tổng: 24 bytes

   ◦ Struct tối ưu:

        struct GoodLayout {
            double d;   // 8 bytes
            int b;      // 4 bytes
            char a;     // 1 byte
            char c;     // 1 byte
        };

   ◦ Tính toán:

        Offset 0: double d (8 bytes)
        Offset 8: int b (4 bytes)
        Offset 12: char a (1 byte)
        Offset 13: char c (1 byte)
        Offset 14: padding (2 bytes) - để chia hết cho 8
        Tổng: 16 bytes

* **Struct với các kiểu phức tạp:**

        struct Complex {
            short s;        // 2 bytes
            char c;         // 1 byte
            int i;          // 4 bytes
            double d;       // 8 bytes
            char arr[3];    // 3 bytes
        };

   ◦ Tính toán

        Offset 0: short s (2 bytes)
        Offset 2: char c (1 byte)
        Offset 3: padding (1 byte) - vì int cần alignment 4
        Offset 4: int i (4 bytes)
        Offset 8: double d (8 bytes)
        Offset 16: char arr[3] (3 bytes)
        Offset 19: padding (5 bytes) - để chia hết cho 8 (alignment của double)
        Tổng: 24 bytes

   ◦ Công cụ kiểm tra offset:

        #include <stdio.h>
        #include <stddef.h> // for offsetof

        struct TestStruct {
            char a;
            int b;
            double c;
            char d;
        };

        void print_offsets() {
            printf("Offset of a: %lu\n", offsetof(struct TestStruct, a));
            printf("Offset of b: %lu\n", offsetof(struct TestStruct, b));
            printf("Offset of c: %lu\n", offsetof(struct TestStruct, c));
            printf("Offset of d: %lu\n", offsetof(struct TestStruct, d));
            printf("Total size: %lu\n", sizeof(struct TestStruct));
        }

* **Struct chứa struct:**

        struct Inner {
            int a;      // 4 bytes
            char b;     // 1 byte
        };              // size = 8 bytes (với padding)

        struct Outer {
            char x;             // 1 byte
            struct Inner inner; // 8 bytes
            double y;           // 8 bytes
        };

   ◦ Tính toán

        Offset 0: char x (1 byte)
        Offset 1: padding (3 bytes) - vì struct Inner có alignment 4
        Offset 4: struct Inner (8 bytes)
            - Offset 4: int a (4 bytes)
            - Offset 8: char b (1 byte)
            - Offset 9: padding (3 bytes)
        Offset 12: padding (4 bytes) - vì double cần alignment 8
        Offset 16: double y (8 bytes)
        Tổng: 24 bytes

* **Struct với mảng:**

        struct WithArray {
            int a;          // 4 bytes
            char arr[5];    // 5 bytes
            double b;       // 8 bytes
        };


   ◦ Tính toán

        Offset 0: int a (4 bytes)
        Offset 4: char arr[5] (5 bytes)
        Offset 9: padding (7 bytes) - vì double cần alignment 8
        Offset 16: double b (8 bytes)
        Tổng: 24 bytes


##### **5.1.5.Quy tắc tổng hợp**

* **Quy tắc 1: Member Alignment**

   ◦ Mỗi thành viên phải ở offset chia hết cho alignment của nó.

* **Quy tắc 2: Struct Alignment**

   ◦ Kích thước struct phải chia hết cho alignment của thành viên lớn nhất.

* **Quy tắc 3: Padding Strategy**

        // Chiến lược thêm padding:
        current_offset = 0;
        for each member in struct:
            alignment = alignment_of(member);
            padding = (alignment - (current_offset % alignment)) % alignment;
            current_offset += padding + sizeof(member);
        end for
        // Thêm padding cuối để chia hết cho alignment lớn nhất

##### **5.1.6.Công thức tính nhanh**

        // Giả sử struct có các thành viên với kích thước: s1, s2, s3...
        // và alignments: a1, a2, a3...

        size = 0;
        max_align = 1;

        for each member:
            align = alignment_of(member);
            max_align = max(max_align, align);
            padding = (align - (size % align)) % align;
            size += padding + sizeof(member);
        end for

        // Padding cuối
        final_padding = (max_align - (size % max_align)) % max_align;
        total_size = size + final_padding;

#### **5.2.Size của Union**

##### **5.2.1.Khái niệm**

* Tất cả thành viên dùng chung một vùng nhớ

* Bằng kích thước của thành viên lớn nhất

* Bằng alignment requirement của thành viên lớn nhất

##### **5.2.2.Công thức tính size union**

        size_union = max(sizeof(member1), sizeof(member2), ...)
        alignment_union = max(alignment(member1), alignment(member2), ...)

##### **5.2.3.Các bước tính kích thước union**

* **Bước 1: Tìm thành viên lớn nhất**

        largest_member = member có kích thước lớn nhất

* **Bước 2: Xác định alignment của union**

        alignment_union = alignment của thành viên lớn nhất


* **Bước 3: Thêm padding nếu cần**

        size_union = sizeof(largest_member) + padding
        // Padding được thêm để size_union chia hết cho alignment_union

##### **5.2.4.VD**

* **Union cơ bản**

        union BasicUnion {
            char a;     // 1 byte, alignment 1
            int b;      // 4 bytes, alignment 4
            double c;   // 8 bytes, alignment 8
        };

   ◦ Tính toán:

        - Thành viên lớn nhất: double c (8 bytes)
        - Alignment union: max(1, 4, 8) = 8
        - Kích thước union: 8 bytes (không cần padding vì 8 ÷ 8 = 1)
        Tổng: 8 bytes

   ◦ Kiểm tra:

        #include <stdio.h>

        union BasicUnion {
            char a;
            int b;
            double c;
        };

        int main() {
            printf("Sizeof BasicUnion: %lu bytes\n", sizeof(union BasicUnion));
            printf("Alignment requirement:\n");
            printf("char: %lu, int: %lu, double: %lu\n", 
                _Alignof(char), _Alignof(int), _Alignof(double));
            return 0;
        }

* **Union với mảng:**

        union WithArray {
            int x;          // 4 bytes, alignment 4
            char arr[10];   // 10 bytes, alignment 1
            double y;       // 8 bytes, alignment 8
        };

   ◦ Tính toán:

        - Thành viên lớn nhất: char arr[10] (10 bytes)
        - Alignment union: max(4, 1, 8) = 8
        - Kích thước cần: 10 bytes
        - Padding cần thêm: (8 - (10 % 8)) % 8 = 6 bytes
        - Tổng: 10 + 6 = 16 bytes

* **Union với struct:**

        struct Point {
            int x;      // 4 bytes
            int y;      // 4 bytes
        };              // size = 8 bytes, alignment = 4

        union UnionWithStruct {
            char a;             // 1 byte, alignment 1
            struct Point p;     // 8 bytes, alignment 4
            double d;           // 8 bytes, alignment 8
        };

   ◦ Tính toán:

        - Thành viên lớn nhất: struct Point p và double d (8 bytes)
        - Alignment union: max(1, 4, 8) = 8
        - Kích thước union: 8 bytes (không cần padding)
        Tổng: 8 bytes

* **Union có thành viên cần alignment lớn:**

        union ComplexUnion {
            char a;         // 1 byte, alignment 1
            int b;          // 4 bytes, alignment 4
            long double c;  // 16 bytes, alignment 16 (tùy hệ thống)
        };

   ◦ Tính toán:

        - Thành viên lớn nhất: long double c (16 bytes)
        - Alignment union: 16
        - Kích thước union: 16 bytes
        Tổng: 16 bytes

* **Union với mảng kích thước lẻ:**

        union OddArrayUnion {
            short s;        // 2 bytes, alignment 2
            char arr[7];    // 7 bytes, alignment 1
            int i;          // 4 bytes, alignment 4
        };

   ◦ Tính toán:

        - Thành viên lớn nhất: char arr[7] (7 bytes)
        - Alignment union: max(2, 1, 4) = 4
        - Kích thước cần: 7 bytes
        - Padding: (4 - (7 % 4)) % 4 = 1 byte
        - Tổng: 7 + 1 = 8 bytes


* **Union trong union:**

        union Inner {
            int a;      // 4 bytes
            double b;   // 8 bytes
        };              // size = 8, alignment = 8

        union Outer {
            char x;             // 1 byte
            union Inner inner;  // 8 bytes
            long y;             // 8 bytes
        };

   ◦ Tính toán:

        - Thành viên lớn nhất: union Inner inner và long y (8 bytes)
        - Alignment union: max(1, 8, 8) = 8
        - Kích thước union: 8 bytes
        Tổng: 8 bytes

* **Union chứa struct có padding:**

        struct PaddedStruct {
            char a;     // 1 byte
            int b;      // 4 bytes
        };              // size = 8 bytes (với padding), alignment = 4

        union UnionWithPadded {
            char x;                 // 1 byte
            struct PaddedStruct s;  // 8 bytes
            double y;               // 8 bytes
        };

   ◦ Tính toán:

        - Thành viên lớn nhất: struct PaddedStruct s và double y (8 bytes)
        - Alignment union: max(1, 4, 8) = 8
        - Kích thước union: 8 bytes
        Tổng: 8 bytes

</details> 

<details> 
 <summary><strong>BÀI 8:MEMORY LAYOUT</strong></summary>

## **BÀI 8:MEMORY LAYOUT**

![Image](https://github.com/user-attachments/assets/0533640f-e379-42a7-a204-6e873241a0c6)

### **I.Text Segment(.text)**

#### **1.1.Mục đích**

* Vùng lưu mã thực thi (executable code).

* Lưu trữ mã máy đã được biên dịch từ mã nguồn C, bao gồm các lệnh thực thi của chương trình

#### **1.2.Đặc điểm**

* Chỉ đọc (read-only) để bảo vệ mã lệnh khỏi bị sửa đổi trong lúc chạy

* Có thể được chia sẻ giữa nhiều tiến trình chạy cùng một chương trình,giúp tiết kiệm bộ nhớ

* Thường nằm ở vùng địa chỉ thấp của bộ nhớ

        #include <stdio.h>

        int main() {
            printf("In text segment.\n");  // Mã này lưu ở .text
            return 0;
        }

   ◦ Biên dịch: `gcc -o prog prog.c`;

   ◦ Xem: `objdump -d prog | grep main`;   

### **II.Initialized Data Segment(.data)**

#### **2.1.Mục đích**

* Lưu trữ các biến toàn cục và biến tĩnh được khởi tạo với giá trị khác 0 trong mã nguồn. 


#### **2.2.Đặc điểm**

* Có thể đọc và ghi (read-write)

* Kích thước được xác định tại thời điểm biên dịch

* Các giá trị khởi tạo được lưu trực tiếp trong file thực thi, do đó làm tăng kích thước file

        #include <stdio.h>

        int global_value = 100;    // .data
        static int static_value = 50;  // .data

        int main() {
            printf("Global: %d, Static: %d\n", global_value, static_value);
            return 0;
        }

   ◦ Xem: `objdump -t prog | grep global_value`;   

### **III.Unitialized Data Segment(.bss)**

#### **3.1.Mục đích**

* Lưu trữ các biến toàn cục và biến tĩnh không được khởi tạo tường minh hoặc được khởi tạo bằng 0

#### **3.2.Đặc điểm**

* Có thể đọc và ghi (read-write)

* Hệ điều hành tự động khởi tạo tất cả các giá trị trong vùng này thành 0 khi chương trình bắt đầu

* Không lưu giá trị cụ thể trong file thực thi, giúp tiết kiệm không gian


        #include <stdio.h>

        int global_zero;           // .bss (init 0)
        static float static_uninit;  // .bss (init 0)

        int main() {
            printf("Global zero: %d, Static uninit: %f\n", global_zero, static_uninit);
            return 0;
        }

        Output: Global zero: 0, Static uninit: 0.000000

### **IV.Heap**

#### **4.1.Mục đích**

* Vùng nhớ động được cấp phát và giải phóng trong lúc chạy chương trình thông qua các hàm như `malloc()`,`calloc()`,`realloc()` và `free()`


#### **4.2.Đặc điểm**

* Kích thước có thể thay đổi động (tăng hoặc giảm ) trong quá trình thực thi

* Thường "mọc" từ địa chỉ thấp lên cao

* Lỗi thường gặp

   ◦ Memory leak: Không gọi `free()` cho bộ nhớ đã cấp phát

   ◦ Use after free: Truy cập bộ nhớ sau khi đã giải phóng

   ◦ Dangling pointer: Con trỏ vẫn trỏ đến vùng nhớ đã giải phóng

   ◦ Fragmentation: Bộ nhớ bị chia thành các mảnh nhỏ,gây khó khăn cho việc cấp phát các khối lớn

        #include <stdio.h>
        #include <stdlib.h>

        int main() {
            int *ptr = malloc(10 * sizeof(int));  // Heap
            if (ptr) {
                ptr[0] = 42;
                printf("Heap value: %d\n", ptr[0]);
                free(ptr);  // Tránh leak
                // ptr[0] = 99;  // Use-after-free: UB!
            }
            return 0;
        }

        Debug: Valgrind valgrind --leak-check=full ./prog.

### **V.Stack**

#### **5.1.Mục đích**

* Lưu trữ các biến cục bộ, tham số hàm, địa chỉ trả về, và trạng thái thanh ghi khi gọi hàm


#### **5.2.Đặc điểm**

* Hoạt động theo cơ chế LIFO

* Mỗi lần gọi hàm, một **stack frame** được tạo ra để lưu trữ thông tin của hàm đó.Khi hàm kết thúc **stack frame** bị xóa

* Thường "mọc" từ địa chỉ cao xuống thấp

* Kích thước stack thường cố định, được xác định bởi hệ điều hành hoặc trình biên dịch.Vượt quá kích thước có thể gây ra stack overflow

        #include <stdio.h>

        void func(int param) {
            int local_var = 10;  // Stack
            printf("Param: %d, Local: %d\n", param, local_var);
        }

        int main() {
            func(20);
            return 0;
        }

### **VI.Các vùng bộ nhớ phụ khác**

#### **6.1.Environment/Arguments Segment**

* Lưu trữ các biến môi trường và các tham số dòng lệnh(`argc, argv`) được truyền vào chương trình

* Thường nằm ở vùng địa chỉ cao, gần stack

        #include <stdio.h>

        int main(int argc, char *argv[]) {
            printf("Args: %d\n", argc);
            for (int i = 0; i < argc; i++) printf("Arg %d: %s\n", i, argv[i]);
            // Env: extern char **environ; printf("%s\n", environ[0]);
            return 0;
        }

#### **6.2. Memory Mapping Segment**

* Dùng cho các file ánh xạ bộ nhớ (memory-mapped files) hoặc các thư viện động được nạp vào bộ nhớ

* Vị trí và cách sử dụng phụ thuộc vào hệ điều hành

        #include <sys/mman.h>
        #include <fcntl.h>
        #include <stdio.h>

        int main() {
            int fd = open("file.txt", O_RDONLY);
            char *map = mmap(NULL, 1024, PROT_READ, MAP_PRIVATE, fd, 0);  // Mmap segment
            printf("Mapped: %s\n", map);  // Nội dung file
            munmap(map, 1024);
            close(fd);
            return 0;
        }

</details>
<details> 
 <summary><strong>BÀI 9: DATA STRUCTURES</strong></summary>
	
## **BÀI 9: DATA STRUCTURES**

### **I.Danh sách liên kết(Linked List)**

<img width="777" height="399" alt="Image" src="https://github.com/user-attachments/assets/86a48646-6d76-4162-a760-56574e90c62a" />

#### **1.1.Định nghĩa**

* Danh sách liên kết là một cấu trúc dữ liệu tuyến tính bao gồm các **nút(node)**, trong đó mỗi nút chứa **dữ liệu** và một **con trỏ** trỏ đến nút tiếp theo

* Không giống như mảng, danh sách liên kết không lưu trữ dữ liệu ở các vị trí bộ nhớ liên kề, cho phép cấp phát bộ nhớ động và kích thước linh hoạt

#### **1.2.Các loại danh sách liên kết**

<img width="1105" height="583" alt="Image" src="https://github.com/user-attachments/assets/f7451c94-ca95-4ee9-8ad3-24d78ecaca2d" />

* **Danh sách liên kết đơn(Singly Linked List)**: 

    ◦ Mỗi nút chứa dữ liệu và con trỏ đến nút tiếp theo.

    ◦ Nút cuối cùng trỏ đến NULL

    ◦ Node có `data` và `next` (đơn hướng).

* **Danh sách liên kết đôi(Doubly Linked List):** 

    ◦ Mỗi nút chứa dữ liệu, con trỏ đến nút tiếp theo và nút trước đó

    ◦ Thêm `prev` (hai hướng, dễ duyệt ngược).

* **Danh sách liên kết vòng(Circular Linked List):** 

    ◦ Nút cuối cùng trỏ ngược lại nút đầu tiên, tạo thành 1 vòng

    ◦ `last->next = first`


#### **1.3.Các thao tác**

* **Cấu trúc cơ bản:**

        #include <stdio.h>
        #include <stdlib.h>

        struct Node {
            int data;
            struct Node* next;
        };

* **Thêm(Insertion):** Thêm nút vào đầu, cuối hoặc vị trí cụ thể

    ◦ **Thêm vào đầu:**


        void insertAtBeginning(struct Node** head, int data) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = *head;
            *head = newNode;
        }

    ◦ **Thêm vào đầu:**


        void insertAtEnd(struct Node** head, int data) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = NULL;
            if (*head == NULL) { *head = newNode; return; }
            struct Node* temp = *head;
            while (temp->next != NULL) temp = temp->next;
            temp->next = newNode;
        }

* **Xóa(Deletion):** Xóa nút khỏi đầu, cuối hoặc vị trí cụ thể

    ◦ **Đầu:**


        void deleteAtBeginning(struct Node** head) {
            if (*head == NULL) return;
            struct Node* temp = *head;
            *head = (*head)->next;
            free(temp);
        }


    ◦ **Cuối:**


        void deleteAtEnd(struct Node** head) {
            if (*head == NULL) return;
            if ((*head)->next == NULL) { free(*head); *head = NULL; return; }
            struct Node* temp = *head;
            while (temp->next->next != NULL) temp = temp->next;
            free(temp->next);
            temp->next = NULL;
        }

* **Duyệt(Traversal):** Truy cập từng nút để hiển thị hoặc xử lý dữ liệu

        void printList(struct Node* head) {
            struct Node* temp = head;
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }

* **Tìm kiếm(Search):** Tìm nút có giá trị cụ thể


        struct Node* search(struct Node* head, int data) {
            struct Node* temp = head;
            while (temp != NULL) {
                if (temp->data == data) return temp;
                temp = temp->next;
            }
            return NULL;
        }


* **Cập nhật(Update):** Sửa đổi dữ liệu của 1 Nút


        void update(struct Node* head, int oldData, int newData) {
            struct Node* temp = head;
            while (temp != NULL) {
                if (temp->data == oldData) {
                    temp->data = newData;
                    return;
                }
                temp = temp->next;
            }
        }


#### **1.4.Ưu điểm**

* **Kích thước động:** Có thể mở rộng hoặc thu hẹp trong thời gian chạy

* **Thêm và xóa hiệu quả hơn mảng**

* **Sử dụng bộ nhớ linh hoạt**

#### **1.5.Nhược điểm**

* **Không hỗ trợ truy cập ngẫu nhiên; cần duyệt tuần tự**

* **Tốn thêm bộ nhớ cho con trỏ**

#### **1.6.Ví dụ**

* **Singly Linked List**

            #include<stdio.h>
            #include<stdlib.h>

            //Định nghĩa cấu trúc nút
            struct Node{
                int data;
                struct Node * next;
            };

            //Thêm nút vào đầu danh sách
            void insertAtBeginning(struct Node** head, int data){
                struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
                newNode->data = data;
                newNode->next = *head;
                *head = newNode;
            }

            //In danh sách
            void printList(struct Node* head){
                struct Node* temp = head;
                while (temp != NULL){
                    printf("%d ->", temp->data);
                    temp = temp->next;
                }
                printf("NULL\n");
            }

            int main(){
                struct Node* head = NULL;
                insertAtBeginning(&head, 3);
                insertAtBeginning(&head, 2);
                insertAtBeginning(&head, 1);
                printList(head); // Kết quả: 1 -> 2 -> 3 -> NULL
                return 0;
            }

* **Doubly Linked List**

        #include <stdio.h>
        #include <stdlib.h>

        struct Node {
            int data;
            struct Node *next;
            struct Node *prev;  // Doubly
        };

        void insertAtBeginning(struct Node** head, int data) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->data = data;
            newNode->next = *head;
            newNode->prev = NULL;
            if (*head) (*head)->prev = newNode;
            *head = newNode;
        }

        void printList(struct Node* head) {
            struct Node* temp = head;
            while (temp != NULL) {
                printf("%d <-> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }

        int main() {
            struct Node* head = NULL;
            insertAtBeginning(&head, 3);
            insertAtBeginning(&head, 2);
            insertAtBeginning(&head, 1);
            printList(head);  // 1 <-> 2 <-> 3 <-> NULL
            return 0;
        }

### **II.Ngăn xếp(Stack)**

<img width="1006" height="568" alt="Image" src="https://github.com/user-attachments/assets/985f8cab-b54f-4b6d-8745-57afb631355d" />

#### **2.1.Định nghĩa**

* Ngăn xếp là một cấu trúc dữ liệu tuyến tính hoạt động theo nguyên tắc **Last In, First Out(LIFO)**

* Các phần tử được thêm(push) và xóa(pop) từ cùng một đầu gọi là **đỉnh(top)**
 

#### **2.2.Các thao tác**

* **Cấu trúc cơ bản:**


        #define MAX 100
        struct Stack {
            int items[MAX];
            int top;
        };

        void initStack(struct Stack* s) { 
            s->top = -1; 
            }

* **Push:** Thêm phần tử vào đỉnh


        void push(struct Stack* s, int value) {
            if (s->top == MAX - 1) { 
                printf("Ngăn xếp đầy\n"); 
                return; 
                }
            s->items[++(s->top)] = value;
        }


* **Pop:** Xóa và trả về phần tử ở đỉnh

        int pop(struct Stack* s) {
            if (s->top == -1) { 
                printf("Ngăn xếp rỗng\n"); 
                return -1; 
                }
            return s->items[(s->top)--];
        }

* **Peek/Top:** Xem phần tử ở đỉnh mà không Xóa

        int peek(struct Stack* s) {
            if (s->top == -1) return -1;
            return s->items[s->top];
        }

* **isEmpty:** Kiểm tra ngăn xếp có rỗng không

        int isEmpty(struct Stack* s){
            return s->top == -1;
        }

* **isFull:** Kiểm tra ngăn xếp có đầy không(với ngăn xếp dựa trên mảng)


        int isFull(struct Stack* s){
            return s->top == MAX - 1;
        }

* **VD:**

            #include <stdio.h>
            #define MAX 100
            struct Stack { 
                int items[MAX]; 
                int top; 
                };

            void initStack(struct Stack* s) { 
                s->top = -1; 
                }

            void push(struct Stack* s, int value) {
                if (s->top == MAX - 1) { 
                    printf("Ngăn xếp đầy\n"); 
                    return; 
                    }
                s->items[++(s->top)] = value;
            }
            int pop(struct Stack* s) {
                if (s->top == -1) { 
                    printf("Ngăn xếp rỗng\n"); 
                    return -1; }
                return s->items[(s->top)--];
            }
            int main() {
                struct Stack s;
                initStack(&s);
                push(&s, 1);
                push(&s, 2);
                printf("Đã xóa: %d\n", pop(&s)); // Kết quả: Đã xóa: 2
                return 0;
            }


### **III.Hàng đợi(Queue)**

<img width="1086" height="420" alt="Image" src="https://github.com/user-attachments/assets/a041c8c3-99c8-4c65-886b-fa76715beeb9" />

#### **3.1.Định nghĩa**

* **Hàng đợi** là một cấu trúc dữ liệu tuyến tính hoạt động theo nguyên tắc **First In, First Out(FIFO)**

* Phần tử được thêm vào từ cuối (**rear**) và xóa từ đầu (**front**)

#### **3.2.Các loại hàng đợi**

* **Hàng đợi thông thường (Simple Queue):** FIFO cơ bản

* **Hàng đợi vòng (Circular Queue):** Đầu và cuối hàng đợi được kết nối để sử dụng lại không gian

* **Hàng đợi ưu tiên (Priority Queue):** Phần tử có ưu tiên cao được xử lý trước

* **Hàng đợi hai đầu (Deque):** Cho phép thêm/xóa từ 2 đầu

#### **3.3.Các thao tác**

* **Cấu trúc cơ bản:**

        #define MAX 100
        struct Queue {
            int items[MAX];
            int front, rear;
        };

        void initQueue(struct Queue* q) { 
            q->front = q->rear = -1; 
            }


* **Enqueue: Thêm phần tử vào cuối hàng đợi**

        void enqueue(struct Queue* q, int value) {
            if (q->rear == MAX - 1) { 
                printf("Đầy\n"); 
                return; 
                }
            if (q->front == -1) q->front = 0;
            q->items[++(q->rear)] = value;
        }

* **Dequeue: Xóa và trả về phần tử ở đầu**

        int dequeue(struct Queue* q) {
            if (q->front == -1 || q->front > q->rear) { 
                printf("Rỗng\n"); 
                return -1; 
                }
            return q->items[(q->front)++];
        }


* **Front: Xem phần tử ở đầu**

        int front(struct Queue* q) {
            if (q->front == -1 || q->front > q->rear) return -1;
            return q->items[q->front];
        }

* **isEmpty: Kiểm tra hàng đợi rỗng**

        int isEmpty(struct Queue* q) {
            return q->front == -1 || q->front > q->rear; 
        }

* **isFull: Kiểm tra hàng đợi đầy**


        int isFull(struct Queue* q){
            return q->rear == MAX - 1;
        }


* **VD:**

        #include <stdio.h>
        #define MAX 100
        struct Queue { 
            int items[MAX]; 
            int front, rear; 
            };
        void initQueue(struct Queue* q) { 
            q->front = -1; 
            q->rear = -1; 
            }
        void enqueue(struct Queue* q, int value) {
            if (q->rear == MAX - 1) { 
                printf("Hàng đợi đầy\n"); 
                return; 
                }
            if (q->front == -1) q->front = 0;
            q->items[++q->rear] = value;
        }
        int dequeue(struct Queue* q) {
            if (q->front == -1 || q->front > q->rear) {
                printf("Hàng đợi rỗng\n"); 
                return -1; 
                }
            return q->items[q->front++];
        }
        int main() {
            struct Queue q;
            initQueue(&q);
            enqueue(&q, 1);
            enqueue(&q, 2);
            printf("Đã xóa: %d\n", dequeue(&q)); // Kết quả: Đã xóa: 1
            return 0;
        }


### **IV.JSON- Xử lý dữ liệu JSON trong C**

#### **4.1.Định nghĩa**

* **JSON(JavaScript Object Notation)** là một định dạng dữ liệu nhẹ, dễ đọc, được sử dụng để trao đổi dữ liệu giữa các hệ thống

* JSON thường được biểu diễn dưới dạng cặp **key-value**, mảng, hoặc các đối tượng lồng nhau

#### **4.2.Cấu trúc JSON**

* **Object:** `{ "key": value }

* **Array:** `[value1, value2, ...]

* **Value:** Chuỗi số, boolean, null, Object, hoặc Array

* **Key:** Luôn là chuỗi


#### **4.3.Thư viện xử lý JSON trong C**

* Trong C, không có hỗ trợ tích hợp cho JSON, nhưng có thể sử dụng các thư viện như cJSON, json-c, hoặc Jansson

* Cài `gcc prog.c -lcjson`

#### **4.4. Các thao tác với JSON**

* **Phân tích cú pháp (Parsing):** 

    ◦ Chuyển chuỗi JSON thành cấu trúc dữ liệu trong C.

        cJSON_Parse(str)

* **Tạo JSON:** 

    ◦ Tạo đối tượng JSON từ dữ liệu trong C.

        cJSON_CreateObject()

* **Truy cập dữ liệu:** 

    ◦ Lấy giá trị từ các khóa hoặc mảng.

        cJSON_GetObjectItem(root, "key")

* **Sửa đổi:** 

    ◦ Thêm, xóa hoặc cập nhật dữ liệu trong JSON.

        cJSON_AddItemToObject()

#### **4.5. Ứng dụng**

* Lưu trữ cấu hình chương trình.

* Trao đổi dữ liệu giữa client và server

* Lưu trữ dữ liệu trong cơ sở dữ liệu NoSQL (như MongoDB).

* API RESTful.


        #include <stdio.h>
        #include <stdlib.h>
        // #include "cJSON.h"  // Giả định lib đã có

        char* createJSON() {
            // cJSON* root = cJSON_CreateObject();  // Uncomment với lib
            // ... (code như gốc)
            return "{\"name\":\"Nguyen Van A\",\"age\":25,\"skills\":[\"C\",\"Python\"]}";  // Hardcode demo
        }

        void parseJSON(const char* jsonString) {
            // cJSON* root = cJSON_Parse(jsonString);
            printf("Tên: Nguyen Van A\n");  // Demo output
            printf("Tuổi: 25\n");
            printf("Kỹ năng: C Python\n");
        }

        int main() {
            char* jsonString = createJSON();
            printf("JSON: %s\n", jsonString);
            parseJSON(jsonString);
            free(jsonString);
            return 0;
        }



### **V.Binary Trees**

<img width="994" height="550" alt="Image" src="https://github.com/user-attachments/assets/22976c7a-4c1d-40ba-8b49-adb7780edd43" />

#### **5.1.Định nghĩa**

* **Cây nhị phân** là cấu trúc dữ liệu phân cấp (hierarchical), nơi mỗi nút (node) có tối đa hai nút con: nút con trái (left child) và nút con phải (right child).

* Cây có một nút gốc (root) và không có chu kỳ, làm cho nó phù hợp cho các ứng dụng như tìm kiếm, sắp xếp và lưu trữ dữ liệu có thứ tự tự nhiên.

#### **5.2.Phân loại**

* **Cây Nhị Phân Đầy Đủ (Full Binary Tree):** 

    Mỗi nút có 0 hoặc 2 con.

* **Cây Nhị Phân Hoàn Chỉnh (Complete Binary Tree):** 

    Tất cả mức đầy trừ mức cuối cùng (lấp từ trái sang phải), dùng cho heap.

* **Cây Nhị Phân Tìm Kiếm (Binary Search Tree – BST):** 

    Đối với mọi nút, tất cả nút con trái < nút gốc < tất cả nút con phải. Đây là loại phổ biến nhất cho search/sort.

* **Cây Cân Bằng (Balanced Trees):** 

    Như AVL hoặc Red-Black, đảm bảo height O(log n) bằng cách tự cân bằng sau insert/delete.


#### **5.3.Đặc Điểm**

* **Số Nút Tối Đa:** Với height h, tối đa 2^{h+1} - 1 nút (full tree).

* **Traversal (Duyệt Cây):** Các cách duyệt để xử lý tất cả nút

    ◦ **Inorder (Left-Root-Right):** Sắp xếp tăng dần cho BST (O(n)).

    ◦ **Preorder (Root-Left-Right):** Copy tree, prefix notation.

    ◦ **Postorder (Left-Right-Root):** Xóa tree, postfix notation.   

#### **5.4. Thao tác cơ bản**

* **Cấu trúc nút:** 

        struct TreeNode {
            int data;
            struct TreeNode* left;
            struct TreeNode* right;
        };

* **Tạo nút:** 

        struct TreeNode* createNode(int data) {
            struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            newNode->data = data;
            newNode->left = newNode->right = NULL;
            return newNode;
        }

* **Insert (BST):** 

        void insert(struct TreeNode** root, int data) {
            if (*root == NULL) {
                *root = createNode(data);
                return;
            }
            if (data < (*root)->data) insert(&((*root)->left), data);
            else if (data > (*root)->data) insert(&((*root)->right), data);
            // Bỏ qua duplicate hoặc xử lý theo nhu cầu
        }

* **Search:** 

        struct TreeNode* search(struct TreeNode* root, int data) {
            if (root == NULL || root->data == data) return root;
            if (data < root->data) return search(root->left, data);
            return search(root->right, data);
        }

</details>

# PHẦN 2: C++ Advanced
<details>
	<summary><strong>BÀI 10: Lập trình hướng đối tượng (OOP)</strong></summary>

## **BÀI 10: Lập trình hướng đối tượng (OOP)**

### **10.1. Classes and Objects**

#### **10.1.1. Khái niệm**

*  **Class (Lớp):** 
   
    ◦ Là một bản thiết kế hoặc khuôn mẫu định nghĩa các **thuộc tính (dữ liệu)** và **hành vi (phương thức)** của 1 loại thực thể
   
    ◦ Class mô tả cách các đối tượng sẽ tạo ra

*  **Object (Đối tượng):**

    ◦ Là một thể hiện (instance) cụ thể của một class, được tạo ra từ bản thiết kế đó

    ◦ Mỗi đối tượng có dữ liệu riêng nhưng chia sẻ cấu trúc và hành vi được định nghĩa trong class

* **VD thực tế:**

   ◦ Class giống như bản vẽ kỹ thuật của một ô tô, mô tả các đặc điểm (màu sắc, động cơ) và hành vi (chạy, dừng)

   ◦ Object là một chiếc xe cụ thể được sản xuất từ bản vẽ đó,VD: Vinfast trắng

#### **10.1.2. Cấu trúc và cách sử dụng**

*  **Cú pháp :** 
   
    ```
    class ClassName {
        public: // Phần công khai (có thể truy cập từ ngoài)
      
        //Thuộc tính (biến thành viên)
        Datatype attribute;

        //Constructor (hàm khởi tạo)
        ClassName(Datatype param1, Datatype param2){
            attribute = param1;
            //Khởi tạo thuộc tính
        }

        //Phương thức (hàm thành viên)
        ReturnType method(){
            //Logic
        }
    };
    ```
* **Để tạo object:** `ClassName obj(param1, param2)`

* **Truy cập:** `obj.attribute;` hoặc `obj.method();`

#### **10.1.3. VD**
   
    
    #include <iostream>
    #include <string>
    using namespace std;

    class Book {
    public:

        //Thuộc tính
        string title;
        string author;

        //Phương thức
        void displayInfo(){
            cout << "Book: " << title << ", Author: " << author << endl;
        }
    };

    int main(){

        //Tạo đối tượng
        Book book1;
        book1.title = "Harry Potter";
        book1.author = "A";

        //Sử dụng đối tượng
        book1.displayInfo();

        return 0;
    }
    
### **10.2. Encapsulation**

#### **10.2.1. Khái niệm**

* **Encapsulation (Đóng gói):** 

    ◦ Là nguyên tắc gói gọn dữ liệu và phương thức liên quan vào một class, đồng thời kiểm soát quyền truy cập thông qua `public`,`private`,`protected`

    ◦ Mục tiêu là ẩn chi tiết triển khai và chỉ cung cấp giao diện công khai

* **VD thực tế:** 

    ◦ Một chiếc máy pha cà phê có nút bấm (giao diện công khai) để người dùng chọn chế độ pha, nhưng cách máy xử lý bên trong (đun nước, xay cà phê) được ẩn đi

#### **10.2.2.Quyền truy cập**

* **public**: Có thể truy cập từ bên ngoài class
* **private**: Chỉ có thể truy cập từ bên trong class
* **protected**: Truy cập được trong class và các class con(kế thừa)

#### **10.2.3. Getter và Setter**

* **Getter**: Phương thức công khai trả về giá trị của thuộc tính riêng tư, thường có const để không thay đổi đối tượng.

* **Setter**: Phương thức công khai để sửa đổi thuộc tính riêng tư, thường kèm kiểm tra hợp lệ.

* **Lưu ý:** Sử dụng getter/setter để tuân thủ encapsulation, tránh truy cập trực tiếp private attributes.

#### **10.2.4. VD**

    
    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    private:
        string name;
        int age;

    public:
        // Constructor
        Person(string name, int age) {
            setName(name);
            setAge(age);
        }

        // Getter
        string getName() const { 
            return name; 
            }
        int getAge() const { 
            return age; 
            }

        // Setter
        void setName(string name) {
            if (!name.empty()) this->name = name;
            else this->name = "Unknown";
        }
        void setAge(int age) {
            if (age >= 0) this->age = age;
            else this->age = 0;
        }

        void introduce() {
            cout << "Tôi là " << name << ", " << age << " tuổi" << endl;
        }
    };

    int main() {
        Person person("Nam", 25);
        person.introduce(); // Tôi là Nam, 25 tuổi
        person.setAge(-5); // Không hợp lệ, age = 0
        person.setName(""); // Không hợp lệ, name = Unknown
        person.introduce(); // Tôi là Unknown, 0 tuổi
        cout << "Tên: " << person.getName() << ", Tuổi: " << person.getAge() << endl;
        return 0;
    }

#### **10.2.5. Friend Function và Friend Class (Hàm bạn và Lớp bạn)**

* **Friend:** 
    
    ◦ Cho phép một hàm hoặc lớp khác truy cập vào các thành viên private/ protected của class, mà không cần làm chúng public
    
    ◦ Đây là ngoại lệ của encapsulation, dùng khi cần hợp tác chặt chẽ giữa các class, nhưng không lạm dụng để tránh phá vỡ tính đóng gói.

* **Friend Function (Hàm bạn):** 
    
    ◦ Một hàm bên ngoài class được khai báo là friend, có thể truy cập private data

    ◦ Cú pháp
    
    ```
    friend ReturnType functionName(ClassName& obj); (khai báo trong class)
    ```
* **Friend Class (Lớp bạn):** 
    
    ◦ Một class khác được khai báo là friend,tất cả phương thức của nó có thể truy cập private data

    ◦ Cú pháp
    
    ```
    friend class OtherClass; (khai báo trong class)
    ```

* **VD:** 

    ```
    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    private:
        string secret = "This is private!";  // Dữ liệu riêng tư

    public:
        // Khai báo hàm friend
        friend void showSecret(Person& p);  // Hàm bạn

        // Khai báo lớp friend
        friend class FriendClass;
    };

    // Định nghĩa hàm friend (bên ngoài class)
    void showSecret(Person& p) {
        cout << "Friend function accesses: " << p.secret << endl;
    }

    class FriendClass {
    public:
        void accessSecret(Person& p) {
            cout << "Friend class accesses: " << p.secret << endl;
        }
    };

    int main() {
        Person person;
        showSecret(person);  // Output: Friend function accesses: This is private!
        
        FriendClass fc;
        fc.accessSecret(person);  // Output: Friend class accesses: This is private!
        
        return 0;
    }
    ```
### **10.3. Kế thừa (Inheritance)**

#### **10.3.1. Khái niệm**

* **Kế thừa (Inheritance):** 

    ◦ Cho phép một lớp con (derived class) thừa hưởng thuộc tính và phương thức của lớp cha (base class), thiết lập quan hệ "is-a" (là một).

    ◦ Mục tiêu: Tái sử dụng mã, mở rộng chức năng.

* **VD thực tế:** 

    ◦ Một lớp Dog là một loại Animal, nên Dog có thể kế thừa các đặc điểm chung của Animal (như tên, tuổi) và thêm các đặc điểm riêng (như giống chó).

#### **10.3.2. Các loại kế thừa**

* **Single Inheritance:** 

    ◦ Một lớp con kế thừa từ một lớp cha.
  
      
	  class Parent {
      public:
      	//Thuộc tính và phương thức lớp cha
      	void parentMethod(){
      	//Logic
      	}
      };

	  class Child : public Parent {
      public:
      	//Thuộc tính và phương thức của lớp con
        void childMethod(){
  		//Logic
  		}
  	  };
  	  
* **Multiple Inheritance:** 

    ◦ Lớp con kế thừa từ lớp cha, lớp cha kế thừa từ lớp khác.
	```
	class Parent1 {
    public:
 		//Thuộc tính và phương thức của Parent1
 		void method1(){
 		//Logic
 		}
 	};

 	class Parent2 {
 	public:
 		//Thuộc tính và phương thức của parent2
 		void method2(){
 		//Logic
 		}
 	};

 	class Child : public Parent1, public Parent2 {
 	public:
 		//Thuộc tính và phương thức của lớp con
 		void childMethod(){
 		//Logic
 		}
 	};
 	```
* **Multilevel Inheritance:**

    ◦ Lớp con kế thừa từ lớp cha, lớp cha kế thừa từ lớp khác.
	```
	class Grandparent {
 	public:
 		void grantparentMethod(){
 		//Logic
 		}
 	};

 	class Parent : public Grandparent {
 	public:
 		void parentMethod(){
 		//Logic
 		}
 	};

 	class Child : public Parent {
 	public:
 		void childMethod(){
 		//Logic
 		}
 	};
 	```
* **Hierarchical Inheritance:**

    ◦ Nhiều lớp con kế thừa từ một lớp cha.
	```
	class Parent {
 	public:
 		void parentMethod(){
 		//Logic
 		}
 	};

 	class Child1 : public Parent {
 	public:
 		void child1Method(){
 		//Logic;
 		}
 	};

 	class Child2 : public Parent {
 	public:
 		void child2Method(){
 		//Logic;
 		}
 	};
 	```
#### **10.3.3. Cú pháp**

    
    class Base {
    public:
        void baseMethod() {}
    };
    class Derived : public Base {
    public:
        void derivedMethod() {}
    }
    

#### **10.3.4. VD**

    ```
    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    protected:
        string name;
        int age;

    public:
        Person(string name, int age) : name(name), age(age) {}
        void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
    };

    class Student : public Person {
    private:
        string studentId;

    public:
        Student(string name, int age, string id) : Person(name, age), studentId(id) {}
        void display() {
            Person::display();
            cout << "Student ID: " << studentId << endl;
        }
    };

    int main() {
        Student student("Alice", 20, "S123");
        student.display();
        // Output:
        // Name: Alice, Age: 20
        // Student ID: S123
        return 0;
    }    

    ```
    
### **10.4. Đa hình (Polymorphism)**

#### **10.4.1. Khái niệm**

* **Đa hình (Polymorphism):** 

    ◦ Cho phép các đối tượng của các lớp khác nhau (nhưng có quan hệ kế thừa) được xử lý như đối tượng của lớp cha, nhưng hành vi thực tế phụ thuộc vào lớp con. Nghĩa là "một giao diện, nhiều cách triển khai".
   
* **Có 2 loại:** 

    ◦ **Compile-time Polymorphism:** Quyết định lúc biên dịch, qua function overloading hoặc operator overloading.

    ◦ **Run-time Polymorphism:** Quyết định lúc chạy, qua virtual function và override.

#### **10.4.2. Compile-time Polymorphism**

* **Function Overloading:** 

    ◦ Nhiều hàm cùng tên nhưng khác tham số.

    ```
    void print(int x); void print(string s);
    ```

* **Operator Overloading:** 

    ◦ Định nghĩa lại ý nghĩa của toán tử (như +, <<).

    
#### **10.4.3. Run-time Polymorphism**

*  Sử dụng từ khóa `virtual` trong `lớp cha`, và `override (C++11)` trong `lớp con` để ghi đè. Dùng con trỏ hoặc tham chiếu đến lớp cha để gọi.

* Lưu ý: Không virtual thì gọi phương thức cha (không đa hình động).
   
#### **10.4.4. VD**

    ```
    #include <iostream>
    using namespace std;

    class Animal {
    public:
        virtual void makeSound() {
            cout << "Some generic animal sound" << endl;
        }
    };

    class Dog : public Animal {
    public:
        void makeSound() override {
            cout << "Woof Woof!" << endl;
        }
    };

    class Cat : public Animal {
    public:
        void makeSound() override {
            cout << "Meow Meow!" << endl;
        }
    };

    int main() {
        Animal* animals[2];
        animals[0] = new Dog();
        animals[1] = new Cat();
        for (int i = 0; i < 2; i++) {
            animals[i]->makeSound();
            delete animals[i];
        }
        // Output:
        // Woof Woof!
        // Meow Meow!
        return 0;
    }   

    ```
### **10.5. Hàm khởi tạo (Constructor)**

#### **10.5.1. Khái niệm**

* **Hàm khởi tạo (Constructor):** 

    ◦  Là phương thức đặc biệt, được gọi tự động khi đối tượng được tạo, dùng để khởi tạo thuộc tính.
   
* **Đặc điểm:** 

    ◦ Tên trùng với lớp, không có kiểu trả về.

    ◦ Có thể overload với các tham số khác nhau.

    ◦ Nếu không định nghĩa, trình biên dịch cung cấp constructor mặc định không tham số.

#### **10.5.2. Các loại constructor**

* **Constructor mặc định:** 

    ◦ Không tham số, khởi tạo giá trị mặc định.
  
    ◦ Có dùng danh sách khởi tạo
	 ```
	 ClassName(): member1(value1), member2(value2), ... {
     //Thân hàm
  	 }
     ```
     ```
     #include <iostream>
	 #include <string>

	 class Person {
	 public:
    	std::string name; // Thành viên không tĩnh
    	int age;          // Thành viên không tĩnh
    	static int count; // Thành viên tĩnh

     Person() : name("Unknown"), age(0) { // Constructor mặc định với danh sách khởi tạo
        count++;
        std::cout << "So doi tuong: " << count << std::endl;
    	}
	 };

	 int Person::count = 0;
     ```
     ◦ Không dùng danh sách khởi tạo
     ```
     ClassName(){
      //Thân hàm
     }
     ```
* **Constructor có tham số:** 

    ◦ Khởi tạo với giá trị cụ thể.
    ```
	ClassName(Type1 param1, Type2 param2, ...) : member1(param1), member2(param2), ...{
    //Thân hàm
    } 
    ```
* **Copy Constructor:**

    ◦ Sao chép dữ liệu từ một đối tượng khác.
	```
    ClassName(const ClassName& other) : member1(other.member1), member2(other.member2), ... {
    //Thân hàm
 	}
 	```
    ```
	const ClassName&: Tham chiếu hằng đến một đối tượng của cùng lớp (ClassName), đảm bảo không sửa đổi đói tượng được sao chép
    other: Tên tham số đại diện cho đối tượng được sao chép 
    ```
* **Move Constructor (C++11):**

    ◦ Chuyển tài nguyên từ đối tượng tạm thời.
    ```
    ClassName(ClassName&& other) noexcept : member1(std::move(other.member1)), member2(std::move(other.member2)), ... {
    //Thân hàm (thường đặt lại trạng thái của other)
    }
    ```
    ```
	ClassName&&: Tham chiếu rvalue (rvalue reference) đến một đối tượng tạm thời của lớp ClassName.
    other: Tên tham số đại diện cho đối tượng tạm thời.
    noexcept: (Tùy chọn, nhưng khuyến nghị) Đảm bảo constructor không ném ngoại lệ, tối ưu hóa hiệu suất.
    Danh sách khởi tạo, sử dụng std::move để chuyển tài nguyên từ other sang đối tượng mới.
    std::move: Chuyển đổi other.member thành rvalue để kích hoạt chuyển giao tài nguyên.
    ```
#### **10.5.3. VD**


    
    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    private:
        string name;
        int age;

    public:
        // Constructor mặc định
        Person() : name("Unknown"), age(0) {}

        // Constructor có tham số
        Person(string name, int age) : name(name), age(age) {}

        // Copy Constructor
        Person(const Person& other) : name(other.name), age(other.age) {}

        void introduce() {
            cout << "Tôi là " << name << ", " << age << " tuổi" << endl;
        }
    };

    int main() {
        Person person1; // Constructor mặc định
        Person person2("Nam", 25); // Constructor có tham số
        Person person3 = person2; // Copy constructor
        person1.introduce(); // Tôi là Unknown, 0 tuổi
        person2.introduce(); // Tôi là Nam, 25 tuổi
        person3.introduce(); // Tôi là Nam, 25 tuổi
        return 0;
    }

### **10.6. Hàm hủy (Destructor)**

#### **10.6.1. Khái niệm**

* **Hàm hủy (Destructor):** 

    ◦  Là phương thức đặc biệt, được gọi tự động khi đối tượng bị hủy (ra khỏi phạm vi hoặc dùng delete).

* **Lưu ý:**
    
    ◦ Destructor chỉ có một, không overload được. Virtual destructor cần nếu có kế thừa để gọi đúng destructor con.
   
* **Đặc điểm:** 

    ◦ Tên là `~ClassName()`, không tham số, không kiểu trả về.

    ◦ Dùng để dọn dẹp tài nguyên (bộ nhớ động, file, kết nối mạng).

    ◦ Trình biên dịch cung cấp destructor mặc định nếu không định nghĩa.


#### **10.6.2. VD**

    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    private:
        string name;
        int* data; // Bộ nhớ động

    public:
        Person(string name, int value) : name(name) {
            data = new int(value);
            cout << "Constructor called for " << name << endl;
        }

        ~Person() {
            delete data; // Giải phóng bộ nhớ
            cout << "Destructor called for " << name << endl;
        }

        void display() {
            cout << "Name: " << name << ", Data: " << *data << endl;
        }
    };

    int main() {
        Person person("Nam", 25);
        person.display(); // Name: Nam, Data: 25
        // Destructor tự động gọi khi person ra khỏi phạm vi
        return 0;
    }

### **10.7. Nạp chồng toán tử (Operator Overloading)**

#### **10.7.1. Khái niệm**

* **Operator Overloading:** 

    ◦  Nạp chồng toán tử cho phép định nghĩa lại ý nghĩa của các toán tử (+, <<, ==, v.v.) cho các lớp do người dùng định nghĩa.
   
    ◦ Thuộc compile-time polymorphism.
  
	```
	Bình thường, các toán tử này chỉ hoạt động với các kiểu dữ liệu cơ bản như int, float, double. Ví dụ: 3 + 5 sẽ cho ra kết quả là 8.
    Nhưng nếu bạn có một lớp tự định nghĩa, chẳng hạn như lớp Vector2D (đại diện cho một vector 2 chiều), bạn có thể định nghĩa toán tử + để cộng hai vector theo cách bạn muốn.
 	```

* **Lưu ý:**

   ◦  Không thay đổi thứ tự ưu tiên toán tử.

   ◦  Không nạp chồng một số toán tử như `::, .*, sizeof.`

   ◦  Có hai loại: **Member operator (trong class)** và **Non-member (friend operator, hữu ích cho toán tử như <<).**

* **Các loại toán tử phổ biến:**

   ◦  Nhị nguyên: + , - , * , / , == , != , < , > , = (gán)

   ◦  Đơn nguyên: ++ , -- , ! , - (âm)

   ◦  Khác: [] (index), () (gọi hàm), -> (con trỏ)

#### **10.7.2. Cú pháp**

* **Member:** `ReturnType operator+(const ClassName& other) const { ... }`

* **Friend:** `friend ReturnType operator+(const ClassName& a, const ClassName& b);`

* **Trả về:** Thường là object mới hoặc tham chiếu (&) cho hiệu suất.

#### **10.7.3.VD**

    ```
    #include <iostream>
    using namespace std;

    class Vector2D {
    public:
        int x, y;

        // Constructor với giá trị mặc định
        Vector2D(int x = 0, int y = 0) : x(x), y(y) {}

        // Toán tử +: Cộng hai vector
        Vector2D operator+(const Vector2D& other) const {
            return Vector2D(x + other.x, y + other.y);
        }

        // Toán tử -: Trừ hai vector
        Vector2D operator-(const Vector2D& other) const {
            return Vector2D(x - other.x, y - other.y);
        }

        // Toán tử ==: So sánh hai vector
        bool operator==(const Vector2D& other) const {
            return x == other.x && y == other.y;
        }

        // Toán tử ++: Tăng x, y lên 1 (prefix)
        Vector2D& operator++() {
            x++; y++; // Tăng x, y
            return *this; // Trả về chính vector sau khi tăng
        }

        // Toán tử <<: Xuất vector ra màn hình
        friend ostream& operator<<(ostream& os, const Vector2D& vec) {
            os << "(" << vec.x << ", " << vec.y << ")";
            return os;
        }

        // Toán tử >>: Nhập vector từ bàn phím
        friend istream& operator>>(istream& is, Vector2D& vec) {
            cout << "Nhap x, y: ";
            is >> vec.x >> vec.y;
            return is;
        }
    };

    int main() {
        // Tạo hai vector
        Vector2D v1(1, 2), v2(3, 4);

        // Thử toán tử +
        cout << "v1 + v2 = " << v1 + v2 << endl; // (4, 6)

        // Thử toán tử -
        cout << "v2 - v1 = " << v2 - v1 << endl; // (2, 2)

        // Thử toán tử ==
        if (v1 == Vector2D(1, 2)) {
            cout << "v1 bang (1, 2)" << endl; // In ra
        }

        // Thử toán tử ++
        ++v1; // Tăng v1 thành (2, 3)
        cout << "Sau ++v1, v1 = " << v1 << endl;

        // Thử toán tử nhập
        Vector2D v3;
        cin >> v3; // Ví dụ nhập: 5 6
        cout << "Vector vua nhap: " << v3 << endl;

        return 0;
    }
    ```

### **10.8. Kỹ thuật khởi tạo (Uniform Initialization)**

#### **10.8.1. Khái niệm**

* **Uniform Initialization:** 

    ◦  Uniform Initialization (C++11) cung cấp cách khởi tạo thống nhất cho các kiểu dữ liệu, sử dụng dấu `{}`.
   
    ◦ Ngăn chặn lỗi ép kiểu (type narrowing).

    ◦ Dễ đọc, thống nhất cho mọi kiểu dữ liệu.


#### **10.8.2. Cú pháp**

    Type var{value};            //Khởi tạo biến         
    Type obj{param1, param2};   //Khởi tạo đối tượng    
    Type arr[]{value1, value2}; //Khởi tạo mảng        
    ClassName obj[];            //Khởi tạo mặc định

    
 ◦ `{}` có thể chứa danh sách giá trị hoặc để trống (khởi tạo mặc định).

 ◦ Hỗ trợ khởi tạo với `std::initializer_list` cho các lớp hoặc container
#### **10.8.3.VD**

    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    public:
        string name;
        int age;

        Person(string name, int age) : name(name), age(age) {}
        void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
    };

    int main() {
        // Uniform initialization
        Person person1{"Nam", 25};
        person1.display(); // Name: Nam, Age: 25

        // Khởi tạo mảng
        int arr[]{1, 2, 3};
        cout << "Array: ";
        for (int x : arr) cout << x << " "; // Array: 1 2 3
        cout << endl;

        // Khởi tạo biến
        int x{5};
        cout << "x: " << x << endl; // x: 5
        return 0;
    }

### **10.9. Con trỏ this**

#### **10.9.1. Khái niệm**


* Con trỏ this là một con trỏ đặc biệt, trỏ đến đối tượng hiện tại của lớp.
   
* Phân biệt giữa thuộc tính lớp và tham số có cùng tên.

* Trả về chính đối tượng hiện tại (hữu ích trong nạp chồng toán tử hoặc phương thức chuỗi).


#### **10.9.2. VD**


    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    private:
        string name;
        int age;

    public:
        Person(string name, int age) {
            this->name = name; // Phân biệt với tham số
            this->age = age;
        }

        Person& setName(string name) {
            this->name = name;
            return *this; // Trả về đối tượng hiện tại
        }

        void display() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
    };

    int main() {
        Person person("Nam", 25);
        person.display(); // Name: Nam, Age: 25
        person.setName("Lan").display(); // Name: Lan, Age: 25
        return 0;
    }

### **10.10. Thành viên tĩnh (Static Member)**

#### **10.10.1. Khái niệm**


* Thành viên tĩnh thuộc về lớp, không thuộc về đối tượng cụ thể, được chia sẻ giữa tất cả các đối tượng.
   
* Bao gồm:

    ◦ **Biến tĩnh:** Được khai báo bằng static, khởi tạo ngoài lớp.

    ◦ **Phương thức tĩnh:** Chỉ truy cập biến tĩnh hoặc thực hiện logic không phụ thuộc vào đối tượng.


#### **10.10.2. VD**


    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    public:
        static int count; // Biến tĩnh
        string name;

        Person(string name) : name(name) {
            count++;
        }

        ~Person() {
            count--;
        }

        static void showCount() {
            cout << "Số đối tượng Person: " << count << endl;
        }
    };

    // Khởi tạo biến tĩnh
    int Person::count = 0;

    int main() {
        Person::showCount(); // Số đối tượng Person: 0
        Person p1("Nam");
        Person::showCount(); // Số đối tượng Person: 1
        Person p2("Lan");
        Person::showCount(); // Số đối tượng Person: 2
        return 0;
    }

### **10.11. Phương thức const**

#### **10.11.1. Khái niệm**


* Phương thức const là phương thức không thay đổi trạng thái của đối tượng (không sửa đổi thuộc tính).
   
* Được đánh dấu bằng từ khóa const sau khai báo phương thức.

* Dùng trong getter hoặc các phương thức chỉ đọc dữ liệu.
    
#### **10.11.2. VD**


    #include <iostream>
    #include <string>
    using namespace std;

    class Person {
    private:
        string name;
        int age;

    public:
        Person(string name, int age) : name(name), age(age) {}

        void display() const {
            cout << "Name: " << name << ", Age: " << age << endl;
            // name = "Test"; // Lỗi biên dịch, vì phương thức const
        }
    };

    int main() {
        Person person("Nam", 25);
        person.display(); // Name: Nam, Age: 25
        return 0;
    }

</details> 


<details>
	<summary><strong>BÀI 11: Kế thừa, Interface, Abstract Class</strong></summary>

## **BÀI 11: Kế thừa, Interface, Abstract Class**

### **11.1. Multiple Inheritance & Diamond Problem**

#### **11.1.1. Khái niệm**

*  **Multiple Inheritance (Kế thừa đa cấp):** 
   
    ◦ Một lớp con (derived class) có thể kế thừa từ nhiều lớp cha (bases classes) cùng lúc
   
    ◦ Tuy nhiên, kế thừa đa cấp có thể dẫn đến vấn đề **Diamond Problem**

*  **Diamond Problem:**

    <img width="214" height="199" alt="Image" src="https://github.com/user-attachments/assets/bbebbfb2-d25b-4ae2-9a97-8e69c2046c4b" />


    ◦ Xảy ra khi một lớp con kế thừa từ hai lớp cha, mà hai lớp cha này lại cùng kế thừa từ một lớp ông

    ◦ Điều này có thể tạo ra bản sao của lớp ông trong lớp con, gây xung đột khi truy cập thành viên của lớp ông

    => Trong trường hợp này, lớp Z kế thừa từ X và Y, cả X và Y đều kế thừa từ A, dẫn đến việc Z có thể chứa 2 bản sao của A


#### **11.1.2. Giải pháp: Virtual Inheritance**

* Sử dụng từ khóa `virtual` khi kế thừa để đảm bảo chỉ có một bản sao duy nhất của lớp ông trong lớp con

*  **Cú pháp :** 
   
    ```
    class A { /* ... */ };
    class X : virtual public A { /* ... */ };
    class Y : virtual public A { /* ... */ };
    class Z : public X, public Y { /* ... */ };
    ```
* Với `virtual Inheritance` , chỉ một bản sao của lớp A được chia sẻ giữa X và Y, tránh xung đột

#### **11.1.3. VD**
   

    #include <iostream>
    using namespace std;

    class A {
    public:

        void show() { cout << "Class A" << endl; }
    };

    class X : virtual public A {};
    class Y : virtual public A {};
    class Z : public X, public Y {};

    int main(){
    
        Z z;
        z.show();       // Không gây lỗi do chỉ có 1 bản sao của A
        return 0;
    }

* Lưu ý: Nếu không dùng virtual, trình biên dịch sẽ báo lỗi hoặc yêu cầu xác định rõ ràng `(e.g., d.X::show())`.

### **11.2. Virtual Function, Pure Virtual, vtable**

#### **11.2.1. Virtual Function**

* **Virtual Function (Hàm ảo):** 

    ◦ Là hàm được khai báo với từ khóa `virtual` trong lớp cha, cho phép đa hình runtime

    ◦ Khi hàm ảo được gọi thông qua con trỏ hoặc tham chiếu của lớp cha,hàm con sẽ được thực thi nếu nó ghi đè (override)


* **vtable (Virtual Table):** 

    ◦ Là bảng con trỏ hàm được tạo bởi trình biên dịch để lưu trữ địa chỉ của các hàm ảo

    ◦ Mỗi đối tượng của lớp có hàm ảo sẽ chứa một con trỏ đến vtable, giúp xác định hàm nào sẽ được gọi tại runtime

#### **11.2.2. Pure Virtual Function**

* **Pure Virtual Function (Hàm ảo thuần túy)**: 

    ◦ Là hàm ảo không có triển khai trong lớp cha, được khai báo với `=0`

    ◦ Lớp chứa hàm ảo thuần túy trỏ thành **abstact class**, không thể tạo đối tượng trực tiếp

    ◦ Mục đích: Buộc các lớp con phải triển khai hàm này


* **Cú pháp**: 

    ```
    class Base {
    public:
        virtual void func() = 0;    //Hàm ảo thuần túy
    }

    ```
* **VD**: 

    ```
    #include <iostream>
    using namespace std;

    class Animal {
    public:
        virtual void makeSound() = 0; // Pure virtual function
        virtual ~Animal() {} // Virtual destructor
    };

    class Dog : public Animal {
    public:
        void makeSound() override {
            cout << "Woof Woof!" << endl;
        }
    };

    class Cat : public Animal {
    public:
        void makeSound() override {
            cout << "Meow Meow!" << endl;
        }
    };

    int main() {
        Animal* animals[] = { new Dog(), new Cat() };
        for (Animal* animal : animals) {
            animal->makeSound();
            delete animal;
        }
        // Output:
        // Woof Woof!
        // Meow Meow!
        return 0;
    }

    ```

### **11.3. Interface Design**

#### **11.3.1. Khái niệm**

* **Interface (Giao diện):** 

    ◦ Trong C++, giao diện được mô phỏng bằng cách sử dụng lớp trừu tượng chỉ chứa các hàm ảo thuần túy (`=0`)

    ◦ Giao diện định nghĩa contract mà các lớp con phải tuân thủ

* **Mục đích:** 

    ◦ Tách biệt giao diện (chức năng) và triển khai (cách thực hiện)

    ◦ Dễ dàng bảo trì, mở rộng, và thay thế triển khai mà không ảnh hưởng đến mã sử dụng giao diện.

#### **11.3.2. Cú pháp**

    
    class Interface {
    public: 
        virtual void method1() = 0;
        virtual void method2() = 0;
        virtual ~Interface() {}  // Virtual destructor
    }
 	
#### **11.3.3. VD**

    
    #include <iostream>
    using namespace std;

    class Drawable {
    public:
        virtual void draw() = 0;
        virtual ~Drawable() {}
    };

    class Circle : public Drawable {
    public:
        void draw() override {
            cout << "Drawing a circle" << endl;
        }
    };

    class Rectangle : public Drawable {
    public:
        void draw() override {
            cout << "Drawing a rectangle" << endl;
        }
    };

    int main() {
        Drawable* shapes[] = { new Circle(), new Rectangle() };
        for (Drawable* shape : shapes) {
            shape->draw();
            delete shape;
        }
        // Output:
        // Drawing a circle
        // Drawing a rectangle
        return 0;
    }
    



### **11.4. Object Slicing, Upcasting & Downcasting**

#### **11.4.1. Object Slicing**

* **Object Slicing:** 

    ◦ Xảy ra khi một đối tượng của lớp con được gán trực tiếp cho một biến của lớp cha

    ◦ Phần dữ liệu và hành vi đặc trưng của lớp con sẽ bị mất, chỉ giữ lại phần thuộc về lớp cha

* **Nguyên nhân:**

    ◦ Gán giá trị (value copy) thay vì sử dụng con trỏ hoặc hàm tham chiếu
   
* **VD:** 

    ```
    #include <iostream>
    using namespace std;

    class Base {
    public:
        virtual void show() { cout << "Base" << endl; }
    };

    class Derived : public Base {
    public:
        void show() override { cout << "Derived" << endl; }
        void extra() { cout << "Extra function" << endl; }
    };

    int main() {
        Derived derived;
        Base base = derived; // Object slicing
        base.show(); // Output: Base
        // base.extra(); // Lỗi: extra() không tồn tại trong Base
        return 0;
    }

    ```

#### **11.4.2. Upcasting**

* **Upcasting:** 

    ◦ Chuyển một con trỏ hoặc tham chiếu từ lớp con lên lớp cha. Đây là quá trình an toàn và tự động, vì lớp con luôn là một loại của lớp cha (quan hệ "is-a").


* **Cú pháp:** 

    ```
    Derived derived;
    Base* base = &derived; // Upcasting

    ```

* **VD:**

    ```
    #include <iostream>
    using namespace std;

    class Base {
    public:
        virtual void show() { cout << "Base" << endl; }
    };

    class Derived : public Base {
    public:
        void show() override { cout << "Derived" << endl; }
    };

    int main() {
        Derived derived;
        Base* base = &derived; // Upcasting
        base->show(); // Output: Derived (do virtual function)
        return 0;
    }

    ```
#### **11.4.3. Downcasting**

*  **Downcasting:** 

    ◦ Chuyển một con trỏ hoặc tham chiếu từ lớp cha xuống lớp con. Đây là quá trình không an toàn, cần sử dụng `dynamic_cast` để kiểm tra tính hợp lệ tại runtime.

*  **Cú pháp:**

    ```
    Base* base = new Derived();
    Derived* derived = dynamic_cast<Derived*>(base);

    ```
   
#### **11.4.4. VD**

    ```
    #include <iostream>
    using namespace std;

    class Base {
    public:
        virtual void show() { cout << "Base" << endl; }
        virtual ~Base() {}
    };

    class Derived : public Base {
    public:
        void show() override { cout << "Derived" << endl; }
        void extra() { cout << "Extra function" << endl; }
    };

    int main() {
        Base* base = new Derived();
        Derived* derived = dynamic_cast<Derived*>(base);
        if (derived) {
            derived->show(); // Output: Derived
            derived->extra(); // Output: Extra function
        } else {
            cout << "Downcast failed" << endl;
        }
        delete base;
        return 0;
    }
    ```

* **Lưu ý:** Nếu `dynamic_cast` thất bại (base không thực sự trỏ đến Derived), con trỏ trả về sẽ là nullptr.



</details> 

<details>
	<summary><strong>BÀI 12: Smart Pointer & RAII</strong></summary>

## **BÀI 12: Smart Pointer & RAII**

### **12.1. Smart Pointer**

#### **12.1.1. Khái niệm**

*  **Smart Pointer** là các lớp trong C++ (thư viện `<memory>`) quản lý bộ nhớ động một cách tự động, giúp tránh rò rỉ bộ nhớ và lỗi con trỏ

*  Chúng thay thế cho việc sử dụng con trỏ thô `(new/delete)` bằng cách tự động giải phóng tài nguyên khi không còn được sử dụng, dựa trên cơ chế RAII.

*  Có 3 loại chính 

    ◦ **std::unique_ptr:** 
    
       Sở hữu duy nhất một đối tượng, tự động giải phóng khi ra khỏi phạm vi
       Không thể sao chép, chỉ có thể di chuyển (move) 

    ◦ **std::shared_ptr:**
       
       Sở hữu chia sẻ, sử dụng bộ đếm tham chiếu (reference count) để theo dõi số lượng con trỏ sở hữu đối tượng
       Đối tượng được giải phóng khi bộ đếm về 0
       
    ◦ **std::weak_ptr:**

       Tham chiếu yếu, không sở hữu đối tượng, dùng để tránh vòng tham chiếu (circular dependency) với `shared_ptr`


#### **12.1.2. std::unique_ptr**

*  **Tại sao dùng unique_ptr :**
   
    ◦ Khi bạn muốn một tài nguyên chỉ có một chủ sở hữu duy nhất, tránh việc nhiều nơi cùng can thiệp

    ◦ Đảm bảo tài nguyên được giải phóng tự động khi `unique_ptr` ra khỏi scope

    ◦ Ngăn chặn sao chép ngoài ý muốn (khác với `shared_ptr`,`unique_ptr` không cho copy)

    ◦ Phù hợp với

    => Quản lý tài nguyên độc quyền (file handle, socket, thiết bị ngoại vi)

    => Sử dụng trong RAII để chắc chắn giải phóng bộ nhớ
    
    => Trả về đối tượng từ hàm mà không cần lo lắng về copy

*  **Đặc điểm :**

    ◦ Chỉ một `unique_ptr` có thể sở hữu một đối tượng tại một thời điểm

    ◦ Không thể sao chép (copy), chỉ có thể di chuyển (move) quyền sở hữu

    ◦ Tự động gọi `delete` khi unique_ptr ra khỏi phạm vi hoặc khi gọi reset()

*  **Cú pháp :** 
   
    ```
    #include <memory>
    std::unique_ptr<Type> ptr = std::make_unique<Type>(params);
    ```

*  **Các hàm thành viên thường dùng :**

   ◦ **get()** : Trả về con trỏ thô

   
        auto p = std::make_unique<int>(10);
        int* raw = p.get();
        std::cout << *raw << std::endl;  //In: 10
   

   ◦ **release()** : Trả về con trỏ thô và bỏ quyền sở hữu (không tự xóa)

   
        auto p = std::make_unique<int>(20);
        int* raw = p.release();
        std::cout << *raw << std::endl;  //In: 20
        delete raw; //Phải tự xóa
   

   ◦ **reset()**  : Thay đổi đối tượng đang quản lý (giải phóng cái cũ nếu có)

   
        auto p = std::make_unique<int>(30);
        p.reset(new int(40));
        std::cout << *p << std::endl;   //In: 40

   

   ◦ **swap()** : Hoán đổi hai `unique_ptr`

   
        auto p1 = std::make_unique<int>(1);
        auto p2 = std::make_unique<int>(2);
        p1.swap(p2);
        std::cout << *p1 << " " << *p2 << std::endl; //In: 2 1
   

   ◦ `operator*` và `operator->` : Truy cập đối tượng như con trỏ thường

   
        struct Test { 
            void hi(){ 
                std::cout << "Hi\n"; 
                } 
            };

        auto p = std::make_unique<Test>();
        (*p).hi();   // dùng *
        p->hi();     // dùng ->
   


*  **VD:**

    
        #include <iostream>
        #include <memory>
        using namespace std;

        class File {
        public:
            File(string name)  {
                cout << "Mo file: " << name << endl;
            }
            ~File(){
                cout << "Dong file" << endl;
            }
            void write(string msg){
                cout << "Ghi: " << msg << endl;
            }
        };
        int main(){
            unique_ptr<File> f = make_unique<File>("data.txt");
            f->write("Xin chao");

            //Chuyen quyen so huu
            unique_ptr<File> f2 = move(f);
            if(!f) cout << "f khong con giu file\n";

            f2->write("Noi dung moi");
            return 0;
        }
    

    ```
        Mở file: data.txt
        Ghi: Xin chao
        f không còn giữ file
        Ghi: Noi dung moi
        Đóng file

    ```

#### **12.1.3. std::shared_ptr**

*  **Tại sao dùng shared_ptr :**
   
    ◦ Nếu dùng con trỏ thường (vd: Motorbike* ), ta sẽ phải tự nhớ khi nào cần xóa, nguy cơ double delete hoặc memory leak

    => shared_ptr giải quyết vấn đề bằng reference counting, khi không còn ai giữ tự động `delete` đối tượng

    => Dùng shared_ptr khi nhiều module cùng ghi vào một file logger (file log)
    
    => Nhiều client cùng dùng chung một kết nối cơ sở dữ liệu

    => Nhiều đối tượng cùng trỏ tới một cấu hình (config)

*  **Đặc điểm :**

    ◦ Nhiều `shared_ptr` có thể sở hữu cùng một đối tượng

    ◦ Sử dụng bộ đếm tham chiếu (reference count) để quản lý vòng đời đối tượng

    ◦ Đối tượng được giải phóng khi bộ đếm về 0

*  **Cú pháp :**
    
        #include <memory>
        std::shared_ptr<Type> ptr = std::make_shared<Type>(params);
    

*  **Các hàm thành viên thường dùng :**

   ◦ **use_count()** : Trả về số `shared_ptr` đang cùng quản lý đối tượng

   
        auto p1 = std::make_shared<int>(10);
        auto p2 = p1; // cùng quản lý
        std::cout << p1.use_count() << std::endl;  //In: 2
   

   ◦ **reset()** : Bỏ quản lý đối tượng hiện tại (giảm reference count đi 1, nếu về 0 thì hủy đối tượng)

   
        auto p = std::make_shared<int>(42);
        p.reset();  //bỏ quản lý -> đối tượng bị hủy
        std::cout << (p ? "con giu" : "da reset") << std::endl;

   

   ◦ **get()** : Trả về con trỏ thô (Type*) đang được quản lý

   
        auto p = std::make_shared<int>(100);
        int* raw = p.get();  //Lấy con trỏ thô
        std::cout << *raw << std::endl;

   

   ◦ **`operator *` và operator->** : Truy cập đối tượng giống như con trỏ thường 

   
        struct Test {
            void hello(){
                std::cout << "Hi\n";
            }
        };

        auto p = std::make_shared<Test>();
        (*p).hello();  //Dùng operator*
        p->hello();    //Dùng operator->


   

   ◦ **unique()** : Trả về `true` nếu chỉ có 1 `shared_ptr` quản lý đối tượng

   
        auto p1 = std::make_shared<int>(7);
        std::cout << p1.unique() << std::endl;  // true (chỉ p1 giữ)
        
        auto p2 = p1;
        std::cout << p1.unique() << std::endl;  // false

   

   ◦ `swap()` : Hoan đổi 2 `shared_ptr` với nhau

   
        auto p1 = std::make_shared<int>(1);
        auto p2 = std::make_shared<int>(2);

        p1.swap(p2);
        std::cout << *p1 " " << *p2 << std::endl; //In 2 1

   

*  **VD:**

    
        #include <iostream>
        #include <memory>

        class Motorbike {
        public:
            Motorbike(std::string model) : model(model) {
                std::cout << "Mua xe: " << model << std::endl;
            }
            ~Motorbike(){
                std::cout << "Ban xe: " << model << std::endl;
            }
            void use(const std::string& user){
                std::cout << user << " dang chay xe " << model << std::endl;
            }
        private:
            std::string model;
        };

        int main(){
            auto bike = std::make_shared<Motorbike>("Honda");
            // use_count = 1 (chỉ có bike)

            {
                auto user1 = bike; 
                auto user2 = bike;
                user1->use("Tung");
                user2->use("Binh");
                std::cout << "So nguoi dang dung: " << bike.use_count() << std::endl;
                //use_count = 3 (bike, user1, user2)
            }

            std::cout << "Con lai: " << bike.use_count() << std::endl;

    }
    

#### **12.1.4. std::weak_ptr**

*  **Tại sao dùng weak_ptr :**
   
    ◦ shared_ptr dùng reference count để quản lý đối tượng

    ◦ Nếu 2 đối tượng tham chiếu lẫn nhau bằng shared_ptr, reference count sẽ không bao giờ về 0 => gây ra memory leak

    => Dùng weak_ptr cho mối quan hệ không sở hữu

    => Dùng weak_ptr không làm tăng reference count, chỉ quan sát đối tượng
    
    => Khi đối tượng bị hủy ,`weak_ptr` sẽ tự động trở thành `expired()`

    => Dùng trong các quan hệ kiểu Cha-con, Cache hoặc observer

*  **Đặc điểm :**

    ◦ Không sở hữu đối tượng, không làm tăng bộ đếm tham chiếu

    ◦ Phải dùng `lock()` để truy cập đối tượng (tạo `shared_ptr` tạm thời).

    ◦ rở thành `expired()` khi đối tượng bị hủy.

*  **Cú pháp :**
    
    
        #include <memory>
        std::weak_ptr<Type> weak = shared_ptr;
    

*  **Các hàm thành viên thường dùng :**

   ◦ **expired()** : Kiểm tra xem đối tượng đã bị hủy chưa

   
        auto sp = std::make_shared<int>(10);
        std::weak_ptr<int> wp = sp;

        std::cout << (wp.expired() ? "het" : "con") << std::endl; // In: con
        sp.reset();
        std::cout << (wp.expired() ? "het" : "con") << std::endl; // In: het
   

   ◦ **lock()** : Lấy `shared_ptr` từ `weak_ptr` (nếu còn sống)

   
        auto sp = std::make_shared<int>(20);
        std::weak_ptr<int> wp = sp;

        if(auto p = wp.lock())    // lock tạo shared_ptr
            std::cout << *p << std::endl;   // In: 20


   

   ◦ **use_count()** : Số `shared_ptr` đang quản lý đối tượng

   
        auto sp = std::make_shared<int>(30);
        std::weak_ptr<int> wp = sp;
        
        std::cout << wp.use_count() << std::endl;  //In 1
   

   ◦ **reset()** : Bỏ quan sát đối tượng (không ảnh hưởng đến đối tượng)

   
        auto sp = std::make_shared<int>(40);
        std::weak_ptr<int> wp = sp;

        wp.reset();   // wp không quan sát nữa
        std::cout << (wp.expired() ? "het" : "con") << std::endl; // In: het

   

*  **VD:**

    
        #include <iostream>
        #include <memory>
        using namespace std;

        class Parent;  // khai báo trước

        class Child {
        public:
            weak_ptr<Parent> parent; 
            ~Child(){ cout << "Child destroyed\n"; }
        };

        class Parent {
        public:
            shared_ptr<Child> child;
            ~Parent(){ cout << "Parent destroyed\n"; }
        };

        int main(){
            auto p = make_shared<Parent>();
            p->child = make_shared<Child>();
            p->child->parent = p;  

            cout << "End main\n";
        }

    
</details> 







