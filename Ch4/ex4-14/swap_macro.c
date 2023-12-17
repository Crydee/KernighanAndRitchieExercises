#include <stdio.h>

#define swap(t, x, y) {t temp = y; \
  y = x; \
  x = temp; \
  }

int main() {
  int varone = 1, vartwo = 2;
  printf("Before the swap, varone: %d, vartwo: %d\n", varone, vartwo);
  swap(int, varone, vartwo);
  printf("After the swap, varone: %d, vartwo: %d\n", varone, vartwo);

  char charone = 'a', chartwo = 'b';
  printf("Before the swap, charone: %c, chartwo: %c\n", charone, chartwo);
  swap(int, charone, chartwo);
  printf("After the swap, charone: %c, chartwo: %c\n", charone, chartwo);
}
