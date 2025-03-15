#ifndef PRNG_H
#define PRNG_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct prng_s prng_t;

struct prng_s {
  uint64_t state[4];
};

int
prng_init (prng_t *generator, int64_t seed);

bool
prng_next_bool (prng_t *generator);

int32_t
prng_next_int32 (prng_t *generator);

int64_t
prng_next_int64 (prng_t *generator);

double
prng_next_double (prng_t *generator);

#ifdef __cplusplus
}
#endif

#endif // PRNG_H
