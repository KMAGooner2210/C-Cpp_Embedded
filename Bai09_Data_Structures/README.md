## **Bài tập**

* **1.	Tạo và in danh sách**
```
o	Viết hàm Node* create_node(int data): Tạo một nút mới với giá trị data và con trỏ next là NULL.
o	Viết hàm void print_list(Node *head): In lần lượt giá trị của tất cả các nút. Nếu danh sách rỗng, in “Danh sách rỗng”.
o	Trong hàm main, tạo 3 nút với giá trị [10, 20, 30], liên kết chúng thành danh sách, và in danh sách.
```
* **2.	Thêm phần tử**
```
•  Mô tả: Viết chương trình C để tạo một danh sách liên kết đơn từ input của người dùng, thêm các phần tử vào đầu hoặc cuối danh sách theo yêu cầu người dùng, và in danh sách sau mỗi thao tác thêm. 
•  Yêu cầu chi tiết: 
	Hàm void insert_at_head(Node **head_ref, int data): Thêm một nút mới với giá trị data vào đầu danh sách, sử dụng con trỏ kép để cập nhật head.
	Hàm void insert_at_end(Node **head_ref, int data): Thêm một nút mới với giá trị data vào cuối danh sách.

	Hàm main: 
o	Yêu cầu người dùng nhập số lượng phần tử (n) và các giá trị số nguyên để tạo danh sách ban đầu.
o	In danh sách vừa nhập.
o	Yêu cầu người dùng nhập một giá trị để thêm vào đầu danh sách, gọi insert_at_head, và in danh sách sau khi thêm.
o	Yêu cầu người dùng nhập một giá trị để thêm vào cuối danh sách, gọi insert_at_end, và in danh sách sau khi thêm.
o	Giải phóng bộ nhớ của danh sách để tránh rò rỉ bộ nhớ.

	Các hàm hỗ trợ: 
o	Node* create_node(int data): Tạo một nút mới với giá trị data.
o	void print_list(Node* head): In danh sách liên kết.
o	void free_list(Node** head_ref): Giải phóng bộ nhớ của danh sách.

 	Input: 
•	Một số nguyên n (số lượng phần tử ban đầu, n ≥ 0).
•	n giá trị số nguyên để tạo danh sách liên kết.
•	Một giá trị số nguyên để thêm vào đầu danh sách.
•	Một giá trị số nguyên để thêm vào cuối danh sách.

  	Output: 
•	Danh sách vừa nhập ban đầu.
•	Danh sách sau khi thêm phần tử vào đầu.
•	Danh sách sau khi thêm phần tử vào cuối.
•	Thông báo xác nhận danh sách đã được giải phóng (danh sách rỗng).
```
* **3.	Xóa và tìm kiếm**
```
•  Mô tả: Viết chương trình C để tạo một danh sách liên kết đơn từ input của người dùng, tìm kiếm một nút chứa giá trị cụ thể, xóa nút đầu tiên chứa giá trị cụ thể, và in kết quả sau các thao tác. 
•  Yêu cầu chi tiết: 
	Hàm void delete_node(Node **head_ref, int data): Xóa nút đầu tiên trong danh sách chứa giá trị data. Nếu không tìm thấy, không làm gì.
	Hàm Node* search_node(Node *head, int data): Tìm và trả về con trỏ tới nút đầu tiên chứa giá trị data. Trả về NULL nếu không tìm thấy.

	Hàm main: 
o	Yêu cầu người dùng nhập số lượng phần tử (n) và các giá trị số nguyên để tạo danh sách.
o	In danh sách vừa nhập.
o	Yêu cầu người dùng nhập một giá trị để tìm kiếm, gọi search_node, và in kết quả (tìm thấy hoặc không tìm thấy).
o	Yêu cầu người dùng nhập một giá trị để xóa, gọi delete_node, và in danh sách sau khi xóa.
o	Giải phóng bộ nhớ của danh sách để tránh rò rỉ bộ nhớ.

	Các hàm hỗ trợ: 
o	Node* create_node(int data): Tạo một nút mới với giá trị data.
o	void insert_at_tail(Node** head_ref, int data): Thêm nút vào cuối danh sách để giữ thứ tự nhập.
o	void print_list(Node* head): In danh sách liên kết.
o	void free_list(Node** head_ref): Giải phóng bộ nhớ của danh sách.
	
	Input: 
•	Một số nguyên n (số lượng phần tử, n ≥ 0).
•	n giá trị số nguyên để tạo danh sách liên kết.
•	Một giá trị số nguyên để tìm kiếm.
•	Một giá trị số nguyên để xóa.
	
	 Output: 
•	Danh sách vừa nhập.
•	Kết quả tìm kiếm (tìm thấy giá trị tại địa chỉ nút hoặc không tìm thấy).
•	Danh sách sau khi xóa nút chứa giá trị được yêu cầu.
•	Thông báo xác nhận danh sách đã được giải phóng (danh sách rỗng).
```
* **4.	Giải phóng bộ nhớ**
```
o	Viết hàm void free_list(Node **head_ref): Giải phóng toàn bộ bộ nhớ của danh sách và đặt head về NULL.
o	Trong hàm main, tạo danh sách với các số [5, 10, 15], in danh sách, giải phóng, và in lại để xác nhận danh sách rỗng.
```
* **5 . Đảo ngược danh sách**
```
•  Mô tả: Viết một chương trình C để tạo một danh sách liên kết đơn từ input của người dùng, đảo ngược danh sách liên kết, và in kết quả trước và sau khi đảo ngược. 
•  Yêu cầu chi tiết: 
	Hàm void reverse_list(Node **head_ref): Đảo ngược danh sách liên kết đơn bằng cách thay đổi liên kết của các nút (ví dụ: [10 -> 20 -> 30] thành [30 -> 20 -> 10]).

	Hàm main: 
o	Cho phép người dùng nhập số lượng phần tử (n) và các giá trị của danh sách liên kết.
o	In danh sách vừa nhập.
o	Gọi hàm reverse_list để đảo ngược danh sách.
o	In danh sách sau khi đảo ngược.
o	Giải phóng bộ nhớ danh sách để tránh rò rỉ bộ nhớ.

	Các hàm hỗ trợ: 
o	Node* create_node(int data): Tạo một nút mới với giá trị data.
o	void insert_at_tail(Node** head_ref, int data): Thêm nút vào cuối danh sách để giữ thứ tự nhập.
o	void print_list(Node* head): In danh sách liên kết.
o	void free_list(Node** head_ref): Giải phóng bộ nhớ danh sách.

	Input: 
•	Số lượng phần tử n (số nguyên không âm).
•	n giá trị số nguyên cho danh sách.
    Output: 
•	Danh sách vừa nhập.
•	Danh sách sau khi đảo ngược.
•	Danh sách sau khi giải phóng (rỗng).
```
* **6.    Phát hiện vòng trong danh sách**
```
•	Mô tả: Viết một chương trình C để tạo một danh sách liên kết đơn từ input của người dùng, kiểm tra xem danh sách có vòng hay không, và cho phép người dùng tùy chọn tạo vòng tại một vị trí cụ thể.
•	Yêu cầu chi tiết: 
	Hàm int has_cycle(Node *head): Sử dụng thuật toán Floyd’s Cycle-Finding (con trỏ nhanh-chậm) để kiểm tra xem danh sách có vòng hay không. Trả về 1 nếu có vòng, 0 nếu không.

	Hàm main: 
	Cho phép người dùng nhập số lượng phần tử (n) và các giá trị của danh sách liên kết.
	In danh sách vừa nhập và kiểm tra xem nó có vòng hay không.
	Hỏi người dùng có muốn tạo vòng không. Nếu có, yêu cầu nhập vị trí (1-based index) để nút cuối trỏ về (tạo vòng).
	In danh sách sau khi tạo vòng (nếu có) và kiểm tra lại xem có vòng hay không.
	Giải phóng bộ nhớ danh sách, đảm bảo phá vòng (nếu có) trước khi giải phóng.

	Các hàm hỗ trợ: 
	Node* create_node(int data): Tạo một nút mới với giá trị data.
	void insert_at_tail(Node** head_ref, int data): Thêm nút vào cuối danh sách.
	void print_list(Node* head): In danh sách, giới hạn số nút để tránh lặp vô hạn khi có vòng.
	void free_list(Node** head_ref): Giải phóng bộ nhớ danh sách.

	Input: 
o	Số lượng phần tử n.
o	n giá trị cho danh sách.
o	Lựa chọn có tạo vòng hay không (1: có, 0: không).
o	Nếu tạo vòng, nhập vị trí nút (từ 1 đến n) để nút cuối trỏ về.

	Output: 
o	Danh sách vừa nhập.
o	Kết quả kiểm tra vòng ban đầu.
o	Nếu tạo vòng: danh sách sau khi tạo vòng và kết quả kiểm tra vòng.
o	Danh sách sau khi giải phóng (rỗng).
```
* **7.   Hợp nhất hai danh sách**
```
•  Mô tả: Viết chương trình C để tạo hai danh sách liên kết đơn đã được sắp xếp tăng dần từ input của người dùng, hợp nhất chúng thành một danh sách mới cũng được sắp xếp tăng dần, và in kết quả. 
•  Yêu cầu chi tiết: 
	Hàm Node* merge_lists(Node *head1, Node *head2): Hợp nhất hai danh sách liên kết đã được sắp xếp tăng dần thành một danh sách mới, chỉ điều chỉnh con trỏ mà không tạo nút mới. Trả về con trỏ tới nút đầu của danh sách hợp nhất.

	Hàm main: 
o	Yêu cầu người dùng nhập số lượng phần tử (n1) và các giá trị số nguyên đã sắp xếp tăng dần cho danh sách thứ nhất.
o	Yêu cầu người dùng nhập số lượng phần tử (n2) và các giá trị số nguyên đã sắp xếp tăng dần cho danh sách thứ hai.
o	In cả hai danh sách vừa nhập.
o	Gọi merge_lists để hợp nhất hai danh sách, in danh sách kết quả.
o	Giải phóng bộ nhớ của danh sách hợp nhất để tránh rò rỉ bộ nhớ.

	Các hàm hỗ trợ: 
o	Node* create_node(int data): Tạo một nút mới với giá trị data.
o	void insert_at_tail(Node** head_ref, int data): Thêm nút vào cuối danh sách để giữ thứ tự nhập.
o	void print_list(Node* head): In danh sách liên kết.
o	void free_list(Node** head_ref): Giải phóng bộ nhớ của danh sách.
	
	Input: 
•	Một số nguyên n1 (số lượng phần tử của danh sách thứ nhất, n1 ≥ 0).
•	n1 giá trị số nguyên đã sắp xếp tăng dần cho danh sách thứ nhất.
•	Một số nguyên n2 (số lượng phần tử của danh sách thứ hai, n2 ≥ 0).
•	n2 giá trị số nguyên đã sắp xếp tăng dần cho danh sách thứ hai.

    Output: 
•	Danh sách thứ nhất vừa nhập.
•	Danh sách thứ hai vừa nhập.
•	Danh sách sau khi hợp nhất.
•	Thông báo xác nhận danh sách đã được giải phóng (danh sách rỗng).
```