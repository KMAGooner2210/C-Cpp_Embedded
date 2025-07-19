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

### **2.1.Variadic Functions: Hàm có số lượng tham số không cố định**

#### **2.1.1.Định nghĩa**

*  Variadic Functions cho phép định nghĩa hàm nhận số lượng tham số thay đổi.

*  Triển khai thông qua thư viện <stdarg.h>, cung cấp các macro và kiểu dữ liệu để xử lý danh sách tham số biến thiên.

#### **2.1.2.Thành phần chính**
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

   
#### **2.1.3.Quy tắc và lưu ý**

* **Tham số cố định:** Hàm này phải có ít nhất một tham số cố định trước dấu `...` .Tham số thường được dùng để xác định số lượng hoặc kiểu của các tham số biến thiên

* **Kiểu dữ liệu:** Phải biết chính xác kiểu dữ của từng tham số biến thiên để gọi `va_arg` đúng cách.Nếu chỉ định sai kiểu,chương trình có thể trả về sai hoặc lỗi

* **Không thể đếm trực tiếp số tham số:** Không có cách nào để tự động biết được số lượng tham số biến thiên, trừ khi sử dụng một tham số cố định để chỉ định

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
#### **2.1.5.Khi không sử dụng Variadic Function**
*   **Cú pháp phức tạp khi gọi hàm:**

    ◦ Người dùng phải tạo một mảng (int numbers[] = {1, 2, 3}) trước khi gọi hàm, ngay cả khi chỉ cần truyền một vài số.

    ◦ Điều này làm tăng số lượng mã lệnh và giảm tính trực quan so với cách gọi đơn giản của variadic functions, như sum(3, 1, 2, 3).

*   **Thiếu tính linh hoạt:**
    ◦ Nếu muốn truyền các số riêng lẻ (không phải từ một mảng có sẵn), người dùng phải tự xây dựng mảng trước. 
    ◦ Ví dụ, không thể gọi trực tiếp sum_array(1, 2, 3) mà phải làm như sau:
```
  int temp[] = {1, 2, 3};
  sum_array(temp, 3);
  Với variadic functions, bạn chỉ cần gọi sum(3, 1, 2, 3) mà không cần tạo mảng trung gian.
```

*  **Khó xử lý các tham số không đồng nhất:**

    ◦ Nếu bạn muốn mở rộng hàm để xử lý các kiểu dữ liệu khác nhau (ví dụ: tổng của int, double, hoặc thậm chí chuỗi), việc sử dụng mảng trở nên phức tạp hơn nhiều.  

    Bạn sẽ cần:

    ◦ Một mảng cho mỗi kiểu dữ liệu.

    ◦ Hoặc một cơ chế phức tạp để lưu trữ và phân tích các kiểu dữ liệu khác nhau.

    ◦ Với variadic functions, bạn có thể sử dụng chuỗi định dạng hoặc các tham số cố định để chỉ định kiểu, như trong `printf("%d %f %s", 42, 3.14, "hello")`

### **2.2. Inline Functions (Hàm nội tuyến)**
#### **2.2.1.Định nghĩa**

*  Từ khóa inline gợi ý trình biên dịch thay thế lời gọi hàm bằng nội dung thân hàm tại điểm gọi, thay vì thực hiện lời gọi hàm thông thường.

*  Mục đích: Giảm chi phí gọi hàm (lưu trữ trạng thái, chuyển ngăn xếp), tăng hiệu suất, đặc biệt trong hệ thống nhúng yêu cầu thời gian thực.

#### **2.2.2.Đặc điểm**
*  **Không đảm bảo:** 
   
    ◦ Trình biên dịch có thể bỏ qua gợi ý inline nếu hàm quá lớn hoặc không phù hợp. 
   
*  **Ứng dụng:**

    ◦ Thường dùng cho hàm nhỏ, đơn giản, được gọi thường xuyên trong vòng lặp hoặc mã thời gian thực.

* **Nhược điểm:**

    ◦ Tăng kích thước mã trong file thực thi do nội dung hàm được sao chép tại mỗi điểm gọi.

* **Vị trí bộ nhớ:**

    ◦ Mã hàm inline thường nằm trong Text Segment.
   
#### **2.2.3.Cú pháp**

```
inline return_type function_name(parameters) {
    // Thân hàm
}
```
#### **2.2.4.VD**

```
#include <stdio.h>

inline uint16_t square(uint16_t x) {
    return x * x;
}

int main() {
    uint16_t result = square(5); // Trình biên dịch thay thế bằng 5 * 5
    printf("Square: %u\n", result); // In: Square: 25
    return 0;
}
```
#### **2.2.5.Lưu ý**

* **Kích thước hàm:** Chỉ nên sử dụng inline cho hàm nhỏ để tránh tăng kích thước mã.

* **Tính tương thích:** Một số trình biên dịch nhúng (như GCC) yêu cầu khai báo inline trong file header hoặc cùng file với lời gọi.

* **Hiệu suất:** Hữu ích trong hệ thống nhúng cho các hàm điều khiển phần cứng hoặc xử lý ngắt nhanh.

### **2.3.Assert - Kiểm tra lỗi với Assert**

#### **2.3.1.Định nghĩa**

* Để kiểm tra các giả định và gỡ lỗi ta sử dụng Macro Assert được định nghĩa trong thư viện `<assert.h>`.Macro này giúp phát hiện lỗi lập trình tại thời điểm chạy bằng cách kiểm tra các biểu thức logic

#### **2.3.2.Các thành phần chính của assert** 

* **assert(expression):**

    ◦ Macro này kiểm tra giá trị của biểu thức `expression` tại thời điểm chạy

    ◦ Nếu `expression` trả về `0`(sai), chương trình sẽ in thông báo lỗi(bao gồm biểu thức sai, tên file,số dòng và có thể tên hàm) và gọi `abort()` để dừng chương trình

    ◦ Nếu `expression` trả về giá trị `khác 0`(đúng), chương trình tiếp tục chạy bình thường

* **Thông báo lỗi:**

    ◦ Khi `assert` thất bại, thông báo lỗi cung cấp thông tin chi tiết để định vị lỗi

    VD: 

  ```
  Assertion Failed: (ptr != null), function myFunction, file example.c, line 42
  ```

* **Vô hiệu hóa assert:**

    ◦  Khi định nghĩa macro `NDEBUG` trong chế độ biên dịch release, mọi `assert` sẽ bị vô hiệu hóa, và biểu thức trong `assert` sẽ không được thực thi

    ◦  Điều này đảm bảo `assert` không gây ảnh hưởng đến hiệu suất của chương trình

#### **2.3.3.Mục đích và cách sử dụng** 

* **Kiểm tra điều kiện tiên quyết(preconditions):**

    ◦  Đảm bảo các điều kiện phải đúng trước khi thực thi hàm,ví dụ: con trỏ NULL,chỉ số mảng hợp lệ

    ◦  VD: `assert(ptr!=NULL);`

* **Kiểm tra điều kiện hậu quyết(postconditions):**

    ◦ Đảm bảo các điều kiện phải đúng sau khi thực thi,ví dụ: giá trị trả về nằm trong khoảng mong đợi

    ◦ VD: `assert(result >=0);`

* **Kiểm tra bất biến(invariants):**

    ◦ Đảm bảo các điều kiện luôn đúng tại một thời điểm cụ thể trong chương trình, ví dụ: biến đếm không âm

    ◦ VD: `assert(counter>=0);`

#### **2.3.4. Cú pháp**
```
#include <assert.h>

return_type function_name(parameters) {
    assert(condition); // Kiểm tra điều kiện
    // Xử lý logic
    return result;
}
```
#### **2.3.5. VD**
```
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
```
#### **2.3.6. Lưu ý**
* Không sử dụng cho logic chương trình:

    ◦ Vì assert bị vô hiệu hóa trong chế độ release, không đặt mã logic quan trọng trong assert (e.g., assert(x = 5);).

* Không dùng cho lỗi runtime thông thường:

    ◦ assert chỉ dùng để phát hiện lỗi lập trình trong giai đoạn phát triển, không phù hợp cho lỗi runtime như input sai (dùng if-else hoặc try-catch).

* Khi không sử dụng Assert:

    ◦ Phải tự viết if-else để kiểm tra lỗi, làm tăng độ dài và phức tạp mã:
```
if (ptr == NULL) {
    fprintf(stderr, "Error: NULL pointer in file %s, line %d\n", __FILE__, __LINE__);
    exit(1);
}
```

</details> 
<details>
	<summary><strong>BÀI 3: Advanced Pointers</strong></summary>

## **Bài 3: Advanced Pointers**

### **3.1.Function Pointers - Con trỏ hàm**

#### **3.1.1.Định nghĩa**

Là một loại con trỏ đặc biệt trong C, thay vì trỏ đến dữ liệu như (`int*` hay `char*`), nó **trỏ đến địa chỉ một hàm** trong bộ nhớ 

 *  **Mục đích:** 
   
    ◦  Lưu trữ địa chỉ của hàm để gọi hàm đó tại runtime
   
    ◦  Cho phép truyền hàm như một tham số(callback) hoặc lưu trữ trong cấu trúc dữ liệu

    ◦  Hỗ trợ lập trình linh hoạt, như chọn hàm để thực thi dựa trên điều kiện hoặc triển khai mẫu thiết kế

 *  **Đặc điểm:**

    ◦ Hàm trong C có địa chỉ cố định trong bộ nhớ, và con trỏ hàm lưu địa chỉ này

    ◦ Con trỏ hàm phải khớp với **kiểu trả về(return type)** và **danh sách tham số** của hàm mà nó trỏ tới



   
