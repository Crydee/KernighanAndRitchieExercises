/* In a two's complement number representation, our version of itoa does not handle the largest negative number, that is, the value of
 * n equal to -(2^(wordsize - 1)).  Explain why not.  Modify it to print that value correctly, regardless of the machine on which it runs. */

/*  The problem is that we make n positive, if it's negative, but a two's complement representation can represent, for a given wordsize, a negative
 *  value with magnitude one larger than the largest positive value. The value of the largest +ve value that can be represented is
 *  2^(wordsize - 1) - 1*/

void itoa(int n, char s[]);
void mod_itoa(int n, char s[]);
int reverse(char s[]);

#include <stdio.h>
#include <limits.h>

int main() {
  int input = INT_MIN;
  char output[100];

  mod_itoa(input, output);
  printf("Calling our modified itoa on %d, gives %s\n", input, output);

  itoa(input, output);
  printf("Calling base itoa on %d, gives %s\n", input, output);

}

void mod_itoa(int n, char s[]) {
  int i, sign;

  if ((sign = n) > 0) /* record sign */
    n = -n;           /* make n -ve */
  i = 0;
  do {
    s[i++] = '0' - (n % 10); /* get next digit */
  } while ((n /= 10) < 0);
  if (sign < 0)
    s[i++] = '-';
  reverse(s);
}

void itoa(int n, char s[]) {
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

int reverse(char s[]) {
  int i, j, k;

  j = 0;
  while (s[j] != '\0')
    j++;
  j--;

  for(i = 0; i < j; i++, j--) {
    k = s[i];
    s[i] = s[j];
    s[j] = k;
  }
  return j;
}
