/* Write the function itob(n,s,b) that converts the integer n into a base b character representation in the string s. */

#include <stdio.h>

int itob(int n, char s[], int b);
int reverse(char s[]);

int main(){
  int input_int = -20, radix = 9;
  char output_str[20];

  itob(input_int, output_str, radix);
  printf("calling itob to display %d in base %d returns: %s\n", input_int, radix, output_str);
}

int itob(int n, char s[], int b) {
  int i = 0, sign;

  if ((sign = n) > 0)
    n = -n;

  while (n < 0) {
    s[i++] = ('0' - (n % b));
    n /= b;
  }

  if (sign < 0)
    s[i++] = '-';

  reverse(s);
  return i;
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