#### **3.1.2.Cú pháp khai báo**


 * `return_type (*pointer_name)(parameter_types);`
 
    ◦ **return_type:** Kiểu dữ liệu mà hàm trả về(VD: `int`,`void`, `double`)

    ◦ **pointer_name:** Tên của con trỏ hàm, được bao quanh bởi dấu `(*...)`

    ◦ **parameter_type:** Danh sách các kiểu tham số mà hàm có thể nhận
    ```
    int  (*opera)(int, int);
    void (*callback)(void);
    double (*compute)(float, int);
    ```
  **=> Dấu `*(pointer_name)` là cần thiết để phân biệt con trỏ hàm với hàm thông thường, nếu không có dấu `*`, khai báo sẽ trở thành function prototype thay vì con trỏ**

#### **3.1.3.Gán giá trị cho con trỏ hàm**

 * Để gán một hàm cho con trỏ hàm, có thể sử dụng tên hàm(hoặc địa chỉ hàm)

 ```
 pointer_name = function_name;
 // hoặc
 pointer_name = &function_name;
 ```

 VD:
 ```
 #include<stdio.h>

 int add(int a, int b){
   return a + b;
 }
 int main(){
   int (*opera)(int,int);
   opera = add;
   return 0;
 }
 ```

#### **3.1.4.Gọi hàm thông qua con trỏ**

 * Có 2 cách để gọi hàm thông qua con trỏ hàm 
 ```
 (*pointer_name)(arguments);
 //hoặc
 pointer_name(arguments);
 ```
 VD:
 ```
 #include<stdio.h>
 int add(int a, int b){
   return a+b;
 }
 int main(){
   int (*opera)(int,int);
   opera = add;
   printf("Result: %d\n",opera(5,3));
   printf("Result: %d\n",(*opera)(5,3));
   return 0;
 }
 }
 ```

 #### **3.1.5.Ứng dụng**

  * **Callbacks:**
   
    ◦ Truyền một hàm làm tham số cho hàm khác để gọi lại sau này

    ◦ VD: Hàm `qsort` trong thư viện chuẩn C

    ```
    #include<stdlib.h>

    int compare(const void* a, const void* b){
      return (*(int*)a) - (*(int*)b);
    }

    int main(){
      int arr[]={5,2,8,1};
      qsort(arr, 4, sizeof(int), compare);
    }
    ```

  * **State Machines:**

    ◦ Dùng con trỏ hàm để biểu diễn các trạng thái và hành vi trong máy trạng thái

    ◦ VD: Một chương trình chuyển đổi dựa trên trạng thái đầu vào

    ```
    void state1(){
      printf("In state1\n");
    }
    void state2(){
      printf("In state2\n");
    }
    void (*current_state)() = state1;
    ```

  * **Strategy Pattern:**

    ◦ Cho phép chọn thuật toán hoặc hành vi tại runtime

  * **Lưu trữ hàm trong cấu trúc dữ liệu:**

    ◦ Lưu con trỏ hàm trong mảng hoặc cấu trúc để gọi động

      VD: Mảng con trỏ hàm để xử lý các lệnh
      ```
      int (*opera[])(int,int)={add,subtract};
      int result = opera[0](5,3); //Gọi add
      ```
   #### **3.1.6.Lưu ý**

   * Kiểm tra khớp kiểu

   * Kiểm tra NULL


### **3.2.Void Pointers - Con trỏ void**

#### **3.2.1.Định nghĩa**

 * Con trỏ void`(void*)` là một loại con trỏ đặc biệt trong C,được gọi là con trỏ "generic" vì nó **có thể trỏ đến bất kỳ kiểu dữ liệu nào(int,char,float,struct,...)** mà không bị ràng buộc bởi kiểu cụ thể

 * **Mục đích:**

   ◦ Cho phép xử lý dữ liệu một cách tổng quát, mà không cần biết trước kiểu dữ liệu

   ◦ Được sử dụng trong các tình huống cần cấp phát bộ nhớ động hoặc truyền dữ liệu mà kiểu chưa được xác Định

 * **Đặc điểm:**

   ◦ **Không thể dereference trực tiếp:** Vì trình biên dịch không biết kích thước hoặc kiểu dữ liệu mà `void*` trỏ đến, nên `*void_ptr` sẽ gây lỗi biên dịch

   ◦ **Không hỗ trợ số học con trỏ:** Các phép toán như `void_ptr++` hoặc `void_ptr + n` không hợp lệ(hoặc không chuẩn) vì trình biên dịch không biết kích thước của kiểu dữ liệu

   ◦ **Ép kiểu:** Trước khi dereference hoặc thực hiện các thao tác, con trỏ void phải được ép kiểu sang một kiểu con trỏ cụ thể

  
#### **3.2.2.Cú pháp khai báo**

```
void *pointer_name;
```
* `void`: Chỉ định rằng con trỏ không gắn với kiểu dữ liệu cụ thể

* `pointer_name`: Tên của con trỏ void

VD:
```
void *generic_ptr;
void *memory_block;
```

#### **3.2.3.Gán giá trị cho con trỏ void**

* Cách gán:

```
pointer_name = &variable; //Gán địa chỉ của biến
pointer_name = another_pointer; //Gán từ con trỏ khác
```

VD:

```
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
```
#### **3.2.4.Sử dụng con trỏ void**

* Để sử dụng con trỏ void, cần **ép kiểu** sang kiểu con trỏ cụ thể trước khi **dereference** hoặc thực hiện thao tác

* **Cách sử dung:**
```
*(type_cast *)pointer_name; //dereference sau khi ép kiểu
```
VD:
```
#include<stdio.h>

int main(){
  int x = 42;
  void *ptr = &x;

  // Ép kiểu void* sang int* để dereference
  int *int_ptr = (int *)ptr;
  printf("Value of x: %d\n", *int_ptr);

  return 0;
}
```
#### **3.2.5.Ứng dụng**

**Hàm generic:**

  ◦ Các hàm như `memset`,`memcpy`,`qsort` trong thư viện C sử dụng `void*` để hoạt động trên bất kỳ kiểu dữ liệu nào

  VD:

  ```
  #include<stdlib.h>

  int compare(const void *a, const void *b){
    return (*(int*)a) - (*(int*)b);
  }

  int main(){
    int arr[]= {5, 2, 8, 1};
    qsort(arr, 4, sizeof(int), compare);
    return 0;
  }

  ```

**Cấp phát bộ nhớ động:**

  ◦ Các hàm như `malloc` và `calloc` trả về `void*` ,cho phép người dùng quyết định kiểu dữ liệu của bộ nhớ được cấp phát

  VD:

  ```
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
  ```
**Truyền tham số linh hoạt:**

  ◦ Dùng trong các hàm cần truyền dữ liệu mà kiểu không xác định trước 

  VD:
  ```
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
  ```

  **Lưu trữ trong cấu trúc dữ liệu:**

  ◦ Dùng để lưu trữ địa chỉ của các đối tượng có kiểu khác nhau trong danh sách liên kết, cây, hoặc các cấu trúc dữ liệu khác

  VD:
  ```
  #include<stdio.h>

  struct Node{
    void *data;
    char type;
  }

  int main(){
    struct Node node;
    int x = 42;

    node.data = &x;
    node.type = 'i';

    printf("Data: %d\n", *(int *)node.data);
    return 0;
  }
  ```

  #### **3.2.6.Lưu ý**
  
  **Kiểm tra ép kiểu:**

   ◦ Ép kiểu sai (ví dụ: ép void* trỏ đến int thành float*) có thể gây lỗi truy cập bộ nhớ hoặc kết quả không mong muốn.

   VD:
   ```
   int x = 42;
   void *ptr = &x;
   float *float_ptr = (float *)ptr; // Sai: Ép kiểu không đúng
   printf("%f\n", *float_ptr);     // Kết quả không xác định
   ```
  **Kiểm tra NULL:**

   ◦ Con trỏ void có thể là NULL, cần kiểm tra trước khi sử dụng.

   ```
   void *ptr = NULL;
   if (ptr != NULL) {
    int *int_ptr = (int *)ptr;
    printf("%d\n", *int_ptr);
    } else {
    printf("Pointer is NULL\n");
    }
   ```

  **Giải phóng bộ nhớ:**

   ◦ Khi dùng `void*` với `malloc` hoặc `calloc`, luôn nhớ giải phóng bộ nhớ bằng `free` để tránh rò rỉ bộ nhớ.

### **3.3.NULL Pointers - Con trỏ NULL**   

#### **3.3.1.Định nghĩa**

* Là một giá trị đặc biệt của con trỏ trong C/C++,biểu thị **con trỏ không trỏ đến bất kỳ địa chỉ bộ nhớ hợp lệ nào**.Nó thường được định nghĩa là `(void*)0` hoặc một macro tương đương(VD: `NULL` trong C hoặc `nullptr` trong C++)

* **Mục đích:**

  ◦ Khởi tạo con trỏ chưa được gán giá trị,tránh việc trỏ đến địa chỉ ngẫu nhiên

  ◦ Đánh dấu kết thúc của danh sách liên kết hoặc cấu trúc dữ liệu

  ◦ Biểu thị trạng thái lỗi hoặc không hợp lệ khi một hàm trả về con trỏ

  ◦ Dùng để kiểm tra tính hợp lệ của con trỏ trước khi truy cập

