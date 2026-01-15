#include <iostream>
#include "rsa_string.h"
#include "rsa_crypto.h"

using namespace std;

vector<long long> encryptString(string text, long long e, long long n) {
    vector<long long> encrypted;

    int blockSize = 1;
    long long maxVal = 256;

    while (maxVal * 256 < n) {
        maxVal *= 256;
        blockSize++;
    }
    blockSize--;
    if (blockSize < 1) blockSize = 1;

    cout << "Su dung block size: " << blockSize << " ky tu/block\n";

    for (size_t i = 0; i < text.length(); i += blockSize) {
        long long m = 0;
        int count = 0;

        for (int j = 0; j < blockSize && i + j < text.length(); j++) {
            m = m * 256 + (unsigned char)text[i + j];
            count++;
        }

        m = m * 256 + count;

        long long c = encrypt(m, e, n);
        if (c != -1)
            encrypted.push_back(c);
    }

    return encrypted;
}

string decryptString(vector<long long> encrypted, long long d, long long n) {
    string decrypted = "";

    for (long long c : encrypted) {
        long long m = decrypt(c, d, n);

        int count = m % 256;
        m /= 256;

        string block = "";
        for (int i = 0; i < count; i++) {
            block = (char)(m % 256) + block;
            m /= 256;
        }

        decrypted += block;
    }

    return decrypted;
}
