# **Danh sách bài tập**


## **Ex1: Tạo lớp và đối tượng đơn giản**
```
Viết một chương trình tạo lớp Rectangle với các thuộc tính length và width (chiều dài và chiều rộng).

Tạo các phương thức để tính chu vi (perimeter) và diện tích (area).
Trong main(), tạo một đối tượng Rectangle và gọi các phương thức để hiển thị chu vi và diện tích.

Ví dụ đầu ra:

Chu vi: 14
Diện tích: 12
```

## **Ex2: Đóng gói với Getter và Setter**

```
Viết lớp Student với các thuộc tính private: name (chuỗi), age (số nguyên), và grade (số thực).

Tạo constructor để khởi tạo các thuộc tính.
Tạo các phương thức getter và setter với kiểm tra hợp lệ (ví dụ: age >= 0, grade từ 0 đến 10).
Tạo phương thức displayInfo để in thông tin sinh viên.
Trong main(), tạo một đối tượng Student, thiết lập giá trị và in thông tin.

Ví dụ đầu ra:

Name: Alice, Age: 20, Grade: 8.5
```
## **Ex3: Constructor và Uniform Initialization**

```
Viết lớp Car với các thuộc tính brand (chuỗi), year (số nguyên), và price (số thực).

Tạo constructor mặc định và constructor có tham số sử dụng Uniform Initialization.
Tạo phương thức display để in thông tin xe.
Trong main(), khởi tạo 2 đối tượng Car (một bằng constructor mặc định, một bằng constructor có tham số) và hiển thị thông tin.

Ví dụ đầu ra:

Car: Unknown, Year: 0, Price: 0
Car: Toyota, Year: 2020, Price: 25000.5
```
## **Ex4: Static Member**
```
Viết lớp Counter với một biến tĩnh count để đếm số đối tượng được tạo.

Mỗi khi tạo hoặc hủy một đối tượng, cập nhật giá trị count.
Tạo phương thức tĩnh showCount để hiển thị số đối tượng hiện tại.
Trong main(), tạo và hủy một vài đối tượng, sau đó gọi showCount để kiểm tra.

Ví dụ đầu ra:

Số đối tượng: 0
Số đối tượng: 2
Số đối tượng: 1
```
## **Ex5: Phương thức const**
```
Viết lớp Circle với thuộc tính private là radius (bán kính).

Tạo constructor để khởi tạo bán kính.
Tạo phương thức getArea và getPerimeter với từ khóa const.
Trong main(), tạo một đối tượng Circle và gọi các phương thức để hiển thị diện tích và chu vi.

Ví dụ đầu ra:

textDiện tích: 78.54
Chu vi: 31.42
```


