/* Write a recursive  ersion of teh function reverse(s), which reerrses the string s in place. */

#include <stdio.h>

void reverse(char s[], int lower, int upper);

int main() {
  char input[] = "abcdefg";

  printf("The result of calling reverse on %s ", input);
  reverse(input, 0, 6);
  printf("is %s\n", input);

}

void reverse(char s[], int lower, int upper) {
  int swap;

  if (lower < upper) {
    reverse(s, lower + 1, upper - 1);
    swap = s[lower];
    s[lower] = s[upper];
    s[upper] = swap;
  }
}

