## **Ex1.	Chuyển Đổi Số Thập Phân Sang Nhị Phân**
o	Yêu cầu: Viết hàm chuyển số thập phân (unsigned int) sang biểu diễn nhị phân dưới dạng chuỗi (string).
```
o	Ví dụ: 

	Input: 5
	Output: "00000101" (giả sử 8 bit)
	Input: 13
	Output: "00001101"
o	Gợi ý: Sử dụng phép dịch bit (>>), toán tử AND (&) và lặp để kiểm tra từng bit.
```
## **Ex2.	Kiểm Tra Bit Thứ n** 
o	Yêu cầu: Viết hàm kiểm tra bit thứ n (tính từ 0) của một số nguyên không dấu (unsigned int) có được set (bằng 1) hay không.
```
o	Ví dụ: 
	Input: value = 5 (nhị phân: 00000101), n = 2
	Output: true (bit 2 là 1)
	Input: value = 5, n = 3
	Output: false (bit 3 là 0)
o	Gợi ý: Sử dụng bitmask và toán tử AND.
```
## **Ex3. Đặt Bit Thứ n** 
o	Yêu cầu: Viết hàm đặt (set) bit thứ n của một số nguyên không dấu thành 1
```
o	Ví dụ: 
	Input: value = 5 (nhị phân: 00000101), n = 3
	Output: 13 (nhị phân: 00001101)
```
## **Ex4.	Xóa Bit Thứ n** 
o	Yêu cầu: Viết hàm xóa (clear) bit thứ n của một số nguyên không dấu, tức là đặt bit đó thành 0.

```
o	Ví dụ: 
	Input: value = 13 (nhị phân: 00001101), n = 3
	Output: 5 (nhị phân: 00000101)
o	Gợi ý: Sử dụng toán tử NOT (~) và AND (&) với bitmask.
```
## **Ex5.	Đảo Bit Thứ n**

o	Yêu cầu: Viết hàm đảo (toggle) bit thứ n của một số nguyên không dấu (từ 0 thành 1 hoặc 1 thành 0).
```
o	Ví dụ: 
	Input: value = 5 (nhị phân: 00000101), n = 3
	Output: 13 (nhị phân: 00001101)
	Input: value = 13 (nhị phân: 00001101), n = 3
	Output: 5 (nhị phân: 00000101)
o	Gợi ý: Sử dụng toán tử XOR (^).
```

## **Ex6.	Đếm Số Bit 1** 
o	Yêu cầu: Viết hàm đếm số bit 1 trong biểu diễn nhị phân của một số nguyên không dấu.
```
o	Ví dụ: 
	Input: 5 (nhị phân: 00000101)
	Output: 2 (có 2 bit 1)
	Input: 15 (nhị phân: 00001111)
	Output: 4
o	Gợi ý: Dùng vòng lặp và toán tử AND hoặc mẹo (value & (value - 1)) để xóa bit 1 thấp nhất.
```

## **Ex7.	Dịch Bit và Kiểm Tra Tràn**
o	Yêu cầu: Viết hàm dịch trái một số nguyên không dấu n vị trí và kiểm tra xem có xảy ra tràn bit không (bit bị mất ở bên trái).
```
o	Ví dụ: 
	Input: value = 5 (nhị phân: 00000101), n = 2, giả sử 8 bit
	Output: 20 (nhị phân: 00010100), không tràn
	Input: value = 100 (nhị phân: 01100100), n = 3, giả sử 8 bit
	Output: 16 (nhị phân: 00010000), có tràn
o	Gợi ý: Kiểm tra các bit cao trước khi dịch bằng bitmask.
```
## **Ex8.	Set Nhiều Bit Cùng Lúc** 
o	Yêu cầu: Viết hàm đặt (set) nhiều bit cụ thể (danh sách các vị trí) của một số nguyên không dấu thành 1.
```
o	Ví dụ: 
	Input: value = 0 (nhị phân: 00000000), positions = [2, 3, 5]
	Output: 44 (nhị phân: 00101100)
o	Gợi ý: Tạo bitmask bằng cách OR nhiều mask đơn lẻ, sau đó áp dụng toán tử OR.
```
## **Ex9.	Kiểm Tra Nhiều Bit Cùng Được Set**
o	Yêu cầu: Viết hàm kiểm tra xem tất cả các bit ở các vị trí cho trước trong một số nguyên không dấu có đều được set (bằng 1) hay không.
```
o	Ví dụ: 
	Input: value = 12 (nhị phân: 00001100), positions = [2, 3]
	Output: true (cả bit 2 và 3 đều là 1)
	Input: value = 12 (nhị phân: 00001100), positions = [2, 4]
	Output: false (bit 4 là 0)
o	Gợi ý: Tạo mask bằng OR, sau đó dùng AND và so sánh.
```
## **Ex10.	Tìm Bit 1 Thấp Nhất**
o	Yêu cầu: Viết hàm tìm vị trí của bit 1 thấp nhất (tính từ 0) trong biểu diễn nhị phân của một số nguyên không dấu. Nếu không có bit 1, trả về -1.
```
o	Ví dụ: 
	Input: 5 (nhị phân: 00000101)
	Output: 0 (bit 1 thấp nhất ở vị trí 0)
	Input: 8 (nhị phân: 00001000)
	Output: 3
	Input: 0 (nhị phân: 00000000)
	Output: -1
o	Gợi ý: Sử dụng value & (-value) để lấy bit thấp nhất, sau đó tìm vị trí bằng cách lặp hoặc mẹo logarit.
```
## **Ex11.Sử Dụng Bit Fields**

