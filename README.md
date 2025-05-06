<details>
	<summary><strong>BÀI 1: Compiler Process (Quy trình biên dịch)</strong></summary>

## **Bài 1: Compiler Process(Quy trình biên dịch)**

### **Compiler GCC-Quy trình biên dịch**

#### Trình biên dịch GCC là công cụ phổ biến để biên dịch mã C/C++.Quá trình biên dịch một file .c thành file thực thi thì thường trải qua 4 giai đoạn chính

 *  **1.Preprocessing (Tiền xử lý):** 
   
    ◦ Xử lý các **chỉ thị tiền xử lý** (#include, #define, #ifdef,...). Có các chức năng như loại bỏ comment, thay thế macro, chèn nội dung file header. 
   
    ◦ Output thường là **file.i**

 *  **2.Compilation (Biên dịch):**

    ◦ Dịch mã C đã qua mã tiền xử lý thành mã **Assembly**

    ◦ Output thường là **file.s**

 * **3.Assembly (Assembler):**

   ◦ Dịch mã Assembly thành **mã máy** dưới dạng object code

   ◦ Output thường là **file.o** hoặc **file.obj**

 * **4.Linking (Liên kết):**

   ◦ Kết hợp object code từ các file nguồn khác nhau và các thư viện (static/dynamic library) để tạo thành file thực thi cuối cùng



### **The Preprocessor - Tiền xử lý trong C**

#### Bộ tiền xử lý là giai đoạn đầu tiên của quá trình biên dịch.Nó hoạt động dựa trên các chỉ thị(directives) bắt đầu bằng dấu #

* **#include<file>:** Chèn nội dung file header của hệ thống

  VD: `#include <iostream>`

* **#include"file":** Chèn nội dung file header do người dùng định nghĩa

  VD:  `#include "my_utility.h"`

* **#define NAME value:** Định nghĩa macro dạng hằng số.Mọi ký hiệu NAME sau đó sẽ được thay bằng value

  VD: `#define MAX_SIZE 100`

* **#define MACRO(params) body:** Định nghĩa macro dạng hàm

  VD: `#define SQUARE(x) ((x)*(x))`

* **#undef NAME:** Hủy định nghĩa 1 macro

  VD: `#undef MAX_SIZE`

* **#ifdef NAME, #ifndef NAME, #if expression, #else, #elif expression, #endif**
```
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
```

* Các macro dựng sẵn: __FILE__(tên file hiện tại), __LINE__(tên dòng hiện tại), __DATE__, __TIME__

```
#include <stdio.h>

int main() {
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    return 0;
}
```
```
File: example.c
Line: 5
Date: May 06 2025
Time: 14:30:00
```

### **C coding Standard & Misra C**

#### **Coding Standard**

  Là bộ quy tắc và hướng dẫn về cách viết mã nguồn

* **1.Quy tắc đặt tên**

  ◦ Sử dụng tên biến/hàm rõ ràng,mang tính mô tả, tránh viết tắt khó hiểu

  ◦ Quy ước camelCase hay snake_case phải được nhất quán trong dự án

  ◦ Các hằng số thường viết hoa với dấu gạch dưới `MAX_BUFFER_SIZE`

* **2.Thụt lề và định dạng**

  ◦ Sử dụng spaces hoặc tab nhất quán (thường là 2 hoặc 4 spaces)

  ◦ Đặt dấu `{` `}` theo kiểu Allman hoặc K&R ,nhưng phải thống nhất

  VD: Kiểu Allman
  ```
  if(condition)
  {
    //code
  }
  ```

  VD: Kiểu K&R 
  ```
  if(condition){
    //code
  }
  ```

  #### **Misra C**

  * Là bộ coding standard nghiêm ngặt dùng để phát triển chủ yếu cho ngành công nghiệp ô tô và hệ thống nhúng yêu cầu độ tin cậy cao 

  * Tránh các hành vi không xác định, không xác định cụ thể, và cấu trúc các ngôn ngữ C tiềm ẩn rủi ro
   
  * **Quy tắc 8.1(MISRA C:2012): Kiểu dữ liệu tường trình**

     ◦ Yêu cầu khai báo kiểu dữ liệu rõ ràng tránh sử dụng các kiểu mặc định như int không ký hiệu

     ◦ VD sai:

     ```
     int x = 10; //không rõ signed hay unsigned
     ```

     ◦ VD đúng:

     ```
     int32_t x = 10; //Rõ ràng là signed 32 bit
     ```

  * **Quy tắc 12.1(MISRA C:2012): Sử dụng dấu () để đảm bảo thứ tự ưu tiên**

     ◦ Tránh dựa vào thứ tự ưu tiên của toán tử

     ◦ VD sai:

     ```
     if (a + b * c > d)
     ```

     ◦ VD đúng:

     ```
     if ((a + (b*c)) > d)
     ```

  * **Quy tắc 17.7(MISRA C:2012): Kiểm tra giá trị trả về của hàm**

     ◦ Giá trị trả về của hàm không được bỏ qua trừ khi khi được ghi chú rõ ràng

     ◦ VD sai:

     ```
     printf("Hello"); //không kiểm tra giá trị trả về
     ```   

     ◦ VD đúng:

     ```
     int result = printf("Hello");

     if(result < 0) {
       //Xử lý lỗi
     }

  * **Quy tắc 21.1(MISRA C:2012): Cấm cấp phát bộ nhớ động**

     ◦ Các hàm như **malloc,free** bị cấm vì gây rò rỉ trong hệ thống nhúng

     ◦ Thay vào đó sử dụng bộ nhớ tĩnh hoặc stack

     ◦ Bộ nhớ tĩnh: tồn tại suốt vòng đời chương trình,chỉ khởi tạo 1 lần

     ```
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
     ```

     ◦ Bộ nhớ stack: tồn tại trong phạm vi hàm, khởi tạo mỗi lần hàm gọi

     ```
     void b_buffer(uint8_t input){
       uint8_t stack_buffer[128] = {0};
       if (input >= 128){
         printf("Input too large for static buffer");
         return;
       }
       stack_buffer[0] = input;
       printf("Stack_buffer[0]= %u\n",stack_buffer[0]);
     }
     
     ```

  * **Quy tắc 9.1(MISRA C:2012): Khởi tạo biến**

     ◦ Tất cả biến phải được khởi tạo trước khi sử dụng để tránh undefined behavior

     ◦ VD sai:

     ```
     int x;
     if (x == 0) //x chưa khởi tạo
     ```

     ◦ VD đúng:

     ```
     int x = 0;
     if (x == 0)
     ```
  * **Quy tắc 14.4(MISRA C:2012): Hạn chế sử dụng goto**

     ◦ goto chỉ được phép trong các trường hợp đặc biệt như xử lý lỗi thống nhất

     ```
     if(error_condition){
       goto cleanup;
     }
     cleanup;
     ```

  * **Quy tắc 5.3(MISRA C:2012): Biến/hàm nội bộ nên là static**

     ◦ Các biến hoặc hàm chỉ sử dụng trong 1 fie nên được khai báo static để tránh xung đột tên

     ```
     static int cter = 10;
     static void inter_function(void){
       counter++;
     }
     ```
  
  * **Quy tắc 16.3(MISRA C:2012): Mỗi file.c nên có file.h tương ứng**

     </details> 
