#include <iostream>
#include <vector>
#include <algorithm>
#include "rsa_keygen.h"
#include "prime_utils.h"
#include "euclid.h"

using namespace std;

bool generateKeys(long long &e, long long &d, long long &n) {
    int p, q;

    do {
        cout << "Nhap p: ";
        cin >> p;
    } while (!isPrime(p));

    do {
        cout << "Nhap q (khac p): ";
        cin >> q;
    } while (!isPrime(q) || q == p);

    n = 1LL * p * q;
    long long phi = 1LL * (p - 1) * (q - 1);

    vector<long long> standardE = {65537, 257, 17, 5, 3};
    for (auto cand : standardE)
        if (cand < phi && __gcd(cand, phi) == 1) {
            e = cand;
            break;
        }

    d = modInverse(e, phi);
    return d != -1;
}
