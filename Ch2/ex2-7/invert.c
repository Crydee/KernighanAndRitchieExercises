/* Write a function invert(x, p, n) that returns x with the n bits that begin at position p inverted (i.e. 1 changed into 0 and */
/* vice versa), leaving the others unchanged. */

#include <stdio.h>

unsigned inverted(unsigned x, int p, int n);
void print_bits(unsigned x);

main() {
  unsigned x = ~0 << 2;
  int n = 6, p = 10;

  printf("x is: ");
  print_bits(x);
  x = inverted(x, p, n);
  
  printf("x is now: ");
  print_bits(x);

}

unsigned inverted(unsigned x, int p, int n) {
  unsigned mask = ~(~0 << n) << (p + 1 - n);
  printf("The mask is: ");
  print_bits(mask);
  return x ^ mask;
}

void print_bits(unsigned x) {
  int shift = 0, lim = sizeof(unsigned) * 8;
  
  while (shift < (lim))
    printf("%d", (x >> ((lim - 1) - shift++)) & 1);
  printf("\n");
}

