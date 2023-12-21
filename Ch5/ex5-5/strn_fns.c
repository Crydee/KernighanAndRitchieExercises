/* Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their
 * argument strings.  For example, strncpy(s,t,n) copies at most n characters of t to s. */
#include <stdio.h>
#include <string.h>

char *my_strncpy(char *s, char *t, int n);
char *my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main() {
  char string_1[50] = "abcdefg", string_2[50] = "12345";
  printf("String 1 is: %s\nString 2 is: %s\n", string_1, string_2);
  my_strncpy(string_1, string_2, 7);
  printf("String 1 after the copy: %s\n", string_1);

  char string_3[50] = "abcdefg", string_4[50] = "12345";
  printf("String 3 is: %s\nString 4 is: %s\n", string_3, string_4);
  my_strncat(string_3, string_4, 4);
  printf("String 3 after concat'ing 4 letters of String 2: %s\n", string_3);

  char string_5[50] = "abcdfg", string_6[50] = "abcdefg";
  printf("String 5 is: %s\nString 6 is: %s\n", string_5, string_6);
  printf("Calling my strncmp on string 5 and string 6 with n 9 gives: %d\n", my_strncmp(string_5, string_6, 9));
}

/* my_strncpy: copy at most n characters of string t to s; return s.  Pad with '\0's if t has fewer than n characters. */
char *my_strncpy(char *s, char *t, int n) {
  char *pstr = s;
  /* count down from n, and check that we haven't reached the end of t. */
  while (n-- > 0 && *t) {
    *s++ = *t++;
  }
  /* pad with '\0's, if we have reached the end of t in the earlier loop before copying n characters. */
  while(n-- > 0) {
    *s++ = *t;
  }
  return pstr;
}

/* my_strncat: concatenate at most n characters of string t to string s, teminate s with '\0'; return s. */
char *my_strncat(char *s, char *t, int n) {
  /* Find the end of s. */
  int len_s = strlen(s);
  my_strncpy(s + len_s, t, n);
  /* Make sure we null-terminate the resulting string, as the question requires that we do so.  Just assume there is space. */
  *(s + len_s + n) = '\0';
  return s;
}

/* my_strncmp: compare at most n characters of string s to string t; return <0 is s<t, 0 if s==t, or >0 if s>t. */
int my_strncmp(char *s, char *t, int n) {
  for (; *s == *t; s++, t++) {
    if (*s == '\0' || --n <= 0) {
      return 0;
    }
  }
  return *s - *t;
}
