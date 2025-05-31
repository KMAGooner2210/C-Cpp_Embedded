
## Bài 1: Đọc giá trị từ thanh ghi phần cứng

Mô tả: 

Trong một hệ thống nhúng, bạn cần đọc trạng thái của một thanh ghi trạng thái (status register) được ánh xạ vào bộ nhớ tại địa chỉ 0x40010000. 

Thanh ghi này có thể thay đổi giá trị do phần cứng. Hãy viết chương trình để liên tục kiểm tra bit thứ 3 của thanh ghi và in ra thông báo khi bit này được bật.


## Bài 2: Đếm và xử lý ngắt từ nút nhấn 

Mô tả: 

Trong một hệ thống nhúng, một nút nhấn được kết nối với một chân GPIO, gây ra ngắt mỗi khi nút được nhấn. Bạn cần viết một chương trình sử dụng biến volatile để:
1.	Đếm số lần nút được nhấn thông qua ISR.
2.	Nếu số lần nhấn đạt đến một ngưỡng (ví dụ: 5 lần), chương trình chính sẽ kích hoạt một hành động (ví dụ: in thông báo hoặc bật/tắt một đèn LED giả lập).

## Bài 3: Điều khiển GPIO với volatile 
Mô tả:

 Trong một hệ thống nhúng, bạn cần điều khiển một chân GPIO (giả sử tại địa chỉ 0x40020000) để bật/tắt một đèn LED. Một ngắt từ timer sẽ thay đổi trạng thái của một biến cờ, và chương trình chính sẽ sử dụng cờ này để bật/tắt LED.
