#ifndef PRNG_XOSHIRO256PP_H
#define PRNG_XOSHIRO256PP_H

#include <stdint.h>

// See https://prng.di.unimi.it/xoshiro256plusplus.c

static inline uint64_t
rotl (const uint64_t x, int k) {
  return (x << k) | (x >> (64 - k));
}

static inline uint64_t
xoshiro256pp (uint64_t s[4]) {
  const uint64_t result = rotl(s[0] + s[3], 23) + s[0];

  const uint64_t t = s[1] << 17;

  s[2] ^= s[0];
  s[3] ^= s[1];
  s[1] ^= s[2];
  s[0] ^= s[3];

  s[2] ^= t;

  s[3] = rotl(s[3], 45);

  return result;
}

#endif // PRNG_XOSHIRO256PP_H
