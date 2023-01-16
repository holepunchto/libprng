#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../include/prng.h"
#include "splitmix64.h"
#include "xoshiro256pp.h"

struct prng_s {
  uint64_t state[4];
};

int
prng_init (int64_t seed, prng_t **result) {
  uint64_t state[4];

  for (int i = 0; i < 4; i++) {
    uint64_t k = state[i] = splitmix64((uint64_t *) &seed);

    if (k == 0) return -1;
  }

  prng_t *generator = malloc(sizeof(prng_t));

  memcpy(generator->state, state, sizeof(state));

  *result = generator;

  return 0;
}

void
prng_destroy (prng_t *generator) {
  free(generator);
}

bool
prng_next_bool (prng_t *generator) {
  return xoshiro256pp(generator->state) >> 63;
}

int32_t
prng_next_int32 (prng_t *generator) {
  return xoshiro256pp(generator->state) >> 32;
}

int64_t
prng_next_int64 (prng_t *generator) {
  return xoshiro256pp(generator->state);
}

double
prng_next_double (prng_t *generator) {
  static const uint64_t exp = 0x3ff0000000000000;

  uint64_t k = exp | xoshiro256pp(generator->state) >> 12;

  return ((double) k) - 1;
}
