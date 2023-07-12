/* In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of
 * n equal to -(2^(wordsize - 1)).  Explain why not.  Modify it to print that value correctly, regardless of the machine on which it runs. */

/*  The problem is that we make n positive if it's negative, but a two's complement representation can represent, for a given wordsize, a negative
 *  value with magnitude one larger than the largest positive value. The value of the largest +ve value that can be represented is
 *  2^(wordsize - 1) - 1*/

void itoa(int n, char s[]);
void mod_itoa(int n, char s[]);

#include <stdio.h>

void mod_itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) > 0) /* record sign */
    n = -n;           /* make n -ve */
  i = 0;
  do {
    s[i++] = '0' - (n % 10); /* get next digit */
  } while ((n /= 10) < 0)
  if (sign < 0)
    s[i++] = '-';
  reverse(s);
}

void itoa(int n, char s[], int width) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n +ve */
  i = 0;
  do {                /* generate digits in reverse order */
    s[i++] = n % 10 + '0';  /* get next digit */
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  reverse(s);
}
