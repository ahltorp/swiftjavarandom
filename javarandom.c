#include "javarandom.h"

void
java_random_setseed(u_int64_t *seed, u_int64_t inseed)
{
    *seed = (inseed ^ 0x5DEECE66DLL) & ((1LL << 48) - 1);
}

int32_t
java_random_next(u_int64_t *seed, int bits)
{
    *seed = (*seed * 0x5DEECE66DL + 0xBLL) & ((1LL << 48) - 1);
    return (int32_t)(*seed >> (48 - bits));
}

int32_t
java_random_nextint(u_int64_t *seed)
{
    return java_random_next(seed, 32);
}

int32_t
java_random_nextint_n(u_int64_t *seed, int32_t n) {
    if ((n & -n) == n)  // i.e., n is a power of 2
        return (int32_t)((n * (int64_t)java_random_next(seed, 31)) >> 31);
    
    int bits, val;
    do {
        bits = java_random_next(seed, 31);
        val = bits % n;
    } while(bits - val + (n-1) < 0);
    return val;
}
