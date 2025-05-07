	Bài tập:

1. Tạo file hello.c đơn giản 
 	Biên dịch từng bước:
	gcc -E hello.c -o hello.i (Xem output tiền xử lý)
	gcc -S hello.i -o hello.s (Xem output Assembly)
	gcc -c hello.s -o hello.o (Tạo object file)
	gcc hello.o -o hello_executable (Liên kết và tạo file thực thi)
	Chạy ./hello_executable.


2.	Viết macro MAX(a, b)  với MAX(x++, y++) và giải thích .

3.	Viết macro DEBUG_PRINT(msg) mà chỉ in ra msg nếu macro DEBUG được định nghĩa. Sử dụng #ifdef và #endif. Biên dịch với và không có flag -DDEBUG.

4.	Sử dụng #if, #elif, #else để định nghĩa một hằng số PLATFORM_NAME dựa trên các macro hệ thống có thể được định nghĩa sẵn (ví dụ _WIN32, __linux__, __APPLE__).
