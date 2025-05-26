**EX1**.	Khai báo int var = 10; int *ptr = &var; int **pptr = &ptr;. In ra giá trị của var bằng cả 3 cách: var, *ptr, **pptr.

**EX2**.	Viết hàm allocate_string(char **str_ptr, int size) cấp phát bộ nhớ cho một chuỗi có kích thước size và gán địa chỉ vùng nhớ đó cho con trỏ được trỏ bởi str_ptr. Trong main, gọi hàm này và kiểm tra xem con trỏ chuỗi trong main có được cập nhật không. Đừng quên free.
