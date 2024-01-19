#include <stdio.h>
#include <assert.h>
#include "code.student.public09.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* this represents one test of the functions in code.student.public09.c */

int main(void) {
  int a, b, c;

  scanf("%d %d %d", &a, &b, &c);

  assert(max(a, b, c) == 999);

  printf("The student code in code.student.public09.c works on its ");
  printf("second test!\n");

  return 0;
}
