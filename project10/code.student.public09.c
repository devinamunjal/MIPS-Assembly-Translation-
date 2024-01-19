#include "code.student.public09.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

int max(int x, int y, int z) {
  x= (x > y) ? x : y;  /* x has the max of x and y */

  return (x > z) ? x : z;
}
