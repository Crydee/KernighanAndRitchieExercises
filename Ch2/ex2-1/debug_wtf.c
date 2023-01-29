// What is going on here then? 
// I think some odd overflow stuff may be going on, since we see squaring, then doubling, then squaring again.  Suspicious!.
#include <stdio.h>
#include <limits.h>

unsigned long int max_unsigned_long_val(void);

int main()
{
  long int li_val;

  printf("Before the loop\n");

  li_val = max_unsigned_long_val();

  printf("After the loop\n");

  printf("The value was: %lu\n", li_val);
  printf("That value plus one is: %lu", li_val + 1);
}

unsigned long int max_unsigned_long_val(void) {
  unsigned long int max_unsigned_long;
  max_unsigned_long = 0;
  while (1) {
    if ((max_unsigned_long * max_unsigned_long) > max_unsigned_long) {
      printf("squaring\n");
      max_unsigned_long = (max_unsigned_long * max_unsigned_long);
      printf("val is: %lu\n", max_unsigned_long);
    } 
    else if ((max_unsigned_long * 2) > max_unsigned_long) {
      max_unsigned_long = max_unsigned_long * 2;
      printf("doubling\n");
      printf("val is: %lu\n", max_unsigned_long);
    }
    else if ((max_unsigned_long + 1) > max_unsigned_long) {
      max_unsigned_long = max_unsigned_long + 1;
//      printf("Adding one\n");
    }
    else
      break;
  }
  return max_unsigned_long;
}
