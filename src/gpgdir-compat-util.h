#ifndef GPGDIR_COMPAT_UTIL_H
#define GPGDIR_COMPAT_UTIL_H

/*
 * ARRAY_SIZE - get the number of elements in a visible array <at> x: the array
 * whose size you want.
 *
 * This does not work on pointers, or arrays declared as [], or function
 * parameters.
 */
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x)[0])

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#endif /* GPGDIR_COMPAT_UTIL_H */
