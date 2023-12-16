/* Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling a recursive
 * routine.*/

#include <stdio.h>
#include <stdlib.h>

void printd(int);
void rec_itoa(int, char []);

int main() {
  char string[100];
  int test_num = -123456;

  rec_itoa(test_num, string);
  printf("rec itoa of %d is %s\n", test_num, string);
}

void rec_itoa(int n, char s[])
{
  static int i;

  if (n / 10) /* If we are not at the most significant digit, then we want to call this fct to handle the more significant digits first.*/
    rec_itoa(n / 10, s);
  else { /* We are at the most significant digit, so we set the index to zero, as we want to fill the array from the left.*/
    i = 0;
    if (n < 0) /* We handle the number being negative here, and from then on we use the absolute val of the number to get the digits.*/
      s[i++] = '-';
  }

  /* These two lines are common to the end case as well as to the recursive case. We always want to add the value of the current
   * right-most digit of the number to the array, and to terminate the array with a null character.  The null will be overwritten in all
   * but the  first call of the fct (the one that handles the least significant digit.*/
  s[i++] = abs(n) % 10 + '0';
  s[i] = '\0';
}

void printd(int n)
{
  if (n < 0) {
    putchar('-');
    n = -n;  /* this is dodgy on a 2's complement system.*/
  }
  if (n / 10)
    printd(n / 10);
  putchar(n % 10 + '0');
}
