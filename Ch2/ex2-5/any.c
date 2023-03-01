/* Write the function any(s1, s2), which returns the first ocation in the string s1 where any character from the string s2 occurs, or -1 if */
/* s1 contains no characters from s2. */

#include <stdio.h>

int any(char s1[], char s2[]);

main() {
  char look_here_for_matches[] = "the quick brown fox jumps over the lazy dog", look_for_these[] = " ";
  int match_loc;
  
  printf("Look in this string \"%s\" for any of the characters contained in this string \"%s\"\n", look_here_for_matches, look_for_these);

  match_loc = any(look_here_for_matches, look_for_these);

  printf("first match is at index %d\n", match_loc);

}

int any(char s1[], char s2[]) {
  int i, k, match;

  match = 0;

  for (i = 0; s1[i] != '\0'; i++) {
    k = 0; 
    while (s2[k] != '\0') {
      if (s1[i] == s2[k++]) {
        return match = i;
      }
    }
  }
  return -1;
}

