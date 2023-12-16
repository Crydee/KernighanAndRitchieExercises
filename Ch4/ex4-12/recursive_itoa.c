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

  if (n / 10)
    rec_itoa(n/10, s);
  else {
    i = 0;
    if (n < 0)
      s[i++] = '-';
  }

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
