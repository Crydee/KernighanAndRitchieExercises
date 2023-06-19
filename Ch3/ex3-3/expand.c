/* Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz
 * in s2.  Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z.  Arrange that a
 * leading or trailing - is taken literally. */

#include <stdio.h>

int expand(char s1[], char s2[]);
int is_int(char c);
int is_lalph(char c);
int is_ualph(char c);

int main() {
  char test_in[1000] = "a-b and c-f and 1-92-4 some- -foo", test_out[1000];

  printf("the test input is: %s\n", test_in);
  expand(test_in, test_out);
  printf("the expanded output is: %s\n", test_out);
  
}

int expand(char in[],char expanded[]) {
  int i, j, k;

  for (i = j = 0; in[i] != '\0'; i++, j++) {
    if (i > 0 && in[i] == '-') {
      /* this may be a shorthand that we want to expand, so check the values on either side. */
      if ((in[i-1] < in[i+1]) && ((is_int(in[i-1]) && is_int(in[i+1])) || (is_lalph(in[i-1]) && is_lalph(in[i+1])) || (is_ualph(in[i-1]) && is_ualph(in[i+1])))) {
        /* we have a - separating values of 'matching type' so write the expansion */
        printf("expanding\n");
        for (k = in[i-1] + 1; k <= in[i+1];j++, k++) {
          printf("writing  %c  to the arr\n", k);
          expanded[j] = k;
        }
        j++;
      } else {
        expanded[j] = in[i];
      }
    } else {
        expanded[j] = in[i];
    }
  }
  return j;
}

int is_int(char c) {
  int ret_val = 0;

  if (('0' <= c) && ('9' >= c))
    ret_val = 1;

  return ret_val;
}

int is_lalph(char c) {
  int ret_val = 0;

  if (('a' <= c) && ('z' >= c))
    ret_val = 1;

  return ret_val;
}

int is_ualph(char c) {
  int ret_val = 0;

  if (('A' <= c) && ('Z' >= c))
    ret_val = 1;

  return ret_val;
}
