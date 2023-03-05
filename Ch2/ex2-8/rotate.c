
unsigned rotate(unsigned x, int n);

main() {}
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

