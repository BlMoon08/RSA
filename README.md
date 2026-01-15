# Cài đặt thuật toán RSA bằng C++

## 1. Giới thiệu và ứng dụng
Dự án này cài đặt **thuật toán mật mã khóa công khai RSA** bằng ngôn ngữ **C++**.  
Chương trình mô phỏng đầy đủ quá trình làm việc của RSA, bao gồm sinh khóa, mã hóa và giải mã dữ liệu.

### Ứng dụng của thuật toán RSA
- Bảo mật thông tin trong truyền thông
- Chữ ký số
- Trao đổi khóa an toàn
- Nền tảng cho các giao thức bảo mật như SSL/TLS

Trong phạm vi dự án này, RSA được cài đặt nhằm:
- Minh họa nguyên lý hoạt động của thuật toán
- Phục vụ mục đích **học tập, nghiên cứu**
- Không hướng đến triển khai bảo mật thực tế

---

## 2. Nội dung đã cài đặt
Chương trình đã cài đặt các nội dung sau:

- Sinh cặp khóa RSA:
  - Khóa công khai `(e, n)`
  - Khóa bí mật `(d, n)`
- Kiểm tra số nguyên tố
- Tính lũy thừa modulo nhanh
- Thuật toán Euclid mở rộng
- Tìm nghịch đảo modulo
- Mã hóa và giải mã:
  - Thông điệp **số nguyên**
  - Thông điệp **chuỗi ký tự** (chia theo block)
- Kiểm tra tính đúng đắn của quá trình mã hóa – giải mã

---

## 3. Cấu trúc thư mục
```text
RSA/
├── include/
│   ├── math_utils.h        // Toán học nền (mulmod, power)
│   ├── prime_utils.h       // Kiểm tra số nguyên tố
│   ├── euclid.h            // Euclid mở rộng, nghịch đảo modulo
│   ├── rsa_keygen.h        // Sinh khóa RSA
│   ├── rsa_crypto.h        // Mã hóa / giải mã số
│   └── rsa_string.h        // Mã hóa / giải mã chuỗi
│
├── src/
│   ├── math_utils.cpp
│   ├── prime_utils.cpp
│   ├── euclid.cpp
│   ├── rsa_keygen.cpp
│   ├── rsa_crypto.cpp
│   └── rsa_string.cpp
│
├── main.cpp                // Chương trình chính
└── README.md
```
# Hướng dẫn biên dịch và chạy chương trình
## Biên dịch
Sử dụng trình biên dịch g++:
```text
g++ main.cpp src/*.cpp -Iinclude -o rsa
```
## Chạy chương trình:
```text
./rsa
```
Sau khi chạy, chương trình sẽ:

Yêu cầu nhập hai số nguyên tố p và q

Tự động sinh khóa RSA

Cho phép chọn:

* Mã hóa / giải mã số nguyên
* Mã hóa / giải mã chuỗi ký tự
# Bộ test vector (Test Case)
```text
Input : 
p = 1009

q = 1013

Kết quả mong đợi:

n = 3233

phi(n) = 3120

e =  65537  (gia tri chuan bao mat)

d = 832193
```
## Test mã hóa – giải mã số nguyên
```text

Input: Thông điệp M = 65

Quá trình: 

C = 65^65537 mod 3233= 341568

M = 341568^2513 mod 3233 = 65

Kết quả: Giải mã đúng, M ban đầu được khôi phục
```

## Test mã hóa – giải mã chuỗi ký tự
```text

Input: Chuỗi: HELLO
Quá trình:
* Chuỗi ký tự đầu vào được chia thành các block nhỏ, mỗi ký tự được biểu diễn bằng 1 byte (ASCII, cơ số 256).
* Mỗi block ký tự được chuyển thành một số nguyên sao cho giá trị luôn nhỏ hơn n của RSA.
* Từng block số được mã hóa độc lập bằng RSA theo công thức C= M^e mod n.
* Khi giải mã, các block được chuyển ngược lại thành ký tự và ghép theo đúng thứ tự ban đầu để thu được chuỗi gốc.
Kết quả:
* Chuỗi đã được mã hóa (5 blocks): 731303 501756 695207 695207 53604
* Chuỗi giải mã: HELLO
```
# Nhận xét và hạn chế

Chương trình không sử dụng padding (PKCS#1, OAEP, …)

Kích thước số nguyên tố nhỏ → không đảm bảo an toàn thực tế

Phù hợp cho học tập và minh họa thuật toán
# Kết luận

Dự án đã cài đặt thành công thuật toán RSA bằng C++ với đầy đủ các chức năng cơ bản.
Chương trình giúp hiểu rõ nguyên lý hoạt động của RSA, cách sinh khóa, mã hóa và giải mã dữ liệu.




