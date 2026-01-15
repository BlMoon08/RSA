#ifndef RSA_STRING_H
#define RSA_STRING_H

#include <vector>
#include <string>
using namespace std;

vector<long long> encryptString(string text, long long e, long long n);
string decryptString(vector<long long> encrypted, long long d, long long n);

#endif
