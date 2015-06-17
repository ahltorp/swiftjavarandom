#ifndef javarandom_c
#define javarandom_c

#include <sys/types.h>

void
java_random_setseed(u_int64_t *seed, u_int64_t inseed);

int32_t
java_random_next(u_int64_t *seed, int bits);

int32_t
java_random_nextint(u_int64_t *seed);

int32_t
java_random_nextint_n(u_int64_t *seed, int32_t n);

#endif /* javarandom_c */
