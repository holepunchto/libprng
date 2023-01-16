#include <assert.h>
#include <stdbool.h>

#include "../include/prng.h"

int
main () {
  prng_t *prng;
  prng_init(1234, &prng);

  assert(prng_next_bool(prng) == true);
  assert(prng_next_bool(prng) == false);

  prng_destroy(prng);
}
