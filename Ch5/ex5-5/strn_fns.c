/* Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their
 * argument strings.  For example, strncpy(s,t,n) copies at most n characters of t to s. */
#include <stdio.h>

char *my_strncpy(char *s, char *t, int n);
char *my_strncat(char *s, char *t, int n);
char *my_strncmp(char *s, char *t, int n);

int main() {
  char string_1[50] = "abcdefg", string_2[50] = "12345";
  printf("String 1 is: %s\nString 2 is: %s\n", string_1, string_2);
  my_strncpy(string_1, string_2, 7);
  printf("String 1 after the copy: %s\n", string_1);
}

/* my_strncpy: copy at most n characters of string t to s; return s.  Pad with '\0's if t has fewer than n characters. */
char *my_strncpy(char *s, char *t, int n) {
  char *pstr = s;
  while (n-- > 0 && *t) {
    *s++ = *t++;
  }
  while(n-- > 0) {
    *s++ = *t;
  }
  return pstr;
}
/* my_strncat: concatenate at most n characters of string t to string s, teminate s ith '\0'; return s. */
char *my_strncat(char *s, char *t, int n) {}
/* my_strncmp: compare at most n characters of string s tto string t; return <0 is s<t, 0 if s==t, or >0 if s>t. */
char *my_strncmp(char *s, char *t, int n) {}
