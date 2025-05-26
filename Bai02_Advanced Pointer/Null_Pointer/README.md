**EX1.	Khởi tạo và kiểm tra NULL**

Yêu cầu:

o	Khai báo một con trỏ kiểu int* tên là ptr.

o	Khởi tạo ptr với giá trị NULL.

o	Viết câu lệnh if để kiểm tra xem ptr có bằng NULL hay không.

o	Nếu ptr là NULL, in ra "Con tro ptr la NULL."

o	Nếu không, in ra "Con tro ptr khong phai la NULL." (Trường hợp này không nên xảy ra nếu bạn khởi tạo đúng).

**EX2.	Tìm kiếm phần tử trong mảng**

Yêu cầu:

o	Viết một hàm int* findValue(int arr[], int size, int valueToFind):

o	Hàm này nhận một mảng số nguyên, kích thước mảng, và một giá trị cần tìm.

o	Nếu tìm thấy valueToFind trong arr, hàm trả về con trỏ trỏ đến vị trí đầu tiên của giá trị đó trong mảng.

o	Nếu không tìm thấy, hàm trả về NULL.

o	Trong hàm main:

o	Khai báo một mảng số nguyên ví dụ.

o	Gọi hàm findValue để tìm một giá trị có trong mảng và một giá trị không có.

o	Kiểm tra con trỏ trả về. Nếu nó không phải NULL, in ra giá trị mà nó trỏ tới. Nếu là NULL, in ra "Khong tim thay gia tri."
