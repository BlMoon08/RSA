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
Input : 
p = 61

q = 53

Kết quả mong đợi:

n = 3233

phi(n) = 3120

e =  257  (gia tri chuan bao mat)

d = 2513

## Test mã hóa – giải mã số nguyên

Input: Thông điệp M = 65

Quá trình: 

C=65^257 mod 3233=2790

M=2973^2513 mod 3233=65

Kết quả: Giải mã đúng, M ban đầu được khôi phục

## Test mã hóa – giải mã chuỗi ký tự

Input: Chuỗi: HELLO

