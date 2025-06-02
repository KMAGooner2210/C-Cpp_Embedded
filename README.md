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

### **4.1.Kiến thức chung**



* Không chỉ xác định phạm vi(scope), thời gian sống(lifetime), và vùng nhớ lưu trữ(memory location) mà còn xác định **liên kết(linkage)** của biến hoặc hàm 

*  **Scope:** Nơi mà tên biến/hàm có thể được truy cập 
   
    ◦  **Block Scope:** Bên trong cặp dấu {}
   
    ◦  **File Scope:** Bên ngoài tất cả các hàm trong một file.Biến/hàm khai báo ở đây thường được gọi là toàn cục(global) cho file đó

    ◦  **Function Prototype Scope:** Chỉ áp dụng cho tên tham số trong khai báo hàm

*  **Lifetime:** Khoảng thời gian biến tồn tại trong bộ nhớ

    ◦ **Automatic:** Biến cục bộ, tồn tại khi khối lệnh chứa nó được thực thi,bị hủy khi ra khỏi khối

    ◦ **Static:** Biến toàn cục, biến `static` cục bộ, biến `extern`.Tồn tại suốt thời gian chương trình chạy

* **Memory Location:**

    ◦ **Stack:** Biến cục bộ 

    ◦ **Data Segment/BSS Segment:** Biến toàn cục, biến `extern`, biến `static`

        Data Segment: Lưu các biến toàn cục/static **đã được khởi tạo**

        BSS Segment: Lưu các biến toàn cục/static **chưa được khởi tạo hoặc khởi tạo bằng 0**

    ◦ **Heap:** Bộ nhớ cấp phát động(qua malloc,calloc)

    ◦ **Text Segment(Code segment):** Mã lệnh của chương trình(các hàm)
* **Linkage:**

    ◦ Quyết định xem một tên(biến / hàm) có thể được tham chiếu từ các đơn vị dịch khác hay không

        External Linkage: Tên có thể được tham chiếu từ các file khác.Biến toàn cục(không static) và hàm(không static) mặc định có liên kết ngoài

        Internal Linkage: Tên chỉ được tham chiếu bên trong file hiện tại.Biến toàn cục static và hàm static có liên kết nội

        No linkage: Biến cục bộ


### **4.2.Extern**

#### **4.2.1.Mục đích**

  * Extern là một **chỉ thị khai báo**

  * **Khi dùng với biến:**

     ◦ Nó thông báo cho trình biên dịch **Biến này được định nghĩa ở đâu đó, có thể ở trong file này hoặc file khác.Đừng cấp phát bộ nhớ cho nó tại đây, chỉ cần biết kiểu và tên của nó thôi.Linker sẽ tìm định nghĩa sau**

  * **Khi dùng với hàm:**

     ◦ **Nó khai báo một hàm mà định nghĩa của nó có thể ở file khác (hoặc ở phần sau của file hiện tại)**.Đối với hàm ,`extern` thường là ngầm định khi bạn khai báo prototype ở phạm vi toàn cục

#### **4.2.2.Extern và Linkage**

  * Extern ngụ ý rằng biến hoặc hàm có **liên kết ngoài**.Điều này có nghĩa là định nghĩa thực sự của biến hoặc hàm đó có thể nằm trong 1 file.c khác và linker sẽ kết nối các tham chiếu đến định nghĩa đó

#### **4.2.3.Sử dụng**  

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


### **4.3.Static**

#### **4.3.1.Biến static cục bộ**

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


#### **4.3.2.Biến static toàn cục**

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


### **4.4.Volatile**  

#### **4.4.1.Định nghĩa**

* Khi một biến được đánh dấu là `Volatile`,trình biên dịch không được phép tối ưu hóa (như loại bỏ hoặc cache) các thao tác đọc/ghi liên quan đến biến này,**vì giá trị của nó có thể thay đổi bất ngờ** từ các nguồn ngoài luồng thực thi hiện tại **(như phần cứng,ISR, hoặc thread khác)**

#### **4.4.2.Hành vi**

* Buộc trình biên dịch đọc/ghi trực tiếp từ/tới bộ nhớ mỗi khi truy cập biến,thay vì cache trong thanh ghi

* Giữ nguyên thứ tự thao tác đọc/ghi,tránh tái sắp xếp do tối ưu hóa

#### **4.4.3.Các trường hợp sử dụng**

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

### **4.5.Register**

#### **4.5.1.Định nghĩa**

* Biến register được sử dụng để gợi ý cho trình biên dịch rằng 1 biến nên được lưu trữ trong **thanh ghi CPU thay vì RAM**

=> Tăng hiệu năng, giảm thời gian truy cập

#### **4.5.2.Đặc điểm**

* ALU là đơn vị xử lý toán học và logic trong CPU, thực hiện các phép toán như cộng, trừ, nhân, chia, AND, OR, XOR, ...


![Image](https://github.com/user-attachments/assets/a73e7c81-7d77-4439-a087-2d87d89a2398)

#### **4.5.3.Hạn chế**

* Không áp dụng cho tất cả biến

* Hạn chế với biến lớn   
 </details> 
