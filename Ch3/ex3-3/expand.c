/* Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz
 * in s2.  Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.  Arrange that a
 * leading or trailing - is taken literally. */

#include <stdio.h>

int expand(char s1[], char s2[]);
int are_ints(char c, char d);
int are_lalph(char c, char d);
int are_ualph(char c, char d);

int main() {
  char test_in[1000] = "a-b and c-f and 1-92-4 some- -foo", test_out[1000];

  printf("the test input is: %s\n", test_in);
  expand(test_in, test_out);
  printf("the expanded output is: %s\n", test_out);
  
}

int expand(char in[],char expanded[]) {
  int i, j, k;

  for (i = j = 0; in[i] != '\0'; i++) {

    if ((i != 0) && (in[i] == '-')) {
      /* check if this is a short-hand that we want to expand. */
      if ((in[i-1] < in[i+1]) && (are_ints(in[i-1], in[i+1]) || are_lalph(in[i-1], in[i+1]) || are_ualph(in[i-1], in[i+1]))) {
        /* we want to expand this shorthand.  Since we've already written the member of the expansion with the smallest valued character constant, we don't want to print it again.
         * We also don't want to write the upper most value as we'll write that when we go round the outer for loop again.  We just want to write the values between the two
         * bounds, if any exist. */
        k = 1;
        while (k < (in[i+1] - in[i-1]))
          expanded[j++] = (in[i-1] + k++);
      } else {
        expanded[j++] = in[i];
      }
    } else {
      expanded[j++] = in[i];
    }
  }
  expanded[j++] = in[i];
  return j;
}

int are_ints(char c, char d) {
  int ret_val = 0;

  if ((('0' <= c) && ('9' >= c)) && (('0' <= d) && ('9' >= d)))
    ret_val = 1;

  return ret_val;
}

int are_lalph(char c, char d) {
  int ret_val = 0;

  if ((('a' <= c) && ('z' >= c)) && (('a' <= d) && ('z' >= d)))
    ret_val = 1;

  return ret_val;
}

int are_ualph(char c, char d) {
  int ret_val = 0;

  if ((('A' <= c) && ('Z' >= c)) && (('A' <= d) && ('Z' >= d)))
    ret_val = 1;

  return ret_val;
}
