/* Write a function setbits(x, p, n, y) that returns x with the n bits that began at position p set to the rightmost n bits of y, leaving the */
/* other bits unchanged.  We assume that the rightmost bit of x is at position 0. */

#include <stdio.h>
#include <limits.h>

void print_bits(unsigned x);
unsigned setbits(unsigned x, int p, int n, unsigned y);

main() {
  unsigned x, y, clearing_mask, setting_mask;
  int n, p;

  n = 10;
  p = 12;

  x = 0;
  y = ~0;
  printf("p is %d, n is %d\n", p, n);
  printf("The binary representation of x = %d is: ", x);
  print_bits(x);

  printf("The binary representation of y = %d is: ", y);
  print_bits(y);

  x = setbits(x, p, n, y); 
  print_bits(x);
}

void print_bits(unsigned x) {
  int shift = 0, lim = sizeof(unsigned) * 8;
  
  while (shift < (lim))
    printf("%d", (x >> ((lim - 1) - shift++)) & 1);
  printf("\n");
}
unsigned setbits(unsigned x, int p, int n, unsigned y) {
  unsigned clearing_mask = ~(~(~0 << n) << (p + 1 - n));
  unsigned setting_mask = (~(~0 << n) & y) << (p + 1 - n);

  printf("The clearing mask is: ");
  print_bits(clearing_mask);
  printf("The setting mask is: ");
  print_bits(setting_mask);
  printf("After the tansforation, x's binary representation is: ");

  return ((x & clearing_mask) | setting_mask);
}
