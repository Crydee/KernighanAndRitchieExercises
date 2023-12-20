/* Write a pointer version of the function strcat that we showed in chapter 2: strcat(s,t) copies the string t to the end of s. */
#include <stdio.h>

void pstrcat(char *s, char *t);

int main() {
  char s[100] = "abcdef01234", t[100] = "gjikl01234";

  printf("s is %s\n", s);
  printf("t is %s\n", t);
  pstrcat(s, t);
  printf("After concatenation, s is: %s\n", s);

}

/* pstrcat: pointer version of strcat from the book.  Concatenate to to end of s; s must be big enough */
void pstrcat(char *s, char *t) {
  /* Find the end of the string s. */
  while(*s)
    s++;
  /* Concatenate t onto s, including the null-terminator. */
  while((*(s++) = *(t++)))
    ;
}
