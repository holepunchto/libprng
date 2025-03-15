#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "../include/prng.h"

int
main() {
  prng_t prng;
  prng_init(&prng, 1234);

  assert(prng_next_int32(&prng) == -1043469703);
  assert(prng_next_int32(&prng) == 1822375822);
  assert(prng_next_int32(&prng) == -198298631);
  assert(prng_next_int32(&prng) == 28919696);
}
