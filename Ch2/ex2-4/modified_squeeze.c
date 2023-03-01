/* Write an altenate version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

main() {
  char test_string[] = "the quick brown fox jumps over the lazy dog", remove_these[] = "aeiou";

  printf("remove from the string \"%s\", any of the characters in the string \"%s\"\n", test_string, remove_these);
  squeeze(test_string, remove_these);
  printf("%s\n", test_string);
}

void squeeze(char s1[], char s2[]) {
  int i, j, k, match;

  for (i = j = 0; s1[i] != '\0'; i++) {
    k = match = 0;
    
    while (s2[k] != '\0') {
      if (s1[i] == s2[k++]) {
        match = 1;
        break;
      }
    }

    if (!match)
      s1[j++] = s1[i];
  }

  while (j < i)
    s1[j++] = '\0';
}

