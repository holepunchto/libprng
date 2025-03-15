#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "../include/prng.h"

static inline bool
fequal(double a, double b) {
  return fabs(a - b) < 0.000001;
}

int
main() {
  prng_t prng;
  prng_init(&prng, 1234);

  assert(fequal(prng_next_double(&prng), 0.757048));
  assert(fequal(prng_next_double(&prng), 0.424305));
  assert(fequal(prng_next_double(&prng), 0.953830));
  assert(fequal(prng_next_double(&prng), 0.006733));
}
