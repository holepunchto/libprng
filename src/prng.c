#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/prng.h"
#include "splitmix64.h"
#include "xoshiro256pp.h"

int
prng_init(prng_t *generator, int64_t seed) {
  uint64_t state[4];

  for (int i = 0; i < 4; i++) {
    uint64_t k = state[i] = splitmix64((uint64_t *) &seed);

    if (k == 0) return -1;
  }

  memcpy(generator->state, state, sizeof(state));

  return 0;
}

bool
prng_next_bool(prng_t *generator) {
  return xoshiro256pp(generator->state) >> 63;
}

uint32_t
prng_next_uint32(prng_t *generator) {
  return xoshiro256pp(generator->state) >> 32;
}

extern uint32_t
prng_next_uint32_range(prng_t *generator, uint32_t min, uint32_t max);

extern int32_t
prng_next_int32(prng_t *generator);

extern int32_t
prng_next_int32_range(prng_t *generator, int32_t min, int32_t max);

uint64_t
prng_next_uint64(prng_t *generator) {
  return xoshiro256pp(generator->state);
}

extern uint64_t
prng_next_uint64_range(prng_t *generator, uint64_t min, uint64_t max);

extern int64_t
prng_next_int64(prng_t *generator);

extern int64_t
prng_next_int64_range(prng_t *generator, int64_t min, int64_t max);

float
prng_next_float(prng_t *generator) {
  return (xoshiro256pp(generator->state) >> 40) * 0x1.0p-24f;
}

double
prng_next_double(prng_t *generator) {
  return (xoshiro256pp(generator->state) >> 11) * 0x1.0p-53;
}
