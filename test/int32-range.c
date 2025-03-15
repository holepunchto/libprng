#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "../include/prng.h"

int
main() {
  prng_t prng;
  prng_init(&prng, 1234);

  assert(prng_next_int32_range(&prng, -500, 500) == -156);
  assert(prng_next_int32_range(&prng, -500, 500) == -233);
  assert(prng_next_int32_range(&prng, -500, 500) == -411);
  assert(prng_next_int32_range(&prng, -500, 500) == 306);
}
