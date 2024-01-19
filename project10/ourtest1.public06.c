#include <stdio.h>
#include <assert.h>
#include "code.student.public05.h"

/* (c) Larry Herman, 2023.  You are allowed to use this code yourself, but
   not to provide it to anyone else. */

/* this represents one test of the functions in code.student.public05.c */

int main(void) {
  assert(sum(216, 250) == 466);

  printf("The student code in code.student.public05.c works on its ");
  printf("first test!\n");

  return 0;
}
