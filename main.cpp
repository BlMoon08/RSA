#include <iostream>
#include <vector>
#include <string>

#include "rsa_keygen.h"
#include "rsa_crypto.h"
#include "rsa_string.h"

using namespace std;

int main() {
    long long e, d, n;

    cout << "========== CHUONG TRINH MA HOA RSA ==========\n\n";

    if (!generateKeys(e, d, n)) {
        cout << "Loi sinh khoa!\n";
        return 1;
    }

    cout << "\n========== KHOA CONG KHAI VA BI MAT ==========\n";
    cout << "Khoa cong khai (e, n): (" << e << ", " << n << ")\n";
    cout << "Khoa bi mat (d, n): (" << d << ", " << n << ")\n";
    cout << "============================================\n\n";

    int choice;
    cout << "Chon loai du lieu muon ma hoa:\n";
    cout << "1. Ma hoa so nguyen\n";
    cout << "2. Ma hoa chuoi ky tu\n";
    cout << "Lua chon cua ban: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        long long M;
        cout << "\nNhap thong diep M (0 <= M < " << n << "): ";
        cin >> M;

        if (M < 0 || M >= n) {
            cout << "Loi: Thong diep khong hop le!\n";
            return 1;
        }

        cout << "\nThong diep goc: " << M << endl;

        long long C = encrypt(M, e, n);
        cout << "Thong diep da ma hoa: " << C << endl;

        long long decrypted = decrypt(C, d, n);
        cout << "Thong diep da giai ma: " << decrypted << endl;

        if (M == decrypted)
            cout << "\n✓ Ma hoa va giai ma thanh cong!\n";
        else
            cout << "\n✗ Loi ma hoa / giai ma!\n";

    } 
    else if (choice == 2) {
        string text;
        cout << "\nNhap chuoi can ma hoa: ";
        getline(cin, text);

        if (text.empty()) {
            cout << "Loi: Chuoi rong!\n";
            return 1;
        }

        cout << "\nChuoi goc: " << text << endl;

        vector<long long> encrypted = encryptString(text, e, n);
        cout << "Chuoi da ma hoa: ";
        for (long long c : encrypted)
            cout << c << " ";
        cout << endl;

        string decrypted = decryptString(encrypted, d, n);
        cout << "Chuoi da giai ma: " << decrypted << endl;

        if (text == decrypted)
            cout << "\n✓ Ma hoa va giai ma thanh cong!\n";
        else
            cout << "\n✗ Loi ma hoa / giai ma!\n";
    }
    else {
        cout << "Lua chon khong hop le!\n";
    }

    return 0;
}
