#ifndef PRNG_SPLITMIX64_H
#define PRNG_SPLITMIX64_H

#include <stdint.h>

// See https://prng.di.unimi.it/splitmix64.c

static inline uint64_t
splitmix64 (uint64_t s[1]) {
  uint64_t x = (s[0] += 0x9e3779b97f4a7c15);

  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;

  return x ^ (x >> 31);
}

#endif // PRNG_SPLITMIX64_H
