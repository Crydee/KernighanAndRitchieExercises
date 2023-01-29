/* Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, */ 
/* by printing appropriate values from standard headers and byy  direct computation. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

unsigned long int max_unsigned_long_val(void);

int main()
{
  char c_val;
  signed char sc_val;
  unsigned char uc_val;

  int i_val;
  signed int si_val;
  unsigned int ui_val;
  long int li_val;
  short int shi_val;
  unsigned long int uli_val;
  unsigned short int ushi_val;
  signed long int sli_val;
  signed short int sshi_val;

  /* range of char, signed and unsigned. */
//  printf("==== The range of values for a range of character types ====\n");
//  printf("The range of values of a char is: %d <-> %d\n", c_val = CHAR_MIN, c_val = CHAR_MAX);
//  printf("The range of values of unsigned chars is: %d <-> %d\n", uc_val = 0, uc_val = UCHAR_MAX);
//  printf("The range of values of signed chars is: %d <-> %d\n", sc_val = SCHAR_MIN, sc_val = SCHAR_MAX);
//  printf("==========\n\n");

  /* range of int, signed and unsigned. */
//  printf("==== The range of values for a range of integer types ====\n");
//  printf("The range of values of ints is: %d <-> %d\n", i_val = INT_MIN, i_val = INT_MAX);
//  printf("The range of values of signed ints is: %d <-> %d\n", si_val = INT_MIN, si_val = INT_MAX); 
//  printf("The range of values of unsigned ints is: %u <-> %u\n", ui_val = 0, ui_val = UINT_MAX);
//  printf("The range of values of long ints is: %ld <-> %ld\n", li_val = LONG_MIN, li_val = LONG_MAX);
//  printf("The range of values of short ints is: %hd <-> %hd\n", shi_val = SHRT_MIN, shi_val = SHRT_MAX);
  /* This one about unsigned long ints is wrong. */
  printf("Before the loop");
  for (li_val = 0; li_val < LONG_MAX; li_val++);
  printf("After the loop");
  printf("The range of values of unsigned long ints is: %lu <-> %lu\n", uli_val = 0, uli_val = max_unsigned_long_val());
//  printf("difference between 2*LONG_MAX and calculated max is: %lu", (2*LONG_MAX) - max_unsigned_long_val());
//  printf("The range of values of unsigned short ints is: %hu <-> %hu\n", shi_val = 0, shi_val = INT_MAX);
//  printf("The range of values of short signed ints is: %hd <-> %hd\n", shi_val = SHRT_MIN, shi_val = SHRT_MAX);

  printf("==========\n\n");
  /* range of short variables. */

  /* range of long variables. */

  /* range of various floating point types. */

}

unsigned long int max_unsigned_long_val(void) {
  unsigned long int max_unsigned_long;
  max_unsigned_long = 0;
  while (1) {
    if (max_unsigned_long > 100)
      break;
    else if ((max_unsigned_long * max_unsigned_long) > max_unsigned_long) {
      printf("squaring\n");
      max_unsigned_long = (max_unsigned_long * max_unsigned_long);
    } 
    else if ((max_unsigned_long * 2) > max_unsigned_long) {
      max_unsigned_long = max_unsigned_long * 2;
      printf("doubling\n");
    }
    else if ((max_unsigned_long + 1) > max_unsigned_long)
      max_unsigned_long = max_unsigned_long + 1;
    else
      break;
  }
  return max_unsigned_long;
}
