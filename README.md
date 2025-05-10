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

<details>
	<summary><strong>BÀI 2: Advanced Function Concepts and Debug</strong></summary>

## **Bài 2: Advanced Function Concepts and Debug**

### **Variadic Functions: Hàm có số lượng tham số không cố định**

#### Cho phép định nghĩa hàm nhận số lượng tham số thay đổi.Để triển khai,ta sử dụng thư viện `<stdarg.h>`, cung cấp các macro và kiểu dữ liệu hỗ trợ xử lý danh sách tham số thay đổi 

 *  **va_list:** 
   
    ◦ Đây là một kiểu dữ liệu đặc biệt dùng để lưu trữ danh sách tham số biến thiên. 
   
    ◦ Hoạt động như một con trỏ hoặc cấu trúc nội bộ để theo dõi các tham số trong danh sách

 *  **va_start(ap, last_fixed_arg)**

    ◦ Macro này khởi tạo đối tượng `va_list(thường được gọi là ap)` để bắt đầu truy cập danh sách tham số biến thiên

    ◦ last_fixed_arg là tham số cố định cuối cùng được truyền vào hàm trước dấu ...(phần tham số biến thiên)

    ◦ Macro này thiết lập `ap` để trỏ đến tham số biến thiên đầu tiên

 * **va_arg(ap,type):**

    ◦ Lấy giá trị của tham số tiếp theo trong danh sách được lưu trong `va_list`

    ◦ `type` là kiểu dữ liệu của tham số được truy xuất

    ◦ Mỗi lần gọi `va_arg`, con trỏ nội bộ của `va_list` sẽ di chuyển đến tham số tiếp theo 


 * **va_end(ap):**

    ◦ Macro này dọn dẹp đối tượng `va_list` sau khi hoàn tất việc truy cập danh sách tham số 

    ◦ Nó đảm bảo giải phóng mọi tài nguyên được cấp phát bởi `va_start` và phải được gọi trước khi hàm kết thúc

   
#### Quy tắc và lưu ý khi sử dụng

 * **Tham số cố định:** Hàm này phải có ít nhất một tham số cố định trước dấu `...` .Tham số thường được dùng để xác định số lượng hoặc kiểu của các tham số biến thiên

 * **Kiểu dữ liệu:** Phải biết chính xác kiểu dữ của từng tham số biến thiên để gọi `va_arg` đúng cách.Nếu chỉ định sai kiểu,chương trình có thể trả về sai hoặc lỗi

 * **Không thể đếm trực tiếp số tham số:** Không có cách nào để tự động biết được số lượng tham số biến thiên, trừ khi sử dụng một tham số cố định để chỉ Định

 * **Cấu trúc chung:**
 ```
 #include<stdarg.h>

 return_type Function_name(fixed_arg,...){
   va_list ap;
   va_start(ap, fixed_arg);
   //Xử lý các tham số biến thiên bằng va_arg
   va_end(ap);
   return result;
 } 
 ```
 * **VD:**
 ```
 #include<stdio.h>
 #include<stdarg.h>

 int sum(int count, ...){
   va_list ap;           // Khai báo khởi tạo va_list
   va_start(ap, count);  // Khởi tạo va_list với tham số cố định cuối cùng là count

   int total =0;
   for(int i=0; i < count; i++){
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
 ```
 * **Khi không sử dụng Variadic Function:**

   **Cú pháp phức tạp khi gọi hàm:**

   Người dùng phải tạo một mảng (int numbers[] = {1, 2, 3}) trước khi gọi hàm, ngay cả khi chỉ cần truyền một vài số.

   Điều này làm tăng số lượng mã lệnh và giảm tính trực quan so với cách gọi đơn giản của variadic functions, như sum(3, 1, 2, 3).

   **Thiếu tính linh hoạt:**
   Nếu muốn truyền các số riêng lẻ (không phải từ một mảng có sẵn), người dùng phải tự xây dựng mảng trước. 
   Ví dụ, không thể gọi trực tiếp sum_array(1, 2, 3) mà phải làm như sau:
```
  int temp[] = {1, 2, 3};
  sum_array(temp, 3);
Với variadic functions, bạn chỉ cần gọi sum(3, 1, 2, 3) mà không cần tạo mảng trung gian.
```

  **Khó xử lý các tham số không đồng nhất:**

  Nếu bạn muốn mở rộng hàm để xử lý các kiểu dữ liệu khác nhau (ví dụ: tổng của int, double, hoặc thậm chí chuỗi), việc sử dụng mảng trở nên phức tạp hơn nhiều.    
  Bạn sẽ cần:

  Một mảng cho mỗi kiểu dữ liệu.

  Hoặc một cơ chế phức tạp để lưu trữ và phân tích các kiểu dữ liệu khác nhau.

  Với variadic functions, bạn có thể sử dụng chuỗi định dạng hoặc các tham số cố định để chỉ định kiểu, như trong `printf("%d %f %s", 42, 3.14, "hello")`

