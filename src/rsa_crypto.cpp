#include "rsa_crypto.h"
#include "math_utils.h"

long long encrypt(long long m, long long e, long long n) {
    return power(m, e, n);
}

long long decrypt(long long c, long long d, long long n) {
    return power(c, d, n);
}
