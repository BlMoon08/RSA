#include "math_utils.h"

long long mulmod(long long a, long long b, long long m) {
    return (__int128)a * b % m;
}

long long power(long long base, long long expo, long long m) {
    long long res = 1;
    base %= m;
    while (expo > 0) {
        if (expo & 1)
            res = mulmod(res, base, m);
        base = mulmod(base, base, m);
        expo >>= 1;
    }
    return res;
}
