/* In a two's complement number system, x &= (x - 1) deletes the rightmost 1-bit in x. */
/* Explain why.  Use this observation to write a faster version of bitcount. */

/* Explanation: */
/* If x is not 0, then it has a rightmost 1-bit.  If that rightmost 1-bit is in the 1's position then it's clearly true. */
/* So we know that the rightmost 1-bit in x is followed by zero or more 0-bits, and no 1-bits, as if there were any other 1-bits */
/* after then the rightmost 1-bit would not be the rightmost 1-bit.  If the rightmost 1-bit is not in the 1's position, then we know */  
/* that it is followed by at least one zero.  We know that if we were to & (bitwise AND) x with any other integral value that the bits in*/
/* the positions after the position of the rightmost 1-bit in x would be set to zero.  When we take 1 from x, we set the rightmost 1-bit */
/* to zero, and set all of the bits to the right to 1.  All other bits are left unchanged.  We can see that this is true since if we */
/* were to add 1 to that value, we'd end up with x again (which is to say, if n + 1 = x <=> x - 1 = n).  Since we already know that */
/* all of the bits in positions to the right of the rightmost 1-bit in x are zero, and we know that the bit in x - 1 in the position */
/* of the rightmost 1-bit in x is also zero, it's clear that the result of x &= (x - 1) will set all the bits from the position of the */
/* rightmost 1-bit of x and to the right to zero.  This deletes the rightmost 1-bit of x since we know that it was the only 1-bit in */
/* that range. */

#include <stdio.h>

int bitcount(unsigned x);

int main() {
  int x = 0177, num;

  num = bitcount(x);
  printf("The number of 1-bits in %d is %d.\n", x, num);

}

int bitcount(unsigned x) {
  int count;

  for (count = 0; x != 0; x &= (x - 1))
    count++;

  return count;
}
