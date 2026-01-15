#include "euclid.h"

long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

long long modInverse(long long e, long long phi) {
    long long x, y;
    long long g = extendedGCD(e, phi, x, y);
    if (g != 1) return -1;
    return (x % phi + phi) % phi;
}
