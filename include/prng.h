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
prng_init(prng_t *generator, uint64_t seed);

bool
prng_next_bool(prng_t *generator);

uint32_t
prng_next_uint32(prng_t *generator);

inline uint32_t
prng_next_uint32_range(prng_t *generator, uint32_t min, uint32_t max) {
  uint32_t range = max - min + 1;
  uint32_t limit = -range % range;
  uint32_t n;

  do {
    n = prng_next_uint32(generator);
  } while (n < limit);

  return min + (n % range);
}

inline int32_t
prng_next_int32(prng_t *generator) {
  return prng_next_uint32(generator);
}

inline int32_t
prng_next_int32_range(prng_t *generator, int32_t min, int32_t max) {
  return prng_next_uint32_range(generator, min, max);
}

uint64_t
prng_next_uint64(prng_t *generator);

inline uint64_t
prng_next_uint64_range(prng_t *generator, uint64_t min, uint64_t max) {
  uint64_t range = max - min + 1;
  uint64_t limit = -range % range;
  uint64_t n;

  do {
    n = prng_next_uint64(generator);
  } while (n < limit);

  return min + (n % range);
}

inline int64_t
prng_next_int64(prng_t *generator) {
  return prng_next_int64(generator);
}

inline int64_t
prng_next_int64_range(prng_t *generator, int64_t min, int64_t max) {
  return prng_next_uint64_range(generator, min, max);
}

float
prng_next_float(prng_t *generator);

double
prng_next_double(prng_t *generator);

#ifdef __cplusplus
}
#endif

#endif // PRNG_H
