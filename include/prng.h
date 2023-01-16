#ifndef PRNG_H
#define PRNG_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct prng_s prng_t;

int
prng_init (int64_t seed, prng_t **result);

void
prng_destroy (prng_t *generator);

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
