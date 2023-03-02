/* Write a function setbits(x, p, n, y) that returns x with the n bits that began at position p set to the rightmost n bits of y, leaving the */
/* other bits unchanged.  We assume that the rightmost bit of x is at position 0. */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

main() {
 int n = 4, p = 4;
 unsigned mask = (~(~0 << n)) << p + 1 - n;
  printf("mask is %d\n", mask);
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned mask = (~(~0 << n)) << p + 1 - n;
}
