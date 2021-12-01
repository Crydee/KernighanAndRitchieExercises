#include <limits.h>

int main()
{
  float f = (float)INT_MAX;
  printf("%d %f\n%d %f\n", INT_MAX, f, INT_MAX - 1, f - 1);
}
