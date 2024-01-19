#include "code.student.public08.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int power(int base, int exponent) {
  int i, result= base;

  for (i= 1; i < exponent; i++)
    result *= base;

  return result;
}
