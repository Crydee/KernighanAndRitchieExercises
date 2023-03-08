/* Write a function rightrot(x,n) that returns the value of the integer x rightrotd to the right by n bit positions. */
#include <stdio.h>
unsigned rightrot(unsigned x, int n);
void print_bits(unsigned x);

main() {
  unsigned n = 100000000, k = 5;

  printf("n is %o ", n);
  printf("with bit pattern: \n");
  print_bits(n);

  printf("Rotating by %d bits gives: ", k);
  n = rightrot(n, k);
  print_bits(n);
}

unsigned rightrot(unsigned x, int n) {
  int i;

  for (i = 0; i < n; i++) {
    if ((x & ~((unsigned)~0 << 1)) == 1) {
      /* We cast ~0 to an unsigned int to make sure that the vacated bits are filled with 0s rather than 1s. */
      x = (x >> 1) | ~((unsigned)~0 >> 1);
    }
    else 
      x = x >> 1;
  }
  return x;
}

void print_bits(unsigned x) {
  int shift = 0, lim = sizeof(unsigned) * 8;
  
  while (shift < (lim))
    printf("%d", (x >> ((lim - 1) - shift++)) & 1);
  printf("\n");
}

