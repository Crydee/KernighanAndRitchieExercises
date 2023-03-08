#include <stdio.h>
unsigned rotate(unsigned x, int n);
void print_bits(unsigned x);

main() {
  unsigned n = 0177, k = 1;

  printf("n is %o ", n);
  printf("with bit pattern: \n");
  print_bits(n);

  printf("Rotating by %d bits gives: ", k);
  n = rotate(n, k);
  print_bits(n);
}

unsigned rotate(unsigned x, int n) {
  int i;

  for (i = 0; i < n; i++) {
    if ((x & ~(~0 << 1)) == 1)
      x = (x >> 1) | ~(~0 >> 1);
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

