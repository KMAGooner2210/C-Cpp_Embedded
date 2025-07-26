## **Bài tập**
**1.Tạo và in danh sách**
```
o	Viết hàm Node* create_node(int data): Tạo một nút mới với giá trị data và con trỏ next là NULL.
o	Viết hàm void print_list(Node *head): In lần lượt giá trị của tất cả các nút. Nếu danh sách rỗng, in “Danh sách rỗng”.
o	Trong hàm main, tạo 3 nút với giá trị [10, 20, 30], liên kết chúng thành danh sách, và in danh sách.
```
**2.Thêm phần tử**
```
o	Viết hàm void insert_at_head(Node **head_ref, int data): Thêm một nút mới với giá trị data vào đầu danh sách, sử dụng con trỏ kép để cập nhật head.
o	Viết hàm void insert_at_end(Node **head_ref, int data): Thêm một nút mới với giá trị data vào cuối danh sách.
o	Trong hàm main, tạo danh sách rỗng, thêm các số [5, 15, 25] (2 số vào đầu, 1 số vào cuối), in danh sách sau mỗi thao tác.
```
**3.Xóa và tìm kiếm**
```
o	Viết hàm void delete_node(Node **head_ref, int data): Xóa nút đầu tiên chứa giá trị data. Nếu không tìm thấy, không làm gì.
o	Viết hàm Node* search_node(Node *head, int data): Tìm và trả về con trỏ tới nút đầu tiên chứa giá trị data. Trả về NULL nếu không tìm thấy.
o	Trong hàm main:
	Tạo danh sách với các số [10, 20, 30, 40].
	Tìm kiếm số 30 và in kết quả (tìm thấy hoặc không).
	Xóa số 20, in danh sách sau khi xóa.
```
**4.Giải phóng bộ nhớ**
```
o	Viết hàm void free_list(Node **head_ref): Giải phóng toàn bộ bộ nhớ của danh sách và đặt head về NULL.
o	Trong hàm main, tạo danh sách với các số [5, 10, 15], in danh sách, giải phóng, và in lại để xác nhận danh sách rỗng.
```
**5.Đảo ngược danh sách**
```
o	Viết hàm void reverse_list(Node **head_ref): Đảo ngược danh sách liên kết (ví dụ: 5->10->15 thành 15->10->5).
o	Trong hàm main, tạo danh sách [10, 20, 30, 40], đảo ngược và in kết quả.
```
**6.Phát hiện vòng trong danh sách**
```
o	Viết hàm int has_cycle(Node *head): Sử dụng thuật toán Floyd’s Cycle-Finding (con trỏ nhanh-chậm) để kiểm tra danh sách có vòng hay không. Trả về 1 nếu có, 0 nếu không.
o	Trong hàm main, thử với danh sách có vòng và không có vòng, in kết quả.
```
**7.Hợp nhất hai danh sách**
```
o	Viết hàm Node* merge_lists(Node *head1, Node *head2): Hợp nhất hai danh sách liên kết đã được sắp xếp tăng dần thành một danh sách mới cũng được sắp xếp. Không tạo nút mới, chỉ điều chỉnh con trỏ.
o	Trong hàm main, tạo hai danh sách [1, 3, 5] và [2, 4, 6], hợp nhất và in danh sách kết quả.
```