* **Đặc điểm:**

  ◦ Gía trị của NULL Pointer thường là `0` trong bộ nhớ,nhưng cách biểu diên thực tế phụ thuộc vào hệ thống

  ◦ Trong C++,`nullptr` là lựa chọn an toàn hơn `NULL`,vì nó có kiểu riêng (`std::nullptr_t`) và tránh các lỗi liên quan đến ép Kiểu

  ◦ dereference một NULL Pointer (vd: `*ptr` hoặc ptr->member`) sẽ gây lỗi **segmentation fault**

#### **3.3.2.Gán giá trị NULL**

  ◦ Gán trị NULL cho con trỏ để đảm bao nó không trỏ đến địa chỉ không xác định

  ```
  Trong C:
  int *ptr;
  ptr = NULL;
  ```
  ```
  Trong C++:
  int *ptr;
  ptr = nullptr;
  ```

#### **3.3.3.Kiểm tra và sử dụng NULL Pointer**

* Kiểm tra con trỏ trước khi **dereference**
  
  ◦ Luôn kiểm tra xem con trỏ có phải là NULL hay không để tránh lỗi truy cập bộ nhớ

  ```
  if(ptr != NULL){
    *ptr  10;
  }else{
    printf("Con trỏ là NULL,không thể truy cập\n");
  }
  ```
* Trong C++ với nullptr
  ```
  if(ptr != nullptr){
    *ptr = 10;
  }else{
    std::cout <<"Con trỏ là nullptr,khong the truy cap" << std::endl;
  }
  ```

* Trả về NULL từ hàm

  ◦ Hàm trả về con trỏ có thể trả về `NULL` để biểu thị lỗi hoặc không tìm thấy dữ liệu
  ```
  int *find_element(int arr[], int size, int value) {
    for(int i = 0; i < size; i++){
      if(arr[i] == value){
        return &arr[i];
      }
    }
    return NULL; //không tìm thấy
  }
  ```

#### **3.3.4.Ứng dụng**

* **Khởi tạo con trỏ:**

  ◦ Đảm bảo con trỏ không trỏ đến địa chỉ ngẫu nhiên trước khi được gán giá trị hợp lệ
  ```
  int *ptr = NULL;
  ptr = malloc(sizeof(int));
  ```

* **Kết thúc danh sách liên kết:**

  ◦ Trong danh sách liên kết, node cuối cùng có con trỏ `next` trỏ đến `NULL`
  ```
  struct Node{
    int data;
    struct Node *next;
  };
  struct Node *head = NULL; 
  ```

* **Kiểm tra lỗi:**

  ◦ Hàm cấp phát bộ nhớ như `malloc` hoặc `calloc` trả về `NULL` nếu không đủ bộ nhớ
  ```
  int *ptr = malloc(sizeof(int) * 10);
  if(ptr == NULL){
    printf("Cap phat bo nho that bai\n");
    exit(1);
  }
  ```

* **Callback và hàm trả về con trỏ:**

  ◦ Hàm trả về con trỏ có thể dùng `NULL` để báo trạng thái không hợp lệ
  ```
  void *process_data(){
    return NULL;
  }
  ```

#### **3.3.5.Lưu ý**

* **Kiểm tra NULL trước khi dereference**
  
  Luôn kiểm tra `if(ptr != NULL)` hoặc `if(ptr)`

* **Sự khác biệt giữa C và C++**
  
  Trong C,`NULL` là 1 macro, thường là `(void*)0`,có thể gây lỗi khi sử dụng ngữ cảnh ép kiểu

* **Tránh gán giá trị khác cho NULL**

* **Giải phóng bộ nhớ**

  Sau khi gọi `free(ptr)`,nên gán `ptr = NULL` để tránh sử dụng con trỏ đã được giải phóng

  ```
  free(ptr);
  ptr = NULL;
  ```

### **3.4.Pointer to Pointer - Con trỏ trỏ đến con trỏ**

#### **3.4.1.Định nghĩa**

* Là biến lưu trữ **địa chỉ của 1 biến con trỏ khác**

* Quản lý con trỏ cấp thấp hơn hoặc hỗ trợ cấu trúc dữ liệu phức tạp

* **Mục đích:**
  
  ◦ Hỗ trợ quản lý cấu trúc dữ liệu, mảng động, danh sách liên kết

  ◦ Cho phép con trỏ được truyền vào hàm

* **Đặc điểm:**

  ◦ Con trỏ cấp 2(`**`) có thể trỏ đến con trỏ cấp 1 (`*`),và con trỏ cấp 1 trỏ đến dữ liệu thực tiếp

  ◦ Hỗ trợ nhiều cấp con trỏ(vd:`***` cho con trỏ cấp 3),nhưng cấp 2 là phổ biến nhất

* **Cú pháp**

  ```
  type **pointer_name;
  ```
  ◦ `type:` Kiểu dữ liệu của biến cuối cùng mà con trỏ cấp 1 trỏ tới(vd: `int`,`char`,`float`)

  ◦ `pointer_name:` Tên con trỏ cấp 2

  VD:
  ```
  int **ptr
  ```

#### **3.4.2.Gán giá trị**

* Gán địa chỉ của một con trỏ cấp 1 cho con trỏ cấp 2

```
pointer_name = &pointer_level_1;
```
VD:
```
int x = 10;
int *ptr = &x;
int **ptr_to_ptr = &ptr;
```
#### **3.4.3.Truy cập giá trị**

* `ptr_to_ptr:` Địa chỉ của con trỏ cấp 1
* `*ptr_to_ptr:` Giá trị của con trỏ cấp 1,tức là địa chỉ của dữ liệu cuối cùng
* `**ptr_to_ptr:` Giá trị dữ liệu cuối cùng mà con trỏ cấp 1 trỏ tới

```
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

```
#### **3.4.4.Ứng dụng**

* **Pass-by-reference cho con trỏ**

  ◦ Cho phép hàm thay đổi con trỏ cấp 1 được truyền vào

  ```
  #include<stdio.h>

  void change_pointer(int **p, int *new_ptr){
    *pp = new_ptr;
  }

  int main(){
    int x = 10, y = 20;
    int *ptr = &x;
    int **ptr_to_ptr = &x;
    int **ptr_to_ptr = &ptr;

    printf("Before: %d\n", *ptr);
    change_pointer(ptr_to_ptr, &y);
    printf("After: %d\n",*ptr);
    return 0;
  }

* **Quản lý mảng các chuỗi:**

  ◦ Sử dụng `char **` để lưu trữ danh sách các chuỗi(mảng con trỏ kiểu `char *`)

  ```
  #include<stdio.h>
  int main(int argc, char ** argv){
    for(int i=0;i<argc;i++){
      printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
  }

  ```

* **Cấp phát và quản lý mảng 2 chiều động**

  ◦ Mảng 2 chiều động được biểu diễn như mảng các con trỏ,mỗi con trỏ trỏ đến một hàng

  VD: Cấp phát mảng 2 chiều 3x4
  ```
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
  ```

### **3.5.Const Pointer - Con trỏ hằng số và hằng con trỏ**   

#### **3.5.1.Định nghĩa**

* **Con trỏ hằng số và hằng con trỏ** là các con trỏ trong C/C++ sử dụng từ khóa `const` để hạn chế việc thay đổi giá trị mà con trỏ trỏ tới hoặc địa chỉ mà con trỏ lưu trữ

#### **3.5.2.Phân loại**

 *  **1.** `const int *ptr` hoặc `int const *ptr`: Con trỏ trỏ tới một giá trị hằng(`int` không thể thay đổi, nhưng địa chỉ mà `ptr` trỏ tới có thể thay đổi)

 *  **2.** `int * const ptr`: Hằng con trỏ trỏ tới một giá trị `int`(**địa chỉ** mà `ptr` trỏ tới **không thể thay đổi**, **giá trị** tại địa chỉ đó **có thể thay đổi**)

 *  **3.** `const int * const ptr` hoặc `int const * const ptr`:Hằng con trỏ trỏ tới một giá trị hằng(**cả giá trị và địa chỉ đều không thể thay đổi**)

#### **3.5.3.Đặc điểm**

   * **Đọc từ phải sang trái:** Cú pháp `const` được hiểu theo cách đọc từ phải sang trái để xác định `const` áp dụng cho giá trị hay con trỏ

   * **Tính bất biến:** 
    
    const int *ptr: Giá trị tại `*ptr` là bất biến
    
    int * const ptr: Địa chỉ mà `ptr` lưu trữ là bất biến
 
    const int * const ptr: Cả giá trị và địa chỉ đều bất biến
  
   * **Khởi tạo:** Hằng con trỏ phải được khởi tạo khi khai báo

#### **3.5.4.Cú pháp**


   * **Con trỏ trỏ tới giá trị hằng**
    
    const int * ptr;
    
   * **Hằng con trỏ trỏ tới giá trị**
    
    int * const ptr = &variable;
    
   * **Hằng con trỏ tới giá trị hằng**
    
    const int * const ptr = &variable;
    
#### **3.5.5.Gán giá trị và sử dụng**

  * VD1: const int *ptr
  ```
  #include<stdio.h>
  int main(){
    int x = 10, y = 20;
    const int *ptr = &x; //ptr trỏ tới x
    ptr = &y; //thay đổi địa chỉ
    printf("%d\n", *ptr);
    return 0;
  }
  ```
  * VD2: int * const ptr
  ```
  #include<stdio.h>
  int main(){
    int x = 10, y = 20;
    int * const ptr = &x;
    *ptr = 15;

    printf("%d\n", *ptr);
    return 0;
  }
  ```
  * VD3: const int * const ptr
  ```
  #include<stdlib.h>
  int main(){
    int x = 10;
    const int * const ptr = &x;

    printf("%d\n", *ptr);
    return 0;
  }
  ```

### **3.6.Size of Pointer - Kích thước của con trỏ**

#### **3.6.1.Định nghĩa**

* **Toán tử sizeof():**

  ◦ Toán tử `sizeof()` trả về kích thước (tính bằng byte) của 1 biến hoặc 1 kiểu dữ liệu

  ◦ Khi áp dụng với con trỏ, `sizeof(pointer_variable)` hoặc `sizeof(pointer_type)` trả về kích thước của chính biến con trỏ

  ◦ Khi áp dụng với toán tử giải tham chiếu `*`,`sizeof(*pointer_variable)` trả về kích thước của kiểu dữ liệu mà con trỏ trỏ tới

#### **3.6.2.Kích thước của con trỏ**

* Kích thước của con trỏ không phụ thuộc vào kiểu dữ liệu mà nó trỏ tới

  VD: `int*`, `char*`, `double*` hoặc `void*` đều có kích thước giống nhau trên cùng 1 hệ thống

* Kích thước của con trỏ phụ thuộc vào kiến trúc hệ thống

  ◦ **32-bit:** Con trỏ thường có kích thước **4 byte**

  ◦ **64-bit:** Con trỏ thường có kích thước 8 byte

* Con trỏ chỉ lưu trữ địa chỉ bộ nhớ,và kích thước của địa chỉ này phụ thuộc vào không gian địa chỉ mà hệ thống hỗ trợ

#### **3.6.3.Kích thước của kiểu dữ liệu mà con trỏ trỏ tới**

* Khi sử dụng `sizeof(*pointer_variable)`,kết quả trả về là kích thước của kiểu dữ liệu mà con trỏ trỏ tới

```
VD:
sizeof(int): thường là 4 byte
sizeof(char): thường là 1 byte
sizeof(double): thường là 8 byte
```

#### **3.6.4.Lưu ý**

* Kích thước của con trỏ có thể khác nhau giữa các hệ thống hoặc trình biên dịch

* Toán tử `sizeof()` là 1 toán tử thời gian biên dịch(compile-time) không phụ thuộc vào giá trị của biến tại thời điểm chạy

```
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
```

```
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
```

* Kiểm tra kích thước con trỏ trong Mảng
```
#include<stdio.h>
int main(){
  int arr[5]={1, 2, 3, 4, 5};
  int *ptr = arr;

  printf("Size cua con tro ptr: %zu bytes \n",sizeof(ptr));
  printf("Size cua kieu du lieu ma ptr tro toi: %zu bytes\n", sizeof(*ptr));
  printf("Size cua mang arr: %zu bytes\n",sizeof(arr));

  return 0;
}
```

```
Size cua con tro ptr: 8 bytes
Size cua kieu du lieu ma ptr tro toi: 4 bytes
Size cua mang arr: 20 bytes
```

* Con trỏ hàm

```
#include<stdio.h>

void myFunction(){
  printf("This is a function.\");
}

int main(){
  void (*func_ptr)() = myFunction;

    printf("Kich thuoc cua con tro ham: %zu bytes\n", sizeof(func_ptr));

    return 0;
}
```
```
Kich thuoc cua con tro ham: 8 bytes
```
   </details> 


<details>
	<summary><strong>BÀI 4: Special Variables</strong></summary>

## **Bài 4: Special Variables**

### **4.1.Tổng quan**

* Trong lập trình C, các biến và hàm được đặc trưng bởi bốn thuộc tính chính: **phạm vi (scope), thời gian sống (lifetime), vị trí bộ nhớ (memory location), và liên kết (linkage).** Những thuộc tính này quyết định cách truy cập, lưu trữ và liên kết các biến và hàm trong chương trình.

*  **Phạm vi(Scope):** Xác định nơi mà tên biến hoặc hàm có thể được truy cập.

*  **Thời gian tồn tại(Lifetime):** Khoảng thời gian biến tồn tại trong bộ nhớ

*  **Vị trí bộ nhớ(Memory Location):**

*  **Liên kết(Linkage):** Quy định khả năng tham chiếu đến tên biến hoặc hàm từ các đơn vị dịch (translation unit) khác.

### **4.2.Phạm vi (Scope)** 

*  Phạm vi xác định nơi mà tên của biến hoặc hàm có thể được truy cập trong chương trình.

#### **4.2.1.Phạm vi khối (Block Scope):**

* Biến được khai báo bên trong một khối lệnh (giới hạn bởi cặp dấu {}).

* Chỉ có thể truy cập trong khối lệnh chứa nó.

* Ví dụ: Biến cục bộ trong hàm hoặc trong một khối for, while.

#### **4.2.2.Phạm vi tệp (File Scope):**

* Biến hoặc hàm được khai báo bên ngoài tất cả các hàm trong một tệp.

* Thường được gọi là biến hoặc hàm toàn cục (global) trong tệp đó.

* Có thể truy cập ở bất kỳ đâu trong tệp, trừ khi bị hạn chế bởi từ khóa như static.

#### **4.2.3.Phạm vi prototype hàm (Function Prototype Scope):**

* Áp dụng cho các tham số trong khai báo hàm (prototype).

* Chỉ tồn tại trong phần khai báo hàm và không ảnh hưởng đến định nghĩa hàm.
```
int globalVar = 10; // File scope
void myFunction(int param) { // param có Function Prototype Scope
    int localVar = 5; // Block scope
    printf("%d\n", localVar);
}
```
### **4.3.Thời gian sống (Lifetime)** 

* Thời gian sống xác định khoảng thời gian một biến tồn tại trong bộ nhớ.

#### **4.3.1.Tự động (Automatic):**

* Biến cục bộ (local variable) được khai báo trong một khối lệnh.
* Tồn tại chỉ khi khối lệnh chứa nó đang thực thi.
* Bị hủy khi thoát khỏi khối lệnh.

#### **4.3.2.Tĩnh (Static):**

* Bao gồm biến toàn cục, biến static cục bộ, và biến extern
* Tồn tại suốt vòng đời của chương trình, từ khi bắt đầu đến khi kết thúc.
* Chỉ được khởi tạo một lần khi chương trình khởi động.
```
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
```
### **4.4. Vị trí bộ nhớ (Memory Location)** 

* Vị trí bộ nhớ xác định nơi mà biến hoặc mã lệnh được lưu trữ trong hệ thống

#### **4.4.1.Stack**

* Lưu trữ các biến cục bộ (automatic variables).
* Bộ nhớ được cấp phát và giải phóng tự động khi khối lệnh thực thi hoặc kết thúc.

#### **4.4.2.Data Segment**

* Lưu trữ các biến toàn cục hoặc biến static đã được khởi tạo với giá trị khác 0.
```
Ví dụ: int globalVar = 10;
```
#### **4.4.3.BSS Segment**

* Lưu trữ các biến toàn cục hoặc biến static chưa được khởi tạo hoặc được khởi tạo bằng 0.
```
Ví dụ: int globalVar;
```

#### **4.4.4.Heap**

* Lưu trữ bộ nhớ được cấp phát động thông qua các hàm như malloc, calloc, hoặc realloc.

#### **4.4.5.Text Segment (Code Segment)**

* Lưu trữ mã lệnh của chương trình (các hàm).

```
int globalVar = 10; // Data Segment
int uninitializedGlobalVar; // BSS Segment
void myFunction() {
    int localVar = 5; // Stack
    int* dynamicVar = malloc(sizeof(int)); // Heap
    // Text Segment chứa mã của myFunction
}
```
### **4.5. Liên kết (Linkage)** 

* Liên kết quyết định xem một tên (biến hoặc hàm) có thể được tham chiếu từ các tệp khác hay không.

#### **4.5.1.Liên kết ngoài (External Linkage)**

* Tên có thể được truy cập từ các tệp khác.

* Áp dụng cho biến toàn cục (không có static) và hàm (không có static).

* Ví dụ: Biến toàn cục hoặc prototype hàm không khai báo static.

#### **4.5.2.Liên kết nội (Internal Linkage)**

* Tên chỉ có thể được truy cập trong tệp hiện tại.

* Áp dụng cho biến toàn cục hoặc hàm được khai báo với từ khóa static.

#### **4.5.3.Không liên kết (No Linkage)**

* Tên chỉ có thể truy cập trong phạm vi khai báo (thường là biến cục bộ).

```
int globalVar = 10; // External Linkage
static int staticGlobalVar = 20; // Internal Linkage
void myFunction() {
    int localVar = 5; // No Linkage
}
```

### **4.6.Extern**

#### **4.6.1.Mục đích**

  * Extern là một **chỉ thị khai báo**

  * **Khi dùng với biến:**

     ◦ Nó thông báo cho trình biên dịch **Biến này được định nghĩa ở đâu đó, có thể ở trong file này hoặc file khác.Đừng cấp phát bộ nhớ cho nó tại đây, chỉ cần biết kiểu và tên của nó thôi.Linker sẽ tìm định nghĩa sau**

  * **Khi dùng với hàm:**

     ◦ **Nó khai báo một hàm mà định nghĩa của nó có thể ở file khác (hoặc ở phần sau của file hiện tại)**.Đối với hàm ,`extern` thường là ngầm định khi bạn khai báo prototype ở phạm vi toàn cục

#### **4.6.2.Ứng dụng**  

 * **Chia sẻ biến toàn cục**
 
    ◦ File 1 (vd: config.c):

    ```
    //Định nghĩa biến toàn cục
    int max_users = 100;
    const char * server_name = "KMA";
    ```

    ◦ File 2 (vd: main.c):
    ```
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


    ```
 * **Khai báo hàm từ file khác**

    ◦ File 1 (vd:math_utils.c):
    ```
    //Định nghĩa hàm
    int add(int a, int b){
      return a + b;
    }
    ```
    ◦ File 2 (vd:math_utils.h):

    ```
    #ifndef MATH_UTILS_H
    #define MATH_UTILS_H

    // Khai báo hàm (extern là ngầm định cho khai báo hàm ở phạm vi file)
    // Viết tường minh extern cũng không sai: extern int add(int, int);
    int add(int a, int b);

    #endif
    ```

    ◦ File 3 (vd:main.c):

    ```
    #include <stdio.h>
    #include "math_utils.h" // Bao gồm khai báo hàm

    int main() {
    int result = add(5, 3);
    printf("Sum: %d\n", result);
    return 0;
    }
    ```


### **4.7.Static**

#### **4.7.1.Biến static cục bộ**

* **Lifetime:** Tồn tại suốt vòng đời chương trình, được cấp phát trong **data segment (khởi tạo khác 0)** hoặc **bss segment (khởi tạo bằng 0 hoặc không khởi tạo)**

* **Scope:** Chỉ truy cập được bên trong Hàm

* **Khởi tạo:** 

  ◦  Chỉ khởi tạo **1 lần** khi hàm được gọi lần đầu, 

  ◦  Giữ giá trị giữa các lần gọi,Giá trị của nó không bị mất đi và được duy trì giữa các lần gọi hàm. 
    
  ◦  Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.



```
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
```


#### **4.7.2.Biến static toàn cục**

* **Lifetime:** Tồn tại **suốt vòng đời chương trình**,từ khi chương trình khởi động(trước khi hàm `main` chạy) đến khi chương trình kết thúc

* **Scope:** Chỉ được truy cập **bên trong file`.c` được định nghĩa,không thể truy cập từ file khác,kể cả khi sử dụng extern

* **Khởi tạo:** 

    Chỉ khởi tạo một lần duy nhất tại thời điểm chương trình khởi động (trước khi main được gọi).

    Giá trị của biến toàn cục static không bị mất và được duy trì trong suốt thời gian chương trình chạy.

    Mỗi lần giá trị biến được thay đổi (bởi bất kỳ hàm nào trong cùng file), giá trị mới sẽ được giữ và sử dụng cho các lần truy cập tiếp theo trong file.

```
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
```
### **4.8.Weak Symbols**  

#### **4.8.1.Định nghĩa**

* Từ khóa `__attribute__((weak))` (trong GCC) đánh dấu một hàm hoặc biến là`weak` symbol, cho phép định nghĩa khác thay thế nó trong quá trình liên kết (linking).

* Mục đích: Cung cấp một định nghĩa mặc định có thể được ghi đè bởi định nghĩa mạnh hơn (strong symbol) trong file khác.
#### **4.8.2.Đặc điểm**

* **Liên kết (Linkage):** Weak symbols có liên kết ngoài (external linkage), nhưng ưu tiên thấp hơn strong symbols.

* **Ứng dụng:**Thường dùng trong hệ thống nhúng để: 
  
  ◦ Cung cấp hàm mặc định cho xử lý ngắt (ISR) hoặc hàm khởi tạo phần cứng.

  ◦ Cho phép người dùng ghi đè hàm mặc định mà không sửa mã nguồn gốc.

* **Không bắt buộc:** Nếu không có định nghĩa mạnh hơn, weak symbol sẽ được sử dụng.

#### **4.8.3.Cú pháp**
```
__attribute__((weak)) return_type function_name(parameters) {
    // Thân hàm mặc định
}
```

#### **4.8.4.VD**
```
// File: default_isr.c
__attribute__((weak)) void TIM1_IRQHandler(void) {
    printf("Default TIM1 Interrupt Handler\n");
}

// File: user_isr.c
void TIM1_IRQHandler(void) {
    printf("User-defined TIM1 Interrupt Handler\n");
}

int main() {
    TIM1_IRQHandler(); // Gọi định nghĩa mạnh từ user_isr.c
    return 0;
}
```
* **Kết quả:** In ra `User-defined TIM1 Interrupt Handler` vì định nghĩa mạnh trong `user_isr.c` ghi đè định nghĩa yếu

#### **4.8.5.Lưu ý**

* **Hỗ trợ trình biên dịch:** __attribute__((weak)) là tính năng của GCC; các trình biên dịch khác có thể sử dụng cú pháp khác (như #pragma weak).

* **Ứng dụng nhúng:** Thường dùng trong các thư viện hoặc mã khởi động (bootloader) để cho phép tùy chỉnh xử lý ngắt hoặc hàm khởi tạo.

* **Kiểm tra NULL:** Nếu không có định nghĩa mạnh, cần đảm bảo weak symbol xử lý an toàn.

### **4.9.Volatile**  

#### **4.9.1.Định nghĩa**

* Từ khóa `volatile` ngăn trình biên dịch tối ưu hóa (như lưu trữ giá trị trong thanh ghi hoặc sắp xếp lại lệnh) các thao tác đọc/ghi biến, vì giá trị của biến có thể thay đổi bất ngờ từ các nguồn bên ngoài (phần cứng, ngắt, hoặc luồng khác).

#### **4.9.2.Hành vi**

* Buộc trình biên dịch đọc/ghi trực tiếp từ/tới bộ nhớ mỗi khi truy cập biến.

* Đảm bảo thứ tự thao tác không bị thay đổi do tối ưu hóa.

#### **4.9.3.Các trường hợp sử dụng**

* **Memory-mapped peripheral registers:** Truy cập các thanh ghi phần cứng(như GPIO,UART) để đảm bảo đọc/ghi chính xác giá trị hiện tại
```
#define GPIO_PORTA_DATA (*(volatile uint32_t *)0x40058000) // Địa chỉ thanh ghi GPIO

void toggle_pin(void) {
    GPIO_PORTA_DATA |= (1 << 5);  // Ghi giá trị để bật bit 5 (pin 5)
    GPIO_PORTA_DATA &= ~(1 << 5); // Ghi giá trị để tắt bit 5
}
```
* **Biến toàn cục trong ISR:** Đảm bảo biến toàn cục được truy cập bởi các routine xử lý ngắt luôn phản ánh giá trị mới nhất

```
volatile uint8_t flag = 0;
void ISR_Tim1(void){
  flag = 1;
}
int main(){
  while(1){
    if(flag){
      flag = 0;
    }
  }
  return 0;
}
```
* **Biến toàn cục trong xử lý đa nguồn:** Đảm bảo giá trị biến được cập nhật đúng khi được truy cập bởi nhiều tác vụ

```
#include <pthread.h>
#include <stdio.h>

volatile int shared_counter = 0; // Biến toàn cục chia sẻ

void* thread1_func(void* arg) {
    while (shared_counter < 10) {
        shared_counter++; // Tăng giá trị biến
        printf("Thread 1: counter = %d\n", shared_counter);
    }
    return NULL;
}

void* thread2_func(void* arg) {
    while (shared_counter < 10) {
        shared_counter++; // Tăng giá trị biến
        printf("Thread 2: counter = %d\n", shared_counter);
    }
    return NULL;
}

int main(void) {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
```

### **4.10.Register**

#### **4.10.1.Định nghĩa**

* Biến register được sử dụng để gợi ý cho trình biên dịch rằng 1 biến nên được lưu trữ trong **thanh ghi CPU thay vì RAM**

* Thường được sử dụng cho các biến được truy cập thường xuyên trong vòng lặp hoặc tính toán.
#### **4.10.2.Đặc điểm**

* **Tăng hiệu năng:** Giảm thời gian truy cập bằng cách lưu biến trong thanh ghi CPU.

* **Không đảm bảo:** Trình biên dịch có thể bỏ qua gợi ý register nếu không có thanh ghi khả dụng.

* **Không thể** lấy địa chỉ của biến register (vì nó không nằm trong RAM).

* **Không áp dụng** cho các biến lớn hoặc cấu trúc phức tạp.

```
void compute() {
    register int i; // Gợi ý lưu i trong thanh ghi
    for (i = 0; i < 1000000; i++) {
        // Tính toán
    }
}
```
### **4.11. Tổng kết**

* **Phạm vi (Scope):** Quy định nơi biến/hàm có thể được truy cập (block, file, prototype)

* **Thời gian sống (Lifetime):** Quy định thời gian tồn tại của biến (automatic, static).

* **Vị trí bộ nhớ (Memory Location):** Quy định nơi lưu trữ biến (stack, heap, data, BSS, text).

* **Liên kết (Linkage):** Quy định khả năng tham chiếu biến/hàm giữa các tệp (external, internal, no linkage).

* Từ khóa đặc biệt:
```
    extern: Khai báo biến/ham có định nghĩa ở nơi khác, ngụ ý liên kết ngoài.
    static: Hạn chế phạm vi (liên kết nội) và kéo dài thời gian sống.
    volatile: Ngăn tối ưu hóa để đảm bảo đọc/ghi chính xác giá trị biến.
    register: Gợi ý lưu biến trong thanh ghi để tăng hiệu năng.
    __attribute__((weak)): Đánh dấu biểu tượng yếu, cho phép ghi đè bởi định nghĩa mạnh hơn.
```
 </details>


<details>
	<summary><strong>BÀI 5: Control Flow</strong></summary>

## **Bài 5: Control Flow**

### **5.1.Goto**

#### **5.1.1.Định nghĩa**

* Câu lệnh `goto` cho phép chương trình **nhảy trực tiếp và vô điều kiện** đến một nhãn được định nghĩa trong cùng một hàm

* Nhãn là một điểm được đánh dấu trong mã nguồn,thường được **đặt tên bằng một định danh (identifier) và kết thúc bằng dấu :**


#### **5.1.2.Mục đích**

*  Dùng để thay đổi luồng điều khiển chương trình một cách thủ công, bỏ qua các cấu trúc điều khiển thông thường như vòng lặp,câu lệnh điều kiện hoặc hàm

*  Được sử dụng để thoát khỏi nested loops
    ```
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            if(some_condition){
                goto exit_loops; //Thoát khỏi cả 2 vòng lặp
            }
        }
    }
    exit_loops:
    ```

#### **5.1.3.Cú pháp**

    
    goto label_name; //Nhảy đến nhãn có tên label_name

    //... (các dòng mã khác)

    label_name: //Định nghĩa nhãn
    // khối mã được thực thi sau khi nhảy đến đây
    
    

```
    #include<stdio.h>
    #include<stdlib.h>

    int main(){

        int * arr = malloc(sizeof(int) * 100);
        if(arr = NULL){
            goto error;
        }

        for(int i =0; i < 5; i++){
            arr[i] = i;
            printf("%d", arr[i]);
        }

        free(arr);
        goto done;
    
    error:
        printf("Loi: Khong the cap phat bo nho!\n");
    
    done:
        printf("End.\n");

        return 0;
    }

```



### **5.2.setjmp và longjmp**

#### **5.2.1.Định nghĩa**

* `setjmp` và `longjmp` là 1 cặp hàm trong C cung cấp cơ chế **nhảy không cục bộ**, cho phép chuyển luồng điều khiển từ một hàm sâu trong ngăn xếp gọi trở về một điểm đã đánh dấu ở một hàm gọi bên ngoài, **bỏ qua các lệnh return thông thường**

* `goto` chỉ nhảy trong phạm vi cùng một hàm

* `setjmp/longjmp` có thể nhảy qua nhiều cấp hàm trong ngăn xếp gọi,kể cả từ hàm con về hàm cha

#### **5.2.2.Mục đích**

* Triển khai cơ chế xử lý ngoại lệ đơn giản trong C

* Thoát khỏi các ngữ cảnh xử lý phức tạp khi xảy ra lỗi hoặc điều kiện đặc biệt

#### **5.2.3.Thư viện**

* Sử dụng thư viện `<setjmp.h>`

* **Hàm int setjmp(jmp_buf env)**

    ◦ **Chức năng:** Lưu trạng thái môi trường hiện tại(bao gồm con trỏ ngăn xếp, thanh ghi, và các thông tin liên quan đến luồng điều khiển) vào biến `jmp_buf_env`

    ◦ **Giá trị trả về:** 

        Trả về 0 khi được gọi trực tiếp (lần đầu tiên)

        Trả về giá trị val(hoặc 1 nếu val == 0)khi được khôi phục bởi longjmp

    ◦ **Lưu ý:**

        jmp_buf là một kiểu dữ liệu đặc biệt (thường là mảng hoặc cấu trúc được định nghĩa trong <setjmp.h>,dùng để lưu trạng thái)

* **Hàm void longjmp(jmp_buf env,int val)**

    ◦ **Chức năng:** Khôi phục trạng thái môi trường đã được lưu trong `env` bởi `setjmp`.Sau khi gọi, luồng thực thi sẽ tiếp tục ngay sau lệnh `setjmp` tương ứng, như thể `setjmp` vừa trả về giá trị `val`

    ◦ **Tham số:** 

        env: Môi trường đã lưu bởi setjmp
        
        val: Giá trị trả về cho `setjmp`. Nếu val == 0, setjmp sẽ trả về 1

    
    ◦ **Lưu ý:**

        Hàm gọi long_jmp không bảo giờ trả về

        longjmp khôi phục trạng thái ngăn xếp và thanh ghi, nhưng không đảm bảo trạng thái của các biến cục bộ hoặc tài nguyên

* **VD:**
```
#include<setjmp.h>
#include<stdio.h>

jmp_buf env;

void check_even(int number){
    if(number % 2 != 0){
        printf("Loi: %d la so le!\n", number);
        longjmp(env, 1); //Nhay ve setjmp voi ma loi 1
    }
    printf("%d la so chan\n", number);
}

int main(){
    if(setjmp(env) == 0){
        printf("Kiem tra so...\n");
        check_even(7);
    }else{
        printf("Da phat hien loi,chuong trinh tiep tuc.\n");
    }
    return 0;
}
```

```
Kiem tra so...
Loi: 7 la so le!
Da phat hien loi,chuong trinh tiep tuc
```
 </details>
<details> 
 <summary><strong>BÀI 6: Bit Manipulation</strong></summary>

## **Bài 6: Bit Manipulation**

### **6.1.Số nhị phân và bit**

#### **6.1.1.Định nghĩa**

* Máy tính lưu trữ và xử lý dữ liệu dưới dạng nhị phân (binary), sử dụng các bit (0 và 1)

* Một byte gồm 8 bit.Các giá trị lớn hơn(như 16,32,64 bit) được dùng cho các kiểu dữ liệu như `short`,`int`,`long`,...

* VD:
  ```
  Số thập phân 5: 00000101
  Số thập phân 13: 00001101
  ```
#### **6.1.2.Số có dấu và không dấu**

* Với **số không dấu (unsigned)**, các bit chỉ biểu diễn **giá trị dương**

* Với **số có dấu(signed)**

  ◦ bit cao nhất (MSB) biểu thị dấu **0 cho dương , 1 cho âm**
  
  ◦ Giá trị thường được biểu diễn dưới dạng bù 2

  VD: 
  ```
  -5 = 11111011
  ```

### **6.2.Bitwise Operators (Toán tử thao tác bit)**

*  Các toán tử này hoạt động trực tiếp trên biểu diễn bit của toán hạng, thường là kiểu số nguyên (`int`,`unsigned int`,...)

#### **6.2.1. & (Bitwise AND)**

* Kết quả bit là 1 nếu cả 2 bit tương ứng là 1

* Ứng dụng : Xóa bit, kiểm tra bit

* VD: 101 & 110 = 100

#### **6.2.2. | (Bitwise OR)**

* Kết quả bit là 1 nếu ít nhất 1 trong 2 bit tương ứng là 1

* Ứng dụng: Đặt bit

* VD: 101 | 110 = 111

#### **6.2.3. ^ (Bitwise XOR)**

* Kết quả bit là 1 nếu 2 bit tương ứng khác nhau

* Ứng dụng: Đảo bit, kiểm tra khác biệt

* VD: 101 ^ 110 = 011

#### **6.2.4. ~ (Bitwise NOT)**

* Đảo tất cả các bit: 0 thành 1, 1 thành 0

* Kết quả phụ thuộc vào kích thước kiểu dữ liệu (8,16,32 bit,...)

* `~101` = `~00000101 = 11111010`

#### **6.2.5. << (Left Shift)**

* Dịch chuyển các bit sang trái n vị trí, các bit mới bên phải được điền bằng 0

* Tương đương nhân với `2^n` (cho số không dấu)

* VD: `101 << 1 = 1010  (Thập phân: 5 << 1 = 10)`

* Lưu ý: Nếu dịch quá nhiều, bit có thể bị mất, gây tràn

#### **6.2.6. >> (Right Shift)**

* Dịch chuyển các bit sang phải n vị trí, các bit mới bên trái được điền bằng 0 (thường cho số không dấu)

* Tương đương chia với `2^n` (cho số không dấu)

 VD: `1011 >> 1 = 0101 (Thập phân: 11 >> 1 = 5)`

* **Arithmetic Shift:** Bit mới bên trái điền bằng bit dấu (MSB) ban đầu (thường cho số có dấu)

 VD: `-5 (11111011) >> 1 = 11111101`

### **6.3.Bitmasks (Mặt nạ bit)**

#### **6.3.1.Định nghĩa**

* Bitmask là một giá trị (thường là hằng số) được thiết kế để thao tác (set,clear,toggle,test) các bit cụ thể trong một biến bằng các toán tử Bitwise

* Mỗi bit trong mask địa diện cho một cờ (flag) hoặc tùy chọn

#### **6.3.2.Kỹ thuật phổ biến**

* **Tạo mask cho bit thứ n** 

◦  Công thức: `1 << n`

◦  VD: Mask cho bit 3: `1 << 3 = 00001000`

* **Set bit thứ n(đặt bit thành 1)**

◦  Công thức: `value |= (1 << n);`

◦ VD: Set bit 3 của `value = 5 (nhị phân: 00000101)`

  ```
  value |= ( 1 << 3); -> 00000101 | 00001000 = 00001101 (thập phân: 13)
  ```

* **Clear bit thứ n(xóa bit, đặt thành 0)**

◦ Công thức: `value &= ~(1 << n);`

◦ VD: Clear bit thứ 3 của `value = 13 (nhị phân: 00001101)`
  ```
  value &= ~(1 << 3); -> 00001101 & 11110111 = 00000101
  ```

* **Toggle bit thứ n(đảo bit: 0 thành 1, 1 thành 0)**

◦ Công thức: `value ^= (1 << n);`

◦ VD: Toggle bit thứ 3 của `value = 5 (nhị phân: 00000101)`
  ```
  value ^= (1 << 3); -> 00000101 ^ 00001000 = 00001101
  ```

* **Test bit thứ n (kiểm tra bit có được set không)**

◦ Công thức: `if (value & (1 << n)) {...}`

◦ Kết quả khác 0 nếu bit được set (là 1)

◦ VD: Kiểm tra bit 2 của `value = 5 (nhị phân: 00000101)`
  ```
  5 & (1 << 2) -> 00000101 & 00000100 = 00000100 (khác 0, bit 2 được set)
  ```

* **Set nhiều bit**

◦ Công thức: `value |= (MASK1 | MASK2);`

◦ VD: Set bit 2 và bit 3: `value |= (1 << 2 | 1 << 3);`
```
00000000 | (00000100 | 00001000) = 00001100 (thập phân: 12)
```

* **Clear nhiều bit**

◦ Công thức: `value &= ~(MASK1 | MASK2);`

◦ VD: Clear bit 2 và 3 của `value = 15 (nhị phân: 00001111)`
```
value &= ~(1 << 2 | 1 << 3); -> 00001111 & 11110011 = 00000011 (thập phân: 3)
```
* **Kiểm tra nhiều bit cùng được set**

◦ Công thức: `if ((value & (MASK1 | MASK2)) == (MASK1 | MASK2)) {...}`

◦ VD: Kiểm tra bit 2 và 3 của `value = 12 (nhị phân: 00001100)`
```
(12 & (1 << 2 | 1 << 3)) == (1 << 2 | 1 << 3) -> (00001100 & 00001100) == 00001100 -> true
```

### **6.4.Bit Fields (Trường bit trong cấu trúc)**

#### **6.4.1.Lý thuyết**

* Bit Fields cho phép định nghĩa các thành viên của một `struct` với số lượng bit cụ thể, giúp tiết kiệm bộ nhớ hoặc ánh xạ chính xác tới cấu trúc dữ liệu của phần cứng (như thanh ghi điều khiển)

```
struct Register {
  unsigned int flag1 : 1;  //flag1 dùng 1 bit
  unsigned int config : 4; //config dùng 4 bit
  unsigned int status : 3; //status dùng 3 bit
};
```
Cách sử dụng:

```
Khởi tạo :  struct Register reg = {1, 5, 2}; (gán flag1 = 1, config = 5, status = 2).
Truy cập :  reg.flag1 = 0; hoặc if (reg.status == 2) { ... }.
```

Lưu ý:

* Thứ tự bit và padding: 
   
   ◦ Thứ tự các bit field trong bộ nhớ (endianness) và cách đóng gói (padding) phụ thuộc vào trình biên dịch và kiến trúc máy, gây vấn đề về tính tương thích (portability).

   ◦ Một số trình biên dịch có thể chèn padding để căn chỉnh byte.

* Hạn chế:

   ◦ Không thể lấy địa chỉ của bit field (ví dụ: &reg.flag1 là lỗi).

   ◦ Kiểu dữ liệu cơ sở thường là `unsigned int` hoặc `int` để tránh vấn đề với số có dấu.

* Ứng dụng:

   ◦ Lập trình nhúng: Điều khiển thanh ghi phần cứng.

   ◦ Nén dữ liệu: Lưu trữ nhiều giá trị nhỏ trong không gian bộ nhớ hạn chế.
</details>
<details> 
 <summary><strong>BÀI 7: Kiểu dữ liệu tùy chỉnh</strong></summary>

## **Bài 7: Kiểu dữ liệu tùy chỉnh**

### **7.1.Structs**

#### **7.1.1.Định nghĩa**

* Struct là kiểu dữ liệu tùy chỉnh, nhóm các biến có kiểu dữ liệu khác nhau thành một đơn vị logic

* Các thành viên được lưu trữ liên tiếp trong bộ nhớ, nhưng có thể có **padding** để đảm bảo căn chỉnh bộ nhớ theo kiến trúc CPU

#### **7.1.2.Đặc điểm**

* Mỗi thành viên có thể truy cập riêng lẻ qua tên

* Kích thước của struct (`sizeof(struct)`) là tổng kích thước của tất cả thành viên, cộng thêm **padding** 

* Padding đảm bảo các thành viên nằm ở địa chỉ chia cho hết kích thước căn chỉnh

* Có thể dùng `__attribute__(packed))` để loại bỏ padding

#### **7.1.3.Cú pháp**

```
struct TenStruct {
    int bien1;      //4 bytes
    double bien2;   //8 bytes
    char ten[10];   //10 bytes 
}

```
#### **7.1.4.Khai báo và truy cập**

* Khai báo biến
```
struct TenStruct bienStruct;
struct TenStruct *conTro = &bienStruct;

```

* Truy cập thành viên

   ◦ Dùng `.` cho biến struct : `bienStruct.bien1 = 10`

   ◦ Dung `->` cho con trỏ struct: `conTro->bien1 = 20` 

#### **7.1.5.Struct lồng nhau**

* Cho phép tổ chức dữ liệu theo cấu trúc phân cấp

* Truy cập thành viên lồng nhau bằng cách dùng nhiều toán tử `.` hoặc `->`

* Padding vẫn áp dụng cho cả struct bên trong và bên ngoài

```
struct SinhVien {
    int maSV;
    char ten[50];
    float diemTB;
};

struct LopHoc {
    char tenLop[20];
    int siSo;
    struct SinhVien sv[100];
};

```

* Truy cập
```
struct LopHoc lop;
lop.sv[0].maSV = 1001;
strcpy(lop.sv[0].ten. "Mai Thanh Tung");
lop.sv[0].diemTB = 8.5;
```




### **7.2.Unions**

#### **7.2.1.Định nghĩa**

* Cho phép lưu trữ nhiều kiểu dữ liệu khác nhau tại **cùng một vị trí bộ nhớ**. 

* Chỉ một thành viên chứa giá trị hợp lệ tại một thời điểm

#### **7.2.2.Đặc điểm**

* Kích thước của union bằng kích thước của thành viên lớn nhất

* Phải tự quản lý thành viên hợp lệ, thường dùng biến/enum bổ sung

* Type punning: Ghi dữ liệu bằng một kiểu và đọc bằng kiểu khác(ví dụ: xem bit của float qua int)

#### **7.2.3.Cú pháp**
```
union DuLieu{
    int soNguyen;       //4 bytes
    float soThuc;       //4 bytes
    char chuoi[20];     //20 bytes
};
```

#### **7.2.4.Khai báo biến và truy cập**

* **Khai báo biến:** `union DuLieu bienUnion;`

* **Truy cập:** `bienUnion.soNguyen = 100;`

#### **7.2.5.Union trong Struct**

* Union được sử dụng như một thành viên của struct để lưu trữ nhiều kiểu dữ liệu khác nhau tại cùng một vị trí bộ nhớ trong struct

* Padding của struct vẫn áp dụng, nhưng union chỉ chiếm kích thước của thành viên lớn nhất

* Cú pháp
```
struct SinhVien {
    int maSV;
    char ten[50];
    enum{ DIEM_SO, DIEM_CHU } kieuDiem;
    union {
        float diemSo;
        char diemChu[3];
    } diem;
};

```

* Truy cập

  ◦ Ghi và đọc dựa trên giá trị của biến `kieuDiem:`
  ```
  struct SinhVien SV;
  sv.kieuDiem = DIEM_SO;
  sv.diem.diemSo = 8.5;
  ```


### **7.3.Typedef (Tạo kiểu dữ liệu mới)**

* **Định nghĩa:** Typedef tạo bí danh(alias) cho kiểu dữ liệu hiện có, giúp mã dễ đọc và tăng tính tương thích

* **Đặc điểm:** 

   ◦ Không tạo kiểu mới, chỉ đặt tên khác

   ◦ Ứng dụng: Rút gọn tên kiểu phức tạp (struct,union,con trỏ hàm), tăng tính rõ ràng

* **Cú pháp:**

```
typedef existing_type new_type_name;

```

* **Ứng dung:**

   ◦ Rút gọn struct: `typedef struct { int x; int y; } Diem;`

   ◦ Rút gọn con trỏ hàm: `typedef int (*HamTinhToan) (int,int);`

   ◦ portability: `typedef unsigned char BYTE;`

### **7.4.Kích thước của Struct và Union**

#### **7.4.1.Kích thước của Struct**

* Kích thước của struct là tổng kích thước của tất cả thành viên, cộng thêm **byte đệm (padding)** để đảm bảo **căn chỉnh bộ nhớ (alignment)** 

* **Alignment:**

   ◦ Mỗi kiểu dữ liệu có yêu cầu căn chỉnh riêng, thường là bộ số của kích thước kiểu (ví dụ: `int` 4 bytes căn chỉnh tại địa chỉ chia hết cho 4, `double` 8 bytes căn chỉnh tại địa chỉ chia hết cho 8)

   ◦ Struct được căn chỉnh theo **yêu cầu căn chỉnh lớn nhất** của bất kỳ thành viên ngoài

* **Padding:**

   ◦ Trình biên dịch thêm byte đệm giữa các thành viên hoặc cuối struct để đảm bảo mỗi thành viên nằm ở địa chỉ phù hợp

   ◦ Kích thước struct phải là bội số của yêu cầu căn chỉnh lớn nhất để hỗ trợ mảng struct

* **Công thức tính:**

   ◦ 1. Xác định kích thước và yêu cầu căn chỉnh của từng thành viên

   ◦ 2. Thêm padding giữa các thành viên để căn chỉnh địa Chỉ

   ◦ 3. Thêm padding cuối struct để kích thước tổng là bội số của yêu cầu căn chỉnh lớn nhất

* **Yếu tố ảnh hưởng**

   ◦ Kiến trúc CPU (32 bit vs 64 bit)

   ◦ Trình biên dịch

   ◦ Thứ tự khai báo thành viên

* **VD1:**

```
struct Example {
    char c;    // 1 byte
    int i;     // 4 bytes
    double d;  // 8 bytes
};

```
Tính toán kích thước (hệ 64 bit)
```
 char c: 1 byte, căn chỉnh 1 byte -> offset 0
 int i: 4 bytes, căn chỉnh 4 bytes -> cần offset chia hết cho 4,nên thêm 3 bytes padding sau c -> offset: 4 (1 + 3)
 double d: 8 bytes, căn chỉnh 8 bytes -> cần offset chia hết cho 8,nên thêm 4 bytes padding sau i -> offset: 12 (4 + 4 + 4)

 => Tổng: 12 + 8 = 20 bytes

 => Struct cần căn chỉnh 8 bytes (lớn nhất trong các thành viên), nên thêm 4 byte padding cuối -> KÍCH THƯỚC: 24 BYTES
```

Loại bỏ padding
```
struct Example {
    char c;
    int i;
    double d;
} __attribute__((packed));

=> KÍCH THƯỚC: 1 + 4 + 8 = 13 bytes
```

* **VD2:**

```
struct Example2 {
    double d;  // 8 bytes
    int i;     // 4 bytes
    char c;    // 1 byte
};

```
Tính toán kích thước (hệ 64 bit)
```
double d: 8 bytes, căn chỉnh 8 bytes → offset 0.
int i: 4 bytes, căn chỉnh 4 bytes → offset 8 (không cần padding).
char c: 1 byte, căn chỉnh 1 byte → offset 12 (8 + 4).

=> Tổng: 12 + 1 = 13 bytes.

=> Căn chỉnh struct: 8 bytes → thêm 3 byte padding cuối → Kích thước: 16 bytes.

=> Thứ tự khai báo ảnh hưởng padding, nên đặt thành viên lớn trước có thể giảm kích thước.

```

#### **7.4.2.Kích thước của Union**

* Kích thước của union (sizeof(union)) bằng kích thước của **thành viên lớn nhất**, cộng thêm padding (nếu cần) để đảm bảo căn chỉnh bộ nhớ.

* **Alignment:**

   ◦ Union được căn chỉnh theo yêu cầu căn chỉnh lớn nhất của bất kỳ thành viên nào.

   ◦ Tất cả thành viên chia sẻ cùng vị trí bộ nhớ, nên không có padding giữa các thành viên.


* **Công thức tính:**

   ◦ 1. Xác định kích thước lớn nhất của các thành viên.

   ◦ 2. Đảm bảo kích thước union là bội số của yêu cầu căn chỉnh lớn nhất.

* **Yếu tố ảnh hưởng**

   ◦ Kiến trúc CPU (32 bit vs 64 bit)

   ◦ Trình biên dịch

   ◦ Kích thước và yêu cầu căn chỉnh của thành viên lớn nhất.

* **VD1:**

```
union Data {
    char c;     // 1 byte
    int i;      // 4 bytes
    double d;   // 8 bytes
};

```
Tính toán kích thước (hệ 64 bit)
```
Thành viên lớn nhất: double d (8 bytes).
Yêu cầu căn chỉnh lớn nhất: 8 bytes.
Kích thước union: 8 bytes (không cần padding thêm vì 8 đã là bội số của 8).

```

Loại bỏ padding
```
union Data {
    char c;
    int i;
    double d;
} __attribute__((packed));

=> KÍCH THƯỚC: 8 bytes vì thành viên lớn nhất (double) yêu cầu tối thiểu 8 bytes.
```

* **VD2:**

```
union Data2 {
    char arr[7]; // 7 bytes
    int i;       // 4 bytes
};

```
Tính toán kích thước (hệ 64 bit)
```
hành viên lớn nhất: char arr[7] (7 bytes).
Yêu cầu căn chỉnh lớn nhất: 4 bytes (int i).
Kích thước union: 7 bytes, nhưng phải là bội số của 4 → thêm 1 byte padding → Kích thước: 8 bytes.

```
</details>
<details> 
 <summary><strong>BÀI 8:Memory Layout</strong></summary>

## **Bài 8: Memory Layout**

![Image](https://github.com/user-attachments/assets/0533640f-e379-42a7-a204-6e873241a0c6)

### **8.1.Text Segment(.text)**

#### **8.1.1.Mục đích**

* Lưu trữ mã máy đã được biên dịch từ mã nguồn C, bao gồm các lệnh thực thi của chương trình

#### **8.1.2.Đặc điểm**

* Chỉ đọc (read-only) để bảo vệ mã lệnh khỏi bị sửa đổi trong lúc chạy

* Có thể được chia sẻ giữa nhiều tiến trình chạy cùng một chương trình,giúp tiết kiệm bộ nhớ

* Thường nằm ở vùng địa chỉ thấp của bộ nhớ

VD: Các hàm như main(), các vòng lặp,câu lệnh điều kiện và các hàm khác đều được lưu ở đây



### **8.2.Initialized Data Segment(.data)**

#### **8.2.1.Mục đích**

* Lưu trữ các biến toàn cục và biến tĩnh được khởi tạo với giá trị khác 0 trong mã nguồn. 


#### **8.2.2.Đặc điểm**

* Có thể đọc và ghi (read-write)

* Kích thước được xác định tại thời điểm biên dịch

* Các giá trị khởi tạo được lưu trực tiếp trong file thực thi, do đó làm tăng kích thước file
```
int global_value = 100; // Lưu trong .data
static int static_value = 50; // Lưu trong .data
```


### **8.3.Unitialized Data Segment(.bss)**

#### **8.3.1.Mục đích**

* Lưu trữ các biến toàn cục và biến tĩnh không được khởi tạo tường minh hoặc được khởi tạo bằng 0

#### **8.3.2.Đặc điểm**

* Có thể đọc và ghi (read-write)

* Hệ điều hành tự động khởi tạo tất cả các giá trị trong vùng này thành 0 khi chương trình bắt đầu

* Không lưu giá trị cụ thể trong file thực thi, giúp tiết kiệm không gian
```
int global_zero; //Lưu trong .bss
static float static_uninit; //Lưu trong .bss
```

### **8.4.Heap**

#### **8.4.1.Mục đích**

* Vùng nhớ động được cấp phát và giải phóng trong lúc chạy chương trình thông qua các hàm như `malloc()`,`calloc()`,`realloc()` và `free()`


#### **8.4.2.Đặc điểm**

* Kích thước có thể thay đổi động (tăng hoặc giảm ) trong quá trình thực thi

* Thường "mọc" từ địa chỉ thấp lên cao

* Lỗi thường gặp

   ◦ Memory leak: Không gọi `free()` cho bộ nhớ đã cấp phát

   ◦ Use after free: Truy cập bộ nhớ sau khi đã giải phóng

   ◦ Dangling pointer: Con trỏ vẫn trỏ đến vùng nhớ đã giải phóng

   ◦ Fragmentation: Bộ nhớ bị chia thành các mảnh nhỏ,gây khó khăn cho việc cấp phát các khối lớn

vd:
```
int *ptr = malloc(10 * sizeof(int));
free(ptr);

```

### **8.5.Stack**

#### **8.5.1.Mục đích**

* Lưu trữ các biến cục bộ, tham số hàm, địa chỉ trả về, và trạng thái thanh ghi khi gọi hàm


#### **8.5.2.Đặc điểm**

* Hoạt động theo cơ chế LIFO

* Mỗi lần gọi hàm, một **stack frame** được tạo ra để lưu trữ thông tin của hàm đó.Khi hàm kết thúc **stack frame** bị xóa

* Thường "mọc" từ địa chỉ cao xuống thấp

* Kích thước stack thường cố định, được xác định bởi hệ điều hành hoặc trình biên dịch.Vượt quá kích thước có thể gây ra stack overflow

vd:
```
void func(int param){
    int local_var = 10; //Lưu trên stack
}

```

### **8.6.Các vùng bộ nhớ phụ khác**

#### **8.6.1.Environment/Arguments Segment**

* Lưu trữ các biến môi trường và các tham số dòng lệnh(argc, argv) được truyền vào chương trình

* Thường nằm ở vùng địa chỉ cao, gần stack


#### **8.6.2. Memory Mapping Segment**

* Dùng cho các file ánh xạ bộ nhớ (memory-mapped files) hoặc các thư viện động được nạp vào bộ nhớ

* Vị trí và cách sử dụng phụ thuộc vào hệ điều hành


</details>
