### **Bài tập 1: Khai báo và truy cập struct**
**Yêu cầu:**
```
Trong hệ thống nhúng ô tô, dữ liệu từ cảm biến nhiệt độ và áp suất được thu thập. Viết chương trình khai báo một struct tên TireSensor để lưu thông tin:

•	ID cảm biến (sensorId, kiểu int)
•	Nhiệt độ (temperature, kiểu float, đơn vị °C)
•	Áp suất (pressure, kiểu float, đơn vị kPa)
•	Thời gian lấy mẫu (timestamp, kiểu unsigned long)
1.	Khai báo một biến kiểu TireSensor và gán giá trị mẫu.
2.	In ra thông tin cảm biến.
```
### **Bài tập 2: Sử dụng con trỏ Struct**
**Yêu cầu:**
```
Sử dụng struct TireSensor 
1.	Khai báo một con trỏ tới struct TireSensor.
2.	Cấp phát động bộ nhớ cho con trỏ này bằng malloc.
3.	Gán giá trị cho các thành viên thông qua con trỏ.
4.	In ra thông tin cảm biến.
5.	Giải phóng bộ nhớ đã cấp phát.
```
### **Bài tập 3: Struct lồng nhau cho hệ thống điều khiển động cơ** 
**Yêu cầu:**
```
Viết chương trình quản lý thông tin hệ thống điều khiển động cơ ô tô:
•	struct FuelInjector gồm: 
o	Tỷ lệ phun nhiên liệu (fuelRate, kiểu float, đơn vị ml/s)
o	Trạng thái (isActive, kiểu char, 0 hoặc 1)
•	struct Engine gồm: 
o	Tốc độ động cơ (rpm, kiểu int, vòng/phút)
o	Nhiệt độ động cơ (engineTemp, kiểu float, đơn vị °C)
o	Mảng 4 kim phun nhiên liệu (injectors, kiểu struct FuelInjector)
1.	Khai báo một biến kiểu struct Engine.
2.	Gán giá trị cho động cơ và 4 kim phun (2 kim active, 2 kim không active).
3.	In ra thông tin động cơ và trạng thái từng kim phun.
```
### **Bài tập 4: Sử dụng Union cơ bản**
**Yêu cầu:**
```
Viết chương trình sử dụng union để lưu trữ thông tin một giá trị có thể là:
•	Số nguyên (intValue, kiểu int)
•	Số thực (floatValue, kiểu float)
•	Chuỗi (stringValue, chuỗi 20 ký tự)
1.	Khai báo một union Data.
2.	Gán lần lượt các giá trị khác nhau (số nguyên, số thực, chuỗi) và in ra.
3.	Thử truy cập một thành viên khác sau khi gán giá trị cho một thành viên để quan sát hành vi.
```
### **Bài tập 5: Union trong Struct**
**Yêu cầu:**
```
Viết chương trình quản lý thông tin kiểm tra cảm biến ô tô (mô phỏng hệ thống nhúng) sử dụng struct và union:
•	struct SensorTest gồm: 
    o	ID cảm biến (sensorId, kiểu int)
    o	Tên cảm biến (sensorName, chuỗi 50 ký tự)
    o	Loại kết quả kiểm tra (resultType, enum với giá trị NUMERIC hoặc STATUS)

    o	union TestResult chứa: 
        Giá trị số (numericValue, kiểu float, ví dụ: giá trị đo được như nhiệt độ hoặc áp suất)
        Trạng thái (status, chuỗi 3 ký tự, ví dụ: "OK", "ERR")

1.	Khai báo một mảng 3 bản ghi kiểm tra cảm biến.
2.	Gán giá trị cho 3 bản ghi (2 bản ghi có giá trị số, 1 bản ghi có trạng thái).
3.	In ra thông tin của từng bản ghi dựa trên resultType.
```
### **Bài tập 6: Sử dụng Typedef** 
**Yêu cầu:**
```
Sử dụng typedef để cải thiện mã quản lý hệ thống cảm biến ô tô 
struct Sensor gồm: 
o	ID cảm biến (sensorId, kiểu int)
o	Tên cảm biến (sensorName, chuỗi 50 ký tự)
o	Giá trị đo (value, kiểu float)
•	struct Vehicle gồm: 
o	Mã xe (vehicleId, chuỗi 20 ký tự)
o	Số lượng cảm biến (numSensors, kiểu int)
o	Mảng tối đa 10 cảm biến (sensors, kiểu struct Sensor)
1.	Tạo bí danh Sensor và Vehicle cho các struct tương ứng.
2.	Tạo bí danh SensorPtr cho con trỏ tới struct Sensor.
3.	Viết chương trình khai báo một biến kiểu Vehicle, gán giá trị cho 3 cảm biến, và in thông tin xe cùng các cảm biến.
```
### **Bài tập 7: Tính kích thước Struct và Padding**
**Yêu cầu:**
```
Cho struct tùy ý:
Tính kích thước của struct đó trên hệ 64-bit.
1.	Sắp xếp lại thứ tự các thành viên để tối ưu hóa kích thước (giảm padding).
2.	Sử dụng __attribute__((packed)) và tính lại kích thước.
3.	Viết chương trình in ra kích thước của struct gốc và struct đã tối ưu để kiểm tra.
```
### **Bài tập 8: Tính kích thước Union**
**Yêu cầu:**
```
Cho union tùy ý
Tính kích thước của union Value trên hệ 64-bit.
1.	Tính kích thước ban đầu
2.	Sử dụng __attribute__((packed)) và tính lại kích thước.
3.	Viết chương trình in ra kích thước của union trong các trường hợp.
```
### **Bài tập 9: Kết hợp Struct, Union, và Typedef**
**Yêu cầu:**
```
Viết chương trình quản lý nhân viên với các yêu cầu sau:
•	struct Employee gồm: 
o	Mã nhân viên (id, kiểu int)
o	Tên (name, chuỗi 50 ký tự)
o	Loại lương (salaryType, enum với giá trị HOURLY hoặc FIXED)
o	union Salary chứa: 
	Lương theo giờ (hourlyRate, kiểu float)
	Lương cố định (fixedSalary, kiểu double)
•	Sử dụng typedef để tạo bí danh Employee và EmployeePtr.
•	Khai báo một mảng 5 nhân viên, gán giá trị (3 nhân viên lương theo giờ, 2 nhân viên lương cố định).
•	Tính tổng lương phải trả (giả sử nhân viên lương theo giờ làm 160 giờ/tháng).
•	In ra thông tin từng nhân viên và tổng lương.
```
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

