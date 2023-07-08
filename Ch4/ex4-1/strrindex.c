/* Write the function strrindex(s,t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none. */

#include <stdio.h>

int strrindex(char s[], char t[]);

int main() {
  char container[] = "012345abcdefg678abcd", target[] = "abcd";

  printf("searching for %s in %s.\n", target, container);

  printf("the rightmost occurrence starts at index %d\n", strrindex(container, target));
}

int strrindex(char s[], char t[]) {
  int i, j, k, ret_val = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = 0, k = i; (t[j] == s[k]) && (t[j] != '\0'); j++, k++)
      ;
    if (t[j] == '\0')  /* We have found a match for the entirety of t. */
      ret_val = i;
  }
  return ret_val;
}
