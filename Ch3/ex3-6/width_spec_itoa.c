/*Write a version of itoa that accepts three arguments instead of two.  The third argument is a minimum field witdh; the converted number must be padded with blanks on the left if necessary
 * to make it wide enough.*/

#include <stdio.h>

void itoa(int n, char [s], int width);
int reverse(char s[]);

int main() {}

void itoa(int n, char [s], int width) {
  int i, sign;

  if ((sign = n) < 0) /* record sign */
    n = -n;           /* make n +ve */
  i = 0;
  do {                /* generate digits in reverse order */
    s[i++] = n % 10 + '0';  /* get next digit */
  } while ((n /= 10) > 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
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
