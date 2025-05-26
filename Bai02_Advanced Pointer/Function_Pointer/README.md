Viết một chương trình C thực hiện các nhiệm vụ sau:
1.	Khai báo các hàm toán học: 
o	Viết bốn hàm: add(int a, int b) (cộng), subtract(int a, int b) (trừ), multiply(int a, int b) (nhân), và divide(int a, int b) (chia).

o	Hàm divide cần kiểm tra trường hợp chia cho 0 và trả về 0 nếu b == 0.

2.	Khai báo mảng con trỏ hàm: 

o	Khai báo một mảng con trỏ hàm int (*operations[])(int, int) để lưu trữ các hàm theo thứ tự: add, subtract, multiply, divide.

3.	Viết hàm thực thi: 
o	Viết hàm int calculate(int a, int b, int operation_index) nhận hai số a, b và chỉ số operation_index (từ 0 đến 3) để chọn phép toán từ mảng operations. Hàm gọi phép toán tương ứng và trả về kết quả.

4.	Viết chương trình chính: 
o	Cho phép người dùng nhập hai số nguyên a, b và một chỉ số operation_index (0: cộng, 1: trừ, 2: nhân, 3: chia).

o	Gọi hàm calculate với các giá trị người dùng nhập và in kết quả.

o	Xử lý trường hợp operation_index không hợp lệ (ngoài khoảng 0-3) bằng cách in thông báo lỗi.

5.	Thêm tính năng lặp: 

o	Sau khi in kết quả, hỏi người dùng có muốn tiếp tục thực hiện phép toán khác không (nhập 'y' để tiếp tục, 'n' để thoát). Lặp lại chương trình cho đến khi người dùng chọn thoát.