## **Ex6: Kế thừa đơn (Single Inheritance)**
```
Viết lớp cơ sở Vehicle với các thuộc tính brand và year, và phương thức displayInfo.

Tạo lớp con Car kế thừa từ Vehicle, thêm thuộc tính numDoors (số cửa).
Ghi đè phương thức displayInfo để hiển thị thêm thông tin numDoors.
Trong main(), tạo đối tượng Car và gọi displayInfo.

Ví dụ đầu ra:

textBrand: Honda, Year: 2021, Number of doors: 4
```
## **Ex7: Nạp chồng toán tử**
```
Viết lớp Complex để biểu diễn số phức với hai thuộc tính real và imag (phần thực và phần ảo).

Nạp chồng toán tử + để cộng hai số phức.
Nạp chồng toán tử << để in số phức dạng (real + imagi).
Trong main(), tạo hai đối tượng Complex, cộng chúng và hiển thị kết quả.

Ví dụ đầu ra:

textComplex 1: (3 + 4i)
Complex 2: (1 + 2i)
Sum: (4 + 6i)
```
## **Ex8: Copy Constructor**
```
Viết lớp Book với các thuộc tính title, author, và price.

Tạo constructor có tham số và copy constructor.
Tạo phương thức display để in thông tin sách.
Trong main(), tạo một đối tượng Book, sao chép nó bằng copy constructor và hiển thị thông tin của cả hai đối tượng.

Ví dụ đầu ra:

textBook: The Hobbit, Author: Tolkien, Price: 29.99
Copied Book: The Hobbit, Author: Tolkien, Price: 29.99
```
## **Ex9: Destructor và quản lý bộ nhớ**
```
Viết lớp DynamicArray với thuộc tính là một con trỏ int* data và size (kích thước mảng).

Tạo constructor để cấp phát động mảng với kích thước cho trước và khởi tạo giá trị.
Tạo destructor để giải phóng bộ nhớ.
Tạo phương thức display để in các phần tử mảng.
Trong main(), tạo một đối tượng DynamicArray, hiển thị mảng và kiểm tra việc giải phóng bộ nhớ.

Ví dụ đầu ra:

textArray: 1 2 3 4 5
Destructor called
```
## **Ex10: Con trỏ this**
```
Viết lớp Employee với các thuộc tính name và salary.

Tạo phương thức setInfo sử dụng con trỏ this để thiết lập giá trị và trả về chính đối tượng (*this) để hỗ trợ phương thức chuỗi (method chaining).
Tạo phương thức display để in thông tin.
Trong main(), tạo một đối tượng và sử dụng phương thức chuỗi để thiết lập thông tin, sau đó hiển thị.

Ví dụ đầu ra:

textName: John, Salary: 50000
```


## **Ex11: Đa hình thời gian chạy (Run-time Polymorphism)**
```
Viết lớp cơ sở Shape với phương thức ảo draw và getArea.

Tạo hai lớp con Rectangle và Circle, ghi đè các phương thức draw và getArea.
Trong main(), tạo một mảng con trỏ Shape*, chứa các đối tượng Rectangle và Circle, sau đó gọi draw và getArea cho từng đối tượng.

Ví dụ đầu ra:

textDrawing Rectangle
Area: 20
Drawing Circle
Area: 78.54
```
## **Ex12: Kế thừa đa cấp (Multilevel Inheritance)**
```
Viết lớp cơ sở Person với các thuộc tính name và age.

Tạo lớp con Student kế thừa từ Person, thêm thuộc tính studentId.
Tạo lớp con GraduateStudent kế thừa từ Student, thêm thuộc tính thesisTitle.
Tạo phương thức display trong mỗi lớp để hiển thị thông tin.
Trong main(), tạo đối tượng GraduateStudent và gọi display.

Ví dụ đầu ra:

textName: Alice, Age: 25, Student ID: S123, Thesis: AI Research
```
## **Ex13: Nạp chồng toán tử phức tạp**
```
Viết lớp Matrix để biểu diễn ma trận 2D với thuộc tính là con trỏ động int** data, rows, và cols.

Nạp chồng toán tử + để cộng hai ma trận cùng kích thước.
Nạp chồng toán tử << để in ma trận.
Tạo constructor, destructor để quản lý bộ nhớ động.
Trong main(), tạo hai ma trận, cộng chúng và hiển thị kết quả.

Ví dụ đầu ra:

textMatrix 1:
1 2
3 4
Matrix 2:
5 6
7 8
Sum:
6 8
10 12
```
## **Ex14: Quản lý danh sách đối tượng**
```
Viết lớp Library để quản lý danh sách các đối tượng Book (mỗi Book có title, author, year).

Tạo phương thức để thêm sách, xóa sách theo title, và hiển thị tất cả sách.
Sử dụng con trỏ động để lưu danh sách sách (hoặc std::vector nếu đã học).
Tạo destructor để giải phóng bộ nhớ.
Trong main(), thực hiện các thao tác thêm, xóa và hiển thị.

Ví dụ đầu ra:

textLibrary:
Book: 1984, Author: Orwell, Year: 1949
Book: Dune, Author: Herbert, Year: 1965
After removing 1984:
Book: Dune, Author: Herbert, Year: 1965
```
