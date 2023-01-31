/* Write a program to determine the ranges of char, short, int, and long variables, both signed and unsigned, */ 
/* by printing appropriate values from standard headers and byy  direct computation. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

  /* range of char, signed and unsigned. */
  printf("==== The range of values for a range of character types ====\n");

  printf("Unsigned chars range from %u to %u\n", 0, UCHAR_MAX);
  printf("Signed chars range from %hhd to %hhd\n", SCHAR_MIN, SCHAR_MAX);
  printf("Chars range from %d to %d\n", CHAR_MIN, CHAR_MAX);

  printf("==========\n\n");

  /* range of int, signed and unsigned. */
  printf("==== The range of values for a range of integer types ====\n");

  printf("The range of values of ints is: %d to %d\n", INT_MIN, INT_MAX);
  printf("The range of values of long ints is: %ld to %ld\n", LONG_MIN, LONG_MAX);
  printf("The range of values for short ints is: %hd to %hd\n\n", SHRT_MIN, SHRT_MAX);

  printf("The range of values of unsigned ints is: %u to %u\n", 0, UINT_MAX);
  printf("The range of values of long unsigned ints is: %lu to %lu\n", 0, ULONG_MAX);
  printf("The range of values of short unsigned ints is: %hu to %hu\n", 0, USHRT_MAX);

  printf("==========\n\n");

  /* range of various floating point types. */
  printf("The range of floats is: %f to %f\n", FLT_MIN, FLT_MAX);
  printf("The range of double precision floats is: %f to %f\n", DBL_MIN, DBL_MAX);
  printf("The range of long doubles is: %Lf to %Lf\n", LDBL_MIN, LDBL_MAX);
}