### **Assert - Kiểm tra lỗi với Assert**

#### Để kiểm tra các giả định và gỡ lỗi ta sử dụng Macro Assert được định nghĩa trong thư viện `<assert.h>`.Macro này giúp phát hiện lỗi lập trình tại thời điểm chạy bằng cách kiểm tra các biểu thức logic

* Các thành phần chính của **assert**

  ◦ **assert(expression):**

    Macro này kiểm tra giá trị của biểu thức `expression` tại thời điểm chạy

    Nếu `expression` trả về `0`(sai), chương trình sẽ in thông báo lỗi(bao gồm biểu thức sai, tên file,số dòng và có thể tên hàm) và gọi `abort()` để dừng chương trình

    Nếu `expression` trả về giá trị `khác 0`(đúng), chương trình tiếp tục chạy bình thường

   ◦ **Thông báo lỗi:**

    Khi `assert` thất bại, thông báo lỗi cung cấp thông tin chi tiết để định vị lỗi

    VD: 

  ```
  Assertion Failed: (ptr != null), function myFunction, file example.c, line 42
  ```

   ◦ **Vô hiệu hóa assert:**

    Khi định nghĩa macro `NDEBUG` trong chế độ biên dịch release, mọi `assert` sẽ bị vô hiệu hóa, và biểu thức trong `assert` sẽ không được thực thi

    Điều này đảm bảo `assert` không gây ảnh hưởng đến hiệu suất của chương trình

* **Mục đích và cách sử dụng:**

   ◦ **Kiểm tra điều kiện tiên quyết(preconditions):**

     Đảm bảo các điều kiện phải đúng trước khi thực thi hàm,ví dụ: con trỏ NULL,chỉ số mảng hợp lệ

     VD: `assert(ptr!=NULL);`

   ◦ **Kiểm tra điều kiện hậu quyết(postconditions):**

     Đảm bảo các điều kiện phải đúng sau khi thực thi,ví dụ: giá trị trả về nằm trong khoảng mong đợi

     VD: `assert(result >=0);`

   ◦ **Kiểm tra bất biến(invariants):**

     Đảm bảo các điều kiện luôn đúng tại một thời điểm cụ thể trong chương trình, ví dụ: biến đếm không âm

     VD: `assert(counter>=0);`

* **Quy tắc và lưu ý khi sử dụng:**

   ◦ **Không sử dụng cho logic chương trình:**

    Vì `assert` bị vô hiệu hóa trong chế độ release, không được đặt mã logic quan trọng trong `assert`

    VD: `assert(x = 5);`

   ◦ **Không dùng để xử lý lỗi runtime thông thường:**

    `assert` chỉ dùng để phát hiện lỗi lập trình trong giai đoạn phát triển, không phù hợp cho các lỗi runtime như input sai từ người dùng (dùng if-else hoặc try-catch cho các trường hợp này).
    
   ◦ **Cấu trúc chung:**

  ```
  #include<assert.h>

  return_type function_name(parameters){
    assert(condition); //Kiểm tra điều kiện
    //Xử lý logic
    return result;
  }
  ```

  VD:
  ```
  #include<stdio.h>
  #include<assert.h>

  void print_array(int* arr, int size){
    assert(arr != NULL); //Precondition: Con trỏ không được NULL
    assert(size > 0); //Precondition:kích thước phải dương

    for(int i=0; i<size; i++){
      printf("%d",&arr[i]);
    }
    printf("\n");
  }

  int main(){
    int numbers[]={1,2,3};
    print_array(numbers, 3);
    print_array(NULL, 0); //Lỗi Assert
    return 0;
  }
  ```

* **Khi không sử dụng Assert:**

    ◦ Cú pháp phức tạp khi kiểm tra lỗi:Phải tự viết các khối if-else để kiểm tra điều kiện và xử lý lỗi, làm tăng độ dài và phức tạp của mã.

    ```
    if (ptr == NULL) {
    fprintf(stderr, "Error: NULL pointer in file %s, line %d\n", __FILE__, __LINE__);
    exit(1);
    }
    ```
    ◦ Khó duy trì và gỡ lỗi

    ◦ Tăng nguy cơ lỗi không được phát hiện

     </details> 