Yêu cầu:

•  Định nghĩa struct: 

•	Sử dụng bit fields để lưu trữ thông tin cấu hình cho một thiết bị phần cứng: 
```
o	enabled: 1 bit (bật/tắt thiết bị, 0 = tắt, 1 = bật).
o	mode: 3 bit (chế độ hoạt động, giá trị từ 0-7, với các chế độ được xác định như sau): 
	0: Tắt (Off).
	1: Tiết kiệm năng lượng (Low Power).
	2: Bình thường (Normal).
	3: Hiệu suất cao (High Performance).
	4: Chẩn đoán (Diagnostic).
	5: Cập nhật firmware (Firmware Update).
	6: Chờ (Idle).
	7: Khẩn cấp (Emergency).
o	priority: 4 bit (mức độ ưu tiên, giá trị từ 0-15, được phân loại như sau): 
	0-3: Thấp (Low).
	4-7: Trung bình (Medium).
	8-11: Cao (High).
	12-15: Rất cao (Critical).
```
•	Tổng cộng 8 bit, giả định đóng gói trong 1 byte.

•  Viết chương trình: 

•	Khởi tạo: Khởi tạo struct với enabled = 1 (thiết bị bật), mode = 3 (chế độ hiệu suất cao), priority = 10 (ưu tiên cao).

•	Kiểm tra tính hợp lệ: 
```
o	Đảm bảo enabled là 0 hoặc 1.
o	Đảm bảo mode từ 0 đến 7.
o	Đảm bảo priority từ 0 đến 15.
o	Nếu bất kỳ giá trị nào không hợp lệ, in thông báo lỗi và dừng chương trình.
```
•	In trạng thái: 
```
o	In giá trị của enabled với mô tả "Thiết bị: Bật" hoặc "Tắt".
o	In giá trị của mode với tên chế độ tương ứng (ví dụ: "Chế độ: Hiệu suất cao").
o	In giá trị của priority với mức ưu tiên tương ứng (ví dụ: "Ưu tiên: Cao").
o	In biểu diễn nhị phân của toàn bộ struct (8 bit, dự kiến: 11001011).
```

## **Ex12. Thanh Ghi Phần Cứng Với Bit Fields**
•  Định nghĩa thanh ghi 16 bit

•	Sử dụng struct với bit fields để biểu diễn một thanh ghi 16 bit, gồm các trường: 
```
o	interrupt: 1 bit (bit 0), giá trị 0-1 (0 = Tắt ngắt, 1 = Bật ngắt).
o	direction: 2 bit (bit 1-2), giá trị 0-3 (0 = Dừng, 1 = Tiến, 2 = Lùi, 3 = Xoay).
o	speed: 5 bit (bit 3-7), giá trị 0-31 (Tốc độ lấy mẫu hoặc điều khiển, ánh xạ: 0 = Tắt, 1-10 = Thấp, 11-20 = Trung bình, 21-31 = Cao).
o	reserved: 3 bit (bit 8-10), luôn giữ giá trị 0 (dự phòng).
o	data: 5 bit (bit 11-15), giá trị 0-31, đại diện cho nhiệt độ (ánh xạ tuyến tính 0-62°C, ví dụ: 20 = 40°C).
```

•  Nhập liệu từ người dùng

•	Kiểm tra tính hợp lệ của giá trị nhập
```
o	interrupt: 0-1.
o	direction: 0-3.
o	speed: 0-31.
o	data: 0-31.
```
•	Nếu nhập sai (số âm, vượt phạm vi, hoặc không phải số), chương trình thông báo lỗi và yêu cầu nhập lại.

•  Cơ chế nhập lại và thoát

## Acknowledgements

 - [Awesome Readme Templates](https://awesomeopensource.com/project/elangosundar/awesome-README-templates)
 - [Awesome README](https://github.com/matiassingers/awesome-readme)
 - [How to write a Good readme](https://bulldogjob.com/news/449-how-to-write-a-good-readme-for-your-github-project)

## Color Reference

| Color             | Hex                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Example Color | ![#0a192f](https://via.placeholder.com/10/0a192f?text=+) #0a192f |
| Example Color | ![#f8f8f8](https://via.placeholder.com/10/f8f8f8?text=+) #f8f8f8 |
| Example Color | ![#00b48a](https://via.placeholder.com/10/00b48a?text=+) #00b48a |
| Example Color | ![#00d1a0](https://via.placeholder.com/10/00b48a?text=+) #00d1a0 |

